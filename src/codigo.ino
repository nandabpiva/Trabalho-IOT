Programação pelo IDE do Arduino:
// Pinos
#define LDRpin A0
#define PIRpin 7
#define RELEpin 10
// Intervalo em que o relê permanece ligado após movimento
#define INTERVALO 7000
// Variáveis
unsigned long timer = 0; // Variável para contagem de tempo
boolean estado = HIGH; // Variável para alteração de estado do relê (HIGH = relê desligado)
boolean desligado = true; // Variável responsável para indicar se a luz foi ligada pelo Arduino
void setup() {
  // Declaração do tipo de pino (entrada/saída)
  pinMode (LDRpin, INPUT);
  pinMode (PIRpin, INPUT);
  pinMode (RELEpin, OUTPUT);
  digitalWrite (RELEpin, estado);
}
void loop() {
  if (digitalRead (PIRpin) == HIGH) {
    timer = millis () + INTERVALO; // Função millis() retorna o valor em milissegundos em que a placa está ligada é somada ao intervalo na variável timer
    if (digitalRead (LDRpin) == HIGH) {
      estado = !estado; // Muda o estado do relê, até conseguir iluminação no ambiente
      digitalWrite (RELEpin, estado);
      delay (500); // Aguarda acionamento do relê/lâmpada
      desligado = false;
    }
  }
  // Muda o estado do relê após o tempo estourado caso tenha sido ligado anteriormente pelo Arduino
  if (millis () >= timer && desligado == false) {
    estado = !estado;
    digitalWrite (RELEpin,estado);
    desligado = true;
  }
}
