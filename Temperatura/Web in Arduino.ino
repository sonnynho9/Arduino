/*
 Projeto: Temperatura
 Autor: Edival Gonçalves
*/
#include <DHT.h> //Biblioteca do Sensor DHT 11
#include <LiquidCrystal.h> //Biblioteca da Tela LCD 16x2
#include <Ethernet.h> //Biblioteca do Ethernet Shield

#define DHTPIN A1 //Pino do Sensor DHT11 na porta Analógica 01
#define DHTTYPE DHT11 //Definindo o tipo de sensor utilizado DHT11
DHT dht(DHTPIN, DHTTYPE);
const int rs = 12,

 
void setup() {

}

// the loop function runs over and over again until power down or reset
void loop() {
  
}
