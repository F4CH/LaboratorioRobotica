# Laboratorio 1: Simulación de un Robot Móvil Diferencial en Webots

## Descripción del laboratorio

Este laboratorio tiene como objetivo comprender el comportamiento cinemático de un robot móvil diferencial mediante una simulación en Webots. Para ello, se utiliza un robot tipo **e-puck**, el cual cuenta con dos ruedas motrices independientes: una rueda izquierda y una rueda derecha. El movimiento del robot depende de la velocidad asignada a cada una de estas ruedas.

A lo largo de la actividad se busca observar cómo cambian las trayectorias del robot según la relación entre las velocidades de ambas ruedas. En particular, se analizan tres comportamientos principales: el movimiento recto, la trayectoria curva y la rotación en el lugar. Además, como parte del desafío, se implementaron trayectorias más complejas, como el dibujo de un círculo y un cuadrado.

La simulación fue realizada en Webots, utilizando un controlador en lenguaje C para manipular directamente la velocidad de los motores del robot. De esta forma, el laboratorio permite relacionar la teoría del modelo cinemático diferencial con una implementación práctica en un entorno de simulación.
## Cómo ejecutar la simulación en Webots

1. Abrir **Webots**.
2. Seleccionar **File > Open World**.
3. Abrir el archivo del mundo ubicado en:

   `worlds/lab.wbt`

4. Verificar que el robot del mundo tenga asignado el controlador:

   `e-puck_avoid_obstacles`

5. Abrir el archivo del controlador ubicado en:

   `controllers/e-puck_avoid_obstacles/e-puck_avoid_obstacles.c`

6. Dentro del ciclo principal del programa, dejar activo únicamente el experimento que se desea ejecutar y comentar los demás.
7. Guardar los cambios realizados en el archivo.
8. En Webots, presionar **Reset** y luego **Play** para reiniciar la simulación y ejecutar el controlador actualizado.
9. Observar la trayectoria del robot en la escena de simulación.

**Nota:** en algunas ocasiones fue necesario recargar o reiniciar el mundo para que Webots aplicara correctamente los cambios realizados en el controlador.

## Resultados obtenidos

A partir de las simulaciones realizadas, se observó que el comportamiento del robot depende directamente de las velocidades asignadas a las ruedas izquierda y derecha.

Cuando ambas ruedas giran con la misma velocidad, el robot se desplaza en línea recta. En cambio, cuando las velocidades son diferentes, el robot describe una trayectoria curva, ya que una rueda avanza más rápido que la otra. Por otro lado, cuando una rueda gira en sentido opuesto a la otra, el robot realiza una rotación en el lugar, girando sobre su propio eje.

Además, en el controlador se implementó el desafío de dibujar un círculo, configurando ambas ruedas en el mismo sentido pero con velocidades diferentes y constantes. También se incorporaron pequeñas perturbaciones aleatorias en los actuadores, lo que permitió comparar una trayectoria ideal con otra afectada por variaciones. Como resultado, se observó que las perturbaciones generan pequeñas desviaciones en el movimiento esperado del robot, haciendo que la trayectoria no sea perfectamente ideal.

## Preguntas de análisis

### 1. ¿Qué ocurre cuando ambas ruedas tienen la misma velocidad?
Cuando ambas ruedas tienen la misma velocidad, el robot avanza en línea recta, ya que no existe diferencia de velocidad entre los lados del robot.

### 2. ¿Cómo cambia la trayectoria cuando las velocidades son diferentes?
Cuando las velocidades son diferentes, el robot deja de avanzar recto y comienza a describir una trayectoria curva.

### 3. ¿Qué ocurre cuando una rueda gira en sentido opuesto a la otra?
Cuando una rueda gira en sentido opuesto a la otra, el robot rota en el lugar, es decir, gira sobre su propio eje.

### 4. ¿Qué tipo de movimiento permite dibujar un círculo?
Para dibujar un círculo, ambas ruedas deben moverse en el mismo sentido, pero con velocidades distintas y constantes.

# Enlace a video de simulación
### https://youtu.be/CsD8px0-FUI

# Integrantes:
### Programador: Benjamin Gomez 
### Experimentador: Pablo Aguilera 
### Analista: Cristobal Rubilar 
### Documentador: Cristian Mejias
### Integrador: Joaquin Garrido
