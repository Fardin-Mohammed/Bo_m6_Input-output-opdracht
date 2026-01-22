#include <LiquidCrystal.h>
// RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup() {
 // LCD starten (16 kolommen, 2 rijen)
 lcd.begin(16, 2);
 // Tekst tonen
 lcd.setCursor(0, 0);   // kolom 0, rij 0
 lcd.print("Hallo!");
 lcd.setCursor(0, 1);   // kolom 0, rij 1
 lcd.print("Fardin is gay");
}
void loop() {
 // niets nodig
}