int LED = 3;
void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  Serial.println("Enter a number:");
}

void loop() {
  while (Serial.available() == 0) {}
  int n = Serial.parseInt();
  long fact = factorial(n);

  if (fact > 50) {
    Serial.println("Factorial > 50. Enter another number:");
  } else {
   
    Serial.print(fact);
    Serial.println(" times");

    for (int i = 0; i < fact; i++) {
      digitalWrite(LED, HIGH);
      delay(300);
      digitalWrite(LED, LOW);
      delay(300);
    }
  }

  Serial.println("Enter a number:");
}


long factorial(int n) {
  long fact = 1;
  for (int i = 1; i <= n; i++) {
    fact *= i;
  }
  return fact;
}
