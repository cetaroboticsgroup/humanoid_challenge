#!/usr/bin/env python
# import the necessary packages
import numpy as np
import imutils
import cv2
import serial
import math

connected = True
camera = cv2.VideoCapture(1)

ser = serial.Serial()			   # create a serial port object
ser.baudrate = 9600			  # baud rate, in bits/second
ser.port = "/dev/ttyACM0"		   # this is whatever port your are using
ser.timeout = 3.0
ser.open()


# define the lower and upper boundaries of the "blue"
# ball in the HSV color space, then initialize the
# list of tracked points
blueLower = (75, 90, 90)
blueUpper = (130, 255, 255)

# keep looping
while True:
    # receive openCM feedback
    n = ser.inWaiting()
    str = ser.read(n)
    if str:
        print str

    # grab the current frame
    (grabbed, frame) = camera.read()

    # resize the frame, blur it, and convert it to the HSV
    # color space
    frame = imutils.resize(frame, width=600)
    lurred = cv2.GaussianBlur(frame, (11, 11), 0)
    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

    # construct a mask for the color "blue", then perform
    # a series of dilations and erosions to remove any small
    # blobs left in the mask
    mask = cv2.inRange(hsv, blueLower, blueUpper)
    mask = cv2.erode(mask, None, iterations=2)
    mask = cv2.dilate(mask, None, iterations=2)

    # find contours in the mask and initialize the current
    cnts = cv2.findContours(mask.copy(), cv2.RETR_EXTERNAL,
                            cv2.CHAIN_APPROX_SIMPLE)[-2]

    # only proceed if at least one contour was found
    if len(cnts) > 0:

        # find the largest contour in the mask
        c = max(cnts, key=cv2.contourArea)

        # ( center (x,y), (width, height), angle of rotation )
        rect = cv2.minAreaRect(c)
        rect = ((rect[0][0], rect[0][1]), (rect[1][0], rect[1][1]), rect[2])
        angle = rect[2]
        #print angle

        box = cv2.boxPoints(rect)
        box = np.int0(box)
        cv2.drawContours(frame, [box], 0, (255, 0, 0), 2)


        ## put text on handle and judge the handle open or not throught angle
        leftTop = box[0]
        if -85 < angle < -60:
            font = cv2.FONT_HERSHEY_SIMPLEX
            cv2.putText(frame, 'open handle', (leftTop[0], leftTop[1]), font, 1, (255, 0, 255), 4)
        else:
            font = cv2.FONT_HERSHEY_SIMPLEX
            cv2.putText(frame, 'cloesd handle', (leftTop[0],leftTop[1]), font, 1, (255, 0, 255),4)

        #tarcking handle

        xb = rect[0][0] / 600.0 * 255
        xb = abs(255-xb)

        # send ASCII values to openCM
        xb = int(round(xb))
        if len(cnts) == 0:
            ser.write(0)
        else:
            ser.write(chr(xb))
        # print xb

    #if no handled is detected
    if len(cnts) == 0:
        font = cv2.FONT_HERSHEY_SIMPLEX
        cv2.putText(frame, 'no handle found', (250, 300), font, 1, (255, 0, 255), 4)

    # show the frame to our screen
    cv2.imshow("Frame", frame)
    key = cv2.waitKey(1) & 0xFF

    # if the 'q' key is pressed, stop the loop
    if key == ord("q"):
        break

while not connected:
    serin = ser.read()
    connected = True

# cleanup the camera and close any open windows
camera.release()
cv2.destroyAllWindows()
ser.close()
