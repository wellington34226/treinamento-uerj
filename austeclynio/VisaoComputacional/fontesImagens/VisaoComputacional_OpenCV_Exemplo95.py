import cv2 
 
# Read image
#src = cv2.imread("Rosto_de_Menina_001.png");
src = cv2.imread("James_Brown_001.png");
cv2.imshow("ORIGINAL COLOR",src);
cv2.waitKey()

#src = cv2.imread("Rosto_de_Menina_001.png", cv2.IMREAD_GRAYSCALE);
src = cv2.imread("James_Brown_001.png", cv2.IMREAD_GRAYSCALE);
assert src is not None, "Arquivo não encontrado!"

# Original image 
cv2.imshow("ORIGINAL",src);
cv2.waitKey()
 
# Basic threhold example 
th, dst = cv2.threshold(src, 100, 255, cv2.THRESH_BINARY);
cv2.imshow("THRESH_BINARY",dst);
cv2.waitKey()
 
# Thresholding with maxValue set to 128
th, dst = cv2.threshold(src,00,128, cv2.THRESH_BINARY); 
cv2.imshow("THRESH_BINARY",dst);
cv2.waitKey()
 
# Thresholding with threshold value set 127
# Pixel values below 127 would be changed to Black
# Pixel values above 127 would be changed to White (255)
th, dst = cv2.threshold(src,127,255,cv2.THRESH_BINARY); 
cv2.imshow("THRESH_BINARY",dst);
cv2.waitKey()
 
# Thresholding using THRESH_BINARY_INV 
th, dst = cv2.threshold(src,127,255, cv2.THRESH_BINARY_INV); 
cv2.imshow("THRESH_BINARY_INV",dst);
cv2.waitKey()
 
# Thresholding using THRESH_TRUNC 
th, dst = cv2.threshold(src,127,255, cv2.THRESH_TRUNC); 
cv2.imshow("THRESH_TRUNC",dst);
cv2.waitKey()
 
# Thresholding using THRESH_TOZERO 
th, dst = cv2.threshold(src,127,255, cv2.THRESH_TOZERO); 
cv2.imshow("THRESH_TOZERO",dst);
cv2.waitKey()
 
# Thresholding using THRESH_TOZERO_INV 
th, dst = cv2.threshold(src,127,255, cv2.THRESH_TOZERO_INV); 
cv2.imshow("THRESH_TOZERO_INV",dst);
cv2.waitKey()
cv2.destroyAllWindows()
