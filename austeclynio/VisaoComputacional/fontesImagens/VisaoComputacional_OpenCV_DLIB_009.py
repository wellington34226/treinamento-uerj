import face_recognition
import cv2

# Carregar a imagem
image = face_recognition.load_image_file("Imagem_Pessoas_Juntas_002.jpg")

# Encontrar todas as faces na imagem
face_locations = face_recognition.face_locations(image)
print(len(face_locations))
# Carregar a imagem usando OpenCV para desenhar retângulos
image_cv = cv2.cvtColor(image, cv2.COLOR_RGB2BGR)

# Desenhar retângulos ao redor das faces detectadas
for (top, right, bottom, left) in face_locations:
    cv2.rectangle(image_cv, (left, top), (right, bottom), (0, 255, 0), 2)
font = cv2.FONT_HERSHEY_SIMPLEX
y,x,c = image.shape
b=int(.95*y)
cv2.putText(image_cv,'Pessoas na Foto! ' + str(len(face_locations)),(50,b), font,1,(0,0,255),2,cv2.LINE_AA)

# Mostrar a imagem com as faces detectadas
cv2.imshow("Faces Detectadas", image_cv)
cv2.waitKey(0)
cv2.destroyAllWindows()
