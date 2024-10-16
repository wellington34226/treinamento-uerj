import cv2 

image = cv2.imread('VisaoComputacional_Imagem_Refeicao_Chile.jpg',1)

#split the image into its three channels
(b_channel, g_channel, r_channel) = cv2.split(image)

#display the images
cv2.imshow('blue channel',b_channel)
cv2.waitKey(5000)
cv2.imshow('green channel',g_channel)
cv2.waitKey(5000)
cv2.imshow('red channel',r_channel) 
cv2.waitKey(5000)
image_merged = cv2.merge((b_channel,g_channel,r_channel))
cv2.imshow('merged image',image_merged) 
cv2.waitKey(0)
cv2.destroyAllWindows()
