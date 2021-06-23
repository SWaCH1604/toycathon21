#define TRIGGERPIN 2                     
#define ECHOPIN    3
int Switch4 = 12;
int PIR = 13;
const int ldrPin = A0;
int Switch3 = 11;
int Switch2 = 10;
int Switch1 = 9;
#include <dht.h>                                
#define dht_apin A1
dht DHT;
void setup(){              
pinMode(TRIGGERPIN, OUTPUT);
pinMode(ECHOPIN, INPUT);
pinMode(PIR, INPUT);
pinMode(ldrPin, INPUT);
pinMode(Switch1, OUTPUT);
digitalWrite(Switch1, LOW);
pinMode(Switch2, OUTPUT);
digitalWrite(Switch2, LOW);
pinMode(Switch3, OUTPUT);
digitalWrite(Switch3, LOW);
pinMode(Switch4, OUTPUT);
digitalWrite(Switch4, LOW);
Serial.begin(9600);                           
}
void loop()          
{
long duration, distance;          
digitalWrite(TRIGGERPIN, LOW);      
delayMicroseconds(3); 
digitalWrite(TRIGGERPIN, HIGH);
delayMicroseconds(12); 
digitalWrite(TRIGGERPIN, LOW);
duration = pulseIn(ECHOPIN, HIGH);      
distance = (duration/2) / 29.1;
Serial.println(distance);            
long state = digitalRead(PIR);
if((state == HIGH)||(distance<19)) {
digitalWrite (Switch1, HIGH);
digitalWrite (Switch2, HIGH);
digitalWrite (Switch3, HIGH);
digitalWrite (Switch4, HIGH);
Serial.println("Motion detected!");
delay(1000);
    }
else {
digitalWrite (Switch1, LOW);
digitalWrite (Switch2, LOW);
digitalWrite (Switch3, LOW);
digitalWrite (Switch4, LOW);
Serial.println("Motion absent!");
delay(1000);
      }

int state1 = digitalRead(ldrPin);
if(state1 <100) {
digitalWrite (Switch1, HIGH);
digitalWrite (Switch2, HIGH);
digitalWrite (Switch3, HIGH);
digitalWrite (Switch4, HIGH);
Serial.println("Motion detected!");
delay(1000);
    }
else {
digitalWrite (Switch1, LOW);
digitalWrite (Switch2, LOW);
digitalWrite (Switch3, LOW);
digitalWrite (Switch4, LOW);
Serial.println("Motion absent!");
delay(1000);
      }

DHT.read11(dht_apin);
Serial.print("Current humidity = ");
Serial.print(DHT.humidity);
Serial.print("%  ");
Serial.print("temperature = ");
Serial.print(DHT.temperature); 
Serial.println("C  ");
if((DHT.humidity<30)||(DHT.temperature<30))
    {
digitalWrite (Switch1, HIGH);
digitalWrite (Switch2, HIGH);
digitalWrite (Switch3, HIGH);
digitalWrite (Switch4, HIGH);  
    }
else{
digitalWrite (Switch1, LOW);
digitalWrite (Switch2, LOW);
digitalWrite (Switch3, LOW);
digitalWrite (Switch4, LOW);      
    }
}
