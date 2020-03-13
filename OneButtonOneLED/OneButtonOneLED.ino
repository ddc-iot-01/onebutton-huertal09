/*
 * Project: Using OneButton library
 * Description: Introduct Students to OneButton Library using a button and the serial monitor
 * Author: Alba Huerta
 * Date: 3-Mar-20
 */

#include <OneButton.h>

// Setup OneButton on pin 23
OneButton button1(23, false);

int buttonState = LOW;
int BLed = 5;
int flash;
int ledDelay(50);



void setup() {

 Serial.begin(9600);
 while (!Serial);

 //link the button 1 functions.
 button1.attachClick(click1); 
 button1.attachDoubleClick(doubleclick1); 
 /*button1.attachLongPressStart(longPresStart1);
 button1.attachLongPressStop(longPressStop1);*/
 button1.setClickTicks(250); //within a quarter of a second recognize
 button1.setPressTicks(2000); // tell them apart
 pinMode(BLed, OUTPUT);
 
 
 if(Serial) Serial.println("Starting OneButton...");

}

void loop() {
  // keep watching the push buttons:
  button1.tick();
  if (buttonState == LOW){
  digitalWrite(BLed, LOW);
}
else
{
  if (flash == LOW){
  digitalWrite(BLed, HIGH);}
  else{
  digitalWrite(BLed, HIGH);
  delay(50);
  digitalWrite(BLed, LOW);
  delay(50);}}
  
  button1.tick();
 
} // loop


// ----- button 1 callback functions

void click1() { // this fucntion will be called when the button1 was pressed 1 time
  Serial.println("Button 1 click.");
  buttonState = !buttonState;
  Serial.print("buttonState =");
  Serial.println(buttonState);

  } // click1


// This function will be called when the button1 was pressed 2 times in a short timeframe.
void doubleclick1() {
  Serial.println("Button 1 doubleclick.");
  flash = !flash;
  Serial.print("flash = ");
  Serial.println(flash);
} // doubleclick1


// This function will be called once, when the button1 is pressed for a long time.
void longPressStart1() {
// print longPress
} // longPressStart1
