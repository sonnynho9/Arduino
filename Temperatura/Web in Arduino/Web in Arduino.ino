/*
 Projeto: Temperatura
 Autor: Edival Gon�alves
*/
#include <DHT.h> //Biblioteca do Sensor DHT 11
#include <LiquidCrystal.h> //Biblioteca da Tela LCD 16x2
#include <Ethernet.h> //Biblioteca do Ethernet Shield

#define DHTPIN A1 //Pino do Sensor DHT11 na porta Anal�gica 01
#define DHTTYPE DHT11 //Definindo o tipo de sensor utilizado DHT11
DHT dht(DHTPIN, DHTTYPE);
const int rs = 12, en, 11, D4 = 5, D5 = 4, D6 = 3, D7 = 2;
LiquidCrystal lcd(rs, en, D4, D5, D6, D7);

//Defini��o de IP, Mask e Gateway
byte mac[] = {
	0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192.168.0.217); //Endere�o IP
IPAddress gateway(192.168.0.1); //Endere�o Gateway
IPAddress subnet(255.255.255.0); //Define a mascara de rede

EthernetServer(80); //Inicializa o servidor web na porta 80

 
void setup() {
	Ethernet.begin(mac, ip, gateway, subnet); //Inicializa a interface de rede
	server.begin(); //Inicializa o Servidor Web
	dht.begin();
	lcd.begin(16, 2); //Escolhendo o numero de colunas e linha no LCD
	lcd.print("TestDHT"); //Teste do DHT

	
}

void loop() {

	//Aguardando conex�o do Browser
	EthernetClient client = server.available();
	if (client) {
		boolean currentLineIsBlank = true;
		while (client.connected()) {
			if (client.available())
				char c = client.read();
			Serial.write(c);
			if (c == 'n' && currentLineIsBlank) {
				//Aqui come�a a p�gina web
				client.println("HTTP/1.1 200 0K");
				client.println("Content-Type: text/html/CSS/JavaScript");
				client.println("Connection: close");
				client.println("Refresh: 2"); //Recarrega a p�gina a cada 2 segundos
				client.println();
				client.println("<!DOCTUPE HTML");
				client.println(" <html> ");
				client.println("<head>");
				client.println("<meta charset="utf - 8" />);
				client.println("<Title>Controlando a temperatura</title>");


			}
		}
	}
}
