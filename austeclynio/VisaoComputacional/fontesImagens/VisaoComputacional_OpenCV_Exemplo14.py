import cv2 as cv
import numpy as np

kernel = np.ones((5,5),np.uint8)

img = cv.imread('Imagem_Linux_001.jpg',0)

erosion = cv.erode(img,kernel,iterations = 1)
dilation = cv.dilate(img,kernel,iterations = 1)

cv.imshow('Original', img)
cv.waitKey(0)
cv.imshow('Erosion', erosion)
cv.waitKey(0)
cv.imshow('Dilation', dilation)
cv.waitKey(0)

img = cv.imread('Varios_Dados_001.jpg',1)

erosion = cv.erode(img,kernel,iterations = 1)
dilation = cv.dilate(img,kernel,iterations = 1)

cv.imshow('Original', img)
cv.waitKey(0)
cv.imshow('Erosion', erosion)
cv.waitKey(0)
cv.imshow('Dilation', dilation)
cv.waitKey(0)

cv.destroyAllWindows()
