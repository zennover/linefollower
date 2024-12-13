#define baudrate 115200

const int sensor[] = {14, 27, 26, 25, 33, 32, 35, 34};

void setup() {
  // put your setup code here, to run once:
Serial.begin(baudrate);
}

void loop()
{
  sCmd.readSerial();
 
  unsigned long current = micros();
  if (current - previous >= params.cycleTime)
  {
    previous = current;

    long normalised[8];
    for (int i = 0; i < 6; i++)
    {
      long value = analogRead(sensor[i]);
      normalised[i] = map(value, params.black[i], params.white[i], 0, 1000);
    }

    int index = 0;
    for (int i = 1; i < 8; i++) if (normalised[i] < normalised[index]) index = i;

    if (index == 0) index = 1;
    else if (index == 5) index = 4;

    long sZero = normalised[index];
    long sMinusOne = normalised[index-1];
    long sPlusOne = normalised[index+1];

    float b = ((float) (sPlusOne - sMinusOne)) / 2;
    float a = sPlusOne - b - sZero;

    float position = -b / (2 * a);  
    position += index - 3.5;   
    position *= 9.525;  //sensor distance in mm
    
  }

  unsigned long difference = micros() - current;
  if (difference > calculationTime) calculationTime = difference;
}
