import cv2
 
# Reading the image
image = cv2.imread('VisaoComputacional_Imagem_RottWeiler.jpg')
cv2.imshow('Original Image', image)
print (image.shape)
cv2.waitKey()

 
# dividing height and width by 2 to get the center of the image
height, width = image.shape[:2]
print(image.shape[:2])
# get the center coordinates of the image to create the 2D rotation matrix
center = (width/2, height/2)
 
# using cv2.getRotationMatrix2D() to get the rotation matrix
rotate_matrix = cv2.getRotationMatrix2D(center=center, angle=45, scale=1)
 
# rotate the image using cv2.warpAffine
rotated_image = cv2.warpAffine(src=image, M=rotate_matrix, dsize=(width, height))
 
cv2.imshow('Original image', image)
cv2.imshow('Rotated image', rotated_image)
# wait indefinitely, press any key on keyboard to exit
cv2.waitKey()

#press any key to close the windows
cv2.destroyAllWindows()
