void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(13, OUTPUT);

  
}

void loop() {
  // put your main code here, to run repeatedly:

  if (digitalRead(2)) {
    makeNoise(261);
  }
  if (digitalRead(3)) {
    makeNoise(294);
  }
  if (digitalRead(4)) {
    makeNoise(329);
  }
  if (digitalRead(5)) {
    makeNoise(349);
  }
  if (digitalRead(6)) {
    makeNoise(392);
  }
  if (digitalRead(7)) {
    makeNoise(440);
  }
  if (digitalRead(8)) {
    makeNoise(494);
  }
}


void makeNoise(int frequency) {
  float randomNoise = random(-analogRead(A0)/128, analogRead(A0)/128);
  float pitchChange = analogRead(A1)/240;
  tone(13, frequency + randomNoise + pitchChange, 10);
}
