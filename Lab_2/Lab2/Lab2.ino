const int leds_1[8] = {9,7,5,3,8,6,4,2}; 
const int leds_2[8] = {9,2,8,3,7,4,6,5}; 
const int btn1 = 11;
const int btn2 = 12;

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 8; i++) {
    pinMode(leds_1[i], OUTPUT);
  }
  pinMode(btn1, INPUT_PULLUP);
  pinMode(btn2, INPUT_PULLUP);
}

void loop() {
  bool isClicked1 = digitalRead(btn1);
  bool isClicked2 = digitalRead(btn2);
  
  if (isClicked1) {
    Serial.write(0xB1);
  }
  
  if (isClicked2) {
    Serial.write(0xB2);
  }
  
  if (Serial.available()) {
    byte command = Serial.read();
    if (command == 0xB1) {
      for (int i = 0; i < 8; i++) {
        digitalWrite(leds_1[i], HIGH);
        delay(700);
        digitalWrite(leds_1[i], LOW);
      }
    } else if (command == 0xB2){
      for (int i = 0; i < 8; i ++) {
        digitalWrite(leds_2[i], HIGH);
        delay(700);
        digitalWrite(leds_2[i], LOW);
      }
    }
  }
}
