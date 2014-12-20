
#include <ME1010_Library.h>
/**
  * wait_for_switch_press
  *
  * Function that waits for the specified switch to be
  * pressed (it should close and then open again).
  *
  * Inputs:
  *   int switch_ID = the switch number or name to check (0, 1, 2, START_BUTTON, or STOP_BUTTON)
  *
  * Outputs:
  *   boolean = true if the input argument was valid or false if it was not.
  */
boolean wait_for_switch_press(int switch_ID)
{
  boolean result_1, result_2;
  result_1 = wait_for_switch(switch_ID, CLOSED);
  result_2 =  wait_for_switch(switch_ID, OPEN);
  return (result_1 && result_2);
}


void setup()
{
  // Remember to call the shield's initialization function in setup.
  initialize_shield();
  Serial.begin(9600);
}


/**
  * This loop function prints out the potentiometer reading on the
  * serial monitor every 250 ms.
  */
void loop()
{
  int switch_ID = 0;
  int Drive_motor = 0;
  int Drive_speed = 100;
  int Whacker_motor = 1;
  int Whacker_speed = 100;
  int hammer_time = 3500;
  int solenoid = 0;
  int reload_solenoid = 1;
  int reload_solenoid_power = 100;
  int solenoid_time = 200;
  int reload_solenoid_time = 500;
  int start_photo = 0;
  int finish_photo = 1;
  int motor_solenoid_delay = 200;
  int after_fire_delay = 1000;
  int hammer_delay = 200;
  int target_1_delay = 0;
  int target_2_delay = 0;
  int target_3_delay = 0;
  int solenoid_power_1 = 83;
  int solenoid_power_2 = 72;
  int solenoid_power_3 = 75;
  
  
 
  // Wait for start button to be pressed.
  serial_printf("waiting for start");
  wait_for_switch_press(START_BUTTON);
  // Wait for phototransistor to exceed 70.
  serial_printf("waiting for photo\n");
  wait_for_photo_to_exceed(start_photo,90);
  serial_printf("photo activated\n");
  
  serial_printf("motor spinning up\n");
  set_motor_power(Drive_motor, Drive_speed);
  
  serial_printf("waiting for pressure sensor\n");
  wait_for_switch_press(switch_ID);
  serial_printf("pressure sensor switched\n");
  delay(target_1_delay);
  //brake_motor(Drive_motor);
  //delay(motor_solenoid_delay);
  
  activate_solenoid(solenoid, solenoid_time, solenoid_power_1);
  serial_printf("gun fired at zombie");
  delay(motor_solenoid_delay);
  //serial_printf("motor spinning up\n");
  activate_solenoid(reload_solenoid, solenoid_time, reload_solenoid_power);
  //set_motor_power(Drive_motor, Drive_speed);
  //delay(after_fire_delay);
  
  
  serial_printf("waiting for pressure sensor\n");
  wait_for_switch_press(switch_ID);
  serial_printf("pressure sensor switched\n");
  delay(target_2_delay);
  //brake_motor(Drive_motor);
//delay(motor_solenoid_delay);
  
  activate_solenoid(solenoid, solenoid_time, solenoid_power_2);
  serial_printf("gun fired at zombie");
  delay(motor_solenoid_delay);
  activate_solenoid(reload_solenoid, solenoid_time, reload_solenoid_power);
  //serial_printf("motor spinning up\n");
  //set_motor_power(Drive_motor, Drive_speed);
  //delay(after_fire_delay);
  
  
  
  serial_printf("waiting for pressure sensor\n");
  wait_for_switch_press(switch_ID);
  serial_printf("pressure sensor switched\n");
  delay(target_3_delay);
  //brake_motor(Drive_motor);
  //delay(motor_solenoid_delay);
  
  activate_solenoid(solenoid, solenoid_time, solenoid_power_3);
  serial_printf("gun fired at zombie");
  //delay(motor_solenoid_delay);
  //serial_printf("motor spinning up\n");
  //set_motor_power(Drive_motor, Drive_speed);
  //delay(after_fire_delay);
  
  
  serial_printf("waiting for pressure sensor\n");
  wait_for_switch_press(switch_ID);
  serial_printf("pressure sensor switched\n");
  delay(hammer_delay);
  
  serial_printf("stopping motor\n");
  brake_motor(Drive_motor);
  
  serial_printf("activating whacker\n");
  set_motor_power(Whacker_motor, Whacker_speed);
  delay(hammer_time);
  serial_printf("stopping zombie whacker");
  brake_motor(Whacker_motor);
  
  serial_printf("Drive motor spinning up\n");
  set_motor_power(Drive_motor, Drive_speed);
  
  serial_printf("waiting for photo\n");
  wait_for_photo_to_exceed(finish_photo,90);
  serial_printf("photo activated\n");
  
  serial_printf("stopping Drive motor");
  
  brake_motor(Drive_motor);
  
  
  // Stop the program to prevent endless loop.
  halt_program();
}

