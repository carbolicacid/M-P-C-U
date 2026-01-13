#define SW1 6
#define SW2 5
#define SW3 4
void setup() {
  // put your setup code here, to run once:
  DDRD = 0b00000000;
  DDRB = 0b000011;
  Serial.begin(9600);
  Serial.println("Red LED for difference and Green LED for borrow.");
}
void loop() {
  // put your main code here, to run repeatedly:
  int a = digitalRead(SW1);
  int b = digitalRead(SW2);
  int c = digitalRead(SW3);
  int in[] = { a, b, c };
  int num = 0;
  for (int i = 0; i < 3; i++) {
    num += in[2 - i] << i;
  }
  switch (num) {
    case 0:
      PORTB = 0b000000;
      break;
    case 1:
      PORTB = 0b000011;
      break;
    case 2:
      PORTB = 0b000011;
      break;
    case 3:
      PORTB = 0b000001;
      break;
    case 4:
      PORTB = 0b000010;
      break;
    case 5:
      PORTB = 0b000000;
      break;
    case 6:
      PORTB = 0b000000;
      break;
    case 7:
      PORTB = 0b000011;
      break;
    default:
      Serial.println("Invalid case.");
  }
}