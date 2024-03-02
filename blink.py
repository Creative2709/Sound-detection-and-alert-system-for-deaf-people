import serial.tools.list_ports

ports = serial.tools.list_ports.comports()
serialInst = serial.Serial()
portList = []

print(ports)

for each in ports :
    portList.append(str(each))
    print(str(each))

print(portList)
# print("Available COM Ports:")
# for port, desc, hwid in sorted(ports):
#     print("{}: {}".format(port, desc))
#     portList.append(port)

# print("")


com = input("Select COM Port for Arduino :-  ")

for i in range(len(portList)):
    if portList[i].startswith("COM" + str(com)):
        use = "COM" + str(com)
        print(use)

serialInst.baudrate = 9600
serialInst.port = use
serialInst.open()

while True:
    command = input("Arduino command ON/OFF/exit : ")
    serialInst.write(command.encode('utf-8'))

    if command == 'exit' :
        exit()


