int button = 7;
int bstate = 0;

void setup() {
  Serial.begin(115200);
  pinMode(button,0);
}

void loop() {
  bstate = digitalRead(button);
  if(bstate){
    Serial.println("On");
  }
  else{
    Serial.println("Off");
  }
  delay(2000);
}
