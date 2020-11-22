#define RESET 13
#define ENABLE 12
#define D4 11
#define D5 10
#define D6 9
#define D7 8

#define BUZZ 7

#define THERMOMETER A5

#include <LiquidCrystal.h>

// Setup LCD
const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

float input = 0;
int temp = 0;

void setup() {

  // Initialize pins
  pinMode(BUZZ, OUTPUT);
  pinMode(THERMOMETER, INPUT);

  // Start LCD
  lcd.begin(20, 4);
  lcd.display();

}

void loop() {
  // put your main code here, to run repeatedly:
  input = analogRead(THERMOMETER);
  temp = (input*5*100)/1024;

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(temp);
  lcd.print("C");

  

  if (temp > 23) {
    for (int i = 0; i<1000; i++){
    digitalWrite(BUZZ, HIGH);
    //delay(10);
    digitalWrite(BUZZ, LOW); 
  }  
  } else {
    delay(1000);
    }
}
