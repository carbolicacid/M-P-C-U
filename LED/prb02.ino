int A, B;
int arr[2];

void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
  pinMode(6, OUTPUT);
  Serial.begin(9600);
  Serial.print("Take two integers: ");

  for (int i = 0; i < 2; i++)

  {
    while (Serial.available() == 0) {}
    arr[i] = Serial.parseInt();
  }

  A = arr[0];
  B = arr[1];
}

void loop() {
  // put your main code here, to run repeatedly:
  if (A % B == 0) {
    digitalWrite(6, HIGH);
    delay(1000);
    digitalWrite(3, LOW);
    delay(1000);

  } else {

    digitalWrite(6, LOW);
    delay(1000);
    digitalWrite(3, HIGH);
    delay(1000);
  }
}
