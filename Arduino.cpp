// Incluir la biblioteca de comunicación serial
#include <SerialComm.h>

// Definir los pines de entrada
const int inputPins[] = {A0, A1, A2, A3, A4, A5, A6, A7};

// Crear una instancia de la comunicación serial
SerialComm serialComm;

void setup() {
  // Iniciar la comunicación serial
  Serial.begin(9600);

  // Configurar los pines de entrada
  for (int i = 0; i < 8; i++) {
    pinMode(inputPins[i], INPUT);
  }

  // Inicializar la comunicación serial con XAMPP
  serialComm.begin("COM3", 9600); // Reemplaza "COM3" con el puerto serie correcto

  // Esperar a que la conexión se establezca
  while (!serialComm.isConnected()) {
    delay(100);
  }
}

void loop() {
  // Leer los valores de los pines y convertirlos en un número decimal
  int decimalNumber = 0;
  for (int i = 0; i < 8; i++) {
    int bitValue = analogRead(inputPins[i]) / 4; // Mapear el rango de 0-1023 a 0-255
    decimalNumber += bitValue << i;
  }

  // Enviar el número decimal a través de la comunicación serial
  serialComm.send(decimalNumber);

  delay(1000);
}

