#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include <conio.h>

//Numeros asociados a las flechas del teclado
#define arriba 72
#define izquierda 75
#define derecha 77
#define abajo 80
#define esc 27




//Funciones portotipo
void un_jugador();
void gotoxy(int ,int); 
void pintar();
void dibujar_cuerpo1();
void borrar_cuerpo1();
void guardar_posicion1();
void teclado();
void dibujar_cuerpo2();
void borrar_cuerpo2();
void guardar_posicion2();
void dibujar_comida();
int game_over1();
int game_over2();
void ganador_2j();
void cambiar_velocidad();
void puntuacion();
void marcador();
void ocultar_cursor();
void dos_jugador();
void torneo();
void ganar_torneo_i(int *,int );
void ganar_torneo_p(int *,int *,int);
void menu();
//Variables globales
	int cuerpo1[200][2]; //matriz que crea el cuerpo de la serpiente 1
	int cuerpo2[200][2]; //matriz que crea el cuerpo de la serpiente 2
	int n1; //variable para guardar las partes del cuerpo de la serpiente 1
	int n2; //variable para guardar las partes del cuerpo de la serpiente 2
	int tam1; //variable que controla el tamaño de la serpiente 1
	int tam2; //variable que controla el tamaño de la serpiente 2
	int x1; //variable para la posicion de la serpiente 1 en eje OX
	int y1;//variable para la posicion de la serpiente 1 en eje OY
	int x2;//variable para la posicion de la serpiente 2 en eje OX
	int y2;//variable para la posicion de la serpiente 2 en eje OY
	int n;//variable para guardar el numero de jugadores en el torneo
	
	int dir1; //variable direccion que empieza haciendo que la serpiente se  mueva hacia la izquierda
	int dir2; //variable direccion que empieza haciendo que la serpiente se  mueva hacia la izquierda
	int comidax=10; //variable para la posicion de la comida en el eje OX
	int comiday=15 ;//variable para la posicion de la comida en el eje OY
	int puntos1;//variable para almacenar los puntos del jugador 1 en el modo un jugador,dos jugadores y torneo impar
	int puntos2;//variable para almacenar los puntos del jugador 2 en el modo dos jugadores y torneo par
	int velocidad;//variable para la velocidad del juego
	int h;//variable para comparar con la puntuacion
	char tecla;//variable para reconocer la tecla pulsada
	char opcion;//variable para reconocer la opcion a elegir
	
//Funcion principal
int main(void) 
{	
	ocultar_cursor();
	menu();
	return 0;
}

//Funcion auxiliar de visualización
void gotoxy(int x,int y)
{
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x1;
	dwPos.Y= y1;
	dwPos.X = x2;
	dwPos.Y= y2;
	dwPos.X = x;
	dwPos.Y= y;
	SetConsoleCursorPosition(hcon,dwPos);
}

//Funcion auxiliar para guardar posicion  de la serpiente 1
void guardar_posicion1()
{
	cuerpo1[n1][0]=x1;	
	cuerpo1[n1][1]=y1;
	n1++; 
	if(n1==tam1) //no dejamos que n sobrepase a tamaño
		n1=1;
}
//Funcion auxiliar para guardar la posicion de las serpiente 2
void guardar_posicion2()
{
	cuerpo2[n2][0]=x2;
	cuerpo2[n2][1]=y2;
	n2++; 
	if(n2==tam2) //no dejamos que n sobrepase a tamaño
		n2=1;
}
//Funcion auxiliar para dibujar el cuerpo de la serpiente 1
void dibujar_cuerpo1()
{	
	for(int i=1;i<tam1;i++)
	{
		gotoxy(cuerpo1[i][0], cuerpo1[i][1]);
		printf("*");
	}
}
//Funcion auxiliar para dibujar el cuerpo de la serpiente 2
void dibujar_cuerpo2()
{	
	for(int i=1;i<tam2;i++)
	{
		gotoxy(cuerpo2[i][0], cuerpo2[i][1]);
		printf("*");
	}
} 
//Funcion auxiliar para dibujar el escenario donde se movera la serpiete o serpientes
void pintar(){ 
 for(int i=2; i <100 ; i++){
 gotoxy (i, 3); printf ("%c", 205);
 gotoxy(i, 30); printf ("%c", 205); 
 }
 for(int v=4; v < 30; v++){
 gotoxy (2,v); printf ("%c", 186);
 gotoxy(99,v); printf ("%c", 186); 
 }
 gotoxy (2,3); printf ("%c", 201);
 gotoxy (2,30); printf ("%c", 200);
 gotoxy (99,3); printf ("%c", 187);
 gotoxy(99,30); printf ("%c", 188); 
 } 
