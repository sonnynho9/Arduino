/*
 Projeto: Temperatura
 Autor: Edival Gonçalves
*/
#include <DHT.h> //Biblioteca do Sensor DHT 11
#include <LiquidCrystal.h> //Biblioteca da Tela LCD 16x2
#include <Ethernet.h> //Biblioteca do Ethernet 
#include <SPI.h> //Biblioteca de Comunicação Ethernet e Arduino

#define DHTPIN A1 //Pino do Sensor DHT11 na porta Analógica 01
#define DHTTYPE DHT11 //Definindo o tipo de sensor utilizado DHT11
DHT dht(DHTPIN, DHTTYPE);
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//Definição de IP, Mask e Gateway
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192,168,0,88); //Endereço IP
IPAddress gateway(192,168,0,1); //Endereço Gateway
IPAddress subnet(255,255,255,0); //Define a mascara de rede

EthernetServer server(80); //Inicializa o servidor web na porta 80

 
void setup() {
  Ethernet.begin(mac, ip, gateway, subnet); //Inicializa a interface de rede
  server.begin(); //Inicializa o Servidor Web
  dht.begin();
  lcd.begin(16, 2); //Escolhendo o numero de colunas e linha no LCD
  lcd.print("TestDHT"); //Teste do DHT

  
}

void loop() {

  //Aguardando conexão do Browser
  EthernetClient client = server.available();
  if (client) 
  {
    boolean currentLineIsBlank = true;
    while (client.connected())
    {
      if (client.available())
      {
        char c = client.read();
        if (client == '\n' && currentLineIsBlank);
      }
        //Aqui começa a página web
        client.println("HTTP/1.1 200 0K");
        client.println("Content-Type: text/css");
        client.println("Connection: close");
        client.println("Refresh: 2"); //Recarrega a página a cada 2 segundos
        client.println();
        client.println("<!DOCTYPE HTML>");
        client.println(" <html> ");
        client.println("<head>");
        client.println("<Title>Controlando a temperatura</title>");
        client.println("</head)");
        client.println("body { background-color: #00ffff;");

      }
    }
  }

