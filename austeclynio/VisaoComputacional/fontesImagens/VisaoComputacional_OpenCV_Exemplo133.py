import cv2 

#image2 = cv2.imread('VisaoComputacional_Imagem_RottWeiler.jpg')
image2 = cv2.imread('Rosto_de_Menina_001.png')
#image2 = cv2.imread("James_Brown_001.png");

cv2.imshow('Original', image2)
cv2.waitKey(0)

gray = cv2.cvtColor(image2, cv2.COLOR_BGR2GRAY)
cv2.imshow('Cinza', gray)
cv2.waitKey(0)

blur = cv2.bilateralFilter(src=gray, d=9, sigmaColor=75, sigmaSpace=75)  # Aplicam-se os filtros
cv2.imshow('Filtrado', blur)
cv2.waitKey(0)

ret, thresh2 = cv2.threshold(blur, 100, 255, cv2.THRESH_BINARY) # Transforma para binária
cv2.imshow('Imagem Binaria', thresh2)
cv2.waitKey(0)

canny = cv2.Canny(thresh2, 70, 150)  # Detecta as bordas
cv2.imshow('Bordas Detectadas', canny)
cv2.waitKey(0)

contours5, hierarchy5 = cv2.findContours(thresh2, cv2.RETR_CCOMP, cv2.CHAIN_APPROX_NONE)
image_copy6 = image2.copy()
cv2.drawContours(image_copy6, contours5, -1, (0, 255, 0), 2, cv2.LINE_AA)
print("Numero of Contornos = " ,len(contours5)) 
# see the results
cv2.imshow('CCOMP', image_copy6)

cv2.waitKey(0)
print(len(contours5))
cv2.destroyAllWindows()
