import cv2
import numpy as np

image = cv2.imread('Varios_Ovos_001.jpg')
cv2.imshow('Original', image)
cv2.waitKey(0)
kernel = np.ones((5,5),np.uint8)
img = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
cv2.imshow('Cinza', img)
cv2.waitKey(0)

#img = cv2.erode(img,kernel,iterations = 1)
#cv2.imshow('Erosao', img)
#cv2.waitKey(0)

img = cv2.Canny(img, 30, 200)
cv2.imshow('Canny', img)
cv2.waitKey(0)

contours, hierarchy = cv2.findContours(img,cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_NONE)
print("Numero of Contornos = " ,len(contours))

cv2.drawContours(image, contours, -1, (0, 255, 0), 1)
cv2.imshow('Contours', image)
cv2.waitKey(0)
cv2.destroyAllWindows()
