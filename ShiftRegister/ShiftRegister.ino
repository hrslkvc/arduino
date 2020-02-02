//Pin connected to ST_CP of 74HC595
int latchPin = 4;
//Pin connected to SH_CP of 74HC595
int clockPin = 3;
////Pin connected to DS of 74HC595
int dataPin = 2;

byte leds = 0;



void setup() {
  Serial.begin(9600);
  //set pins to output so you can control the shift register
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop() {
  singleUpThenDown();

  singlePassThrough();

  singleZeroThrough();

  passThrough();

  upThenDown();

}

void writeToRegister() {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, leds);
  digitalWrite(latchPin, HIGH);
  delay(50);
}

void singlePassThrough() {
  leds = 1;
  for (int i = 0; i < 8; i++) {
    writeToRegister();
    leds = leds << 1;
    delay(100);
  }
}


void singleZeroThrough() {
  leds = 254;
  int counter = 1;
  do  {
    writeToRegister();

    leds = leds - counter;
    counter *= 2;
    delay(100);
  } while (leds > 127);
}

void singleUpThenDown() {
  leds = 1;
  writeToRegister();
  while (leds < 128) {
    leds = leds << 1;
    writeToRegister();
    Serial.println(leds, BIN);
  }

  while (leds > 1) {
    writeToRegister();
    leds = leds >> 1;
    Serial.println(leds, BIN);
  }

}


void upThenDown() {

  for (int i = 0; i < 8; i++) {
    bitSet(leds, i);
    writeToRegister();
    Serial.println(leds, BIN);
  }

  for (int i = 8; i >= 0; i--) {
    bitClear(leds, i);
    writeToRegister();
    Serial.println(leds, BIN);
  }
}

void passThrough() {
  for (int i = 0; i < 8; i++) {
    bitSet(leds, i);
    writeToRegister();
  }

  for (int i = 0; i < 8; i++) {
    bitClear(leds, i);
    writeToRegister();
  }
}
