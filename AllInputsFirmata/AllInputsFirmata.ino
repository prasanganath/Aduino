
#include <Firmata.h>

byte pin;

int analogValue;
int previousAnalogValues[TOTAL_ANALOG_PINS];

byte portStatus[TOTAL_PORTS]; 
byte previousPINs[TOTAL_PORTS];

unsigned long currentMillis;    
unsigned long previousMillis;   
int samplingInterval = 19;

void sendPort(byte portNumber, byte portValue)
{
  portValue = portValue & portStatus[portNumber];
  if (previousPINs[portNumber] != portValue) {
    Firmata.sendDigitalPort(portNumber, portValue);
    previousPINs[portNumber] = portValue;
  }
}

void setup()
{
  byte i, port, status;

  Firmata.setFirmwareVersion(FIRMATA_FIRMWARE_MAJOR_VERSION, FIRMATA_FIRMWARE_MINOR_VERSION);

  for (pin = 0; pin < TOTAL_PINS; pin++) {
    if IS_PIN_DIGITAL(pin) pinMode(PIN_TO_DIGITAL(pin), INPUT);
  }

  for (port = 0; port < TOTAL_PORTS; port++) {
    status = 0;
    for (i = 0; i < 8; i++) {
      if (IS_PIN_DIGITAL(port * 8 + i)) status |= (1 << i);
    }
    portStatus[port] = status;
  }

  Firmata.begin(57600);
}

void loop()
{
  byte i;

  for (i = 0; i < TOTAL_PORTS; i++) {
    sendPort(i, readPort(i, 0xff));
  }
 
  currentMillis = millis();
  if (currentMillis - previousMillis > samplingInterval) {
    previousMillis += samplingInterval;
    while (Firmata.available()) {
      Firmata.processInput();
    }
    for (pin = 0; pin < TOTAL_ANALOG_PINS; pin++) {
      analogValue = analogRead(pin);
      if (analogValue != previousAnalogValues[pin]) {
        Firmata.sendAnalog(pin, analogValue);
        previousAnalogValues[pin] = analogValue;
      }
    }
  }
}


