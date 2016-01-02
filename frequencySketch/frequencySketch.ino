#include <FreqPeriod.h>

double lfrq;
long int pp;

void setup() {
  
  Serial.begin(9600);
  FreqPeriod::begin();
  Serial.print ("starting program: ");

}

void loop() {
  
  pp = FreqPeriod::getPeriod();
  
  if (pp) {
    
    lfrq = 16000400.0 /pp;
    Serial.println(lfrq/31.36);
    
  }
  delay(10);
  
}
