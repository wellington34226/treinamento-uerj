import cv2
import numpy as np
 
# Read the image using imread function
image = cv2.imread('VisaoComputacional_Imagem_RottWeiler.jpg')
cv2.imshow('Original Image', image)
cv2.waitKey()
print (image.shape)
 
# let's downscale the image using new  width and height
down_width = 300
down_height = 100
down_points = (down_width, down_height)
resized_down = cv2.resize(image, down_points, interpolation= cv2.INTER_LINEAR)
 
# let's upscale the image using new  width and height
up_width = 900
up_height = 650
up_points = (up_width, up_height)
resized_up = cv2.resize(image, up_points, interpolation= cv2.INTER_LINEAR)
 
# Display images
cv2.imshow('Resized Down by defining height and width', resized_down)
cv2.waitKey()
cv2.imshow('Resized Up image by defining height and width', resized_up)
cv2.waitKey()
 
#press any key to close the windows
cv2.destroyAllWindows()
