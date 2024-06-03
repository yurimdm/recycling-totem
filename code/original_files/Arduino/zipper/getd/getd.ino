#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "funcionaesp8266";
const char* password = "senha1234";
int id = 2;
String url = "http://envexpo.000webhostapp.com/app/fromsuspendj.php?id=";
int sendstate = 0;
unsigned long tempo2; //tempo de intervalo de cada requisição

String joseph;

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

  if (Serial.available() > 0)
  {
    joseph = "";
    while (Serial.available() > 0)
    {
      char joestar = Serial.read();

      if (joestar != '\n' && joestar != '\r') joseph.concat(joestar); //deveria transformar serialread em string
      delay (1);
    } //informação atribuida a joseph não está dando concat concat
  }

 
  if (WiFi.status() == WL_CONNECTED && millis() - (unsigned long) tempo2 >= 2000) { //so faz a cada 2 seg
    HTTPClient http;  //Declare an object of class HTTPClient
    HTTPClient clean;
    HTTPClient cleanb;

    // 10 digitos numericos == 2351201011 5 digitos iniciais 

    int valur;// valor de se a porta está ocupada
    for (int jotaro = 2 ; jotaro <= 3; jotaro++) { //pra atribuir a ambos os usb_oc de uma so vez
      if (jotaro == 2) { //define qual informacao de serial read vai pra qual variavel, sendo cada variavel respectiva a uma porta
        valur = (joseph.toInt() / 10) % 10;
      }
      else {
        valur = joseph.toInt() % 10;
      }

      //Serial.print("joseph:");
      //Serial.println(joseph);
      //Serial.print("valur:");
      //Serial.println(valur);
      String valure = String(valur);
      String idplusgg = String(jotaro + 2);
      String urlcleanb = "http://envexpo.000webhostapp.com/app/upgrade.php?id=" + idplusgg + "&value=" + valure;
      cleanb.begin(urlcleanb);

      if (joseph.length() > 0) {
        int httpCodeb = cleanb.GET(); //requisição responsavel pelo usb_ocupado
      }
    }

    if (id == 2) {
      id = 3;
    } else {
      id = 2;
    }


    String idplus = String(id);
    String tempoplus = "";
    //String urlplus = url + idplus + "&value=" + tempoplus;
    String urlplus = url + idplus;

    http.begin(urlplus);
    int httpCode = http.GET();  //requisição responsável por pegar o tempo do banco de dados

    if (httpCode > 0) { //Check the returning code

      String payload = http.getString();
      int stradivarius = payload.toInt();
      if (stradivarius > 0) {
        if (payload.toInt() <= 9) {
          Serial.print("0");
        }
        Serial.print(payload);//printa o tempo
        if (id == 3) { //printa porta de respectivo tempo
          Serial.println("2");
        } else {
          Serial.println("1");
        }
        String urlclean = "http://envexpo.000webhostapp.com/app/upgrade.php?id=" + idplus + "&value=0";
        clean.begin(urlclean);
        int httpCodea = clean.GET();
        //Serial.println(clean.getString());

      }


    }


    http.end();


  }


  //delay(500);

}
