
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int greenPin = 7;

void setup() {
  Serial.begin(9600);
  pinMode(greenPin, OUTPUT);
  lcd.clear();
  lcd.begin(16,2);
  lcd.print("");
}

void loop() {
  if (Serial.available() > 0){
    String msg = Serial.readString();



    if (msg == "mobile_ringtone"){
      for(int i=0; i<100; i++){
        digitalWrite(greenPin , HIGH);
        delay(400);
        digitalWrite(greenPin , LOW);
        delay(400);
      }
    }

    else if (msg == "alarm_sound"){
      for(int i=0; i<100; i++){
        digitalWrite(greenPin , HIGH);
        delay(1000);
        digitalWrite(greenPin , LOW);
        delay(1000);
      }
    }

    else if (msg == "doorbell"){
      for(int i=0; i<100; i++){
        digitalWrite(greenPin , HIGH);
        delay(1000);
        digitalWrite(greenPin , LOW);
        delay(1000);
      }
    }

    else if (msg == "beep_sound"){
      for(int i=0; i<100; i++){
        digitalWrite(greenPin , HIGH);
        delay(1000);
        digitalWrite(greenPin , LOW);
        delay(1000);
      }
    }

    else if (msg == "dog_barking"){
      for(int i=0; i<100; i++){
        digitalWrite(greenPin , HIGH);
        delay(1000);
        digitalWrite(greenPin , LOW);
        delay(1000);
      }
    }

    else if (msg == "coocker_whistle"){
      for(int i=0; i<100; i++){
        digitalWrite(greenPin , HIGH);
        delay(1000);
        digitalWrite(greenPin , LOW);
        delay(1000);
      }
    }

    else if (msg == "unknown_sound"){
    
      }
    }

  }
}

