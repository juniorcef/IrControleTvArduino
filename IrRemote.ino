/* Programa: Controlando o Arduino com Controle Remoto
   Autor: Domingos R S Jr

   vermelho: E0E036C9
   verde: E0E028D7
   azul: E0E06897
   apaga (EXIT): E0E0B44B
   acende tudo OK - E0E016E9
   apaga tudo Sair (POWER) - E0E040BF 
   
    */
  

#include <IRremote.h>

int pinoRecepitorIR = 11;
int valorRecebido;
int ledVermelho = 7;
int ledVerde = 6;
int ledAzul = 5;

// Definindo o código de cada ação que deverá ser realizada
int AcendeVermelho = 0xE0E036C9;
int ApagaVermelho = 0xE0E0B44B;
int AcendeVerde = 0xE0E028D7;
int ApagaVerde = 0xE0E0B44B;
int AcendeAzul = 0xE0E06897;
int ApagaAzul = 0xE0E0B44B;
int AcendeTudo = 0xE0E016E9;
int ApagaTudo = 0xE0E040BF;

IRrecv irrecv(pinoRecepitorIR);
decode_results results;

void setup()
{
pinMode(ledVermelho, OUTPUT); // Definindo os pinos dos leds como saida
pinMode(ledVerde, OUTPUT);
pinMode(ledAzul, OUTPUT);
Serial.begin(9600); // Iniciando o Monitor Serial da IDE
irrecv.enableIRIn(); // Inicializa o receptor IR do controle remoto
}

void loop()
{
if (irrecv.decode(&results)) // Executa caso receba algum códico
{
Serial.print("Valor lido : ");
Serial.println(results.value, HEX);
valorRecebido = (results.value);

if (valorRecebido == AcendeVermelho) //Verifica se a tecla 1 foi acionada
{
digitalWrite(ledVermelho, HIGH); //Acende o led vermelho
}
if (valorRecebido == ApagaVermelho) //Verifica se a tecla 2 foi acionada
{
digitalWrite(ledVermelho, LOW); //Apaga o led vermelho
}
if (valorRecebido == AcendeVerde) //Verifica se a tecla 4 foi acionada
{
digitalWrite(ledVerde, HIGH); //Acende o led verde
}
if (valorRecebido == ApagaVerde) //Verifica se a tecla 5 foi acionada
{
digitalWrite(ledVerde, LOW); //Apaga o led verde
}
if (valorRecebido == AcendeAzul) //Verifica se a tecla 7 foi acionada
{
digitalWrite(ledAzul, HIGH); //Acende o led azul
}
if (valorRecebido == ApagaAzul) //Verifica se a tecla 8 foi acionada
{
digitalWrite(ledAzul, LOW); //Apaga o led verde
}
if (valorRecebido == AcendeTudo) //Verifica se a tecla "OK" foi acionada
{
digitalWrite(ledVermelho, HIGH); //Acende todos os leds
digitalWrite(ledVerde, HIGH);
digitalWrite(ledAzul, HIGH);
}
if (valorRecebido == ApagaTudo) //Verifica se a tecla "Sair" foi acionada
{
digitalWrite(ledVermelho, LOW); //Apaga todos os leds
digitalWrite(ledVerde, LOW);
digitalWrite(ledAzul, LOW);
}
irrecv.resume(); //Le o valor da próxima tecla pressionada
}
}