from _mycv import ffi, lib
import numpy
from PIL import Image
import sys
import cv2
"""
image = numpy.array(Image.open(sys.argv[1]))
image = cv2.imread(sys.argv[1])
"""


"""
img = numpy.array(Image.open(sys.argv[1]))
new_image = 1* image +2 
print len(new_image)
"""
img = cv2.imread(sys.argv[1])
print img.shape

h = img.shape[0]
w = img.shape[1]
ch = img.shape[2]

image = lib.cvCreateMat(h,w, lib.CV_8UC3)
print type(image.data)
print type(image.data.ptr)
print image.data.ptr[0]
idx = 0
for y in range(h):
    for x in range(w):
        image.data.ptr[idx] = 120  #blue
        image.data.ptr[idx+1] = 120 #green
        image.data.ptr[idx+2] = idx%255 #red
        idx += 3

ffi.memmove(image.data.ptr, img, w*h*ch)
#ffi.memmove(img, image.data.ptr,  w*h*ch)

print image.rows
#print ffi.cast("uchar *", image.data.ptr)
print type(image)
lib.cvShowImage('xx', image)
keycode = lib.cvWaitKey(0)