//Funcion auxilir para borrar el cuerpo de la serpiente 1
void borrar_cuerpo1()
{		
	for(int i=1;i<tam1;i++)
	{
		gotoxy(cuerpo1[i][0], cuerpo1[i][1]);
		printf(" ");
	}	
	
}
//Funcion auxilir para borrar el cuerpo de la serpiente 2
	void borrar_cuerpo2()
{		
	for(int i=1;i<tam2;i++)
	{
		gotoxy(cuerpo2[i][0], cuerpo2[i][1]);
		printf(" ");
	}	
	
}
//Función auxiliar para mover la serpiente con el teclado	
void teclado()
{
	if(kbhit())
		 {
		 	tecla=getch(); //captamos la tecla que se esta pulsando en el teclado
		 	switch(tecla)
		 	{
		 		case arriba:
		 			if(dir1!=2) //Los if son porque la serpiente 1 no puede cambiar su direccion de arriba a abajo o de derecha a izquierda debe avanzar haciendo cuadrados
		 				dir1=1;
		 		break;
		 		case abajo:
		 			if(dir1!=1)
		 				dir1=2;
		 		break;
				case derecha:
					if(dir1!=4)
						dir1=3;
				break;
				case izquierda:
					if(dir1!=3)	
						dir1=4;
				break;
				
				case 'w':
		 			if(dir2!=6) //Los if son porque la serpiente 2 no puede cambiar su direccion de arriba a abajo o de derecha a izquierda debe avanzar haciendo cuadrados
		 				dir2=5;
		 		break;
		 		case 's':
		 			if(dir2!=5)
		 				dir2=6;
		 		break;
				case 'd':
					if(dir2!=8)
						dir2=7;
				break;
				case 'a':
					if(dir2!=7)	
						dir2=8;
				break;
			 }
		 }
		 	
}

//Funcion auxiliar para representar la comida
void dibujar_comida ()
{
	
	if(x1==comidax && y1==comiday) //si la serpiente 1 se ha comido la comida
	{
		//se le da una nueva posicion a las varibles comidax y comiday en el eje OX y OY de forma aleatoria
			comidax=(rand()%73)+4; 
			comiday=(rand()%19)+4;
			tam1++;//se aumenta el tamaño de la serpiente 1
			puntos1=puntos1+10; //se aumenta la puntuacion de la serpiente 1
			gotoxy(comidax,comiday);//se situa el cursor en la nueva posicion de la comida
			printf("%c",4);//se dibuja la comida
			cambiar_velocidad();
	}
	else if(x2==comidax && y2==comiday) //si la serpiente 2 se ha comido la comida
	{
			//se le da una nueva posicion a las varibles comidax y comiday en el eje OX y OY de forma aleatoria
			comidax=(rand()%75)+3;
			comiday=(rand()%23)+3;
			tam2++;//se aumenta el tamaño de la serpiente 2
			puntos2=puntos2+10;//se aumenta la puntuacion de la serpiente 2
			gotoxy(comidax,comiday);//se situa el cursor en la nueva posicion de la comida
			printf("%c",4);//se dibuja la comida
			cambiar_velocidad();
	}
		
}
//Funcion auxiliar para determinar si se acaba o no la partida en el formato un jugador
int game_over1()
{	
	int bandera=1; 
	if(y1==3|| y1== 30||x1==2 ||x1==99 ) // en el caso que la serpiente choque con los bordes
		bandera=0; 
		for(int j=tam1-1;j>0;j--)	//recorremos todos los valores de la matriz cuerpo1
		{
			if(cuerpo1[j][0]==x1 && cuerpo1[j][1]==y1) //caso en el que la serpiente 1 choqque consigo misma
			bandera=0;
		}
	return bandera;
}
//Funcion auxiliar para determinar si se acaba la partida o no en el formato de dos jugadores
int game_over2()
{	int bandera=1;
	if(y1==3|| y1== 30||x1==2 ||x1==99 ||y2==3|| y2== 30||x2==2 ||x2==99 )
		bandera=0;
		for(int j=tam1-1;j>0;j--)	//recorremos todos los valores de la matriz cuerpo1 y cuerpo2
		{
			if((cuerpo1[j][0]==x1 && cuerpo1[j][1]==y1 )|| (cuerpo2[j][0]==x2 && cuerpo2[j][1]==y2) ||(cuerpo1[j][0]==x2 && cuerpo1[j][1]==y2)) //caso en el que la serpiente 1 o la serpiente 2 choca con su propio cuerpo o se chocan entre si
			bandera=0;
		}
		return bandera;
}
//Funcion auxiliar para determinar el ganador de el modo 2 jugadores
void ganador_2j()
{
	system("CLS");
	if(puntos1>puntos2)
	{
		gotoxy(25,5);
		printf("Jugador 1 ha ganado.\n");
	}
	else if (puntos2>puntos1)
	{
		gotoxy(25,5);
		printf("Jugador 2 ha ganado.\n");
	}
	else
	{
		gotoxy(25,5);
		printf("Empate");
	}
}

