import cv2 
 
# Read image 
src = cv2.imread('VisaoComputacional_Imagem_RottWeiler.jpg',cv2.IMREAD_GRAYSCALE); 
 
# Basic threhold example 
th, dst = cv2.threshold(src, 0, 255, cv2.THRESH_BINARY);
print('THRESH_BINARY')
cv2.imwrite('VisaoComputacional_Imagem_RottWeiler-Threshold-Example.jpg', dst);
img = cv2.imread('VisaoComputacional_Imagem_RottWeiler-Threshold-Example.jpg')
cv2.imshow('Imagem_RottWeiler-Threshold-Example',img)
cv2.waitKey()
print(th)
# Thresholding with maxValue set to 128
th, dst = cv2.threshold(src, 0, 128, cv2.THRESH_BINARY);
cv2.imwrite("VisaoComputacional_Imagem_RottWeiler-thresh-binary-maxval.jpg", dst);
img = cv2.imread('VisaoComputacional_Imagem_RottWeiler-thresh-binary-maxval.jpg')
cv2.imshow('Imagem_RottWeiler-Threshold-Example',img)
cv2.waitKey()
 
# Thresholding with threshold value set 127 
th, dst = cv2.threshold(src,127,255, cv2.THRESH_BINARY);
cv2.imwrite("VisaoComputacional_Imagem_RottWeiler-thresh-binary.jpg", dst); 
img = cv2.imread('VisaoComputacional_Imagem_RottWeiler-thresh-binary.jpg')
cv2.imshow('Imagem_RottWeiler-Threshold-Example',img)
cv2.waitKey()
print(th)
# Thresholding using THRESH_BINARY_INV 
th, dst = cv2.threshold(src,127,255, cv2.THRESH_BINARY_INV);
print('THRESH_BINARY_INV')
cv2.imwrite("VisaoComputacional_Imagem_RottWeiler-thresh-binary-inv.jpg", dst); 
img = cv2.imread('VisaoComputacional_Imagem_RottWeiler-thresh-binary-inv.jpg')
cv2.imshow('Imagem_RottWeiler-Threshold-Example',img)
cv2.waitKey()

# Thresholding using THRESH_TRUNC 
th, dst = cv2.threshold(src,127,255, cv2.THRESH_TRUNC);
print('THRESH_TRUNC')
cv2.imwrite("VisaoComputacional_Imagem_RottWeiler-thresh-trunc.jpg", dst); 
img = cv2.imread('VisaoComputacional_Imagem_RottWeiler-thresh-trunc.jpg')
cv2.imshow('Imagem_RottWeiler-Threshold-Example',img)
cv2.waitKey()

# Thresholding using THRESH_TOZERO 
th, dst = cv2.threshold(src,127,255, cv2.THRESH_TOZERO);
print('THRESH_TOZERO')
cv2.imwrite("VisaoComputacional_Imagem_RottWeiler-thresh-tozero.jpg", dst); 
img = cv2.imread('VisaoComputacional_Imagem_RottWeiler-thresh-tozero.jpg')
cv2.imshow('Imagem_RottWeiler-Threshold-Example',img)
cv2.waitKey()

# Thresholding using THRESH_TOZERO_INV 
th, dst = cv2.threshold(src,127,255, cv2.THRESH_TOZERO_INV);
print('THRESH_TOZERO_INV');
cv2.imwrite("VisaoComputacional_Imagem_RottWeiler-thresh-to-zero-inv.jpg", dst);
img = cv2.imread('VisaoComputacional_Imagem_RottWeiler-thresh-to-zero-inv.jpg')
cv2.imshow('Imagem_RottWeiler-Threshold-Example',img)
cv2.waitKey()

cv2.destroyAllWindows()
