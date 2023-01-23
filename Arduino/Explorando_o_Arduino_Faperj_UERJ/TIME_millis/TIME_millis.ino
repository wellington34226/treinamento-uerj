unsigned long startTime;
unsigned long elapsedTime;

void setup () {
  Serial.begin(115200); 
  startTime = millis(); 
}

void loop () {
  
          
          elapsedTime = millis() - startTime;
          if (elapsedTime/1000 > 120){  // 5 minutos           
           Serial.println("teste de millis");
           startTime = millis();
          }
      
      
}
