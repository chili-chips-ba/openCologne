# openCologne
## * WORK IN PROGRESS * UNDER CONSTRUCTION *
> WHILE THIS NOTICE IS PRESENT, DON'T EXPECT DESIGN, SIM, OR ANY OTHER FILE IN HERE 2BE DOIN' WHAT IT'S SAYIN'

**To do list**:
- [ ] Fix UART issues (tx of multiple bytes is incorrect)
- [ ] Run integration tests on PSRAM + UART + PySerial

To get the design running:
```
cd 3.build
make hw_all
```

Then to start the serial communication, automatically write and read random bytes on random locations it's:
```
cd 4.testing
python3 pyauto.py
```

#### End of Document
