/*
  Fade two LEDs with a potentiometer
*/

int led1 = 9;           // the PWM pin the LED is attached to
int led2 = 11;
int brightness1 = 0;    // how bright LED1 is
int brightness2 = 255 - brightness1;    // how bright LED2 is


// the setup routine runs once when you press reset:
void setup() {
  // declare pins 9 and 11 to be LED outputs:
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  // serial input for the potentiometer
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read analog input from the potentiometer, divide it by 4 since it's range (0-1023)is bigger than the brightness output(0-255) value
  int brightness1 = analogRead(A0) / 4;
  // subtract LED1 brightness from 255 to get the oposite value and use it for LED2
  int brightness2 = 255 - brightness1; 
  // update LED brightness according to the calculated analog input
  analogWrite(led1, brightness1);
  analogWrite(led2, brightness2);
}
