import cv2
import numpy as np

img = cv2.imread('Varios_Madeira_001.jpg')

cv2.imshow('Original', img)
cv2.waitKey(0)

kernel2 = np.ones((5, 5), np.float32) / 25
img2D = cv2.filter2D(src=img, ddepth=-1, kernel=kernel2)
cv2.imshow('filter2D', img2D)
cv2.waitKey(0)


img_blur = cv2.blur(src=img, ksize=(5,5)) 
cv2.imshow('Blurred', img_blur) 
cv2.waitKey(0)

gaussian_blur = cv2.GaussianBlur(src=img,ksize=(5,5),sigmaX=0, sigmaY=0)
 

cv2.imshow('Gaussian Blurred', gaussian_blur)     
cv2.waitKey(0)

median = cv2.medianBlur(src=img, ksize=5)
cv2.imshow('Median Blurred', median)     
cv2.waitKey(0)

bilateral_filter = cv2.bilateralFilter(src=img, d=9, sigmaColor=75, sigmaSpace=75)
cv2.imshow('Bilateral Filtering', bilateral_filter) 
cv2.waitKey(0)

cv2.destroyAllWindows()
