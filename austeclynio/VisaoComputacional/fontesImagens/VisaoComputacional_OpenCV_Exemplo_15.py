import cv2
import numpy as np
img = cv2.imread('Grupo_Caxias_001.jpg',1)
#img = cv2.imread('Onde_Esta_Wally_001.jpg',1)
#img = cv2.imread('Carta_Baralho_001.jpg',1)
cv2.imshow('Original',img)
cv2.waitKey(0)
gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
cv2.imshow('Gray',gray)
cv2.waitKey(0)

template = cv2.imread('Template_Caxias_001.jpg',1)
#template = cv2.imread('Wally.jpg',1)
#template = cv2.imread('Carta_Baralho_Template_001.jpg',1)
cv2.imshow('Template',template)
cv2.waitKey(0)
template = cv2.cvtColor(template, cv2.COLOR_BGR2GRAY)
cv2.imshow('Gray Template',template)
cv2.waitKey(0)

h,w = template.shape[0], template.shape[1]
print(h)
print(w)
matched = cv2.matchTemplate(gray,template,cv2.TM_CCOEFF_NORMED)
threshold = 0.9
loc = np.where( matched >= threshold)
for pt in zip(*loc[::-1]):
    cv2.rectangle(img, pt, (pt[0] + w, pt[1] + h), (0,255,255), 3)
cv2.imshow('Matched with Template',img)
cv2.waitKey(0)
cv2.destroyAllWindows()


