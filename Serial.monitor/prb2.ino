void setup() {
  Serial.begin(9600);
  Serial.print("Enter three numbers: ");
  while (Serial.available() == 0) {}
  int a = Serial.parseInt();
  int b = Serial.parseInt();
  int c = Serial.parseInt();

  Serial.println(a);
  Serial.println(b);
  Serial.println(c);

  int m = mini(a, b, c);
  Serial.print("Minimum= ");
  Serial.println(m);
}

void loop() {
  // put your main code here, to run repeatedly:
}

int mini(int a, int b, int c) {


  if (a <= b && a <= c) {
    int mini = a;
  } else if (b <= a && b <= c) {
    int mini = b;
  } else {
    int mini = c;
  }
}
