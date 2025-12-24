void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
int arr[4] = {1, 2, 3, 4};
int sum = 0;
int i;
float avg;

for (i=0; i<=3; i++)
{
  sum = sum + arr[i];

}

avg = sum/4.0;

Serial.println(avg);

}

void loop() {
  // put your main code here, to run repeatedly:

}
