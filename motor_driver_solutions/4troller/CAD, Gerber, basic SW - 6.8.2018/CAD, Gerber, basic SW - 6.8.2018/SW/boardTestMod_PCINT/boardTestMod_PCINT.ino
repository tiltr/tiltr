#include <iBUSserial.h> //https://github.com/Hrastovc/iBUS
#include "tankSteering.h"
#include "def.h"
#include "table.h"
#include "commutation.h"

volatile uint8_t HALL_M1, HALL_M2, HALL_M3, HALL_M4;
int left_motor_duty = 0;
int right_motor_duty = 0;
byte break_en = 0;

Tank tank(1000, 2000, 1000, 2000, 20);

void setup() {
  //SET OUTPUT PINS
  EN1_IOregister |= (1 << EN1);
  EN2_IOregister |= (1 << EN2);
  EN3_IOregister |= (1 << EN3);
  EN4_IOregister |= (1 << EN4);
  EN5_IOregister |= (1 << EN5);
  EN6_IOregister |= (1 << EN6);
  EN7_IOregister |= (1 << EN7);
  EN8_IOregister |= (1 << EN8);
  EN8_IOregister |= (1 << EN9);
  EN10_IOregister |= (1 << EN10);
  EN11_IOregister |= (1 << EN11);
  EN12_IOregister |= (1 << EN12);
  PWM1A_IOregister |= (1 << PWM1A_pin);
  PWM1B_IOregister |= (1 << PWM1B_pin);
  PWM1C_IOregister |= (1 << PWM1C_pin);
  PWM3A_IOregister |= (1 << PWM3A_pin);
  PWM3B_IOregister |= (1 << PWM3B_pin);
  PWM3C_IOregister |= (1 << PWM3C_pin);
  PWM4A_IOregister |= (1 << PWM4A_pin);
  PWM4B_IOregister |= (1 << PWM4B_pin);
  PWM4C_IOregister |= (1 << PWM4C_pin);
  PWM5A_IOregister |= (1 << PWM5A_pin);
  PWM5B_IOregister |= (1 << PWM5B_pin);
  PWM5C_IOregister |= (1 << PWM5C_pin);
  BEAT_LED_IOregister |= (1 << BEAT_LED);
  RELAY1_IOregister |= (1 << RELAY1);
  
  //set PCINT pins
  PCMSK0 |= (1 << PCINT4);  //HALL 1, PCIE0, PB4
  PCMSK1 |= (1 << PCINT9);  //HALL 2, PCIE1, PJ0
  PCMSK1 |= (1 << PCINT10); //HALL 3, PCIE1, PJ1
  PCMSK1 |= (1 << PCINT11); //HALL 4, PCIE1, PJ2
  PCMSK1 |= (1 << PCINT12); //HALL 5, PCIE1, PJ3
  PCMSK1 |= (1 << PCINT13); //HALL 6, PCIE1, PJ4
  PCMSK1 |= (1 << PCINT14); //HALL 7, PCIE1, PJ5
  PCMSK1 |= (1 << PCINT15); //HALL 8, PCIE1, PJ6
  PCMSK2 |= (1 << PCINT20); //HALL 9, PCIE2, PK4
  PCMSK2 |= (1 << PCINT21); //HALL 10, PCIE2, PK5
  PCMSK2 |= (1 << PCINT22); //HALL 11, PCIE2, PK6
  PCMSK2 |= (1 << PCINT23); //HALL 12, PCIE2, PK7
  
  //set PCINT interrupt
  PCICR |= (1 << PCIE0) | (1 << PCIE1) | (1 << PCIE2);
  
  //set timer1, PWM1
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1 = 0;
  OCR1A = 0;
  OCR1B = 0;
  OCR1C = 0;
  TCCR1A |= (1 << COM1A1) | (1 << COM1B1) | (1 << COM1C1);
  TCCR1A |= (1 << WGM10);
  TCCR1B |= (1 << CS10);
  
  //set timer3, PWM3
  TCCR3A = 0;
  TCCR3B = 0;
  TCNT3 = 0;
  OCR3A = 0;
  OCR3B = 0;
  OCR3C = 0;
  TCCR3A |= (1 << COM3A1) | (1 << COM3B1) | (1 << COM3C1);
  TCCR3A |= (1 << WGM30);
  TCCR3B |= (1 << CS30);

  //set timer4, PWM4
  TCCR4A = 0;
  TCCR4B = 0;
  TCNT4 = 0;
  OCR4A = 0;
  OCR4B = 0;
  OCR4C = 0;
  TCCR4A |= (1 << COM4A1) | (1 << COM4B1) | (1 << COM4C1);
  TCCR4A |= (1 << WGM40);
  TCCR4B |= (1 << CS40);

  //set timer5, PWM5
  TCCR5A = 0;
  TCCR5B = 0;
  TCNT5 = 0;
  OCR5A = 0;
  OCR5B = 0;
  OCR5C = 0;
  TCCR5A |= (1 << COM5A1) | (1 << COM5B1) | (1 << COM5C1);
  TCCR5A |= (1 << WGM50);
  TCCR5B |= (1 << CS50);
  
  iBUS.begin(115200);
}

