
# Python script to: -  connect the UART
#                   -  randomize the input PSRAM command data 
#                   -  read out the result and compare
import serial
import time
import threading
import random 

addr = bytearray([4,3,2])
wdat = bytearray([7,8])

addr = []
wdat = []
ready_to_read = 1 # sort of a mutex, cant read until the command is sent

def randomize_data():
    global addr, wdat
    # Randomize addr with a fixed length of 3 bytes
    addr = [random.randint(0, 255) for _ in range(3)]
    # Randomize wdat with a fixed length of 2 bytes
    wdat = [random.randint(0, 255) for _ in range(2)]

def send_data(ser):
    global addr, wdat, ready_to_read
    while True:
        randomize_data()
        to_write = bytearray([1]) + bytearray(addr) + bytearray(wdat)
        to_read =  bytearray([0]) + bytearray(addr)


        ready_to_read = 0
        ser.write(to_write)  # Send bytes directly
        #print(f"Sent write command:, {to_write}")  # Optional: for debugging        
        time.sleep(0.01)  # Wait for 1 millisecond

        ser.write(to_read)  # Send bytes directly
        #print(f"Sent read command:{to_read}\n\n")
        time.sleep(0.01)

        ready_to_read = 1
        #print("Sent read command:", to_read)  # Optional: for debugging
        time.sleep(0.01)  # Wait for 10 milliseconds

def read_data(ser):
    global addr, wdat, ready_to_read

    while True:
        if ser.in_waiting == 2 and ready_to_read:  # Check if any data is available to read
            data = ser.read(2)  # Read one byte at a time
            if data:
                # Convert the byte to an integer and print it
                data_hex = hex(int.from_bytes(data, byteorder='little'))
                wdat_hex = hex(wdat[1] | (wdat[0]<<8))
                addr_int = (addr[0]<<16) | (addr[1]<<8) | addr[2]
                addr_hex = hex(addr_int)
                print(f"Address: {addr_hex: <10}  Wrote: {wdat_hex: <10}   Read: {data_hex: <10}")
                if(wdat_hex != data_hex):
                    print(' ERROR')
        elif ser.in_waiting > 2:
            data = ser.read(ser.in_waiting)
        else:
            time.sleep(0.0001)

def main():
    port = '/dev/ttyACM0'  # Serial port to use (change as needed)
    baud_rate = 115200     # Baud rate

    # Try to setup the serial connection
    try:
        ser = serial.Serial(port, baud_rate, timeout=0)
        #ser.set_buffer_size(rx_size = 128, tx_size = 128)  # Smaller buffer sizes
        print(f"Successfully connected to {port}")
    except serial.SerialException as e:
        print(f"Failed to connect to {port}: {e}")
        return

    # Start sending and reading threads
    sender_thread = threading.Thread(target=send_data, args=(ser,))
    receiver_thread = threading.Thread(target=read_data, args=(ser,))
    
    sender_thread.daemon = True
    receiver_thread.daemon = True

    sender_thread.start()
    receiver_thread.start()

    # Keep the main program running indefinitely
    try:
        while True:
            time.sleep(1)  # Sleep in main thread to prevent CPU overuse
    except KeyboardInterrupt:
        print("Program interrupted by the user.")
        ser.close()  # Ensure the serial port is closed on exit

if __name__ == "__main__":
    main()
'''
------------------------------------------------------------------------------
Version History:
------------------------------------------------------------------------------
 2024/6/7 Tarik Ibrahimovic: Initial Creation
'''
