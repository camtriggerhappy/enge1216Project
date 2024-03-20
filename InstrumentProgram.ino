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
#include <Wire.h>

Tone t1;
Tone t2;
Tone t3;
Tone t4;
Tone t5;
Tone t6;
Tone t7;
int currentOctave = 0;
Adafruit_SSD1306 lcd(128, 64, &Wire, -1);

const int bOctaves[7] = { NOTE_B1, NOTE_B2, NOTE_B3, NOTE_B4, NOTE_B5, NOTE_B6, NOTE_B7 };
const int aOctaves[7] = { NOTE_A1, NOTE_A2, NOTE_A3, NOTE_A4, NOTE_A5, NOTE_A6, NOTE_A7 };
const int gOctaves[7] = { NOTE_G1, NOTE_G2, NOTE_G3, NOTE_G4, NOTE_G5, NOTE_G6, NOTE_G7 };
const int fOctaves[7] = { NOTE_F1, NOTE_F2, NOTE_F3, NOTE_F4, NOTE_F5, NOTE_F6, NOTE_F7 };
const int eOctaves[7] = { NOTE_E1, NOTE_E2, NOTE_E3, NOTE_E4, NOTE_E5, NOTE_E6, NOTE_E7 };
const int dOctaves[7] = { NOTE_D1, NOTE_D2, NOTE_D3, NOTE_D4, NOTE_D5, NOTE_D6, NOTE_D7 };
int cOctaves[7] = { NOTE_C1, NOTE_C2, NOTE_C3, NOTE_C4, NOTE_C5, NOTE_C6, NOTE_C7 };


void setup() {
  // put your setup code here, to run once:

  if (!lcd.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {  // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
  }


  delay(6);
  pinMode(2, INPUT);

  pinMode(3, INPUT);

  pinMode(4, INPUT);

  pinMode(5, INPUT);

  pinMode(6, INPUT);

  pinMode(7, INPUT);

  pinMode(8, INPUT);
  t1.begin(13);
  pinMode(13, OUTPUT);

  Serial.begin(115200);
}

void loop() {
  lcd.clearDisplay();
  if (digitalRead(2)) {
    keyTone(1);

  } else if (digitalRead(3)) {
    keyTone(3);

  } else if (digitalRead(4)) {
    keyTone(5);

  } else if (digitalRead(5)) {
    keyTone(6);

  } else if (digitalRead(6)) {
    keyTone(8);

  } else if (digitalRead(7)) {
    keyTone(10);

  } else if (digitalRead(8)) {
    keyTone(12);

  } else if (digitalRead(9)) {

    currentOctave--;
    delay(300);

  } else if (digitalRead(10)) {

    currentOctave++;
    delay(300);

  } else {
    t1.stop();
  }
  if (currentOctave > 6) {
    currentOctave = 6;
  }
  if (currentOctave < 0) {
    currentOctave = 0;
  }

  lcd.setTextSize(1);
  lcd.setTextColor(WHITE);
  lcd.setCursor(0, 10);
  lcd.println(currentOctave);
  lcd.display();
  Serial.println(currentOctave);
}

void keyTone(float i)
{
  // TODO: test and fill in "max input" and "max pitch interval wanted"
  // float noise = random(-analogRead(A0) / "max input" * "max pitch interval wanted", analogRead(A0)/"max input" * "max pitch interval wanted");
  // float pitchOffest = (analogRead(A0) / "max input" - 0.5) * "max pitch interval wanted";
  t1.play(pow(2, (currentOctave * 12 + i - 49 - 9) / 12) * 440);
  // t1.play(pow(2, (currentOctave * 12 + i - 49 - 9 + noise + pitchOffest) / 12) * 440);
}
