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
void dibujar_cuerpo();
void borrar_cuerpo();
void guardar_posicion();
void teclado();
void dibujar_comida();
bool game_over();
void cambiar_velocidad();
void puntuacion();
void marcador();
void ocultar_cursor();
//Variables globales
	int cuerpo[200][2]; //matriz que crea el cuerpo de la serpiente
	int n; //variable para guardar las partes del cuerpo de la serpiente
	int tam; //varibale que controla el tamaño de la serpiente
	int x;
	int y;
	int dir; //varibale direccion que empieza haciendo que la serpiente se  mueva hacia la izquierda
	int comidax=10;
	int comiday=15 ;
	int puntos;
	int velocidad;
	int h;
	char tecla;
	int opcion;
//Funcion principal
int main(void) 
{	
	ocultar_cursor();
	do
	{
	
	system("CLS");
	gotoxy(12,5);
	printf("Elija una opcion:\n");
	printf("\t\tUn jugador-1\n");
	printf("\t\tDos jugadores-2\n");
	printf("\t\tSalir-3\n");
	scanf("%d",&opcion);
	switch(opcion)
	{
		case 1: 
		system("CLS");
		n=1;
		x=10; 
		y=12;
		dir=3;
		tam=3;
		puntos=0;
		velocidad=100;
		h=1;
		un_jugador();
		marcador();
		
		
		Sleep(2000);
		
		break;
		case 2:
		break;
		case 3: printf("Cerrando el juego...\n");
		break;
	}
	
}while(opcion!=3);
	
	
	return 0;
}

//Funcion auxiliar de visualización
void gotoxy(int x,int y)
{
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y= y;
	SetConsoleCursorPosition(hcon,dwPos);
}

//Funcion auxiliar para guardar posicion 
void guardar_posicion()
{
	cuerpo[n][0]=x;
	cuerpo[n][1]=y;
	n++; 
	if(n==tam) //no dejamos que n sobrepase a tamanio
		n=1;
}
//Funcion auxiliar para dibujar el cuerpo de la serpiente
void dibujar_cuerpo()
{	
	for(int i=1;i<tam;i++)
	{
		gotoxy(cuerpo[i][0], cuerpo[i][1]);
		printf("*");
	}
}
//Funcion auxilir para dibujar el cuerpo
void borrar_cuerpo()
{		
	for(int i=1;i<tam;i++)
	{
		gotoxy(cuerpo[i][0], cuerpo[i][1]);
		printf(" ");
	}	}
//Función auxiliar para mover la serpiente con el teclado	
void teclado()
{
	if(kbhit())
		 {
		 	tecla=getch();
		 	switch(tecla)
		 	{
		 		case arriba:
		 			if(dir!=2) //Los if son porque la serpiente no puede cambiar su direccion de arriba a abajo o de derecha a izquierda debe avanzar haciendo cuadrados
		 				dir=1;
		 		break;
		 		case abajo:
		 			if(dir!=1)
		 				dir=2;
		 		break;
				case derecha:
					if(dir!=4)
						dir=3;
				break;
				case izquierda:
					if(dir!=3)	
						dir=4;
				break;
			 }
		 }
		 	
}
//Funcion auxiliar para representar la comida
void dibujar_comida ()
{
	
	if(x==comidax && y==comiday)
	{
		comidax=(rand()%73)+3;
		comiday=(rand()%19)+3;
		tam++;
		puntos=puntos+10;
		gotoxy(comidax,comiday);
		printf("%c",4);
		cambiar_velocidad();
	}
}
bool game_over()
{	
	if(y==3|| y== 23||x==2 ||x==77 )
		return false;
		for(int j=tam-1;j>0;j--)	//recorremos todos los valores de la matriz cuerpo
		{
			if(cuerpo[j][0]==x && cuerpo[j][1]==y)
			return false;
		}
	return true;
}
//Funcion auxiliar para la puntuación
void puntuacion()
{
	gotoxy(3,1);
	printf("Puntuacion:%d\n",puntos);
}
//Funcion auxiliar para disminuir la velocidad y que parezca que se mueve mas rapido la serpiente
void cambiar_velocidad()
{
	if(puntos==h*10)
	{
		velocidad=velocidad-5;
		h++;
	}
}
void un_jugador()
{

	gotoxy(comidax,comiday);
	printf("%c",4);
	
	while(tecla!=esc&& game_over()) //bucle 
	{	
		ocultar_cursor();
		pintar();
		 borrar_cuerpo();
		 guardar_posicion();
		 dibujar_cuerpo();
		 teclado();
		 teclado();//Se pone para poder dar una tecla y otra en un periodo de tiempo corto y lo reconozca.
		 dibujar_comida ();
		 puntuacion();
		 if(dir==1) 
			 y--;
		 if(dir==2)
		 	y++;
		 if(dir==3) 
		 	x++;	
		 if(dir==4) 
		 	x--;
		Sleep(velocidad); 
		
	}
}
void marcador()
{
	system("CLS");
	gotoxy(12,5);
	printf("Puntuacion:%d\n",puntos);
	printf("\n");
}
void ocultar_cursor() 
{
 CONSOLE_CURSOR_INFO cci = {100, FALSE};
 
 SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}
void pintar(){ 
 for(int i=2; i < 78; i++){
 gotoxy (i, 3); printf ("%c", 205);
 gotoxy(i, 23); printf ("%c", 205); 
 }
 for(int v=4; v < 23; v++){
 gotoxy (2,v); printf ("%c", 186);
 gotoxy(77,v); printf ("%c", 186); 
 }
 gotoxy (2,3); printf ("%c", 201);
 gotoxy (2,23); printf ("%c", 200);
 gotoxy (77,3); printf ("%c", 187);
 gotoxy(77,23); printf ("%c", 188); 
 } 



