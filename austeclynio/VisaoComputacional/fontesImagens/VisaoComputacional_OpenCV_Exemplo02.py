import numpy as np
import cv2
# Load a color image
img = cv2.imread('BGR_Azul_Verde_Vermelho.png',1)

print(img.shape)

# General Pixel Value (BGR)
print(img[100,70])   # img[y,x]
print(img[100,210])
print(img[100,140])

# By Matrix
print(img[100,70,0])  # img[y,x,#]
print(img[100,70,1])
print(img[100,70,2])


# By Matrix
print(img[140,140,0])
print(img[140,140,1])
print(img[140,140,2])

# By Matrix
print(img[50,210,0])
print(img[50,210,1])
print(img[50,210,2])

cv2.imshow('OpenCV - Color',img)
cv2.waitKey(5000)

# Modify Pixel Color
for i in range(100):  # y
    for j in range(100): # x
        img[i,j]=[0,0,0]   # altera para cor preta

        
cv2.imshow('OpenCV - Color _ Modified',img)
cv2.waitKey(0)
cv2.destroyAllWindows()
