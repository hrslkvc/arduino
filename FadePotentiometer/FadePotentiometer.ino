/*
  Fade

  This example shows how to fade an LED on pin 9 using the analogWrite()
  function.

  The analogWrite() function uses PWM, so if you want to change the pin you're
  using, be sure to use another PWM capable pin. On most Arduino, the PWM pins
  are identified with a "~" sign, like ~3, ~5, ~6, ~9, ~10 and ~11.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Fade
*/

int led1 = 9;           // the PWM pin the LED is attached to
int led2 = 11;
int brightness1 = 0;    // how bright the LED is
int brightness2 = 255 - brightness1;    // how bright the LED is


// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  int brightness1 = analogRead(A0) / 4;
  int brightness2 = 255 - brightness1; 
  // set the brightness of pin 9:
  analogWrite(led1, brightness1);
  analogWrite(led2, brightness2);}
