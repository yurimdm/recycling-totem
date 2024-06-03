#include "SoftwareSerial.h"

String inString = "";    // string to hold input
int inStringint;

SoftwareSerial serial1(5,4);

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(115200);
  serial1.begin(115200);
  pinMode(13,OUTPUT);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  // send an intro:
  Serial.println("\n\nString toInt():");
  Serial.println();
}

void loop() {
  // Read serial input:
  while (serial1.available() > 0) {
    int inChar = serial1.read();
    if (isDigit(inChar)) {
      // convert the incoming byte to a char and add it to the string:
      inString += (char)inChar;
    }
    // if you get a newline, print the string, then the string's value:
    if (inChar == '\n') {
      inStringint = inString.toInt();
      if(inStringint==1){
        digitalWrite(13,1);
      }
      if(inStringint==0){
        digitalWrite(13,0);
      }
      Serial.print("Value:");
      Serial.println(inStringint);
      Serial.print("String: ");
      Serial.println(inString);
      // clear the string for new input:
      inString = "";
    }
  }
}
