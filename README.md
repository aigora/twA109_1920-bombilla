# Título del Trabajo
 Snake
## Descripción proyecto
El juego consiste en que dos o más jugadores controlan una larga y delgada línea semejante a una serpiente. Para obtener puntos el usuario deberá recopilar los cuadrados que encuentre a su paso lo que aumentará su tamaño, pudiendo moverse en línea recta y haciendo giros de noventa grados en cualquiera de las direcciones. Además, deberá evitar chocar consigo mismo, con los demás participantes y con los bordes de la pantalla en cuyo caso si lo hiciera el juego terminaría.

## Integrantes del equipo

Víctor José Villamar Guamán.Usuario:@victor-villamar.<p>
Valeri Paola Ramirez Moreira.Usuario:@VALERIRAMIREZ.<p>
Carlos Sandoval Herrera.
Usuario:@Carlos-sandoval.<p>

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

|Snake|
| :------------- |
|Programa en el cual uno o mas jugadores controlan una serpiente simulada por "--" en un espacio limitado en el cual van apareciendo recuadros.El jugador obtiene puntos por cada cuadrado que recoge aumentado la longitud de la serpiente.El usuario pierde cuando choca consigo mismo,con la paredes de la pantalla o si choca con otro jugador.Una vez acabado la partida saldra la puntuacion de los jugadores de mayor a menor.La puntuacion viene determinada por la longitud de la serpiente de cada jugador.|
|**Requisitos funcionales**|
|1º-Poder jugar dos jugadores de forma simultanea con diferentes teclas del teclado.
2º- Poder elegir jugar solo o con mas jugadores.
3º- La serpiente debe poder realizar cualquier tipo de giro para poder moverse con libertad por la pantalla
4º- La puntuacion realizada debe ser almacenada y poder acceder a ella al final de la partida.|

## Identificacion de  subprogramas
<b>-Funcion gotoxy</b>: para representar en pantalla piezas sencillas.Lo que permite esta funciones situar el cursor en el punto en el que quieres empezar a imprimir.Esta funcion devuelve un valor entero.<p>
<b>-Función guardar_posicion</b>:para guardar la posicion en la que se encuentra nuestra serpiente.Esta funcion no devuelve nada.<p>
<b>-Función dibujar_cuerpo</b>:para dibujar el cuerpo de la serpiente.Dentro tiene incluida la funcion gotoxy en un bucle para aumentar el tamaño de la serpiente cuando la varibale "tam" aumente.Esta funcion no devuelve nada<p>
<b>-Función borrar_cuerpo</b>:para borrar el cuerpo de la serpiente.Es la misma funcion que dibujar_cuerpo pero en vez de imprimir un * impirme un espacio.Esta funcion no devuelve nada.<p>
<b>-Función pintar</b>:Delimita el mapa del juego.Dentro lleva incorporada la funcíon gotoxy para que el cursor se coloque en la posición para dibujar el mapa.<p>
<b>-Función teclado1</b>:para mover la serpiente con las flechas del teclado en un jugador y en el caso que sean dos jugadores tambien con las letras awsd.Dentro lleva incorporado la funcion kbhit que devuelve uno cuando se pulsa una tecla y cero si no se ha pulsado.Para capturar la tecla pulsada se utiliza la funcion getch que devuelve la tecla pulsada.<p>
<b>-Función dibujar_comida</b>:para dibujar la comida.Dentro de ella lleva la funcion rand para que al aplicar la funcion gotoxy no situe el cursor en lugares aleatorios.Ademas cada vez que se ejecuta esta funcion se aumenta el tamaño de la serpiente y los puntos.<p>
<b>-Función puntuacion</b>:para representar la puntuación del jugador.Dentro lleva la funcion gotoxy para situar el marcador.<p>
<b>-Función game_over</b>:para determinar cuando se temina el juego.La funcion recorre los elementos que forman la serpiente y si coincide su posicion con las paredes del mapa o con sigo misma (en el caso de dos jugadores lo mismo con la otra serpiente y ademas compara que ambas no tengan la misma posición) devuelve false.<p>
<b>-Funcion ganador_2j</b>:determina en el modo de dos jugadores quien ha ganado comparando sus puntuaciones.En el caso de que sean iguales o que ninguno tenga puntuacion considera que es empate.<p>
<b>-Función menu</b>:Crea un menu de opciones para determinar a que modo quieres acceder.Este menu se repite hasta que el usuario pulse la tecla 3.<p>
<b>-Función un_jugador</b>:Incorpora todas las funciones excepto las de dos jugadores.Funcion que pone en marcha el juego.<p>
<b>-Funcion dos_jugador</b>:Incopora todas las funciones y pone en marcha el juego pero para dos personas.<p>
<b>-Función marcador</b>:Crea un marcador al final de la partida de un jugador.<p>
<b>-Función ocultar_cursor</b>:Oculta el cursor.<p>




