import serial
import time
import threading

def send_data(ser):
    while True:
        ser.write(b'T')  # Send the character 'T'
        time.sleep(0.01)  # Wait for 10 milliseconds

def read_data(ser):
    while True:
        if ser.in_waiting > 0:  # Check if any data is available to read
            data = ser.read(1)  # Read one byte at a time
            if data:
                print(data.decode('ascii', errors='replace'), end='', flush=True)
        else:
            time.sleep(0.01)  # Sleep a short time to prevent high CPU usage



def main():
    port = '/dev/ttyACM0'  # Serial port to use (change as needed)
    baud_rate = 115200     # Baud rate

    # Try to setup the serial connection
    try:
        ser = serial.Serial(port, baud_rate, timeout=0)
       # ser.set_buffer_size(rx_size = 128, tx_size = 128)  # Smaller buffer sizes
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

