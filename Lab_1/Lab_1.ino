const int leds[8] = {13,11,9,7,12,10,8,6};
const int button = 2;

void setup() {
  for (int i = 0; i < 8; i++) {
    pinMode(leds[i], OUTPUT);
  }
  pinMode(button, INPUT_PULLUP);
}

void loop() {
  bool isClicked = digitalRead(button);
  if (isClicked) {
    for (int i = 0; i < 8; i++) {
      digitalWrite(leds[i], HIGH);
      delay(650);
      digitalWrite(leds[i], LOW);
    }
  }
}
