# Título del Trabajo
 Bombilla
## Descripción proyecto
Controlar la iluminacion de una bombilla mediante la intensidad del silbido.<p>
La intensidad del silbido se detectara con un sensor de sonido que recogera los datos en arduino y seran enviados al ordenador.<p>
En C se desarollara un algoritmo que con los datos recogidos mande una informacion u otra para que se ilumine mas o menos la bombilla.<p>
Esta informacion,enviada por el ordenador, sera devuelta a arduino con el cual se iluminara la bombilla.




![Untitled Diagram](https://user-images.githubusercontent.com/61121669/76017871-9bc18f80-5f1f-11ea-8e34-9d41923a7931.png)


## Integrantes del equipo

<p>Víctor José Villamar Guamán  usuario:@victor-villamar.<p>
<p>Valeri Paola Ramirez Moreira usuario:@VALERIRAMIREZ.<p>
<p>Carlos Sandoval Herrera usuario:@Carlos-sandoval.<p>

## Objetivos del trabajo
<li>Consultar bibliografia para seleccionar un algoritmo sencillo para captar la entrada de sonido como la salida de luminosidad.

<li>Transmitir la intensidad al PC y alimentar con ella el algoritmo de determinacion de la intensidad.

<li>Crear un algoritmo que sea capaz de determinar la luminosidad en funcion de la intensidad del sonido.

### Hadware
Pc,Arduino UNO,Sensor de sonido,Dimmer AC,bombilla.
### Software
Desarrollo en C.Programacion del microcontrolador a través del IDE de Arduino

## Datos de los miembros del grupo
|Nombre|Apellidos|Nº Matricula|Email|
| :-------------: | :-------------: |:-------------: |:-------------: |
|Víctor José|Villamar Guamán|55512|victor.villamar.guaman@alumnos.upm.es|
|           |               |     |                                     |
|           |               |     |                                     |

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

** Hadware-Fundamentos técnicos
|Detectacion del sonido-Sensor sonido KY-038|
| :------------- |
|Fuente:https://www.luisllamas.es/detectar-sonido-con-arduino-y-microfono-ky-038/|

Un micrófono es un transductor que convierte las ondas sonoras en señales eléctricas.Podemos conectar un micrófono a un procesador como Arduino para detectar sonidos.
La salida producida por un micrófono es una señal eléctrica analógica que representa el sonido recibido. Sin embargo, en general, esta señal demasiado baja para ser medida y tiene que ser amplificada.<p>

![Explicacion sonido](https://www.luisllamas.es/wp-content/uploads/2016/11/arduino-microfono-ky-038-funcionamiento.png)
<p>

Existen placas como la KY-038 que incorporan un micrófono junto con un comparador LM393, que permite obtener la lectura tanto como un valor analógico como de forma digital.
El uso habitual de este tipo de sensores no amplificados es emplear la salida digital para detectar el sonido cuando este supera un cierto umbral, regulado a través de un potenciómetro ubicado en la placa.

La salida analógica permite obtener una estimación del volumen registrado. Sin embargo, como hemos comentado, este tipo de módulos con micrófono no resultan adecuados para medir el sonido de forma analógica ya que carecen de amplificación.

Si solo queremos detectar el sonido, y no medirlo, este tipo de sensores son más apropiados ya que únicamente requieren la lectura de una señal digital, sin necesitar realizar más cálculos.
**Nota:** Deberemos calibrar el umbral de disparo de la salida digital con el potenciómetro instalado en el módulo para el nivel de sonido deseado.
<p>

|![ imagen montaje](https://encrypted-tbn0.gstatic.com/images?q=tbn%3AANd9GcRXftg4hnegt06hcipBUXK0vM8lgM-AMga9sbdmuGoYmGfUgmOu)|
<p>

|![Ejemplo codigo](http://cursoarduino.proserquisa.com/wp-content/uploads/2016/10/28-02.png)|



