void setup() {

  Serial.begin(9600);
  Serial.print("Enter input Radius(r): "); //string input
  while (Serial.available()==0) //wait as long as there is no data
  {

  }
  float r = Serial.parseFloat();
  Serial.println(r);
  
  float s = area(r);
  Serial.print("Area=");
  Serial.print(s);


}

void loop() {
  
}
float area(float r)
  {
    float a = PI*r*r;
    return a;
  }
