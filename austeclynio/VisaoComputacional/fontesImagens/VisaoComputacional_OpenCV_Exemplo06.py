import numpy as np
import cv2
image = cv2.imread('VisaoComputacional_Imagem_Refeicao_Chile.jpg')
(canalAzul, canalVerde, canalVermelho) = cv2.split(image)

zeros = np.zeros(image.shape[:2], dtype = "uint8")

cv2.imshow("Vermelho", cv2.merge([zeros, zeros,canalVermelho]))
cv2.waitKey(5000)
cv2.imshow("Verde", cv2.merge([zeros, canalVerde, zeros]))
cv2.waitKey(5000)
cv2.imshow("Azul", cv2.merge([canalAzul, zeros, zeros]))
cv2.waitKey(5000)
cv2.imshow("Original", cv2.merge([canalAzul, canalVerde, canalVermelho]))
cv2.waitKey(0)
cv2.destroyAllWindows()


