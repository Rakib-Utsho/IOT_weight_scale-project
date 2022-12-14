/*
 Setup your scale and start the sketch WITHOUT a weight on the scale
 Once readings are displayed place the weight on the scale
 Press +/- or a/z to adjust the calibration_factor until the output readings match the known weight
 Arduino pin 6 -> HX711 CLK
 Arduino pin 5 -> HX711 DOUT
 Arduino pin 5V -> HX711 VCC
 Arduino pin GND -> HX711 GND 
*/

#include "HX711.h"

HX711 scale(5, 6);
float calibration_factor =  2350; // this calibration factor is adjusted according to my load cell
float units;
float finalweight;
float weight=0;
float average=0;

void setup() {
  Serial.begin(9600);
  Serial.println("ready to read and please ensure the weight more than 1 Kg");
  
//  Serial.println("Remove all weight from scale");
//  Serial.println("After readings begin, place known weight on scale");
//  Serial.println("Press + or a to increase calibration factor");
//  Serial.println("Press - or z to decrease calibration factor");

  scale.set_scale(calibration_factor);
  scale.tare();  //Reset the scale to 0


  

 // long zero_factor = scale.read_average(); //Get a baseline reading
  //Serial.print("Zero factor: "); //This can be used to remove the need to tare the scale. Useful in permanent scale projects.
  //Serial.println(zero_factor);
}

void loop(){

  Serial.print("Reading: ");
  units = scale.get_units(10), 2;
  //units = (units*0.454)-0.02;
  //Serial.print(units);
  if (units < 0)
  {
    units = 0.00;
    //Serial.print(units);
    //Serial.print("please enter the weight more then 1 kg");
    
  }
  else{
    units = ((units*0.40359237)-.6); 
  }
 
  Serial.print("weight: ");
  Serial.print(units);
  Serial.print(" KG"); 
  //Serial.print(" calibration_factor: ");
  //Serial.print(calibration_factor);
  Serial.println();
  delay(1000);
//  if(Serial.available())
//  {
//    char temp = Serial.read();
//    Serial.println("temp"+temp);
//    Serial.println(temp);
//    if(temp == '+' || temp == 'a')
//      calibration_factor += 1;
//    else if(temp == '-' || temp == 'z')
//      calibration_factor -= 1;
//  }
//  if(Serial.available())
//  {
//    char temp = Serial.read();
//    if(temp == 't' || temp == 'T')
//      scale.tare();
//  }
}
