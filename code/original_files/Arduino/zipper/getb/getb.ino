#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "funcionaesp8266";
const char* password = "senha1234";
int id = 1;
String url = "http://envexpo.000webhostapp.com/app/upgrade.php?id=";
int sendstate = 0;
String inString = "";
int inStringint;

void setup () {

  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {

    delay(1000);
    Serial.println(" ");
    Serial.println("Connecting..");

  }

}

void loop() {

  if (WiFi.status() == WL_CONNECTED) { //Check WiFi connection status

    if (Serial.available() > 0)
    {
      inString = "";
      while (Serial.available() > 0)
      {
        char tempo = Serial.read();

        if (tempo != '\n' && tempo != '\r') inString.concat(tempo);
        delay (1);
      }
      Serial.print("inString=");
      Serial.println(inString);
      HTTPClient http;  //Declare an object of class HTTPClient

      
      // if you get a newline, print the string, then the string's value:
      
      //  HTTPClient http;  //Declare an object of class HTTPClient
        
        inStringint = inString.toInt()%100000;
        String idplus = String(id);
        String tempoplus = String(inStringint);
        String urlplus = url + idplus + "&value=" + tempoplus;

        http.begin(urlplus);  //Specify request destination
        int httpCode = http.GET();                                                                  //Send the request

        if (httpCode > 0) { //Check the returning code

          String payload = http.getString();   //Get the request response payload
          sendstate = payload.toInt();
          Serial.println(" ");
          Serial.println(payload);                     //Print the response payload
          Serial.write(sendstate);
        }

        http.end();   //Close connection


      // clear the string for new input:
      inString = "";
    }

  }
  delay(5000);    //Send a request every 5 seconds
}
