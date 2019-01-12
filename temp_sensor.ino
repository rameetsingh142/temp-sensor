#include "dht.h"
#include <SoftwareSerial.h>`
#define rxPin 2                     // define SoftwareSerial rx data pin  
#define txPin 3                     // define SoftwareSerial tx data pin  
#define dht_apin A0 // Analog Pin sensor is connected to
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
String readString;
SoftwareSerial blueTooth(rxPin, txPin);

 
dht DHT;
 
void setup(){
  blueTooth.begin(9600);
  Serial.begin(9600);
  delay(500);//Delay to let system boot
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
  delay(1000);//Wait before accessing Sensor
 lcd.begin(16, 2);
}//end "setup()"
 
void loop(){
  //Start of Program 
  int a;
  int c,d; 
    DHT.read11(dht_apin); 
     a= DHT.humidity;
     if (Serial.available())  
     { 
       c = Serial.read();  
       d = Serial.read();  
        
       Serial.println(c);      
       Serial.println(d);  // Write the character to the Serial Monitor  
       delay(1000);
        
       blueTooth.write (c);   // Write the character to Bluetooth
       
       blueTooth.write (d);    
       delay(1000);
       
     }  
}  
  
    
   
