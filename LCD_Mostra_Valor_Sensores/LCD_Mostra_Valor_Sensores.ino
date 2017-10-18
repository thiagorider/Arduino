/*
  LiquidCrystal Library - Mostra Valores de A0 ateh A5
 


 
  O circuito:
 * LCD RS      ---> Digital pin 12
 * LCD Enable  ---> Digital pin 11
 * LCD D4      ---> Digital pin 5
 * LCD D5      ---> Digital pin 4
 * LCD D6      ---> Digital pin 3
 * LCD D7      ---> Digital pin 2
 * LCD R/W     ---> ground
 * Potenciometro de 10K:
   * Nas pontas +5V e ground
   * Pino central ---> LCD VO
 2
 */

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("hello, world!");
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(millis()/1000);
}

