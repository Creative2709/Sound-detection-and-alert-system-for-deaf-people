#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int green = 7;
const int motor = 4;
const int yellow = 5;
const int red = 6;
const int blue = 8;
LiquidCrystal_I2C lcd(0x27, 16 , 2);

void setup() {
  Serial.begin(9600);
  Wire.begin();
  lcd.init();
  lcd.backlight();
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(motor, OUTPUT);
  lcd.print("SOUND ALERT FOR ");
  lcd.setCursor(0,1);
  lcd.print("DEAF PEOPLE !!!");
}

void loop() {
  if (Serial.available() > 0){
    String msg = Serial.readString();


    if (msg == "mobile_ringtone"){
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("SOMEONE CALLING.");
      digitalWrite(yellow, HIGH);
      for(int i=0; i<4; i++)
      {
        digitalWrite(motor , HIGH);
        delay(1000);
        digitalWrite(motor, LOW);
        delay(1000);
      }
      digitalWrite(yellow, LOW);
      delay(5000);
      lcd.clear();
      lcd.print("SOUND ALERT FOR ");
      lcd.setCursor(0,1);
      lcd.print("DEAF PEOPLE !!!");

    }

    else if (msg == "alarm_sound"){
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("WAKE UP !!!");
      digitalWrite(green, HIGH);
      for(int i=0; i<2; i++)
      {
        digitalWrite(motor, HIGH);
        delay(1000);
        digitalWrite(motor, LOW);
        delay(1000);
      }
      digitalWrite(green, LOW);
      delay(5000);
      lcd.clear();
      lcd.print("SOUND ALERT FOR ");
      lcd.setCursor(0,1);
      lcd.print("DEAF PEOPLE !!!");

    }

    else if (msg == "doorbell"){
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("SOMEONE ON DOOR.");
      digitalWrite(red, HIGH);
      for(int i=0; i<3; i++)
      {
        digitalWrite(motor , HIGH);
        delay(1000);
        digitalWrite(motor, LOW);
        delay(1000);
      } 
      digitalWrite(red, LOW);
      delay(5000);
      lcd.clear();
      lcd.print("SOUND ALERT FOR ");
      lcd.setCursor(0,1);
      lcd.print("DEAF PEOPLE !!!");

    }

    else if (msg == "beep_sound"){
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("BEEP SOUND");
        digitalWrite(blue, HIGH);
      for(int i=0; i<1; i++)
      {
        digitalWrite(motor , HIGH);
        delay(1000);
        digitalWrite(motor, LOW);
        delay(1000);
      }
        digitalWrite(blue, LOW);
        delay(5000);
        lcd.clear();
        lcd.print("SOUND ALERT FOR ");
        lcd.setCursor(0,1);
        lcd.print("DEAF PEOPLE !!!");


    }

    else if (msg == "unknown_sound"){
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print(msg);
      }
    }

  }


