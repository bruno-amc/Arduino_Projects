/*
MATERIAL LIST:
⚫ 1 NTC temperature sensor; // 1 Sensor de temperatura NTC;
⚫ Arduino UNO + USB cable; // Arduino UNO + cabo USB;
⚫ 1 resistor of 10k ohms; // 1 resistor de 10k ohms;
⚫ 1 resistor of 330 OHM for the LED;
⚫ 1 LED;
⚫ Breadboard; // Protoboard;
⚫ Jumper wires for breadboard connections; // Jumpers para conexão no protoboard;
*/
//Connect the DIGITAL 13 OUTPUT to the 330 ohm resistor and then to the anode of the LED. 
// Connect the ground (-) output to the LED cathode.

#define ledPin 13 // Define o pino digital D13 para o controle do LED
#define temperaturaAcionamentoLED 25 //temperatura a partir da qual o LED liga

#define Vin 5.0 // Defines the input voltage constant as 5.0V 
               // Define a constante de tensão de entrada como 5.0V

#define T0 298.15 // Defines the reference temperature constant as 298.15 Kelvin (25°C) 
                 // Define a constante de temperatura de referência como 298,15 Kelvin (25°C)

#define Rt 10000 // Resistor used in the voltage divider circuit 
                 // Resistor usado no circuito divisor de tensão

#define R0 10000 // Initial resistance value of the NTC at 25°C 
                 // Valor inicial de resistência do NTC a 25°C

#define T1 273.15 // Temperature in Kelvin at 0°C (from datasheet) 
                 // Temperatura em Kelvin a 0°C (do datasheet)

#define T2 373.15 // Temperature in Kelvin at 100°C (from datasheet) 
                 // Temperatura em Kelvin a 100°C (do datasheet)

#define RT1 35563 // Resistance value of the NTC at T1 (0°C) 
                  // Valor de resistência do NTC em T1 (0°C)

#define RT2 549 // Resistance value of the NTC at T2 (100°C) 
                // Valor de resistência do NTC em T2 (100°C)

float beta = 0.0; // Beta coefficient, calculated from the NTC characteristics 
                  // Coeficiente Beta, calculado a partir das características do NTC

float Rinf = 0.0; // R∞ (infinity resistance), calculated parameter for the NTC 
                  // R∞ (resistência infinita), parâmetro calculado para o NTC

float TempKelvin = 0.0; // Variable to store the temperature in Kelvin 
                        // Variável para armazenar a temperatura em Kelvin

float TempCelsius = 0.0; // Variable to store the temperature in Celsius 
                         // Variável para armazenar a temperatura em Celsius

float Vout = 0.0; // Voltage output from the voltage divider, read from A0 
                  // Tensão de saída do divisor de tensão, lida a partir de A0

float Rout = 0.0; // Calculated resistance of the NTC sensor 
                  // Resistência calculada do sensor NTC

void setup() {
  Serial.begin(9600); // Initializes serial communication at 9600 baud rate for the serial monitor 
                      // Inicializa a comunicação serial a 9600 bps para o monitor serial

  beta = (log(RT1 / RT2)) / ((1 / T1) - (1 / T2)); // Calculates the Beta coefficient based on datasheet values 
                                                   // Calcula o coeficiente Beta com base nos valores do datasheet

  Rinf = R0 * exp(-beta / T0); // Calculates R∞ using the Beta coefficient and reference temperature 
                               // Calcula R∞ usando o coeficiente Beta e a temperatura de referência

  delay(100); // Adds a delay of 100 milliseconds to ensure the setup is complete before entering the loop 
              // Adiciona um atraso de 100 milissegundos para garantir que a configuração esteja completa antes de entrar no loop
}

void loop() {
  Vout = Vin * ((float)(analogRead(0)) / 1024.0); // Reads the analog value from pin A0 and calculates the output voltage 
                                                  // Lê o valor analógico do pino A0 e calcula a tensão de saída

  Rout = (Rt * Vout / (Vin - Vout)); // Calculates the resistance of the NTC sensor based on the voltage divider formula 
                                     // Calcula a resistência do sensor NTC com base na fórmula do divisor de tensão

  TempKelvin = (beta / log(Rout / Rinf)); // Calculates the temperature in Kelvin using the NTC formula 
                                          // Calcula a temperatura em Kelvin usando a fórmula do NTC

  TempCelsius = TempKelvin - 273.15; // Converts the temperature from Kelvin to Celsius 
                                     // Converte a temperatura de Kelvin para Celsius

  if (TempCelsius > temperaturaAcionamentoLED){
    digitalWrite(ledPin, HIGH); // Liga o led aplicando 5V ao pino 13 do arduino se a temperatura em celsius for maior do que a temp definida para ligar o led
  } else {
    digitalWrite(ledPin, LOW); // desliga o LED aplicando 0V ao pino 13 do arduino
  }


  Serial.print("Temperature in Celsius: "); // Prints the label for temperature in Celsius to the serial monitor 
                                            // Imprime o rótulo da temperatura em Celsius no monitor serial

  Serial.print(TempCelsius); // Prints the calculated temperature in Celsius 
                             // Imprime a temperatura calculada em Celsius

  Serial.print(" Temperature in Kelvin: "); // Prints the label for temperature in Kelvin to the serial monitor 
                                            // Imprime o rótulo da temperatura em Kelvin no monitor serial

  Serial.println(TempKelvin); // Prints the calculated temperature in Kelvin and moves to the next line 
                              // Imprime a temperatura calculada em Kelvin e pula para a próxima linha
  Serial.println(analogRead(0));
 float tensaoLida = ((float)(analogRead(0)) / 1024.0)*5; //converte a leitura analógica para Volts
 Serial.println(tensaoLida);

  delay(500); // Adds a delay of 500 milliseconds before the next loop iteration 
              // Adiciona um atraso de 500 milissegundos antes da próxima iteração do loop
}
