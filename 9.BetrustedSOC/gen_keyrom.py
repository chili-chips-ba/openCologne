#! /usr/bin/env python3
import argparse
import sys
from Crypto.IO import PEM
from cryptography import x509
from cryptography.hazmat.primitives.serialization import Encoding
from cryptography.hazmat.primitives.serialization import PublicFormat

import binascii

"""
Reverse the order of bits in a word that is bitwidth bits wide
"""
def bitflip(data_block, bitwidth=32):
    if bitwidth == 0:
        return data_block

    bytewidth = bitwidth // 8
    bitswapped = bytearray()

    i = 0
    while i < len(data_block):
        data = int.from_bytes(data_block[i:i+bytewidth], byteorder='big', signed=False)
        b = '{:0{width}b}'.format(data, width=bitwidth)
        bitswapped.extend(int(b[::-1], 2).to_bytes(bytewidth, byteorder='big'))
        i = i + bytewidth

    return bytes(bitswapped)

def main():
    global DEVKEY_PATH

    parser = argparse.ArgumentParser(description="Sign binary images for Precursor")
    parser.add_argument(
        "--dev-pubkey", required=False, help="developer public key (X.509 ED25519)", type=str, nargs='?', metavar=('developer key'), const='./devkey/dev-x509.crt'
    )
    parser.add_argument(
        "--output", required=False, help="output name, defaults to keystore.bin", type=str, nargs='?', metavar=('output file'), const='keystore.bin'
    )
    parser.add_argument(
        "--efuse-key", help="populates the FPGA AES key with a locally generated .nky file", type=str, nargs='?', metavar=('.nky file'), const='blank.nky'
    )
    args = parser.parse_args()
    if not len(sys.argv) > 1:
        print("No arguments specified, doing nothing. Use --help for more information.")
        exit(1)

    if args.output is None:
        output_file = 'keystore.bin'
    else:
        output_file = args.output

    if args.dev_pubkey is None:
        dev_pubkey = './devkey/dev-x509.crt'
    else:
        dev_pubkey = args.dev_pubkey

    if args.efuse_key:
        with open(args.efuse_key, "r") as nky:
            for lines in nky:
                line = lines.split(' ')
                if line[1] == '0':
                    nky_key = line[2].rstrip().rstrip(';')
        efuse_key = int(nky_key, 16).to_bytes(32, byteorder='big')
    else:
        efuse_key = bytes([0] * 32)

    with open(dev_pubkey, "rb") as dev_pubkey_f:
        cert_file = dev_pubkey_f.read()
        #print(cert_file)
        cert = x509.load_pem_x509_certificate(cert_file)
        pubkey = cert.public_key().public_bytes(Encoding.Raw, PublicFormat.Raw)
        print("using public key: ", binascii.hexlify(pubkey))

        with open(output_file, "wb") as ofile:
            written = 0
            written += ofile.write(efuse_key)
            written += ofile.write(bytes([0] * 0x10 * 4)) # pad to the public key
            written += ofile.write(pubkey)
            written += ofile.write(bytes([0] * ( (0xff * 4) - written)))
            written += ofile.write(bytes(int(0x0001).to_bytes(4, 'little'))) # version 00.01 plus all other fuses blank
            print("wrote {} bytes to {}".format(written, output_file))

if __name__ == "__main__":
    main()
    exit(0)
