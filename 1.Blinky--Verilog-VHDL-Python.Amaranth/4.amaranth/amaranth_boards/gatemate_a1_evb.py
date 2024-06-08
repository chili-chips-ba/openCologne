import os
import argparse
import subprocess
import shutil
import unittest

from amaranth.build import *
from amaranth.vendor import GateMatePlatform
from .resources import *

__all__ = [
    "GateMate_A1_EVB"
]

class _GateMate_A1_EVB(GateMatePlatform):
    package                = "CCGM1A1"
    default_clk            = "CLK0"

    resources = [
        Resource("CLK0", 0, Pins("IO_SB_A8", dir = "i"), Clock(12e6), Attrs(SCHMITT_TRIGGER="true")),

        *LEDResources(pins = "IO_SB_B6", attrs=Attrs())  
    ]

    connectors = []

class GateMate_A1_EVB(_GateMate_A1_EVB):
    device = "Olimex"
