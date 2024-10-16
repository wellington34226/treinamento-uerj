import numpy as np
import cv2 as cv
from matplotlib import pyplot as plt
img = cv.imread('VisaoComputacional_Imagem_RottWeiler.jpg')

cv.imshow('Histograma 1', img)
cv.waitKey(0)

color = ('b','g','r')
for i,col in enumerate(color):
    hist = cv.calcHist([img],[i],None,[256],[0,256])
    plt.plot(hist, color = col)
    plt.xlim([0,256])
plt.show()
cv.waitKey(0)
img = cv.imread('VisaoComputacional_Imagem_Refeicao_Chile.jpg')
cv.imshow('Histograma 2', img)
cv.waitKey(0)

for i,col in enumerate(color):
    hist = cv.calcHist([img],[i],None,[256],[0,256])
    plt.plot(hist, color = col)
    plt.xlim([0,256])
plt.show()
cv.waitKey()
cv.destroyAllWindows()
