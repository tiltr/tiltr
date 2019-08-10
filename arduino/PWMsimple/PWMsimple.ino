/*
  Minimalistic example to to get the wheels turning.
  Look at HoverboardAPI.c to learn which other functions are available.

  Further information on https://github.com/bipropellant
*/


#include <HoverboardAPI.h>

//InterruptIn hall_A_int(PA_10);

HardwareSerial Serial4(PA1, PA0);

#define hall_A_int PA10
#define hall_B_int PB3
#define hall_C_int PB5
#define LED PA5


//DigitalIn   hall_A_read(PA_10);
//InterruptIn hall_A_int(PA_10);
//DigitalIn   hall_B_read(PB_3);
//InterruptIn hall_B_int(PB_3);
//DigitalIn   hall_C_read(PB_5);
//InterruptIn hall_C_int(PB_5);

volatile bool forward = false;
volatile int counter = 0;

void hall_a_rise()
{
  forward = (digitalRead(hall_B_int) ? true : false);
  counter += (forward ? 1 : (-1));
  digitalWrite(LED, (forward ? HIGH : LOW));
}




void hall_a_change()
{
  static unsigned long last_interrupt_time = 0;
  unsigned long interrupt_time = millis();
  if (interrupt_time - last_interrupt_time > 10)
  {
    if (digitalRead(hall_A_int)) {
      forward = (digitalRead(hall_B_int) ? true : false);
    }
    if (!digitalRead(hall_A_int)) {
      forward = (digitalRead(hall_B_int) ? false : true);
    }
    counter += (forward ? 1 : (-1));
    digitalWrite(LED, (forward ? HIGH : LOW));
  }
}

void hall_b_change()
{
  if (digitalRead(hall_B_int))
  {
    forward = (!digitalRead(hall_C_int) ? false : true);
  }
  if (!digitalRead(hall_B_int))
  {
    forward = (!digitalRead(hall_C_int) ? true : false);
  }
  counter += (forward ? 1 : (-1));
  digitalWrite(PA5, forward);
}

void hall_c_change()
{
  if (digitalRead(hall_C_int)) {
    forward = (!digitalRead(hall_A_int) ? false : true);
  }
  if (!digitalRead(hall_B_int)) {
    forward = (digitalRead(hall_A_int) ? true : false);
  }
  counter += (forward ? 1 : (-1));
}


int serialWrapper(unsigned char *data, int len) {
  return (int) Serial4.write(data, len);
}
HoverboardAPI hoverboard = HoverboardAPI(serialWrapper);

void setup() {
  Serial4.begin(115200);

  //attachInterrupt(digitalPinToInterrupt(hall_B_int), hall_a_rise, RISING);
  attachInterrupt(digitalPinToInterrupt(hall_B_int), hall_a_change, CHANGE);
  //attachInterrupt(digitalPinToInterrupt(hall_C_int), hall_b_change, CHANGE);
  //attachInterrupt(digitalPinToInterrupt(hall_A_int), hall_c_change, CHANGE);
  //attachInterrupt(digitalPinToInterrupt(hall_B_int), hall_a_fall, FALLING);
  pinMode(LED, OUTPUT);
}

bool p_flag = true;
long timer = millis();
long timer_2 = millis();
int speed_var = 300;
void loop() {
  //digitalWrite(LED, HIGH);
  delay(500);
  while (1) {

    hoverboard.sendPWM(speed_var, 0, PROTOCOL_SOM_NOACK);
    //hoverboard.sendPWMData(10, speed_var, 100, 50, 10, PROTOCOL_SOM_NOACK);

    //digitalWrite(LED, forward);
    if ((millis() - timer) > 2000) {
      speed_var = speed_var * (-1);
      timer = millis();
    }

    if (((millis() - timer_2) > 1000) && p_flag) {
      //void HoverboardAPI::sendBuzzer(uint8_t buzzerFreq, uint8_t buzzerPattern, uint16_t buzzerLen, char som) {
      for (int i = 0; i < 10; i++) {
        hoverboard.sendBuzzer((8 + (i * 2)), 1, 100, PROTOCOL_SOM_NOACK);
        delay(50);
      }
      //      for (int i = 10; i > 0; i--) {
      //        hoverboard.sendBuzzer((8 + (i * 2)), 1, 100, PROTOCOL_SOM_NOACK);
      //        delay(100);
      //      }
      Serial4.println("unlockASCII");
      Serial4.println('P');
      Serial4.println('p');
      Serial4.println('P');
      p_flag = false;

    }
  }
  //delay(300);
}
