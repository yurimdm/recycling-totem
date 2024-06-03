String qqcoisa="";
String inString = "";
int inStringint;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // Read serial input:
  while (Serial.available() > 0) {
    int inChar = Serial.read();
    Serial.print("inChar=");
    Serial.println(inChar);
    if (isDigit(inChar)) {
      // convert the incoming byte to a char and add it to the string:
      inString += (char)inChar;
      Serial.println("");
    }
    // if you get a newline, print the string, then the string's value:
    if (inChar == '\n') {
      inStringint = inString.toInt();
      Serial.print("Destinatário ");
      Serial.println(inStringint);

      // clear the string for new input:
      inString = "";
    }
  }
}
