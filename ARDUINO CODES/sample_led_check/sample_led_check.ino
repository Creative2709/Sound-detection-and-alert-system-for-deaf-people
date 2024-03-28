const int greenPin = 7;

void setup() {
  pinMode(greenPin, OUTPUT);
  // put your setup code here, to run once:

}

void loop() {
  while(1){
    digitalWrite(greenPin , HIGH);
    delay(400);
    digitalWrite(greenPin, LOW);
    delay(400);
  }
  // put your main code here, to run repeatedly:

}
