#define LED 7
int Potvalue = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
  Potvalue = analogRead(A0);
  Serial.print("\nCurrent value of the potentiometer: ");
  Serial.println(Potvalue);
  if (Potvalue > 512) {
    digitalWrite(LED, 1);
    Serial.println("LED is on.");
    delay(500);
  } else {
    digitalWrite(LED, 0);
    Serial.println("LED is off.");
    delay(500);
  }
}