import numpy as np
import cv2 as cv

 
img = cv.imread('VisaoComputacional_Imagem_RottWeiler.jpg')


img_blur = cv.GaussianBlur(img,(3,3),0) 
edges = cv.Canny(img_blur,100,200)

cv.imshow('Original image', img)
cv.waitKey()
cv.imshow('Canny image', edges)

cv.waitKey()

cv.destroyAllWindows()
