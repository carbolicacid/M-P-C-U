#define SW1 9
#define SW2 10
#define LED 5

void setup() {
  Serial.begin(9600);
  pinMode(SW1, INPUT);
  pinMode(SW2, INPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  while (!Serial.available());
  int n = Serial.parseInt();

  while (!Serial.available()) {
    int a = digitalRead(SW1);
    int b = digitalRead(SW2);

    switch (n) {
      case 1: digitalWrite(LED, a & b); 
      break;
      case 2: digitalWrite(LED, a | b); 
      break;
      case 3: digitalWrite(LED, !(a & b)); 
      break;
      case 4: digitalWrite(LED, !(a | b)); 
      break;
      case 5: digitalWrite(LED, a ^ b); 
      break;
      case 6: digitalWrite(LED, !(a ^ b)); 
      break;
      
    }
  }
}
