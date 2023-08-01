int analogPin = A0;     // analog pin A3
int pinLED =5;
                          
int val = 0;              // variável para armazenar o valor lido

void setup(){
  Serial.begin(115200); // Inicia a saída serial com 115200bpi
  pinMode(pinLED, OUTPUT); 
}

void loop(){
  val = analogRead(analogPin);     // lê o valor analógico
  Serial.println(val);                       // apresenta o valor na saída serial
  
  //val = map (val,0,1023,0,255);
  analogWrite(pinLED,map (val,0,1023,0,255));
  delay(500);
}
