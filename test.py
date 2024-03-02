import serial.tools.list_ports
import serial

# List available COM ports
ports = serial.tools.list_ports.comports()

# Print available ports
print("Available COM Ports:")
for port, desc, hwid in sorted(ports):
    print("{}: {}".format(port, desc))

# Ask user to select a COM port
com = input("Select COM Port for Arduino (e.g., COM1, COM2, etc.): ")

# Validate and set the selected COM port
use = None
for port, _, _ in ports:
    if port == com:
        use = com
        break

if use is None:
    print("Error: Selected COM port is not available.")
    exit()

# Configure serial communication with Arduino
serialInst = serial.Serial(use, 9600)

# Main loop for sending commands to Arduino
while True:
    command = input("Arduino command (ON/OFF/exit): ").strip().lower()

    # Send command to Arduino
    serialInst.write(command.encode('utf-8'))

    # Check if the user wants to exit
    if command == 'exit':
        break

# Close the serial connection
serialInst.close()
