#include <Arduino.h>
#include <SPI.h>

// Definição do pino
#define VIBRATION_SENSOR 34

void setup() {
  // Inicializa a comunicação serial
  Serial.begin(115200);
  pinMode(VIBRATION_SENSOR, INPUT);
}

void loop() {
  Serial.println(digitalRead(VIBRATION_SENSOR));
  delay(3000);
}


/*#include <LoRa.h>
#include <Wire.h>
#include <SSD1306Wire.h>

// Pinos do LoRa
const int csPin = 18;
const int resetePin = 23;
const int irqPin = 26;

// Configurações LoRa
const long frequencia = 915E6;
const long bandwidth = 125E3;
const int SF = 7;
const int CR = 5;

// Pino do LED
const int pirPin = 23;

int acionamento;

// Configuração do Display
SSD1306Wire display(0x3c, SDA, SCL);

void inicializarDisplay() {
  display.init();
  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_16);
  display.setTextAlignment(TEXT_ALIGN_CENTER);
  display.clear();
  display.drawString(display.getWidth() / 2, display.getHeight() / 2, "LoRa Iniciado");
  display.display();
}

void exibirMensagemDisplay(const String &texto, int yOffset = 0) {
  display.clear();
  display.drawString(display.getWidth() / 2, (display.getHeight() - 16) / 2 + yOffset, texto);
  display.display();
}


void setup() {
  Serial.begin(115200);

  pinMode(pirPin, INPUT);   //Define pino sensor como entrada
  
  inicializarDisplay();
  
  LoRa.setPins(csPin, resetePin, irqPin);
  
  if (!LoRa.begin(frequencia)) {
    Serial.println("Falha ao iniciar LoRa!");
    exibirMensagemDisplay("Falha LoRa", -10);
    while (1);
  }
  
  LoRa.setSpreadingFactor(SF);
  LoRa.setSignalBandwidth(bandwidth);
  LoRa.setCodingRate4(CR);
  
  Serial.println("LoRa Transceptor Inicializado");
  exibirMensagemDisplay("LoRa Pronto", -10);
}

void loop() {
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    String receivedMessage = "";
    while (LoRa.available()) {
      receivedMessage += (char)LoRa.read();
    }
    
    Serial.println("Recebido: " + receivedMessage);
    Serial.println("RSSI: " + String(LoRa.packetRssi()));
    
    exibirMensagemDisplay("Rx: " + receivedMessage);
    
  }

  static unsigned long ultimoEnvio = 0;
  if (millis() - ultimoEnvio > 5000) {
    String mensagem = "Olá LoRa! Tempo: " + String(millis());
    
    LoRa.beginPacket();
    LoRa.print(mensagem);
    LoRa.endPacket();
    
    Serial.println("Enviando: " + mensagem);
    exibirMensagemDisplay("Tx: " + mensagem);
    
    delay(50);

    ultimoEnvio = millis();
  }

  acionamento = digitalRead(pirPin); //Le o valor do sensor PIR
  Serial.println(digitalRead(pirPin));
  if (acionamento == LOW)  //Sem movimento, mantem led azul ligado
    {
      Serial.println("Sem movimento");
    }else  //Caso seja detectado um movimento, aciona o led vermelho
    {
      Serial.println("Movimento detectado");
    }
  delay(1000);
}*/