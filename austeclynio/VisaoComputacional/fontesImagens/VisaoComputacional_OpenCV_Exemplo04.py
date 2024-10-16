import cv2
import numpy as np
img = cv2.imread('ROI_Conjunto_Bebidas.png',cv2.IMREAD_COLOR)
print(img.shape)
ROI = img[180:230,160:190]
cv2.imshow('ROI',ROI)
cv2.waitKey(5000)

img[180:230,160:190] = 255
cv2.imshow('ROI',img)
cv2.waitKey(0)
cv2.destroyAllWindows()
