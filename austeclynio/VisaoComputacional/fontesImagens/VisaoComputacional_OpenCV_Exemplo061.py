import numpy as np
import cv2

imageClone1 = cv2.imread('VisaoComputacional_Imagem_Refeicao_Chile.jpg')
imageClone1[:,:,0] = 0
imageClone1[:,:,1] = 0
cv2.imshow("Vermelho", imageClone1)
cv2.waitKey(5000)
imageClone2 = cv2.imread('VisaoComputacional_Imagem_Refeicao_Chile.jpg')
imageClone2[:,:,0] = 0
imageClone2[:,:,2] = 0
cv2.imshow("Verde", imageClone2)
cv2.waitKey(5000)
imageClone3 = cv2.imread('VisaoComputacional_Imagem_Refeicao_Chile.jpg')
imageClone3[:,:,1] = 0
imageClone3[:,:,2] = 0
cv2.imshow("Azul", imageClone3)
cv2.waitKey(5000)
image_merged = cv2.merge((imageClone3[:,:,0],imageClone2[:,:,1],imageClone1[:,:,2]))
cv2.imshow('merged image',image_merged) 
cv2.waitKey(0)
cv2.destroyAllWindows()


