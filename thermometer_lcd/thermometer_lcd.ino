
// Definere pins på arduinoen som der bliver brugt
#define RESET 13
#define ENABLE 12
#define D4 11
#define D5 10
#define D6 9
#define D7 8

#define BUZZ 7

#define THERMOMETER A5

// Importer LCD bibliotek
#include <LiquidCrystal.h>

// Setup LCD
const int rs = RESET, en = ENABLE, d4 = D4, d5 = D5, d6 = D6, d7 = D7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Definere variabler som modtager spændingen, og omregner det til temperatur
float input = 0;
float temp = 0;

// Function der køre en gang i starten af programmet
void setup() {
  // Initializere analog pins
  pinMode(BUZZ, OUTPUT);
  pinMode(THERMOMETER, INPUT);

  // Sætter refereance punktet til 1,1V
  analogReference(INTERNAL);
  analogRead(THERMOMETER);

  // Starter LCD'en
  lcd.begin(20, 4);
  lcd.display();

}

// Function der looper i gennem programmet
void loop() {
  // Modtager spænding fra LM35 og omregner det til Celsius
  input = analogRead(THERMOMETER);
  temp = (input*1.1*100)/1024;

  // Nulstiller LCD
  lcd.clear();
  lcd.setCursor(0,0);

  // Skriver temperatur til LCD
  lcd.print(temp);
  lcd.print("C");


  // Tester om temperatur er over grænsenieveu
  if (temp > 23) {
    // Hvis temeraturen er høj nok, bipper der en buzzer 100 gange på et sekund
    for (int i = 0; i<100; i++){
      digitalWrite(BUZZ, HIGH);
      delay(5);
      digitalWrite(BUZZ, LOW); 
      delay(5);
    }  
  } else {
      // Hvis temperature ikke er høj nok venter programmet i et sekund
      delay(1000);
  }
}
