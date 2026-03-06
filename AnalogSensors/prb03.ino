int potVal1, potVal2;
float v1, v2;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  analogReference(DEFAULT);
}
void loop() {
  // put your main code here, to run repeatedly:
  potVal1 = analogRead(A0);
  potVal2 = analogRead(A1);
  v1 = 5.0 / 1023 * potVal1;
  v2 = 5.0 / 1023 * potVal2;
  Serial.print("\nValue of the 1st potentiometer: ");
  Serial.println(v1);
  Serial.print("Value of the 2nd potentiometer: ");
  Serial.println(v2);
  if (v1 > v2) {
    Serial.println("1st potentiometer has the higher value.");
    delay(1000);
  } else if (v1 < v2) {
    Serial.println("2nd potentiometer has the higher value.");
    delay(1000);
  } else {
    Serial.println("Both potentiometers has the same value.");
    delay(1000);
  }
}