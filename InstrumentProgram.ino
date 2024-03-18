#include <Adafruit_GFX.h>
#include <Adafruit_GrayOLED.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_SPITFT_Macros.h>
#include <gfxfont.h>
#include <Adafruit_BusIO_Register.h>
#include <Adafruit_I2CDevice.h>
#include <Adafruit_I2CRegister.h>
#include <Adafruit_SPIDevice.h>
#include <Adafruit_SSD1306.h>
#include <splash.h>
#include <Tone.h>

Tone t1;
Tone t2;
Tone t3;
Tone t4;
Tone t5;
Tone t6;
Tone t7;
LiquidCrystal_I2C lcd(serial, 128, 64)

void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT);
  t1.begin(2);
  pinMode(3, INPUT);
  t2.begin(3);
  pinMode(4, INPUT);
  t3.begin(4);
  pinMode(5, INPUT);
  t4.begin(5);
  pinMode(6, INPUT);
  t5.begin(6);
  pinMode(7, INPUT);
  t6.begin(7);
  pinMode(8, INPUT);
  t7.begin(8);
  pinMode(13, OUTPUT);
  Tone bOctaves[8] = [NOTE_B1, NOTE_B2, NOTE_B3, NOTE_B4, NOTE_B5, NOTE_B6, NOTE_B7, NOTE_B8];
  Tone aOctaves[8] = [NOTE_A1, NOTE_A2, NOTE_A3, NOTE_A4, NOTE_A5, NOTE_A6, NOTE_A7, NOTE_A8];
  Tone gOctaves[8] = [NOTE_G1, NOTE_G2, NOTE_G3, NOTE_G4, NOTE_G5, NOTE_G6, NOTE_G7, NOTE_G8];
  Tone fOctaves[8] = [NOTE_F1, NOTE_F2, NOTE_F3, NOTE_F4, NOTE_F5, NOTE_F6, NOTE_F7, NOTE_F8];
  Tone eOctaves[8] = [NOTE_E1, NOTE_E2, NOTE_E3, NOTE_E4, NOTE_E5, NOTE_E6, NOTE_E7, NOTE_E8];
  Tone dOctaves[8] = [NOTE_D1, NOTE_D2, NOTE_D3, NOTE_D4, NOTE_D5, NOTE_D6, NOTE_D7, NOTE_D8];
  Tone cOctaves[8] = [NOTE_C1, NOTE_C2, NOTE_C3, NOTE_C4, NOTE_C5, NOTE_C6, NOTE_C7, NOTE_C8];
  int currentOctave = 0;
}

void loop() {
  if (digitalRead(2)) {
    play(bOctaves[currentOctave]);
    lcd.print(bOctaves[currentOctave]);
  } else if (digitalRead(3)) {
    play(aOctaves[currentOctave]);
    lcd.print(aOctaves[currentOctave]);
  } else if (digitalRead(4)) {
    play(gOctaves[currentOctave]);
    lcd.print(gOctaves[currentOctave]);
  } else if (digitalRead(5)) {
    play(fOctaves[currentOctave]);
    lcd.print(fOctaves[currentOctave]);
  } else if (digitalRead(6)) {
    play(eOctaves[currentOctave]);
    lcd.print(eOctaves[currentOctave]);
  } else if (digitalRead(7)) {
    play(dOctaves[currentOctave]);
    lcd.print(dOctaves[currentOctave]);
  } else if (digitalRead(8)) [
    play(cOctaves[currentOctave]);
    lcd.print(cOctaves[currentOctave]);
  ] else if (digitalRead(9)) {
    currentOctave++;
  } else if (digitalRead(10)) {
    currentOctave--;
  } else {
    stop();
  }
}