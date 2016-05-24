//    #                                                     ######                                            
//   # #   #####  #####  #    # # #    #  ####              #     #  ####  #####   ####  #      ######  ####  
//  #   #  #    # #    # #    # # ##   # #    #             #     # #    # #    # #    # #      #      #    # 
// #     # #    # #    # #    # # # #  # #    #    #####    ######  #    # #    # #    # #      #####  #    # 
// ####### #####  #    # #    # # #  # # #    #             #   #   #    # #    # #    # #      #      #    # 
// #     # #   #  #    # #    # # #   ## #    #             #    #  #    # #    # #    # #      #      #    # 
// #     # #    # #####   ####  # #    #  ####              #     #  ####  #####   ####  ###### #       ####  

// Inclui a biblioteca para utilizar o LCD.
#include  <LiquidCrystal.h>

// Define o pino A0 como "sensor"
#define sensor 0

// Variavel para ler o sinal do pino do Arduino
int  Ventrada;

// Vari�vel que recebe o valor convertido para temperatura.
float  Temperatura;

/*
  Esta funcao acima declara quais os pinos do Arduino serao utilizados para o controle do LCD
*/
LiquidCrystal  lcd    (12, 11, 5, 4, 3, 2);

//Constante para fixar valor da porta serial 0
const int LM35 = 0;

//Variavel para armazenar valor da temperatura
float temperatura = 0;

//Variavel para armazenar o valor do ADC(Analog-to-Digital)
int ADClido = 0;


void  setup()
{

  //Inicializa comunicacao serial
  Serial.begin(9600);

  //Posiciona no inicio do Display
  lcd.begin(16, 1);

  //Escreve mensagem de inicio
  lcd.print("Iniciando...");

  /*
      INTERNAL: an built-in reference, equal to 1.1 volts on the ATmega168 or ATmega328 and 2.56 volts on the ATmega8 (not available on the Arduino Mega)
  */
  analogReference(INTERNAL);
}

void  loop()
{
  //Leitura da porta analogica 0
  ADClido = analogRead(LM35);

  Serial.println(ADClido);

  //convertendo temperatura para celcius
  temperatura = ADClido * 0.1075268817;

  //Escrevendo na saida Serial
  Serial.print("Temperatura = ");
  Serial.print(temperatura);
  Serial.println(" *C");

  //Escrevendo no Display LCD
  lcd.begin(16, 1);
  lcd.print("Temp.: ");
  lcd.print(temperatura);
  lcd.println(" *C");

  //Delay para leitura de 1 segundo
  delay(1000);

}