//Funcion auxiliar para la puntuación
void puntuacion()
{

	if(opcion==49|| (n%2!=0)) //si se elige el modo de un jugador
	{
		gotoxy(3,1);
		printf("Puntuacion:%d\n",puntos1);// se imprime la puntuacion
	}
	else if(opcion==50)//si se elige el modo de dos jugadores
	{
		gotoxy(3,1);
		printf("Jugador 1:%d\n",puntos1);//se imprime la puntuacion del jugador 1
		gotoxy(3,2);
		printf("Jugador 2:%d\n",puntos2);//se imprime la puntuacion del jugador 2
	}
	else if(opcion==51 || (n%2==0)) //si se elige el modo torneo
	{
		
		gotoxy(3,1);
		printf("Jugador flechas:%d\n",puntos1);//se imprime la puntuacion del jugador flechas
		gotoxy(3,2);
		printf("Jugador AWSD:%d\n",puntos2);//se imprime la puntuacion del jugador  AWSD
		
	}
}

//Funcion auxiliar para disminuir la velocidad y que parezca que se mueve mas rapido la serpiente
void cambiar_velocidad()
{
	if(puntos1==h*10 ||puntos2==h*10)
	{
		velocidad=velocidad-5;// se disminuye la velocidad
		h++;// se aumenta el tamaño de la varibale
	}
}
//Funcion auxiliar para crear un menu de opciones
void menu()
{
	do //El menu se repite hasta que se pulse la tecla 4
	{
	
		system("CLS");
		gotoxy(25,5);
		printf("Elija una opcion:\n");
		printf("\t\tUn jugador-1\n");
		printf("\t\tDos jugadores-2\n");
		printf("\t\tTorneo-3\n");
		printf("\t\tSalir-4\n");
		if(kbhit())
		 {
			opcion=getch();// se capta la opcion con el teclado
			switch(opcion)
			{
				case 49: 
				system("CLS");//Se borra todo lo que hay en la pantalla
				//Delcaramos todas las variables necesarias para el modo de 1 jugador
				n1=1;
				x1=10; 
				y1=12;
				dir1=3;
				tam1=3;
				puntos1=0;
				velocidad=100;
				h=1;
				un_jugador();
				marcador();
				
				
				Sleep(2000);//El programa se detiene por 2000 segundos
				
				break;
				case 50:
					system("CLS");//Se borra todo lo que hay en la pantalla
				//Declaramos todas la variables necesarias para el modo de 2 jugadores
				n1=1;
				x1=10; 
				y1=12;
				dir1=3;
				tam1=3;
				n2=1;
				x2=50;
				y2=12;
				dir2=7;
				tam2=3;
				puntos1=0;
				puntos2=0;
				velocidad=100;
				h=1;
				dos_jugador();
				Sleep(2000);//El programa se detine por 2000 segundos
				break;
				case 51:
					torneo();
				
					break;
					
				case 52: printf("Cerrando el juego...\n");
				break;
			}
		}
	
}while(opcion!=52);

}
//Funcion auxiliar para crear el modo de un jugador
void un_jugador()
{

	gotoxy(comidax,comiday);
	printf("%c",4);
	
	while(tecla!=esc&& game_over1()==1) //bucle que se repite hasta que el jugador pulse esc o pierda la partida
	{	
		ocultar_cursor();
		pintar();
		 borrar_cuerpo1();
		 guardar_posicion1();
		 dibujar_cuerpo1();
		 teclado();
		 teclado();//Se pone para poder dar una tecla y otra en un periodo de tiempo corto y lo reconozca.
		 dibujar_comida ();
		 puntuacion();
		 if(dir1==1) 
			 y1--;
		 if(dir1==2)
		 	y1++;
		 if(dir1==3) 
		 	x1++;	
		 if(dir1==4) 
		 	x1--;
		Sleep(velocidad); 
		
	}
}
//Funcion auxiliar para crear el modo de dos jugadores
void dos_jugador()
{

	gotoxy(comidax,comiday);
	printf("%c",4);
	
	while(tecla!=esc && game_over2()==1) //bucle que se repite hasta que uno de los jugadores pulse esc o se acabe el juego
	{	
		ocultar_cursor();
		pintar();
		borrar_cuerpo2();
		guardar_posicion2();
		dibujar_cuerpo2();
		borrar_cuerpo1();
		guardar_posicion1();
		dibujar_cuerpo1();
		dibujar_comida ();
		puntuacion();
		teclado();
		teclado();//Se pone para poder dar una tecla y otra en un periodo de tiempo corto y lo reconozca.
		teclado();
		teclado();
		//Serpiente 1
		 if(dir1==1) 
			 y1--;
		 if(dir1==2)
		 	y1++;
		 if(dir1==3) 
		 	x1++;	
		 if(dir1==4) 
		 	x1--;
		//Serpiente 2
		 	if(dir2==5) 
			y2--;
		 if(dir2==6)
		 	y2++;
		 if(dir2==7) 
		 	x2++;	
		 if(dir2==8) 
		 	x2--;
		
		Sleep(velocidad); 	
	}
	if(opcion==50)
		ganador_2j();
}

