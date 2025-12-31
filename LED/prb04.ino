void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(3, OUTPUT);

  Serial.print("Enter two integers: ");
  while (Serial.available() == 0) {}
  int A = Serial.parseInt();
  Serial.print(A);
  while (Serial.available() == 0) {}
  int B = Serial.parseInt();
  Serial.print(B);
  while (Serial.available() == 0) {}
  String s = Serial.readString();
  Serial.print(s);
  if (s == "Add" || s == "+") {
    Serial.println(A + B);
  }

  else if (s == "Subtract" || s == "-") {
    Serial.println(A - B);
  } else if (s == "Multiply" || s == "*") {
    Serial.println(A * B);
  } else if (s == "Division" || s == "/") {
    Serial.println(A / B);
  } else if (s == "Modulas" || s == "%") {
    Serial.println(A % B);
  } else {
    digitalWrite(3, HIGH);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
}
