#include <webots/robot.h>
#include <webots/motor.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TIME_STEP 64

int main(int argc, char **argv) {
  wb_robot_init();

  // 1. Motores identificados
  WbDeviceTag motor_izquierdo = wb_robot_get_device("left wheel motor"); 
  WbDeviceTag motor_derecho = wb_robot_get_device("right wheel motor");

  // 2. Configuración para control por velocidad
  wb_motor_set_position(motor_izquierdo, INFINITY);
  wb_motor_set_position(motor_derecho, INFINITY);
  
  srand(time(NULL)); // Para la extensión de perturbaciones

  while (wb_robot_step(TIME_STEP) != -1) {
    
    
    // Estas variables siempre suman un pequeño error aleatorio
    double ruido_izq = ((rand() % 201) - 100) / 1000.0; 
    double ruido_der = ((rand() % 201) - 100) / 1000.0;

    // ==========================================================
    // SELECCIÓN DE EXPERIMENTOS (Para su uso se tiene que descomentar uno a la vez)
    // ==========================================================
    
    //double v_base = 4.0;

    // EXPERIMENTO 1: Movimiento Recto (vr = vl)
    //wb_motor_set_velocity(motor_izquierdo, v_base + ruido_izq);
    //wb_motor_set_velocity(motor_derecho, v_base + ruido_der);

    // EXPERIMENTO 2: Trayectoria Curva (vr != vl)
    // wb_motor_set_velocity(motor_izquierdo, 2.0 + ruido_izq);
    // wb_motor_set_velocity(motor_derecho, 5.0 + ruido_der);

    // EXPERIMENTO 3: Rotación en el lugar (vr = -vl)
    // wb_motor_set_velocity(motor_izquierdo, -v_base + ruido_izq);
    // wb_motor_set_velocity(motor_derecho, v_base + ruido_der);

    // DESAFÍO: Dibujar un Círculo
    // wb_motor_set_velocity(motor_izquierdo, 1.5 + ruido_izq);
    // wb_motor_set_velocity(motor_derecho, 6.0 + ruido_der);
    
    //DESAFÍO: Dibujar un Cuadrado
    /*
    double t = wb_robot_get_time();
    double v_l = 0.0;
    double v_r = 0.0;

    // Definimos la duración de cada parte del movimiento
    double t_avance = 4.0; // 4 segundos caminando recto
    double t_giro   = 1.1; // TIEMPO CLAVE: Ajusta este decimal para los 90°
    double ciclo    = t_avance + t_giro;

    // Usamos fmod para saber en qué parte del ciclo estamos
    double tiempo_en_ciclo = fmod(t, ciclo);

    if (tiempo_en_ciclo < t_avance) {
        // FASE 1: AVANZAR RECTO
        v_l = 5.0; 
        v_r = 5.0;
        printf("Dibujando LADO del cuadrado\n");
    } 
    else {
        // FASE 2: ROTACIÓN EN EL LUGAR
        // Bajamos la velocidad de giro para que sea más preciso
        v_l = -2.0; 
        v_r = 2.0;
        printf("Girando ESQUINA (90 grados)\n");
    }
    // Se reduce el ruido que se pueda generar para tener mas presicion 
    ruido_izq = ((rand() % 201) - 100) / 2000.0; 
    ruido_der = ((rand() % 201) - 100) / 2000.0;
    wb_motor_set_velocity(motor_izquierdo, v_l + ruido_izq);
    wb_motor_set_velocity(motor_derecho, v_r + ruido_der);
    */
    // ==========================================================

    printf("Ejecutando simulación...\n");
  };
  
  wb_robot_cleanup();
  
  return 0;
}