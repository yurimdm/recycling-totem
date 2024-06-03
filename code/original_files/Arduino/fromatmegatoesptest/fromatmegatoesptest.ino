int qqcoisa = 42;
char b1;
char b2;
char b3;
char b4;
char b5;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  b1 = (qqcoisa%10)+48;
  b2 = ((qqcoisa/10)%10)+48;
  b3 = ((qqcoisa/100)%10)+48;
  b4 = ((qqcoisa/1000)%10)+48;
  b5 = ((qqcoisa/10000)%10)+48;
  Serial.write(b5);
  Serial.write(b4);
  Serial.write(b3);
  Serial.write(b2);
  Serial.write(b1);
  Serial.write("\n");
  delay(2000);
}
