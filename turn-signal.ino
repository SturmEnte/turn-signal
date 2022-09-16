const int BLED_PIN_START = 2;
const int BLED_PIN_END = 6;
const int WLED_PIN_START = 7;
const int WLED_PIN_END = 11;

const int LEFT_BTN = 12;
const int RIGHT_BTN = 13;

const int BLINK_SPEED = 50;
const int WAIT_TIME = 100;

void setup() {
  for(int i = BLED_PIN_START; i <= WLED_PIN_END; i++){
    pinMode(i, OUTPUT);
  }
  pinMode(LEFT_BTN, INPUT);
  pinMode(RIGHT_BTN, INPUT);
}

void loop() {
  int left_pressed = digitalRead(LEFT_BTN);
  int right_pressed = digitalRead(RIGHT_BTN);

  if(left_pressed == HIGH){
    for(int i = WLED_PIN_END; i >= WLED_PIN_START; i--){
      digitalWrite(i, HIGH);
      delay(BLINK_SPEED);
    }

    delay(WAIT_TIME);

    for(int i = WLED_PIN_END; i >= WLED_PIN_START; i--){
      digitalWrite(i, LOW);
    }
  }  
  if (right_pressed == HIGH){
    for(int i = BLED_PIN_START; i <= BLED_PIN_END; i++){
      digitalWrite(i, HIGH);
      delay(BLINK_SPEED);
    }

    delay(WAIT_TIME);

    for(int i = BLED_PIN_START; i <= BLED_PIN_END; i++){
      digitalWrite(i, LOW);
    }
  }
}
