/*
 * @aureleq
 *
 * Description: Sends a Sigfox message when pushing a button
 * Button needs to be wired between GND and pin 7 by default
 * Interrupts are being used to enable low power mode.
 * As board with be in sleeping mode most of the time, a board reset needs to be performed to upload a new sketch (double tap on reset button)
*/

#include <SigFox.h>
#include <ArduinoLowPower.h>

const uint8_t SWITCH_PIN = 7;
const String payload = "COKE NOW!";
const uint8_t debug = false;

void setup() {

  if (debug == true) {
    Serial.begin(9600);
    while (!Serial) {};
  }
  
  if (!SigFox.begin()) {
    Serial.println("Shield error or not present!");
    return;
  }
  // Enable debug led and disable automatic deep sleep
  // Comment this line when shipping your project :)
  //SigFox.debug();

  Serial.println("Sigfox shield detected");
  String ID = SigFox.ID();
  Serial.println("ID  = " + ID);
  delay(100);

  // Send the module to the deepest sleep
  SigFox.end();

  // attach switch pin and enable the interrupt on voltage rising event
  pinMode(SWITCH_PIN, INPUT_PULLUP);
  LowPower.attachInterruptWakeup(SWITCH_PIN, buttonPressed, RISING); // switch is closed by default, open when pushing the button

}

void loop()
{
  // Sleep until an event is recognized
  LowPower.sleep();

  // if we get here it means that an event was received
  Serial.println("Button pushed!");
  delay(100);
  sendString(payload);
}

void sendString(String str) {
  // Start the module
  SigFox.begin();
  // Wait at least 30mS after first configuration (100mS before)
  delay(100);
  // Clears all pending interrupts
  SigFox.status();
  delay(1);

  SigFox.beginPacket();
  SigFox.print(str);

  int ret = SigFox.endPacket();  // send buffer to SIGFOX network
  if (ret > 0) {
    Serial.println("No transmission");
  } else {
    Serial.println("Transmission ok");
  }

  Serial.println(SigFox.status(SIGFOX));
  Serial.println(SigFox.status(ATMEL));
  SigFox.end();
}


void buttonPressed() {
}


