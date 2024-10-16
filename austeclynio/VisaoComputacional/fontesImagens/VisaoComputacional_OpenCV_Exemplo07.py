import cv2
import numpy as np
 
img = cv2.imread('ROI_Conjunto_Bebidas.png',cv2.IMREAD_COLOR) 

image = cv2.resize(img, (1280, 720))
 
pt1 = (400, 40)
pt2 = (800, 300)
color = (0, 255, 255)
thickness = 1
lineType = cv2.LINE_4

 
img_rect = cv2.rectangle(image, pt1, pt2, color, thickness, lineType) 
cv2.imshow("Conjunto_Bebidas", img_rect) 
cv2.waitKey(2000)

thickness = -1
img_rect = cv2.rectangle(image, pt1, pt2, color, thickness, lineType)
cv2.imshow("Conjunto_Bebidas", img_rect)
cv2.waitKey(3000)

text = "Minhas Bebidas!!!"
onde = (450, 170)
fontFace = cv2.FONT_HERSHEY_SIMPLEX
fontScale = 1
color = (0,0,255) 
img_text = cv2.putText(img_rect, text, onde, fontFace, fontScale, color, lineType) 
cv2.imshow("Conjunto_Bebidas",img_text)
cv2.waitKey(0)
cv2.destroyAllWindows()
