int ledPin = 19;  //GPIO19


int freq = 5000;
int ledChannel = 0;
int resolution = 8;
 
void setup(){  
  ledcSetup(ledChannel, freq, resolution);   // Define canal, frequencia e resolução  
  ledcAttachPin(ledPin, ledChannel);
}
 
void loop(){
  
  for(int dutyCycle = 0; dutyCycle <= 255; dutyCycle++){ 
    ledcWrite(ledChannel, dutyCycle);
    delay(10);
  }
  for(int dutyCycle = 255; dutyCycle >= 0; dutyCycle--){   
    ledcWrite(ledChannel, dutyCycle);   
    delay(10);
  }
}