void loop() {

  if(iBUS.available()){
    tank.setValues(1, iBUS.ch(1));
    tank.setValues(2, iBUS.ch(2));
    
    tank.calc();
    
    left_motor_duty = tank.leftMotor();
    right_motor_duty = tank.rightMotor();

    break_en = map(iBUS.ch(7), 1000, 2000, 0, 1);

    if(iBUS.ch(10) > 1500){ //Power stage relay
      RELAY1_port |= (1 << RELAY1);
    }else{
      RELAY1_port &= ~(1 << RELAY1);
    }
  }
  
  if(left_motor_duty > 0){  //forward
    commutation_M1(HALL_M1, left_motor_duty);
    commutation_M2(HALL_M2, left_motor_duty);
  }else if(left_motor_duty < 0){  //backward
    commutation_M1(~HALL_M1 & 0b111, abs(left_motor_duty));
    commutation_M2(~HALL_M2 & 0b111, abs(left_motor_duty));
  }else if(break_en){ //break on
    commutation_M1(HALL_M1, 0);
    commutation_M2(HALL_M2, 0);
  }else{ //break off
    commutation_M1(0, 0);
    commutation_M2(0, 0);
  }

  if(right_motor_duty > 0){  //forward
    commutation_M3(~HALL_M3 & 0b111, right_motor_duty);
    commutation_M4(~HALL_M4 & 0b111, right_motor_duty);
  }else if(right_motor_duty < 0){  //backward
    commutation_M3(HALL_M3, abs(right_motor_duty));
    commutation_M4(HALL_M4, abs(right_motor_duty));
  }else if(break_en){ //break on
    commutation_M3(HALL_M3, 0);
    commutation_M4(HALL_M4, 0);
  }else{ //break off
    commutation_M3(0, 0);
    commutation_M4(0, 0);
  }
  
  /*
  BEAT_LED_port |= (1 << BEAT_LED);
  delay(abs(left_motor_duty));
  BEAT_LED_port &= ~(1 << BEAT_LED);
  delay(abs(left_motor_duty));
  */
}

//PCINT0 ISR
ISR(PCINT0_vect) {
  HALL_M1 = ((PINB & 0b00010000) >> 2) | (HALL_M1 & 0b00000011);
}

//PCINT1 ISR
ISR(PCINT1_vect) {
  HALL_M1 = ((PINJ & 0b00000010) >> 1) | ((PINJ & 0b00000001) << 1) | (HALL_M1 & 0b00000100);
  HALL_M2 = ((PINJ & 0b00010000) >> 4) | ((PINJ & 0b00001000) >> 2) | (PINJ & 0b00000100);
  HALL_M3 = ((PINJ & 0b01000000) >> 5) | ((PINJ & 0b00100000) >> 3) | (HALL_M3 & 0b00000001);
}

//PCINT2 ISR
ISR(PCINT2_vect) {
  HALL_M3 = ((PINK & 0b00010000) >> 4) | (HALL_M3 & 0b00000110);
  HALL_M4 = ((PINK & 0b10000000) >> 7) | ((PINK & 0b01000000) >> 5) | ((PINK & 0b00100000) >> 3);
}

