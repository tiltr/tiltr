
void commutation_M1(byte step, byte duty){
  switch(step){
    case 6:
      PWM1A = 0;
      PWM1B = 0;
      EN1_port &= ~(1 << EN1);
      EN2_port |= (1 << EN2);
      EN3_port |= (1 << EN3);
      PWM1C = duty;
      break;
    case 3:
      PWM1A = 0;
      PWM1C = 0;
      EN1_port |= (1 << EN1);
      EN2_port |= (1 << EN2);
      EN3_port &= ~(1 << EN3);
      PWM1B = duty;
      break;
    case 2:
      PWM1A = 0;
      PWM1B = 0;
      EN1_port |= (1 << EN1);
      EN2_port &= ~(1 << EN2);
      EN3_port |= (1 << EN3);
      PWM1C = duty;
      break;
    case 5:
      PWM1B = 0;
      PWM1C = 0;
      EN1_port |= (1 << EN1);
      EN2_port &= ~(1 << EN2);
      EN3_port |= (1 << EN3);
      PWM1A = duty;
      break;
    case 4:
      PWM1B = 0;
      PWM1C = 0;
      EN1_port |= (1 << EN1);
      EN2_port |= (1 << EN2);
      EN3_port &= ~(1 << EN3);
      PWM1A = duty;
      break;
    case 1:
      PWM1A = 0;
      PWM1C = 0;
      EN1_port &= ~(1 << EN1);
      EN2_port |= (1 << EN2);
      EN3_port |= (1 << EN3);
      PWM1B = duty;
      break;
    case 0:
      PWM1A = 0;
      PWM1B = 0;
      PWM1C = 0;
      EN1_port &= ~(1 << EN1);
      EN2_port &= ~(1 << EN2);
      EN3_port &= ~(1 << EN3);
      break; 
  }
}

void commutation_M2(byte step, byte duty){
  switch(step){
    case 6:
      PWM3A = 0;
      PWM3B = 0;
      EN4_port &= ~(1 << EN4);
      EN5_port |= (1 << EN5);
      EN6_port |= (1 << EN6);
      PWM3C = duty;
      break;
    case 3:
      PWM3A = 0;
      PWM3C = 0;
      EN4_port |= (1 << EN4);
      EN5_port |= (1 << EN5);
      EN6_port &= ~(1 << EN6);
      PWM3B = duty;
      break;
    case 2:
      PWM3A = 0;
      PWM3B = 0;
      EN4_port |= (1 << EN4);
      EN5_port &= ~(1 << EN5);
      EN6_port |= (1 << EN6);
      PWM3C = duty;
      break;
    case 5:
      PWM3B = 0;
      PWM3C = 0;
      EN4_port |= (1 << EN4);
      EN5_port &= ~(1 << EN5);
      EN6_port |= (1 << EN6);
      PWM3A = duty;
      break;
    case 4:
      PWM3B = 0;
      PWM3C = 0;
      EN4_port |= (1 << EN4);
      EN5_port |= (1 << EN5);
      EN6_port &= ~(1 << EN6);
      PWM3A = duty;
      break;
    case 1:
      PWM3A = 0;
      PWM3C = 0;
      EN4_port &= ~(1 << EN4);
      EN5_port |= (1 << EN5);
      EN6_port |= (1 << EN6);
      PWM3B = duty;
      break; 
    case 0:
      PWM3A = 0;
      PWM3B = 0;
      PWM3C = 0;
      EN4_port &= ~(1 << EN4);
      EN5_port &= ~(1 << EN5);
      EN6_port &= ~(1 << EN6);
      break;  
  }
}

void commutation_M3(byte step, byte duty){
  switch(step){
    case 6:
      PWM4A = 0;
      PWM4B = 0;
      EN7_port &= ~(1 << EN7);
      EN8_port |= (1 << EN8);
      EN9_port |= (1 << EN9);
      PWM4C = duty;
      break;
    case 3:
      PWM4A = 0;
      PWM4C = 0;
      EN7_port |= (1 << EN7);
      EN8_port |= (1 << EN8);
      EN9_port &= ~(1 << EN9);
      PWM4B = duty;
      break;
    case 2:
      PWM4A = 0;
      PWM4B = 0;
      EN7_port |= (1 << EN7);
      EN8_port &= ~(1 << EN8);
      EN9_port |= (1 << EN9);
      PWM4C = duty;
      break;
    case 5:
      PWM4B = 0;
      PWM4C = 0;
      EN7_port |= (1 << EN7);
      EN8_port &= ~(1 << EN8);
      EN9_port |= (1 << EN9);
      PWM4A = duty;
      break;
    case 4:
      PWM4B = 0;
      PWM4C = 0;
      EN7_port |= (1 << EN7);
      EN8_port |= (1 << EN8);
      EN9_port &= ~(1 << EN9);
      PWM4A = duty;
      break;
    case 1:
      PWM4A = 0;
      PWM4C = 0;
      EN7_port &= ~(1 << EN7);
      EN8_port |= (1 << EN8);
      EN9_port |= (1 << EN9);
      PWM4B = duty;
      break;   
    case 0:
      PWM4A = 0;
      PWM4B = 0;
      PWM4C = 0;
      EN7_port &= ~(1 << EN7);
      EN8_port &= ~(1 << EN8);
      EN9_port &= ~(1 << EN9);
      break;
  }
}

void commutation_M4(byte step, byte duty){
  switch(step){
    case 6:
      PWM5A = 0;
      PWM5B = 0;
      EN10_port &= ~(1 << EN10);
      EN11_port |= (1 << EN11);
      EN12_port |= (1 << EN12);
      PWM5C = duty;
      break;
    case 3:
      PWM5A = 0;
      PWM5C = 0;
      EN10_port |= (1 << EN10);
      EN11_port |= (1 << EN11);
      EN12_port &= ~(1 << EN12);
      PWM5B = duty;
      break;
    case 2:
      PWM5A = 0;
      PWM5B = 0;
      EN10_port |= (1 << EN10);
      EN11_port &= ~(1 << EN11);
      EN12_port |= (1 << EN12);
      PWM5C = duty;
      break;
    case 5:
      PWM5B = 0;
      PWM5C = 0;
      EN10_port |= (1 << EN10);
      EN11_port &= ~(1 << EN11);
      EN12_port |= (1 << EN12);
      PWM5A = duty;
      break;
    case 4:
      PWM5B = 0;
      PWM5C = 0;
      EN10_port |= (1 << EN10);
      EN11_port |= (1 << EN11);
      EN12_port &= ~(1 << EN12);
      PWM5A = duty;
      break;
    case 1:
      PWM5A = 0;
      PWM5C = 0;
      EN10_port &= ~(1 << EN10);
      EN11_port |= (1 << EN11);
      EN12_port |= (1 << EN12);
      PWM5B = duty;
      break;   
    case 0:
      PWM5A = 0;
      PWM5B = 0;
      PWM5C = 0;
      EN10_port &= ~(1 << EN10);
      EN11_port &= ~(1 << EN11);
      EN12_port &= ~(1 << EN12);
      break;
  }
}

