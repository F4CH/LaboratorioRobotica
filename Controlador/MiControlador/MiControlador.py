from controller import Robot
import random

# 1. Inicialización del Robot
robot = Robot()
timestep = int(robot.getBasicTimeStep())

# 2. Configurar Actuadores
left_motor = robot.getDevice('left wheel motor')
right_motor = robot.getDevice('right wheel motor')

# Configurar motores para control por velocidad (posición infinita)
left_motor.setPosition(float('inf'))
right_motor.setPosition(float('inf'))
left_motor.setVelocity(0.0)
right_motor.setVelocity(0.0)

# Parámetros del robot (
L = 0.052 # Distancia entre ruedas en metros
MAX_SPEED = 6.28 # Velocidad máxima en rad/s

def calcular_velocidades(v_deseada, omega_deseada):
    """
    Aplica el Modelo Cinemático inverso:
    vr = v + (omega * L) / 2
    vl = v - (omega * L) / 2
    """
    vr = v_deseada + (omega_deseada * L) / 2.0
    vl = v_deseada - (omega_deseada * L) / 2.0
    return vl, vr

# --- Bucle Principal  ---
while robot.step(timestep) != -1:

    # Caso A: Movimiento recto (v=2.0, omega=0) -> vr = vl
    # v_cmd, w_cmd = 2.0, 0.0

    # Caso B: Rotación en el lugar (v=0, omega=2.0) -> vr = -vl
    # v_cmd, w_cmd = 0.0, 2.0

    # Caso C: Círculo/Curva (v=2.0, omega=1.0) -> vr != vl
    v_cmd, w_cmd = 2.0, 1.0

    # Añadimos un pequeño ruido aleatorio a cada rueda
    perturbacion_l = random.uniform(-0.1, 0.1)
    perturbacion_r = random.uniform(-0.1, 0.1)

    vl, vr = calcular_velocidades(v_cmd, w_cmd)

    # Enviar velocidades a los motores
    left_motor.setVelocity(vl + perturbacion_l)
    right_motor.setVelocity(vr + perturbacion_r)

    # Imprimir para el Analista del grupo
    print(f"Velocidades aplicadas -> Izq: {vl:.2f}, Der: {vr:.2f}")