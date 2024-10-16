import cv2 
import numpy as np 
  
image = cv2.imread('Varios_Dados_001.jpg')
#image = cv2.imread('Varios_MCUS_001.jpg')

assert image is not None, "file could not be read, check with os.path.exists()"
cv2.imshow('Original', image)
cv2.waitKey(0)

gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY) 
cv2.imshow('Gray', gray)
cv2.waitKey(0)

#blur = cv2.GaussianBlur(gray, (11, 11), 0)
blur = cv2.bilateralFilter(src=gray, d=9, sigmaColor=75, sigmaSpace=75) # Aplicam-se os filtros
cv2.imshow('Filtrado', blur)
cv2.waitKey(0)

ret,thresh2 = cv2.threshold(blur, 100, 255, cv2.THRESH_BINARY) # Transforma para binária
cv2.imshow('Imagem binaria', thresh2)
cv2.waitKey(0)

#canny = cv2.Canny(blur, 30, 150, 3)
canny = cv2.Canny(thresh2, 70, 150)# Detecta as bordas
cv2.imshow('Bordas Detectadas', canny)
cv2.waitKey(0)


kernel = np.ones((7, 7), np.uint8)
dilated = cv2.dilate(canny, kernel, iterations=2) # Dilata as bordas
cv2.imshow('Bordas dilatadas', dilated)
cv2.waitKey(0)
  

(cnt, hierarchy) = cv2.findContours(dilated.copy(), cv2.RETR_EXTERNAL,  cv2.CHAIN_APPROX_SIMPLE)

cv2.drawContours(image, cnt, -1, (0, 255, 0), 2) 
  
  
print("Objetos na imagem : ", len(cnt)) 
cv2.imshow('rgb', image)
cv2.waitKey(0)

cv2.destroyAllWindows()
