#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
 
const char* ssid = "funcionaesp8266";
const char* password = "senha1234";
int id = 1;
String url = "http://envexpo.000webhostapp.com/app/upgrade.php?id=";
int sendstate = 0;
int ttime=24;


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
 
HTTPClient http;  //Declare an object of class HTTPClient

String idplus = String(id);
String tempoplus = String(ttime);
String urlplus = url + idplus + "&value=" + tempoplus;
 
http.begin(urlplus);  //Specify request destination
int httpCode = http.GET();                                                                  //Send the request
 
if (httpCode > 0) { //Check the returning code
 
String payload = http.getString();   //Get the request response payload
payload.toInt();
Serial.println(" ");
Serial.println(payload);                     //Print the response payload
 
}
 
http.end();   //Close connection
 
}
 
delay(30000);    //Send a request every 30 seconds
 
}
