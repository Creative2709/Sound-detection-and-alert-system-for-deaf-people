const int green = 7;
const int motor = 4;
const int yellow = 5;
const int red = 6;
const int blue = 8;
void setup() {
  Serial.begin(9600);
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(motor, OUTPUT);
}

void loop() {
  if (Serial.available() > 0){
    String msg = Serial.readString();


    if (msg == "mobile_ringtone"){
      digitalWrite(yellow, HIGH);
      for(int i=0; i<1; i++){
        digitalWrite(motor , HIGH);
        delay(1000);
        digitalWrite(motor, LOW);
        delay(1000);
      }
      digitalWrite(yellow, LOW);

    }

    else if (msg == "alarm_sound"){
        digitalWrite(green, HIGH);
      for(int i=0; i<2; i++){
        digitalWrite(motor, HIGH);
        delay(1000);
        digitalWrite(motor, LOW);
        delay(1000);
      }
      digitalWrite(green, LOW);

    }

    else if (msg == "doorbell"){
      digitalWrite(red, HIGH);
      for(int i=0; i<3; i++){
        digitalWrite(motor , HIGH);
        delay(1000);
        digitalWrite(motor, LOW);
        delay(1000);
      } 
      digitalWrite(red, LOW);

    }

    else if (msg == "beep_sound"){
        digitalWrite(blue, HIGH);
      for(int i=0; i<4; i++){
        digitalWrite(motor , HIGH);
        delay(1000);
        digitalWrite(motor, LOW);
        delay(1000);
      }
        digitalWrite(blue, LOW);

    }

    else if (msg == "unknown_sound"){
    
      }
    }

  }

