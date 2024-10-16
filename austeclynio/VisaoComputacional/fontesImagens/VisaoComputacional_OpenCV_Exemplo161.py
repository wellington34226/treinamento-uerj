import cv2
import numpy as np

img1 = cv2.imread('Imagens_Figuras_Geometricas_001.jpg')
assert img1 is not None, "file could not be read, check with os.path.exists()"
cv2.imshow('Original', img1)
cv2.waitKey(0)

img = cv2.cvtColor(img1, cv2.COLOR_BGR2GRAY)
cv2.imshow('Gray', img)
cv2.waitKey(0)

ret,thresh = cv2.threshold(img,10,255,0)


contours,hierarchy = cv2.findContours(thresh, 1, 2)
print("Numero de figuras na imagem:",len(contours))

for i, cnt in enumerate(contours):
   M = cv2.moments(cnt)
   if M['m00'] != 0.0:
      x1 = int(M['m10']/M['m00'])
      y1 = int(M['m01']/M['m00'])
   area = cv2.contourArea(cnt)
   perimeter = cv2.arcLength(cnt, True)
   perimeter = round(perimeter, 4)
   print(f'Area da figura {i+1}:', area)
   print(f'Perimetro da figura {i+1}:', perimeter)
   img1 = cv2.drawContours(img1, [cnt], -1, (0,255,255), 3)
   cv2.putText(img1, f'Area :{area}', (x1, y1), cv2.FONT_HERSHEY_SIMPLEX, 0.6, (0, 255, 0), 2)
   cv2.putText(img1, f'Perimetro :{perimeter}', (x1, y1+20), cv2.FONT_HERSHEY_SIMPLEX, 0.6, (0, 255, 0), 2)

cv2.imshow("Image", img1)
cv2.waitKey(0)
cv2.destroyAllWindows()
