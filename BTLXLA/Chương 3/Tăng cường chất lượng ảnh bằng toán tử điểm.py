import cv2
import numpy
from copy import deepcopy
import cv2 as cv

def getGrayColor(rgb):
    return rgb[0]

def setGrayColor(color):
    return [color, color, color]

img = cv.imread('cs.jpg')
img = numpy.asarray(img)

ct = deepcopy(img)

r1 = 80
s1 = 20
r2 = 160
s2 = 240

for i in range(len(img)):
    for j in range(len(img[i])):
        x = getGrayColor(img[i][j])
        if(0 <= x and x < r1):
            ct[i][j] = setGrayColor(s1/r1 * x)
        elif(r1 <= x and x < r2):
            ct[i][j] = setGrayColor(((s2 - s1)/(r2 - r1)) * (x - r1) + s1)
        elif(r2 <= x and x <= 255):
            ct[i][j] = setGrayColor(((255 - s2)/(255 - r2)) * (x - r2) + s2)
img1=cv2.resize(img,(252,252))
cv2.imshow('input',img1)
img2=cv2.resize(ct,(252,252))
cv2.imshow('output',img2)
cv2.waitKey(0)