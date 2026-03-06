#define LED 7
int potVal = 0;
int dTime;
float v;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  analogReference(DEFAULT);
  pinMode(LED, OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:potVal = analogRead(A2);
  v = 5.0 / 1023 * potVal;
  Serial.print("\nPotentiometer voltage reading is: ");
  Serial.print(v);
  Serial.println(" V");
  dTime = map(potVal, 0, 1023, 100, 1000);
  Serial.print("LED blinking time is: ");
  Serial.print(dTime);
  Serial.println(" ms");
  digitalWrite(LED, 1);
  delay(dTime);
  digitalWrite(LED, 0);
  delay(dTime);
}