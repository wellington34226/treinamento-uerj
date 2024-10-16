import cv2
import numpy as np
import glob
import os

#path = "*.jpg"
path = "E:/UDTInovUERJ/Cursos_FAPERJ/Visão_Computacional/fontesImagens/*.JPG"
#path = "E:/ViagemChile/imagens/imagens/*.jpg"
template = cv2.imread('Template_Caxias_001.jpg',0)

cv2.imshow('Template',template)
cv2.waitKey(0)

w,h = template.shape[0], template.shape[1]
print(w)
print(h)

for file in glob.glob(path):
    
    fileName_absolute = os.path.basename(file)
    print(fileName_absolute)
    img= cv2.imread(fileName_absolute)
    #print(img)
    cv2.imshow('Archive',img)
    w1,h1 = img.shape[0], img.shape[1]
    print(w1)
    print(h1)
    cv2.waitKey(0)
    gray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)

    matched = cv2.matchTemplate(gray,template,cv2.TM_CCOEFF_NORMED)
    threshold = 0.8
    loc = np.where( matched >= threshold)
    for pt in zip(*loc[::-1]):
        cv2.rectangle(img, pt, (pt[0] + h, pt[1] + w), (0,255,255), 0)
        cv2.imshow('Matched with Template',img)
        
cv2.destroyAllWindows()
print("FIM")        
