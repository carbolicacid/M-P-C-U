void setup() {
  // put your setup code here, to run on
  pinMode(3, OUTPUT);
  pinMode(6, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
 digitalWrite(6, HIGH);
 delay (1000);
 digitalWrite(3, LOW);
 delay (1000);

 digitalWrite(6, LOW);
 delay (1000);
 digitalWrite(3, LOW);
 delay (1000);

 digitalWrite(6, LOW);
 delay (1000);
 digitalWrite(3, HIGH);
 delay (1000);
 
 digitalWrite(6, LOW);
 delay (1000);
 digitalWrite(3, LOW);
 delay (1000);

 digitalWrite(6, HIGH);
 delay (1000);
 digitalWrite(3, HIGH);
 delay (1000);

 digitalWrite(6, LOW);
 delay (1000);
 digitalWrite(3, LOW);
 delay (1000);
}
