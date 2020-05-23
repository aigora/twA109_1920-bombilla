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
void gotoxy2(int,int);
void pintar();
void dibujar_cuerpo1();
void borrar_cuerpo1();
void guardar_posicion1();
void teclado1();
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
	int tam1; //varibale que controla el tamaño de la serpiente 1
	int tam2; //varibale que controla el tamaño de la serpiente 2
	int x1;
	int y1;
	int x2;
	int y2;
	int n;//variable para guardar el numero de jugadores en el torneo
	
	int dir1; //varibale direccion que empieza haciendo que la serpiente se  mueva hacia la izquierda
	int dir2; //varibale direccion que empieza haciendo que la serpiente se  mueva hacia la izquierda
	int comidax=10;
	int comiday=15 ;
	int puntos1;
	int puntos2;
	int velocidad;
	int h;
	char tecla1;
	char tecla2;
	char opcion;
	int cont=1;
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
void teclado1()
{
	if(kbhit())
		 {
		 	tecla1=getch(); //captamos la tecla que se esta pulsando en el teclado
		 	switch(tecla1)
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
	
	if(x1==comidax && y1==comiday)
	{
		
			comidax=(rand()%73)+4;
			comiday=(rand()%19)+4;
			tam1++;
			puntos1=puntos1+10;
			gotoxy(comidax,comiday);
			printf("%c",4);
			cambiar_velocidad();
	}
	else if(x2==comidax && y2==comiday)
	{
		
			comidax=(rand()%75)+3;
			comiday=(rand()%23)+3;
			tam2++;
			puntos2=puntos2+10;
			gotoxy(comidax,comiday);
			printf("%c",4);
			cambiar_velocidad();
	}
		
}
//Funcion auxiliar para determinar si se acaba o no la partida
int game_over1()
{	
	int bandera=1; 
	if(y1==3|| y1== 30||x1==2 ||x1==99 )
		bandera=0;
		for(int j=tam1-1;j>0;j--)	//recorremos todos los valores de la matriz cuerpo1
		{
			if(cuerpo1[j][0]==x1 && cuerpo1[j][1]==y1 && cuerpo2[j][0]==x2 && cuerpo1[j][1]==y2 && cuerpo1[j][0]==x2 && cuerpo1[j][1]==y2 )
			bandera=0;
		}
	return bandera;
}
//Funcion auxiliar para determinar si se acaba la partida o no
int game_over2()
{	int bandera=1;
	if(y1==3|| y1== 30||x1==2 ||x1==99 ||y2==3|| y2== 30||x2==2 ||x2==99 )
		bandera=0;
		for(int j=tam1-1;j>0;j--)	//recorremos todos los valores de la matriz cuerpo1 y cuerpo2
		{
			if((cuerpo1[j][0]==x1 && cuerpo1[j][1]==y1 )|| (cuerpo2[j][0]==x2 && cuerpo2[j][1]==y2) ||(cuerpo1[j][0]==x2 && cuerpo1[j][1]==y2)) 
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
	int i;
	if(opcion==49|| (n%2!=0))
	{
		gotoxy(3,1);
		printf("Puntuacion:%d\n",puntos1);
	}
	else if(opcion==50)
	{
		gotoxy(3,1);
		printf("Jugador 1:%d\n",puntos1);
		gotoxy(3,2);
		printf("Jugador 2:%d\n",puntos2);
	}
	else if(opcion==51 || (n%2==0))
	{
		
		gotoxy(3,1);
		printf("Jugador flechas:%d\n",puntos1);
		gotoxy(3,2);
		printf("Jugador AWSD:%d\n",puntos2);
		
	}
}

//Funcion auxiliar para disminuir la velocidad y que parezca que se mueve mas rapido la serpiente
void cambiar_velocidad()
{
	if(puntos1==h*10 ||puntos2==h*10)
	{
		velocidad=velocidad-5;
		h++;
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
			opcion=getch();
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
	
	while(tecla1!=esc&& game_over1()==1) //bucle 
	{	
		ocultar_cursor();
		pintar();
		 borrar_cuerpo1();
		 guardar_posicion1();
		 dibujar_cuerpo1();
		 teclado1();
		 teclado1();//Se pone para poder dar una tecla y otra en un periodo de tiempo corto y lo reconozca.
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
	
	while(tecla1!=esc&& game_over2()==1&&tecla2!=esc) //bucle 
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
		teclado1();
		teclado1();//Se pone para poder dar una tecla y otra en un periodo de tiempo corto y lo reconozca.
		teclado1();
		teclado1();
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
	system("CLS");
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
	if(n%2==0)
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
				printf("Turno del jugador %d flechas y %d AWSD",i+1,i+1);
				Sleep(2000);
				system("CLS");
				dos_jugador();
				v[i]=puntos1;
				s[i]=puntos2;
				Sleep(2000);
			}
		}
		system("CLS");
		ganar_torneo_p(v,s,n);
		Sleep(2000);
	}
	else
	{
		for( i=0;i<=n;i++)
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
			{	gotoxy(25,5);
				printf("Turno del jugador %d",i+1);
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
	int max=0,igual=0;
	int m=0;
	int s=0;
	int i;
	for (i=0; i<=n; i++)
	{
		if(p[i] > max)
		{
			max =p[i];
			m = (i+1);
		}
		else if(p[i]==max)
		{
			igual=p[i];
			s=(i+1);
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
	int max1=0;
	int max2=0;
	int m1;
	int s1;
	int igual1,igual2;
	int m2;
	int s2;
	int i;
	for (i=0; i<(n/2); i++)
	{
		if(p[i] > max1)
		{
			max1=p[i];
			m1= (i+1);
				
		}
		else if(p[i]==max1)
		{
			igual1=p[i];
			s1=(i+1);
		}
	
		if(q[i]>max2)
			{	
				max2=q[i];
				m2= (i+1);
			}
		else if(q[i]==max2)
		{
			igual2=q[i];
			s2=(i+1);
		}
		
	}
	
	if(max1>max2)
	{ 
		if(max1==igual1)
			printf("Empate entre los jugadores %d flechas y %d flechas",m1,s1);
		else
			printf("El ganador es el %d jugador flechas",m1);
	}
	 if(max2>max1)
	{
		if(max2==igual2)
			printf("Empate entre los jugadores %d AWSD y %d AWSD",m2,s2);
		else
			printf("El ganador es el %d jugador AWSD",m2);
		
	}
	if(max2==max1)
	{
		if(igual1==igual2)
			printf("Empate entre todos los jugadores");
		else
			printf("Empate entre los jugadores %d flechas y %d AWSD",m1,m2);
	}
	
}
//Funcion auxiliar para representar el marcador de los puntos del modo de un jugador
void marcador()
{
	system("CLS");
	gotoxy(25,5);
	printf("Puntuacion:%d\n",puntos1);
	printf("\n");
}
//Funcion para ocultar el cursor durante el juego
void ocultar_cursor() 
{
 CONSOLE_CURSOR_INFO cci = {100, FALSE};
 
 SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}

 



