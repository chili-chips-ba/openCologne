[Back to **README**](README.md)

# Contributing to openCologne

## Found something?

Open an [Issue](https://github.com/chili-chips-ba/openCologne/issues). For bugs, include how to reproduce it: a simulation, a waveform, or logs.

## Want to change something?

1. Bigger change? Open an Issue first, so we agree on the approach
2. Fork, branch off `main`, make the change
3. QA process (being set up on [7.SerDes](7.SerDes), our reference example):
   - **run-lint** shows no errors. Fix lint findings at the root. Waive only as the last resort, with a reason.
   - **run-format --check** passes.
   - The example's **simulation** passes,
   - and its **open-source GateMate build** (Yosys, nextpnr-himbaechel, Project Peppercorn) completes.
   - For a mere cleanup: **run-leq** proves there are no functional changes.
4. Open a Pull Request against `main`.

Observe our RTL coding rules, as in [openPCIE](https://github.com/chili-chips-ba/openPCIE/blob/main/2.rtl/README.md#rtl-coding-rules). The older examples predate them.

## License

BSD-3-Clause ([LICENSE](LICENSE)). Your contribution takes the license of the files it goes into. New files need an SPDX header.

## GenAI

Allowed, if:

- you understand and take responsibility for every line,
- no third-party copyrighted content gets in,
- you say in the Pull Request which tool and model you used, and for what.

Purely AI-generated work is not accepted. This follows [NLnet's GenAI policy](https://nlnet.nl/foundation/policies/generativeAI/), our funder.

-----------
#### End-of-Document
