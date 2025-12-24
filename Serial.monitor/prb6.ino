void setup() {
  Serial.begin(9600);


  Serial.println("Enter 4-bit binary input:");

  while (Serial.available() == 0) {}
  String input = Serial.readString();

  if (input == "0001")
    Serial.println("00 (D0)");
  else if (input == "0010")
    Serial.println("01 (D1)");
  else if (input == "0100")
    Serial.println("10 (D2)");
  else if (input == "1000")
    Serial.println("11 (D3)");
  else
    Serial.println("Wrong");
}

void loop() {
}
