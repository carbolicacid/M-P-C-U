void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  int a, b;

  
  while (Serial.available() == 0) {}
  a = Serial.parseInt();
  Serial.print("First Input: ");
  Serial.println(a);


  
  while (Serial.available() == 0) {}
  b = Serial.parseInt();
  Serial.print("Second Input: ");
  Serial.println(b);


  Serial.print("Enter operation(Add,Division,Multiplication): ");
  while (Serial.available() == 0) {}
  String n = Serial.readString();
  

  if (n == "Add") {
    int output = (a + b);
    Serial.print("output = ");
    Serial.print(output);

  }


  else if (n == "Division") {
    int output = (a / b);
    Serial.print("output = ");
    Serial.print(output);

  }


  else if (n == "Multiplication") {
    int output = (a * b);
    Serial.print("output = ");
    Serial.print(output);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
}
