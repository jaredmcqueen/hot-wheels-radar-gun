int led = 11;
int brightness = 0;
const int BUF_LEN = 4;
int slot = 0;
int i = 0;
int rolling[4] = {0,0,0,0};
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  rolling[slot++] = sensorValue;
  slot = slot == BUF_LEN ? 0 : slot;
  brightness = 0;
  for (i = 0; i < BUF_LEN; i++)
    brightness += slot[i];
  brightness /= BUF_LEN;
  // print out the value you read:
//  Serial.println(sensorValue);
  Serial.println(brightness);
  analogWrite(led, brightness);
  delay(1);        // delay in between reads for stability
}
