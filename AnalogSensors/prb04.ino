#define LED1 9
#define LED2 10
int potVal = 0;
float v;
int PWMval9 = 0;
int PWMval10 = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  analogReference(DEFAULT);
}
void loop() {
  // put your main code here, to run repeatedly:
  potVal = analogRead(A0);
  v = 5.0 / 1023 * potVal;
  Serial.print("\nPotentiometer voltage reading is: ");
  Serial.print(v);
  Serial.println(" V");
  PWMval9 = map(potVal, 0, 1023, 0, 255);
  PWMval10 = map(potVal, 0, 1023, 255, 0);
  analogWrite(LED1, PWMval9);
  analogWrite(LED2, PWMval10);
  delay(10);
}