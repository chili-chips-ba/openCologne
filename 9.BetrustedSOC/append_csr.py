#!/usr/bin/python3

import argparse
import hashlib
import subprocess
import sys

from Crypto.IO import PEM
from nacl import signing  # counter-intuitively, this is from pycryptodome: `pip3 install pycryptodome` (ubuntu) `pip install pycryptodome` (maybe others?)
# note: if you did the sensible thing and tried to install the crypto or pycrypto libraries first when you hit this error
# you have to uninstall those before putting in pycryptodome: `pip remove crypto`, and then `pip install pycryptodome` (or pip3 on ubuntu)
from nacl.signing import SigningKey # from pynacl package: `pip3 install pynacl`
from nacl.encoding import RawEncoder

import socket
from datetime import datetime
import hashlib
import binascii

DEVKEY_PATH='./devkey/dev.key'
SIGNER_VERSION=1

def bytestring_to_record(b, maxlen):
    if len(b) > maxlen:
        ret = int(maxlen).to_bytes(4, 'little') + b[:maxlen]
    else:
        ret = int(len(b)).to_bytes(4, 'little') + b + bytes([0]) * (maxlen - len(b))

    # print(list(ret))  # for generating hostmode emulation records!
    return ret

def compute_metadata(checksum):
    meta = bytearray()

    # collect info about the build environment
    hostname = socket.gethostname()
    date = str(datetime.now())
    source_checksum = hashlib.md5(open('betrusted_soc.py', 'rb').read()).digest()
    tags = subprocess.check_output(["git", "describe", "--tags"])
    log = subprocess.check_output(["git", "log", "--name-status", "HEAD^..HEAD"])
    status_raw = subprocess.check_output(["git", "status"])
    status = ""
    for line in status_raw.decode('utf-8').splitlines():
        # use splitlines() because windows does \n\r, linux does \n only, and splitlines() handles both cases, removing all newline characters
        if "On branch" in line:
            status += line.replace("\t", " ")
            status += '\n' # we only use '\n' on precursor
        if "modified:" in line:
            status += line.replace("\t", " ")
            status += '\n'

    tag_str = str(tags, encoding=sys.getdefaultencoding())
    tag_fields = tag_str[1:].strip().replace('-','.').split('.')
    maj = int(tag_fields[0])
    min = int(tag_fields[1])
    rev = int(tag_fields[2])
    if len(tag_fields) > 3:
        extra = int(tag_fields[3])
    else:
        extra = 0
    if len(tag_fields) > 4:
        commit = int(tag_fields[4][1:], 16) # drop the 'g' prefix, it just means "git" (versus e.g. svn)
    else:
        commit = 0

    # magic
    meta += int(0x61_74_65_6d).to_bytes(4, 'little')
    # version
    meta += int(1).to_bytes(4, 'little')
    # git
    meta += int(extra).to_bytes(4, 'little')
    meta += int(rev).to_bytes(4, 'little')
    meta += int(min).to_bytes(4, 'little')
    meta += int(maj).to_bytes(4, 'little')
    meta += int(commit).to_bytes(4, 'little')

    assert(len(checksum) == 16)
    meta += checksum
    meta += source_checksum

    meta += bytestring_to_record(bytes(date, sys.getdefaultencoding()), 64)
    meta += bytestring_to_record(bytes(hostname, sys.getdefaultencoding()), 64)
    meta += bytestring_to_record(tags, 64)
    meta += bytestring_to_record(bytes(log.decode('utf8').replace('\t', ' '), sys.getdefaultencoding()), 512)
    meta += bytestring_to_record(bytes(status, sys.getdefaultencoding()), 1024)

    # pad to one page
    meta += bytes([0xff]) * (4096 - len(meta))

    print('Built: {} on {}'.format(date, hostname))
    print('Tags: {}'.format(tags))
    print('Parsed tags: {}.{}.{}-{}-{:x}'.format(maj, min, rev, extra, commit))
    print('Checksum: {}'.format(binascii.hexlify(checksum)))

    return meta


