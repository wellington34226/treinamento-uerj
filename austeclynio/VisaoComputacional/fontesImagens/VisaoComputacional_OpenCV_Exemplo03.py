import numpy as np
import cv2
# Load a color image
img = cv2.imread('BGR_Azul_Verde_Vermelho.png',-1)
cv2.imshow('OpenCV - Color _ Modified',img)
cv2.waitKey(5000)
# By Matrix
print("@Inicio normal")
print(img.item(100,70,0))  # pixel específico
print(img.item(100,70,1))  # pixel específico
print(img.item(100,70,2))  # pixel específico

print(img[100,70])
print("@Fim normal")
print(img.shape[0])
print(img.shape[1])
print(img.shape[2])
for i in range(img.shape[0]): # número de linhas
        for j in range(img.shape[1]): # númeto de colunas
                img.itemset((i,j,2),0) # modifica
cv2.imshow('OpenCV - Color _ Modified',img)
print("@Inicio preto")
print(img.item(100,140,0))
print(img.item(100,140,1))
print(img.item(100,140,2))

print(img[100,140])
print("@Fim preto")
cv2.waitKey(5000)

for i in range(img.shape[0]):
          for j in range(img.shape[1]):
                img.itemset((i,j,2),255)
cv2.imshow('OpenCV - Color _ Modified',img)
print("@Inicio vermelho")
print(img.item(100,140,0))
print(img.item(100,140,1))
print(img.item(100,140,2))

print(img[100,140])
print("@Fim vermelho")
cv2.waitKey(0)
cv2.destroyAllWindows()
