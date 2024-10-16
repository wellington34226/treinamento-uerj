import cv2 
import numpy as np 
  
# Load the image 
image = cv2.imread('Varios_MCUS_001.jpg')
assert image is not None, "file could not be read, check with os.path.exists()"
cv2.imshow('Original', image)
cv2.waitKey(0)
  
# Convert the image to grayscale 
gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
cv2.imshow('Gray', gray)
cv2.waitKey(0)
  
blur = cv2.bilateralFilter(src=gray, d=9, sigmaColor=75, sigmaSpace=75)
ret, thresh2 = cv2.threshold(blur, 0, 255, cv2.THRESH_BINARY_INV+cv2.THRESH_OTSU)
cv2.imshow('threshold', thresh2)
cv2.waitKey(0)
  
# Find the contours of the objects in the image 
contours, hierarchy = cv2.findContours(thresh2, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

  
# Loop through the contours and calculate the area of each object 
for cnt in contours: 
    area = cv2.contourArea(cnt) 
  
# Draw a bounding box around each object and display the area on the image 
    x, y, w, h = cv2.boundingRect(cnt) 
    cv2.rectangle(image, (x, y), (x+w, y+h), (0, 255, 0), 2) 
    cv2.putText(image, str(area),(x, y),cv2.FONT_HERSHEY_COMPLEX_SMALL, 1, (0, 0, 255), 1) 
  
# Show the final image with the bounding boxes and areas of the objects overlaid on top 
cv2.imshow('image', image) 
cv2.waitKey(0) 
cv2.destroyAllWindows() 
