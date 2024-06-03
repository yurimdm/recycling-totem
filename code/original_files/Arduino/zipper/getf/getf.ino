#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "christian";
const char* password = "12345678";
int id = 2;
String url = "http://envexpo.000webhostapp.com/app/fromsuspendj.php?id=";
int sendstate = 0;
unsigned long tempo2; //tempo de intervalo de cada requisição
int ideais = 1;
String url2 = "http://envexpo.000webhostapp.com/app/upgrade.php?id=";
String inString = "";
int inStringint;



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

  inString = "";
  if (Serial.available() > 0)
  {
    joseph = "";
    inString = "";
    while (Serial.available() > 0)
    {
      char joestar = Serial.read();

      if (joestar != '\n' && joestar != '\r') joseph.concat(joestar); //deveria transformar serialread em string
      delay (1);
    }
    inString = joseph.substring(0, 5);
  }


  if (WiFi.status() == WL_CONNECTED && millis() - (unsigned long) tempo2 >= 2000) { //so faz a cada 2 seg
    HTTPClient http;  //Declare an object of class HTTPClient
    HTTPClient clean;
    HTTPClient cleanb;
    HTTPClient axl;

    if (inString.toInt() > 0) {
      //Serial.println(inString);
      inStringint = inString.toInt();
      //Serial.println(inStringint);
      String ideaisplus = String(ideais);
      String tempoplus = String(inStringint);
      String roses = url2 + ideaisplus + "&value=" + tempoplus;

      axl.begin(roses);  //Specify request destination
      int slash = axl.GET();

      if (slash > 0) { //Check the returning code

        String payload = axl.getString(); 
        //sendstate = payload.toInt();
        //Serial.println(" ");
        //Serial.println(payload);
        // Serial.write(sendstate);
      }
    }

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
        cleanb.end();
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


/*


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
      //Serial.print("inString=");
      //Serial.println(inString);
      HTTPClient axl;  //Declare an object of class HTTPClient


      // if you get a newline, print the string, then the string's value:

        inString = inString.substring(0,4);
        inStringint = inString.toInt();
        String ideaisplus = String(ideais);
        String tempoplus = String(inStringint);
        String roses = url + idplus + "&value=" + tempoplus;

        axl.begin(urlplus);  //Specify request destination
        int httpCode = http.GET();                                                                  //Send the request

        if (httpCode > 0) { //Check the returning code

         String payload = http.getString();   //Get the request response payload
         //sendstate = payload.toInt();
         //Serial.println(" ");
         //Serial.println(payload);                     //Print the response payload
         // Serial.write(sendstate);
        }

        http.end();   //Close connection


      // clear the string for new input:
      inString = "";
    }

  }
  }
*/
