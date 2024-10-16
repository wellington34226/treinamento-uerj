import numpy as np
import cv2 as cv
# Create a black image
img = np.zeros((512,512,3), np.uint8)
# Draw a diagonal blue line with thickness of 5 px
cv.line(img,(0,0),(511,511),(255,0,0),5)

cv.circle(img,(447,63), 63, (0,0,255), -1)

for x in range(63, img.shape[0], 63):
    cv.circle(img,(x,189), 63, (0,255,0), 1)

#Para desenhar um polígono, primeiro precisa-se das coordenadas dos vértices.
#Transforme esses pontos em uma matriz de formato ROWSx1x2 onde ROWS é o número de vértices e deve ser do tipo int32.
#Aqui desenha-se um pequeno polígono com quatro vértices na cor amarela.

pts = np.array([[10,50],[20,80],[70,40],[90,10]], np.int32)
cv.polylines(img,[pts],True,(0,255,255))


font = cv.FONT_HERSHEY_SIMPLEX
cv.putText(img,'Formas',(10,500), font, 4,(255,255,255),2,cv.LINE_AA)

cv.imshow("Desenhando_Formas",img)
print (img.shape)

cv.waitKey(0)
cv.destroyAllWindows()
