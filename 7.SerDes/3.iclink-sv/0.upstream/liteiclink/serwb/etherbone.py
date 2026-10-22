#
# This file is part of LiteICLink.
#
# Copyright (c) 2017-2024 Florent Kermarrec <florent@enjoy-digital.fr>
# SPDX-License-Identifier: BSD-2-Clause

"""
Etherbone

CERN's Etherbone protocol is initially used to run a Wishbone bus over an
ethernet network. This re-implementation is meant to be run over serdes
and introduces some limitations:
- no probing (pf/pr)
- no address spaces (rca/bca/wca/wff)
- 32bits data and address
- 1 record per frame
"""

from litex.gen import *

from litex.soc.interconnect import stream

from liteeth.common             import *
from liteeth.frontend.etherbone import *

# Etherbone Packet ---------------------------------------------------------------------------------

class _EtherbonePacket(LiteXModule):
    def __init__(self, port_sink, port_source):
        self.tx = tx = LiteEthEtherbonePacketTX(udp_port=0)
        self.rx = rx = LiteEthEtherbonePacketRX()
        self.comb += [
            tx.source.connect(port_sink),
            port_source.connect(rx.sink, omit={"be"}),
            # SERWB only transports full 32-bit words: mark all bytes valid (LiteEth Etherbone
            # discards records with partial byte enables).
            rx.sink.be.eq(2**len(rx.sink.be) - 1),
        ]
        self.sink, self.source = self.tx.sink, self.rx.source

# Etherbone ----------------------------------------------------------------------------------------

class Etherbone(LiteXModule):
    def __init__(self, mode="master", buffer_depth=4):
        self.sink   = sink   = stream.Endpoint(eth_udp_user_description(32))
        self.source = source = stream.Endpoint(eth_udp_user_description(32))

        # # #

        # Encode/encode etherbone packets.
        self.packet = packet = _EtherbonePacket(source, sink)

        # Packets are records with writes and reads (no byte swapping: SerWB is little-endian on
        # both sides of the link).
        self.record = record = LiteEthEtherboneRecord(endianness="little", buffer_depth=buffer_depth)

        # Create MMAP wishbone.
        self.wishbone = {
            "master": LiteEthEtherboneWishboneMaster(),
            "slave":  LiteEthEtherboneWishboneSlave(),
        }[mode]
        self.comb += [
            packet.source.connect(record.sink),
            record.source.connect(packet.sink),
            record.receiver.source.connect(self.wishbone.sink),
            self.wishbone.source.connect(record.sender.sink),
        ]