//Funcion auxiliar para crear el modo torneo
void torneo()
{
	system("CLS");//se borra lo que hay en la pantalla
	int *v,*s; //Se crean dos vectores dinamicos
	int i;
	do 
	{
		printf("Introduce el numero de jugadores:");
			scanf("%d",&n);
		if(n<3 || n>8)
		printf("Minimo 3 jugadores y maximo de 8.\n");
						
	}while(n<3 || n>8);
	v=(int *)malloc(n*sizeof(int)); //Se pide memoria para el vector v
	s=(int *)malloc(n*sizeof(int)); // Se pide memoria para el vector s
	if(s==NULL || v==NULL)
		printf("Memoria insuficiente");
	else //Si hay memoria suficiente para los dos vectores entonces se puede continuar
{
	if(n%2==0)//solo en el caso que los jugadores sean pares
	{			
		for(i=0;i<(n/2);i++)
		{
			system("CLS");
			n1=1;
			x1=10; 
			y1=12;
			dir1=3;
			tam1=3;
			n2=1;
			x2=50;
			y2=12;
			dir2=7;
			tam2=3;
			puntos1=0;
			puntos2=0;
			velocidad=100;
			h=1;
				
			if(i!=n)
			{
				gotoxy(25,5);
				printf("Turno del jugador %d flechas y %d AWSD",i+1,i+1);// se indica el turno de cada jugador
				Sleep(2000);
				system("CLS");
				dos_jugador();
				v[i]=puntos1;//se le asigna al vector dinamico los puntos en cada partida del jugador flecha
				s[i]=puntos2;//se le asigna al vector dinamico los puntos en cada partida del jugador AWSD
				Sleep(2000);
			}
		}
		system("CLS");
		ganar_torneo_p(v,s,n);
		Sleep(2000);
	}
	else //en el caso que los jugadores sean  impares
	{
		for( i=0;i<=n;i++)
		{
			system("CLS");
			n1=1;
			x1=10; 
			y1=12;
			dir1=3;
			tam1=3;
			puntos1=0;
			velocidad=100;
			h=1;
				
			if(i!=n)
			{	gotoxy(25,5);
				printf("Turno del jugador %d",i+1);// se indica el turno de cada jugador
				Sleep(2000);
				system("CLS");
				un_jugador();
				v[i]=puntos1;
				Sleep(2000);
			}
		}
		
		ganar_torneo_i(v,n);
		Sleep(2000);
	}
}
}
//Funcion auxiliar para determinar el ganador del modo torneo de jugadores impares
void ganar_torneo_i(int *p,int n)
{	
	int max=0;//variable para almacenar la puntuacion maxima
	int igual=0; //variable para el caso de empate
	int m=0;//varibale para guardar la posicion donde se encuentre el maximo en el vector
	int s=0;//varibale para guardar la posicion donde se encuentre el igual en el vector
	int i;
	for (i=0; i<=n; i++)
	{
		if(p[i] > max) //caso en el que el vector sea mayor que el maximo
		{
			max =p[i];//se pasa el valor del vector a la varible max
			m = (i+1);//se determina la posicion en el vector
		}
		else if(p[i]==max)//caso en en el que el vector es igual a el maximo
		{
			igual=p[i];//se pasa el valor del vector a la varibale igual
			s=(i+1);// se determina la posicion en el vector
		}
	}	
	if(max>igual)
	printf("El ganador es el %d jugador",m);
	else if(max==igual)
	printf("Empate entre el %d jugador y el %d jugador",m,s);
	
}
//Funcion auxiliar para determinar el ganador del modo torneo de jugadores pares
void ganar_torneo_p(int *p,int *q,int n)
{
	int max1=0;//varibale para almacenar el maximo de los jugadores flechas
	int max2=0;//varibale para almacenar el maximo de los jugadores AWSD
	int m1;//varibale para guardar la posicion donde se encuentre el maximo en el vector de los jugadores flechas
	int s1;//varibale para guardar la posicion donde se encuentre el maximo en el vector de los jugadores AWSD
	int igual1,igual2;//varibales para el caso de que sea igual al maximo en cada jugador
	int m2;//varibale para almacenar el igual de los jugadores flechas
	int s2;//varibale para almacenar el igual de los jugadores flechas
	int i;
	for (i=0; i<(n/2); i++) //se repite el bucle la mitad de las veces
	{
		if(p[i] > max1)//caso en el que el vector de jugador flecas sea mayor que el maximo
		{
			max1=p[i];// se pasa el valor del vector de jugador flechas a la variable 
			m1= (i+1);// se determina la posicion en el vector
				
		}
		else if(p[i]==max1)//caso en en el que el vector de jugador flechas es igual a el maximo
		{
			igual1=p[i];//se pasa el valor del vector de jugador flechas a la varibale
			s1=(i+1);// se determina la posicion en el vector
		}
	
		if(q[i]>max2)//caso en el que el vector de jugador AWSD sea mayor que el maximo
			{	
				max2=q[i];// se pasa el valor del vector de jugador AWSD a la variable 
				m2= (i+1);// se determina la posicion en el vector
			}
		else if(q[i]==max2)//caso en en el que el vector de jugador AWSD es igual a el maximo
		{
			igual2=q[i];//se pasa el valor del vector de jugador AWSD a la varibale
			s2=(i+1);// se determina la posicion en el vector
		}
		
	}
	
	if(max1>max2)//caso en el que max1 es mayor max2
	{ 
		if(max1==igual1)//ademas igual1 el igual a max1
			printf("Empate entre los jugadores %d flechas y %d flechas",m1,s1);
		else
			printf("El ganador es el %d jugador flechas",m1);
	}
	 if(max2>max1)//caso en el que max2 es mayor max1
	{
		if(max2==igual2)//ademas igual2 el igual a max2
			printf("Empate entre los jugadores %d AWSD y %d AWSD",m2,s2);
		else
			printf("El ganador es el %d jugador AWSD",m2);
		
	}
	if(max2==max1)//caso en en el que los maximos sean iguales
	{
		if(igual1==igual2)//ademas son iguales los iguales
			printf("Empate entre todos los jugadores");
		else
			printf("Empate entre los jugadores %d flechas y %d AWSD",m1,m2);
	}
	
}
//Funcion auxiliar para representar el marcador de los puntos del modo de un jugador
void marcador()
{
	system("CLS"); //se borra la pantalla
	gotoxy(25,5);//se coloca el cursor en esa posicion
	printf("Puntuacion:%d\n",puntos1);//se imprime la puntuacion
	printf("\n");
}
//Funcion para ocultar el cursor durante el juego
void ocultar_cursor() 
{
 CONSOLE_CURSOR_INFO cci = {100, FALSE};
 
 SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}

 



