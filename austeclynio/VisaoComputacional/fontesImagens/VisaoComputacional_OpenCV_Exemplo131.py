import cv2 

image2 = cv2.imread('Varios_Dados_001.jpg')
assert image2 is not None, "file could not be read, check with os.path.exists()"
cv2.imshow('Original', image2)
cv2.waitKey(0)

img_gray2 = cv2.cvtColor(image2, cv2.COLOR_BGR2GRAY)
cv2.imshow('Cinza', img_gray2)
cv2.waitKey(0)

suave = cv2.blur(img_gray2, (7, 7))  # Aplicam-se os filtros
cv2.imshow('Filtrado', suave)
cv2.waitKey(0)

ret, thresh2 = cv2.threshold(suave, 100, 255, cv2.THRESH_BINARY) # Transforma para binária
cv2.imshow('Imagem Binaria', thresh2)
cv2.waitKey(0)

contours3, hierarchy3 = cv2.findContours(thresh2, cv2.RETR_LIST, cv2.CHAIN_APPROX_NONE)

image_copy4 = image2.copy()
cv2.drawContours(image_copy4, contours3, -1, (0, 255, 0), 2, cv2.LINE_AA)
print("Numero of Contornos = " ,len(contours3))
cv2.imshow('Contours', image_copy4)


cv2.waitKey(0)

cv2.destroyAllWindows()