def main():
    parser = argparse.ArgumentParser(description="Pad and append CSV file to FPGA bitstream")
    parser.add_argument(
        "-b", "--bitstream", required=True, help="file containing FPGA bitstream", type=str
    )
    parser.add_argument(
        "-c", "--csv-file", required=True, help="file containing CSV input", type=str
    )
    parser.add_argument(
        "-o", "--output-file", required=True, help="destination file for binary data", type=str
    )
    parser.add_argument(
        "--key", required=False, help="signing key", type=str, nargs='?', metavar=('signing key'), const=DEVKEY_PATH
    )

    args = parser.parse_args()

    if args.key is None:
        key = DEVKEY_PATH
    else:
        key = args.key

    with open(key) as key_f:
        key_pem = key_f.read()
        try:
            pem = PEM.decode(key_pem, None)
        except:
            passphrase = input("Enter loader key passphrase: ")
            pem = PEM.decode(key_pem, passphrase)

        (key_pkey, pemtype, enc) = pem
        if pemtype != 'PRIVATE KEY':
            print("PEM type for loader was not a private key. Aborting.")
            exit(1)

    checksum = hashlib.md5(open(args.bitstream, 'rb').read()).digest()

    # NOTE NOTE NOTE
    # can't find a good ASN.1 ED25519 key decoder, just relying on the fact that the last 32 bytes are "always" the private key. always? the private key?
    signing_key = SigningKey(key_pkey[-32:], encoder=RawEncoder)
    signing_data = list()

    TOTAL_LEN     = 0x28_0000
    SIGNATURE_LOC = 0x27_F000
    CSR_CSV_LOC   = 0x27_7000
    METADATA_LOC  = 0x27_6000
    pad_to = 0x7FC0
    with open(args.bitstream, "rb") as bitstream:
        with open(args.csv_file, "rb") as ifile:
            with open(args.output_file, "wb") as ofile:
                # create the CSV appendix
                data = ifile.read() # read in the whole block of CSV data

                git_rev = subprocess.Popen(["git", "describe", "--long", "--always"],
                    stdout=subprocess.PIPE,
                    stderr=subprocess.PIPE)
                (rev, err) = git_rev.communicate()
                data += b"git_rev,"
                data += rev

                odata = bytearray()
                odata += len(data).to_bytes(4, 'little')
                odata += data

                padding = bytes([0xff]) * (pad_to - len(data) - 4)
                odata += padding

                hasher = hashlib.sha512()
                hasher.update(odata)
                digest = hasher.digest()
                odata += digest
                # odata now contains the csv appendix

                # assemble the final output file
                bits = bitstream.read() # read in all the bitstream
                position = 0
                # seek past the preamble junk that's ignored
                while position < len(bits):
                   sync = int.from_bytes(bits[position:position + 4], 'big')
                   if sync == 0xaa995566:
                      break
                   position = position + 1
                program_data = bits[position:]

                aes_padding = 8 # insert padding so that AES blocks line up on erase block boundaries
                # this may have to be adjusted if you change the bitstream header parameters
                written = 0
                written += ofile.write(bytes([0xff] * aes_padding))
                signing_data += bytes([0xff] * aes_padding)

                written += ofile.write(program_data)
                signing_data += program_data

                # insert metadata
                metadata_pad = bytes([0xff]) * (METADATA_LOC - written)
                written += ofile.write(metadata_pad)
                signing_data += metadata_pad
                metadata = compute_metadata(checksum)
                assert(written == METADATA_LOC)
                written += ofile.write(metadata)
                signing_data += metadata

                assert(written == CSR_CSV_LOC)
                # add the CSR data
                written += ofile.write(odata)
                signing_data += odata

                assert(written == SIGNATURE_LOC)

                signature = signing_key.sign(signing_data, encoder=RawEncoder)
                written += ofile.write((int(SIGNER_VERSION).to_bytes(4, 'little')))
                written += ofile.write(len(signing_data).to_bytes(4, 'little'))
                written += ofile.write(signature.signature)
                written += ofile.write(bytes([0xff]) * (TOTAL_LEN - written))
                assert(written == TOTAL_LEN)

if __name__ == "__main__":
    main()
