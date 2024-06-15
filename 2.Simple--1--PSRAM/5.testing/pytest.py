import tkinter as tk
from tkinter import scrolledtext
import serial
import threading

class SerialApp:
    def __init__(self, master):
        self.master = master
        self.master.title("Serial Communication")

        # Setup the serial port
        self.ser = serial.Serial('/dev/ttyACM0', 115200)

        # Create widgets
        self.text_area = scrolledtext.ScrolledText(master, width=40, height=10)
        self.text_area.grid(column=0, row=0, padx=10, pady=10)
        self.entry = tk.Entry(master, width=33)
        self.entry.grid(column=0, row=1, padx=10)
        self.send_button = tk.Button(master, text="Send", command=self.send_data)
        self.send_button.grid(column=1, row=1)

        # Start the thread for listening to incoming serial data
        self.thread = threading.Thread(target=self.receive_data)
        self.thread.daemon = True
        self.thread.start()

    def send_data(self):
        data = self.entry.get()
        if data:
            try:
                # Encode data to ASCII and send
                ascii_data = data.encode('ascii')
                self.ser.write(ascii_data)
                self.entry.delete(0, tk.END)
            except UnicodeEncodeError:
                # Handle the case where data cannot be converted to ASCII
                self.display_data("Error: Non-ASCII characters cannot be sent.\n")


    def receive_data(self):
        while True:
            if self.ser.in_waiting > 0:
                data = self.ser.read_all().decode('ascii', errors='replace')  # Changed to ASCII
                self.display_data(data)


    def display_data(self, data):
        self.text_area.configure(state='normal')
        self.text_area.insert(tk.END, data)
        self.text_area.configure(state='disabled')
        self.text_area.yview(tk.END)

def main():
    root = tk.Tk()
    app = SerialApp(root)
    root.mainloop()

if __name__ == "__main__":
    main()
