#include <webots/robot.h>
#include <webots/motor.h>
#include <stdio.h>
#define TIME_STEP 64

int main(int argc, char **argv) {

  wb_robot_init();
  
  WbDeviceTag motor_izquierdo = wb_robot_get_device("left wheel motor");
  WbDeviceTag motor_derecho = wb_robot_get_device("right wheel motor");
  
  wb_motor_set_position(motor_izquierdo, INFINITY);
  wb_motor_set_position(motor_derecho, INFINITY);
  
  wb_motor_set_velocity(motor_izquierdo, 0.0);
  wb_motor_set_velocity(motor_derecho, 0.0);
  
  while (wb_robot_step(TIME_STEP) != -1) {
    
    double velocidad = 5.0;
    
    wb_motor_set_velocity(motor_izquierdo, velocidad);
    wb_motor_set_velocity(motor_derecho, velocidad);
    
    printf("Funcionando??\n");
  };
  
  wb_robot_cleanup();
  
  return 0;
}
