# Título del Trabajo
 Snake
## Descripción proyecto
El juego consiste en que dos o más jugadores controlan una larga y delgada línea semejante a una serpiente. Para obtener puntos el usuario deberá recopilar los cuadrados que encuentre a su paso lo que aumentará su tamaño, pudiendo moverse en línea recta y haciendo giros de noventa grados en cualquiera de las direcciones. Además, deberá evitar chocar consigo mismo, con los demás participantes y con los bordes de la pantalla en cuyo caso si lo hiciera el juego terminaría.

## Integrantes del equipo

Víctor José Villamar Guamán  usuario:@victor-villamar.
Valeri Paola Ramirez Moreira usuario:@VALERIRAMIREZ.
Carlos Sandoval Herrera usuario:@Carlos-sandoval.

## Objetivos del trabajo
-Conseguir que dos personas puedan jugar de forma simultanea desde un mismo teclado.<p>
-Poder crear la posibilidad de jugar de forma individual o poder hacer un torneo.<p>
-Tener encuenta todos los factores que pueden hacer perder al jugador.<p>
-Crear un contador con la puntucion de los jugadores para ver su clasificacion.<p>
### Hadware
Nuestro trabajo no requiere hadware.
### Software
Desarrollo en C.

## Datos de los miembros del grupo
|Nombre|Apellidos|Nº Matricula|Email|
| :-------------: | :-------------: |:-------------: |:-------------: |
|Víctor José|Villamar Guamán|55512|victor.villamar.guaman@alumnos.upm.es|
|Valeri Paola|Ramirez Moreira|     |                                     |
|Carlos|Sandoval Herrera|54866|                                     |

## Título y resumen

|Encendido de bombilla con el silbido con C y Arduino|
| :------------- |
|Sistema electronico basado en un microcontrolador capaz de aumentar la intensidad de una bombilla mediante el silbido.El silbido sera captado con un sensor de sonido y la intensidad de la bombilla sera modificado con un dimmer.El sistema de comunicarse con el ordenador para determinar con que intensidad se iluminara la bombilla dependiendo de la intensidad del silbido.|
|![imagen proyecto](https://i.imgur.com/vqvOgMz.png)|
|Requisitos funcionales|
| :------------- |
|1º-La aplicacion dispone de un control en pantalla para iniciar todo el proceso.
2º- Al inciar el proceso,el microcontrolador acciona el sensor de sonido.
3ºCada vez que aumente el silbido el sensor de sonido manda la informacion al microcontrolador.
4ºCon el algoritmo del ordenador el dimmer aumenta o disminuye la intensidad de la bombilla.|

## Hadware-Fundamentos técnicos
|Detectacion del sonido-Sensor sonido KY-038|
| :------------- |
|*Fuente*:https://www.luisllamas.es/detectar-sonido-con-arduino-y-microfono-ky-038/|

Un micrófono es un transductor que convierte las ondas sonoras en señales eléctricas.Podemos conectar un micrófono a un procesador como Arduino para detectar sonidos.
La salida producida por un micrófono es una señal eléctrica analógica que representa el sonido recibido. Sin embargo, en general, esta señal demasiado baja para ser medida y tiene que ser amplificada.<p>

![Explicacion sonido](https://www.luisllamas.es/wp-content/uploads/2016/11/arduino-microfono-ky-038-funcionamiento.png)
<p>

Existen placas como la KY-038 que incorporan un micrófono junto con un comparador LM393, que permite obtener la lectura tanto como un valor analógico como de forma digital.
El uso habitual de este tipo de sensores no amplificados es emplear la salida digital para detectar el sonido cuando este supera un cierto umbral, regulado a través de un potenciómetro ubicado en la placa.

La salida analógica permite obtener una estimación del volumen registrado. Sin embargo, como hemos comentado, este tipo de módulos con micrófono no resultan adecuados para medir el sonido de forma analógica ya que carecen de amplificación.

Si solo queremos detectar el sonido, y no medirlo, este tipo de sensores son más apropiados ya que únicamente requieren la lectura de una señal digital, sin necesitar realizar más cálculos.<p>
**Nota:** Deberemos calibrar el umbral de disparo de la salida digital con el potenciómetro instalado en el módulo para el nivel de sonido deseado.
<p>

|![ imagen montaje](https://encrypted-tbn0.gstatic.com/images?q=tbn%3AANd9GcRXftg4hnegt06hcipBUXK0vM8lgM-AMga9sbdmuGoYmGfUgmOu)|
| :------------- |


|![Ejemplo codigo](http://cursoarduino.proserquisa.com/wp-content/uploads/2016/10/28-02.png)|
| :------------- |

##
|Control de la intensidad-Dimmer Ac|
| :------------- |
|*Fuente*:https://naylampmechatronics.com/drivers/398-modulo-dimmer-ac.html|

El módulo Dimmer AC permite controlar cargas de voltaje alterno (220V AC) desde un microcontrolador como Arduino/Pic/Raspberry Pi/ESP8266. Un Dimmer AC (a diferencia de un Relay) permite el control regulado de voltaje AC, permitiendo obtener voltajes intermedios entre 0 y 220V AC y de esa forma variar la intensidad de brillo en bombillas incandescentes, la velocidad en motores ac como ventiladores, la potencia de un calentador resistivo y más.

Un dimmer integra dos etapas: el detector de cruce por zero y el triac. El detector de cruce por cero es un circuito (normalmente un optoacoplador) que permite identificar el instante en el que el voltaje alterno tiene un valor de 0V, es decir cuando el voltaje "cruza" de voltaje positivo a negativo y viceversa. Los triacs son dispositivos semiconductores (tiristor) que pueden permitir el paso de corriente AC mediante una señal de disparo en cada semiciclo de corriente AC. Los Triac son el corazón de los Relay de estado solido o SSR. A diferencia de los relays mecánicos tradicionales un Triac puede activarse muy rápido permitiendo el paso de una porción de la onda de voltaje alterno.

Para regular el voltaje AC el dimmer necesita sincronizar el cruce por cero con el microcontrolador y a partir de ese instante decidir el momento de activación del Triac, de esa forma es posible regular que parte de la onda senoidal estará activa. Esta técnica es conocida como control por ángulo de disparo y es la más recomendada para variar el brillo en bombillas sin causar parpadeos. Otro método de control usando este dispositivo es la Modulación por salto de pulso.

Dentro del modulo tenemos dos grupos de conexiones: potencia y control. En la parte de potencia son dos borneras, se debe conectar el voltaje AC a las borneras "AC-IN", y la carga a las borneras "LOAD". En la parte de control se tienen 4 headers o pines macho, se debe conectar "VCC" a 5V DC, "GND" se conecta a 0V (GND), "Z-C" es el pin de cruce por cero (zero-cross) y debe ir conectado a una entrada digital del Arduino (Pin 2 o 3 en Arduino Uno), "PWM" es el pin de control de disparo del triac (trigger) y debe ir conectado a una salida digital del Arduino.

|![esquema dimmer](http://s020.radikal.ru/i706/1604/ab/8ea593ac010d.png)|
| :------------- |



