void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
  pinMode(6, OUTPUT);
  Serial.begin(9600);
  Serial.print("Enter 4-Digits input: ");
  while (Serial.available() == 0) {}
  String n = Serial.readString();
  Serial.println(n);

  if (n == "1111") {

    digitalWrite(6, HIGH);
    delay(1000);
    digitalWrite(3, HIGH);
    delay(1000);
  } else if (n == "0010") {
    digitalWrite(6, LOW);
    delay(1000);
    digitalWrite(3, HIGH);
    delay(1000);
  } else if (n == "0101") {
    digitalWrite(6, HIGH);
    delay(1000);
    digitalWrite(3, LOW);
    delay(1000);
  } else if (n == "0001") {
    digitalWrite(6, LOW);
    delay(1000);
    digitalWrite(3, LOW);
    delay(1000);
  }


  else {
    Serial.println("INVALID");
  }
}
void loop() {
  // put your main code here, to run repeatedly:
}
