int potValue = 0;
float V;
int percent;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  analogReference(DEFAULT);
}
void loop() {
  // put your main code here, to run repeatedly:
  potValue = analogRead(A1);
  V = 5.0 / 1023 * potValue;
  percent = 100 / 5 * V;
  Serial.print("\nCurrent voltage is: ");
  Serial.print(V);
  Serial.println("V");
  Serial.print("Potentiometer: ");
  Serial.print(percent);
  Serial.println("%");
  delay(500);
}