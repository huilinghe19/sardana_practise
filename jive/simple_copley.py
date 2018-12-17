#!/usr/bin/python
import serial
import time

def handshake_copley(dev, command):
    result = ''
    # send command with LF (line feed)
    dev.write(command+"\n")
    while True:
        # read reply until LF
        data = dev.read(size=1)
        if data is None: # no data means errors or timeout
            break
        if data == "\n": # LF -> expected
            break
        if data == '\r': # CR -> ignored
            continue
        # store data
    	result += data
    return result

# open serial port with timeout
dev = serial.Serial("/dev/ttyS0", baudrate=9600, timeout=2)
print(handshake_copley(dev, "t 1"))
# set desired state: programmed position mode, stepper
# reply should be "ok"
print(handshake_copley(dev, "s r0x24 31"))

# set trajectory profile mode: relative move, s-surve
# reply should be "ok"
print(handshake_copley(dev, "s r0xC8 257"))

# clear latch drive event status
# reply should be "ok"
#print(handshake_copley(dev, "s r0xA1 268435455"))

# set distance to move
# reply should be "ok"
print(handshake_copley(dev, "s r0xCA -40000"))

# start the move
# reply should be "ok"
print(handshake_copley(dev, "t 1"))

# wait for end of move or error
#while True:
    #time.sleep(0.5)
    # request trajectory status register
    # reply should be "v <number>"
    #result = handshake_copley(dev, "g r0xA0")
    #print(result)
    #if result[0:2] != "v ":
        #print("unexpected reply from Copley controller")
        #break
    #if (int(result[2:]) & (1<<27)) == 0:
        #print("motion stopped")
        #break

print("move end or error; see line(s) before")

