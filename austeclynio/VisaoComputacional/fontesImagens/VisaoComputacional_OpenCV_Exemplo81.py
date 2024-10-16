import cv2
import numpy as np 

image = cv2.imread('VisaoComputacional_Imagem_RottWeiler.jpg')
cv2.imshow('Original Image', image)
print (image.shape)
cv2.waitKey()

# Reduz a imagem 0.5 vez
scale_down = 0.5
scaled_f_down = cv2.resize(image, None, fx= scale_down, fy= scale_down, interpolation= cv2.INTER_LINEAR)
 
# Aumenta a imagem 1.5 vezes
scale_up_x = 1.5
scale_up_y = 1.5
scaled_f_up = cv2.resize(image, None, fx= scale_up_x, fy= scale_up_y, interpolation= cv2.INTER_LINEAR)
 
# Apresenta imagens
cv2.imshow('Resized Down by defining height and width', scaled_f_down)
cv2.waitKey()

#Tecle enter para ver
cv2.imshow('Resized Up image by defining height and width', scaled_f_up)
cv2.waitKey()
 
#press any key to close the windows
cv2.destroyAllWindows()
