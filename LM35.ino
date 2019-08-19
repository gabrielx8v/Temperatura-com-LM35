#define LM35PIN A0 // define o pino de leitura do LM35

float temperatura; // Variável que armazenará a temperatura medida.

void setup() {
  // inicia comunicação com o monitor serial.
  Serial.begin(9600);
}

void loop() {
  // le os dados do LM35, envia para a funcao e armazena o retorno na variavel temperatura.
  temperatura = mapf(analogRead(LM35PIN),0,1023,0,500);

  // exibe a temperatura coletada e calculada.
  Serial.print("Temperatura LM35: ");
  Serial.println(temperatura);

  delay(1000); // 1 segundo de delay a cada leitura.
}

// função para ajusatar escalas.
double mapf(double val, double in_min, double in_max, double out_min, double out_max) {
    return (val - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
