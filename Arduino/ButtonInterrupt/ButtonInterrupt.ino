/*
 * Created: April 2016
 * By: Ab Kurk
 * Version:1
 * Description:
 * File Name:Interrupt_demo2.ino
 * This is part of a tutoral to show the difference between attaching an interrupt to a pin v.s. digitalRead(button1Pin). 
 * Attaching an interrupt to a hardware pin gives you the ability to handle inputs as they happen. This demo file has an interrupt
 * attacht to a hardware pin 2 instead of using the traditional digitalRead(button1Pin).
 * Link To Tutorial Page:http://www.thearduinomakerman.info/blog/2016/4/25/using-interrupts
 * 
 */


//Delcaring the button and LED Pins
#define button1Pin 2
#define led1Pin 13
#define led2Pin 12
#define led3Pin 11
#define led4Pin 10
int onoff=0;//0 lights are off 1 light are on
volatile byte state = HIGH;

// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(led3Pin, OUTPUT);
  pinMode(led4Pin, OUTPUT);
  pinMode(button1Pin, INPUT_PULLUP);
  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(button1Pin), blink1, CHANGE);
  
}
void blink1() {
  state = !state;
 
}

// the loop function runs over and over again forever
void loop() {
  
  if (state == LOW) {//using the state variable that gets changed in the interrupt function instead of a digitalRead()
    // turn LEDS on:
    Serial.println("on");
    digitalWrite(led1Pin, HIGH); 
    digitalWrite(led2Pin, HIGH);
    digitalWrite(led3Pin, HIGH);  
    digitalWrite(led4Pin, HIGH);
    onoff=1; 
  } else if(state == HIGH) {//using the state variable that gets changed in the interrupt function instead of a digitalRead()
    // turn LEDs off:
    if(onoff==1){
      digitalWrite(led1Pin, LOW);
      digitalWrite(led2Pin, LOW);
      digitalWrite(led3Pin, LOW);
      digitalWrite(led4Pin, LOW);
      onoff=0; 
      
    }
    
    //walkning LED
     digitalWrite(led1Pin, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(1000);  // wait for a second
      if(state==LOW)return; //returns back to the top of the main loop
        digitalWrite(led1Pin, LOW);    // turn the LED off by making the voltage LOW
        digitalWrite(led2Pin, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(1000);       // wait for a second
         if(state==LOW)return; //returns back to the top of the main loop
        digitalWrite(led2Pin, LOW);    // turn the LED off by making the voltage LOW
        digitalWrite(led3Pin, HIGH);   // turn the LED on (HIGH is the voltage level)
     delay(1000);         // wait for a second
        if(state==LOW)return;
        digitalWrite(led3Pin, LOW);    // turn the LED off by making the voltage LOW
        digitalWrite(led4Pin, HIGH);   // turn the LED on (HIGH is the voltage level)
     delay(1000);         // wait for a second
         if(state==LOW)return; //returns back to the top of the main loop
        digitalWrite(led4Pin, LOW);    // turn the LED off by making the voltage LOW
      
     
     }
}
