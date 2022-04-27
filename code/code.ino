#include <tiny_IRremote.h> 
#include <tiny_IRremoteInt.h> 
IRsend irsend;

long last_fired = 0, led_last_on = 0, led_off = 200000, led_on = 800;
int led_state;

void setup() {
  irsend.enableIROut(38);
  pinMode(0, OUTPUT);
}

void loop() {

  if(millis() - last_fired >= 132) {
    for (int i=0; i<3; i++) {
      irsend.mark(500);
      irsend.space(7500);
    }
    last_fired = millis();
  }
 
   if (led_state == LOW) {
     if (millis() - led_last_on >= led_off) {
       led_state = HIGH;
       led_last_on = millis();
     }
   } else {
     if (millis() - led_last_on >= led_on) {
       led_state = LOW;      
     }
   }
   digitalWrite(0, led_state);

}
