#include <DHT.h> //Biblioteca do Sensor DHT11
#include <LiquidCrystal.h> //Biblioteca da tela LCD 16x2


#define DHTPIN A1 //Pino do Sensor DHT11 na porta Analógica 1
#define DHTTYPE DHT11 //Define o tipo de sensor utilizado DHT11
DHT dht(DHTPIN, DHTTYPE);
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


void setup() {
  lcd.begin(16, 2); //Instalando o numero de colunas e linhas no LCD
  lcd.print("Teste do DHT!");
  dht.begin();
}

void loop() {
  lcd.setCursor(0, 1); //Definindo o cursor do LCD na coluna 0, linha 1
  float t = dht.readTemperature(); //Leitura da Temperatura de 2 em 2 segundos
  if (isnan(t))
  {
    lcd.print("O sensor tá com problema");
  }
  else
  {
    lcd.print ("A temperatura atual é: ");
    lcd.print(t);
    lcd.print(" *C");
  }
  
}
