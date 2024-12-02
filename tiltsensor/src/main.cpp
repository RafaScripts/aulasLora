#include <Arduino.h>
#include <DHT.h>

// Definir o tipo de DHT e o pino
#define DHTPIN 35        // Pino de dados do DHT11 (pode mudar conforme sua conexão)
#define DHTTYPE DHT11   // DHT 11

// Cria o objeto DHT
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // Inicializa comunicação serial
  Serial.begin(115200);
  
  // Inicializa o sensor DHT
  dht.begin();
  
  Serial.println("Sensor DHT11 Inicializado!");
}

void loop() {
  // Aguarda 2 segundos entre as medições
  delay(2000);

  // Leitura da umidade
  float umidade = dht.readHumidity();
  
  // Leitura da temperatura em Celsius
  float temperatura = dht.readTemperature();

  // Verifica se alguma leitura falhou
  if (isnan(umidade) || isnan(temperatura)) {
    Serial.println("Falha na leitura do sensor DHT!");
    return;
  }

  // Imprime as informações
  Serial.print("Umidade: ");
  Serial.print(umidade);
  Serial.print(" %\t");
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" °C");

  // Opcional: Cálculo de índice de calor
  float indiceCalor = dht.computeHeatIndex(temperatura, umidade, false);
  Serial.print("Índice de Calor: ");
  Serial.print(indiceCalor);
  Serial.println(" °C");
}