import cv2 
 
img = cv2.imread('VisaoComputacional_Imagem_Refeicao_Chile.jpg')
 
img1 = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY )
img2 = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)
# Displaying the image 
cv2.imshow('original', img)
cv2.waitKey(0)
cv2.imshow('Gray', img1)
cv2.waitKey(0)
cv2.imshow('HSV', img2)
cv2.waitKey(0)
cv2.destroyAllWindows()
