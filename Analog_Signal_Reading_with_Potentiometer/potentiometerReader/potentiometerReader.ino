#define sensorPin A0 // Define 'sensorPin' como a entrada analógica A0, onde o potenciômetro está conectado

int sensorValue = 0; // Declara uma variável do tipo inteiro chamada 'sensorValue' e a inicializa com 0, que armazenará o valor lido da entrada analógica

float voltage; // Declara uma variável do tipo float chamada 'voltage', que armazenará o valor da tensão calculada com base na leitura do sensor

void setup() {
  Serial.begin(9600); // Inicializa a comunicação serial com o monitor serial a uma velocidade de 9600 bits por segundo (bps)
  delay(100); // Introduz um atraso de 100 milissegundos para garantir que tudo esteja configurado corretamente antes de iniciar o loop
}

void loop() {
  sensorValue = analogRead(sensorPin); // Lê o valor da entrada analógica A0 (valor entre 0 e 1023) e armazena em 'sensorValue'

  // Converte o valor lido do potenciômetro (sensorValue) para uma tensão
  // O valor máximo lido (1023) corresponde à tensão de referência (5V) e o mínimo (0) corresponde a 0V
  voltage = sensorValue * (5.0 / 1024); // Calcula a tensão em volts com base no valor lido: (5V/1024) = 0.00488V por unidade de sensorValue

  Serial.print("Tensão do potenciometro: "); // Imprime no monitor serial a mensagem "Tensão do potenciômetro: "
  Serial.print(voltage); // Imprime o valor da tensão calculada, seguida da mensagem acima

  Serial.print(" Valor: "); // Imprime no monitor serial a mensagem " Valor: "
  Serial.println(sensorValue); // Imprime o valor lido do sensor (sensorValue), seguido de uma nova linha

  delay(500); // Introduz um atraso de 500 milissegundos antes de repetir o loop, para que a leitura e a impressão no monitor serial ocorram a cada meio segundo
}