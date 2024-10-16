import numpy as np
import cv2 as cv

image = cv.imread('VisaoComputacional_Imagem_Refeicao_Chile.jpg',1)
assert image is not None, "Arquivo não encontrado!"
y,x,c = image.shape
print(image.shape)
cv.line(image,(0,0),(x-1,y-1),(255,0,0),4)
cv.line(image,(x-1,0),(0,y-1),(255,0,0),4)
a=int(x/2)
b=int(y/2)
cv.line(image,(a,0),(a,y-1),(255,0,0),4)

font = cv.FONT_HERSHEY_SIMPLEX
cv.putText(image,'Boa comida!',(50,b), font,2,(255,255,255),2,cv.LINE_AA)
cv.imshow('OpenCV - Color',image)


#cv.imwrite("VisaoComputacional_Imagem_Refeicao_Chile_Copia.png", image)
cv.waitKey(0)
cv.destroyAllWindows()
