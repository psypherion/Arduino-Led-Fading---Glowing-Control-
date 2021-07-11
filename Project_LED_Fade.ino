#include <LiquidCrystal.h>
int Contrast = 68;
LiquidCrystal lcd(12, 13, 5, 4, 3, 2);

const int redPin = 11;
const int yellowPin = 10;
const int greenPin = 9;

int brightness_1 = 0;
int fadeAmount_1 = 5;
int brightness_2 = 0;
int fadeAmount_2 = 5;
int brightness_3 = 0;
int fadeAmount_3 = 5;
bool val_1 = true;
bool val_2 = true;
bool val_3 = true;
char comdata;
void setup() {
  // put your setup code here, to run once:
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  analogWrite(6, Contrast);
  lcd.begin(16, 2);
  Serial.begin(9600);
  Serial.println("Press B to start the program");
  Serial.println("Then press R - RED ON, G - GREEN ON, Y -  YELLOW ON, X - ALL is OFF  ");
  Serial.print("choose the letter: ");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    comdata = char(Serial.read());
    if (comdata == 'R' || comdata == 'G' || comdata == 'Y' || comdata == 'X' || comdata == 'B' || val_1 == true || val_2 == true || val_3 == true || Serial.available() == 0) {
      if (comdata == 'B') {
        Serial.println("Your Program Has Started");
        lcd.setCursor(0, 0);
        lcd.print("Program Started");
      }
      else if (comdata == 'X') {
        Serial.println("ALL LEDs ARE OFF");
        digitalWrite(redPin, LOW);
        digitalWrite(greenPin, LOW);
        digitalWrite(yellowPin, LOW);
        lcd.setCursor(0, 0);
        lcd.clear();
        lcd.print("TURNED OFF");
      }
      while (comdata == 'R' || val_1) {
        if (comdata == 'R')
        {
          Serial.println("Red LED is ON");
          lcd.setCursor(0, 1);
          lcd.clear();
          lcd.print("RED LED IS ON");
        }
        analogWrite(redPin, brightness_1);
        brightness_1 = brightness_1 + fadeAmount_1;
        if (brightness_1 == 0 || brightness_1 == 255)
        {
          fadeAmount_1 = -fadeAmount_1;
        }
        delay(30);
        if (Serial.available() > 0)
        {
          digitalWrite(redPin, LOW);
          val_1 = !val_1;
          break;
        }
      }
      while (comdata == 'G' || val_2) {
        if (comdata == 'G')
        {
          Serial.println("Green LED is ON");
          lcd.setCursor(0, 1);
          lcd.clear();
          lcd.print("GREEN LED IS ON");
        }
        analogWrite(greenPin, brightness_2);
        brightness_2 = brightness_2 + fadeAmount_2;
        if (brightness_2 == 0 || brightness_2 == 255)
        {
          fadeAmount_2 = -fadeAmount_2;
        }
        delay(30);
        if (Serial.available() > 0)
        {
          digitalWrite(greenPin, LOW);
          val_2 = !val_2;
          break;
        }
      }
      while (comdata == 'Y' || val_3) {
        if (comdata == 'Y')
        {
          Serial.println("Yellow LED is ON");
          lcd.setCursor(0, 1);
          lcd.clear();
          lcd.print("YELLOW LED IS ON");
        }
        analogWrite(yellowPin, brightness_3);
        brightness_3 = brightness_3 + fadeAmount_3;
        if (brightness_3 == 0 || brightness_3 == 255)
        {
          fadeAmount_3 = -fadeAmount_3;
        }
        delay(30);
        if (Serial.available() > 0)
        {
          digitalWrite(yellowPin, LOW);
          val_3 = !val_3;
          break;
        }
      }
    }
    else
    {
      Serial.println("Please Use Above Mentioned KeyWords");
      lcd.setCursor(0, 1);
      lcd.clear();
      lcd.print("WRONG INPUT");
    }
  }
}
