#include <Adafruit_NeoPixel.h>
#include <Servo.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

Servo myservo;
int pos = 0;


const int trigPin = 9;
const int echoPin = 10;
float duration, distance;


#define PIN1 7
#define PIN2 8
#define NUM_LEDS 180

Adafruit_NeoPixel strip1(NUM_LEDS, PIN1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2(NUM_LEDS, PIN2, NEO_GRB + NEO_KHZ800);

void setup() {
  strip1.begin();
  strip2.begin();
  strip1.show();
  strip2.show();
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);

  myservo.attach(6);

  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Hallo!");
  lcd.setCursor(0, 1);
  lcd.print("Fardin is gay");
}

void loop() {
  waveEffect();
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(10);

  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(1);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}

void waveEffect() {
  static uint16_t pos = 0;
  pos++;

  for (int i = 0; i < NUM_LEDS; i++) {
    int brightness = (sin((i + pos) * 0.20) * 127) + 128;

    int r = brightness * 0.1;  
    int g = brightness * 0.3;
    int b = brightness;

    strip1.setPixelColor(i, strip1.Color(r, g, b));
    strip2.setPixelColor(i, strip2.Color(r, g, b));
  }

  strip1.show();
  strip2.show();
  delay(25);  
}

