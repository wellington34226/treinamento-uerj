import numpy as np  
import cv2  
import dlib  
 
detector = dlib.get_frontal_face_detector()   
   
JAWLINE_POINTS = list(range(0, 17))  
RIGHT_EYEBROW_POINTS = list(range(17, 22))  
LEFT_EYEBROW_POINTS = list(range(22, 27))  
NOSE_POINTS = list(range(27, 36))  
RIGHT_EYE_POINTS = list(range(36, 42))  
LEFT_EYE_POINTS = list(range(42, 48))  
MOUTH_OUTLINE_POINTS = list(range(48, 61))  
MOUTH_INNER_POINTS = list(range(61, 68))  
  
predictor = dlib.shape_predictor("shape_predictor_68_face_landmarks.dat")  #Já baixado
   
# Read the image  
#image_path = "Imagem_Pessoas_Juntas_001.jpg"
image_path = "Grupo_Caxias_001.jpg"

image = cv2.imread(image_path)
faces = detector(image)
print("Achadas {0} faces!".format(len(faces)))

for face in faces:
    x, y, w, h = face.left(), face.top(), face.width(), face.height()
    cv2.rectangle(image, (x, y), (x + w, y + h), (0, 0, 255), 2)   
    dlib_rect = dlib.rectangle(int(x), int(y), int(x + w), int(y + h))   
    landmarks = np.matrix([[p.x, p.y]  
                for p in predictor(image, dlib_rect).parts()])   
    landmarks_display = landmarks[RIGHT_EYE_POINTS + LEFT_EYE_POINTS + NOSE_POINTS + JAWLINE_POINTS + MOUTH_OUTLINE_POINTS]   
    for idx, point in enumerate(landmarks_display):
      pos = (point[0, 0], point[0, 1])
      cv2.circle(image, pos, 2, color=(0, 255, 255), thickness=-1)  
   
cv2.imshow("Landmarks achados", image)
cv2.waitKey(0)
cv2.destroyAllWindows()
