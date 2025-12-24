void setup() {
  Serial.begin(9600);
  Serial.print("Student ID: ");
  while (Serial.available() == 0) {}
  long ID = Serial.parseInt();
  Serial.println(ID);

  int roll = (ID % 1000);
  int dept = (ID / 1000) % 10;
  int term = (ID / 100000) % 10;
  int year = 2000 + (ID / 10000000);

  if (year == 2019) {
    Serial.print("Admission Year: ");
    Serial.println("2019");
  }

  else if (year == 2017) {
    Serial.print("Admission Year: ");
    Serial.println("2017");
  }

  if (term == 2) {
    Serial.println("Fall");
  } else if (term == 1) {
    Serial.println("Spring");
  }


  if (dept == 5) {
    Serial.println("EEE");
  }

  else if (dept == 7) {
    Serial.println("IPE");
  } else {
  }

  Serial.print("Roll. No.: ");
  Serial.print(roll);
}

void loop() {
  // put your main code here, to run repeatedly:
}
