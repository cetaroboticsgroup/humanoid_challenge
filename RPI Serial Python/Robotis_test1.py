
#! /usr/bin/env python

import serial

connected = True

ser = serial.Serial("/dev/ttyACM0", 9600)

while not connected:
    serin = ser.read()
    connected = True

ser.write("1")
ser.read()
ser.close()
