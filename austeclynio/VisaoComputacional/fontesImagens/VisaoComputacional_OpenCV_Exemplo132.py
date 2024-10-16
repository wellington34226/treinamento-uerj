import cv2 
image2 = cv2.imread('Rosto_de_Menina_001.png')
#image2 = cv2.imread("James_Brown_001.png");

cv2.imshow('Original', image2)
cv2.waitKey(0)

img_gray2 = cv2.cvtColor(image2, cv2.COLOR_BGR2GRAY)
cv2.imshow('Cinza', img_gray2)
cv2.waitKey(0)

ret, thresh2 = cv2.threshold(img_gray2, 100, 255, cv2.THRESH_BINARY) # Transforma para binária
cv2.imshow('Threshold', thresh2)
cv2.waitKey(0)

contours4, hierarchy4 = cv2.findContours(thresh2, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_NONE)
image_copy5 = image2.copy()
cv2.drawContours(image_copy5, contours4, -1, (0, 255, 0), 2, cv2.LINE_AA)

cv2.imshow('EXTERNAL', image_copy5)
cv2.waitKey(0)
print(len(contours4))
cv2.destroyAllWindows()
