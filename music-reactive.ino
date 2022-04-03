#define Rpin 11
#define Gpin 10
#define Bpin 9
#define delayLEDS 100
#define sensorPin A0

float sensorValue = 0, filteredSignal = 0,
      filteredSignalValues[] = {2.05, 1.8, 1.6, 1.4, 1.2, 1.0, 0.8, 0.6, 0.4, 0.2};
void setup()
{

  Serial.begin(9600);
  DDRB |= (1 << 3);
  DDRB |= (1 << 2);
  DDRB |= (1 << 1);
}

void loop()
{

  MainFunction();
}

void MainFunction()
{

  sensorValue = (float)analogRead(sensorPin) * (5.0 / 1024.0);

  FilterSignal(sensorValue);

  Serial.print(sensorValue);
  Serial.print(" ");
  Serial.println(filteredSignal);
  if (filteredSignal >= 0.35)
    CompareSignalFiltered(filteredSignal);
  if (filteredSignal < 0.35)
    RGBColor(0, 0, 0);
}

void FilterSignal(float sensorSignal)
{

  filteredSignal = (0.5 * filteredSignal) + (0.5 * sensorSignal);
}

void CompareSignalFiltered(float filteredSignal)
{
  Serial.print(filteredSignal);
  if (filteredSignal > filteredSignalValues[0])
  {
    RGBColor(0, 0, 255);
    Serial.println("Blue");
  }
  else if (filteredSignal <= filteredSignalValues[0] && filteredSignal > filteredSignalValues[1])
  {
    Serial.println("Azure");
    RGBColor(0, 255, 255);
  }
  else if (filteredSignal <= filteredSignalValues[1] && filteredSignal > filteredSignalValues[2])
  {
    RGBColor(0, 127, 255);
    Serial.println("Cyan");
  }
  else if (filteredSignal <= filteredSignalValues[2] && filteredSignal > filteredSignalValues[3])
  {
    RGBColor(0, 255, 127);
    Serial.println("Aqua marine");
  }
  else if (filteredSignal <= filteredSignalValues[3] && filteredSignal > filteredSignalValues[4])
  {
    RGBColor(0, 255, 0);
    Serial.println("Green");
  }
  else if (filteredSignal <= filteredSignalValues[4] && filteredSignal > filteredSignalValues[5])
  {
    RGBColor(255, 255, 0);
    Serial.println("Yellow");
  }
  else if (filteredSignal <= filteredSignalValues[5] && filteredSignal > filteredSignalValues[6])
  {
    RGBColor(255, 0, 255);
    Serial.println("Magenta");
  }
  else if (filteredSignal <= filteredSignalValues[6] && filteredSignal > filteredSignalValues[7])
  {
    RGBColor(255, 0, 127);
    Serial.println("Rose");
  }
  else if (filteredSignal <= filteredSignalValues[7] && filteredSignal > filteredSignalValues[8])
  {
    RGBColor(255, 127, 0);
    Serial.println("Orange");
  }
  else if (filteredSignal <= filteredSignalValues[8] && filteredSignal > filteredSignalValues[9])
  {
    RGBColor(255, 0, 0);
    Serial.println("Red");
  }
  else if (filteredSignal <= filteredSignalValues[9])
  {
    RGBColor(255, 0, 0);
    Serial.println("Red");
  }
  else
  {
    RGBColor(0, 0, 255);
    Serial.println("Default: Blue");
  }
}

void RGBColor(int Rcolor, int Gcolor, int Bcolor)
{

  analogWrite(Rpin, Rcolor);
  analogWrite(Gpin, Gcolor);
  analogWrite(Bpin, Bcolor);

  delay(delayLEDS);
}