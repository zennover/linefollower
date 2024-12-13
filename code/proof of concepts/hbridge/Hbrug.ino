#define motor1PWM1 18
#define motor1PWM2 19
#define motor2PWM1 12
#define motor2PWM2 21
#define Baudrate 115200

void setup() {
  // put your setup code here, to run once
  Serial.begin(baudrate);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalwrite(18, HIGH);
delay(1000);
digitalwrite(18, LOW);
delay(1000);
digitalwrite(19, high);
delay(1000);
digitalwrite(19, LOW);
delay(1000);
digitalwrite(12, HIGH);
delay(1000);
digitalwrite(12, LOW);
delay(1000);
digitalwrite(21, high);
delay(1000);
digitalwrite(21, LOW);
delay(1000);
}
