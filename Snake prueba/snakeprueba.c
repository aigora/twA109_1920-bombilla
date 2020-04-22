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
void gotoxy(int ,int); 
void dibujar_cuerpo();
void borrar_cuerpo();
void guardar_posicion();
void teclado();
void dibujar_comida();
bool game_over();
void cambiar_velocidad();
void puntuacion();
//Variables globales
	int cuerpo[200][2]; //matriz que crea el cuerpo de la serpiente
	int n=1; //variable para guardar las partes del cuerpo de la serpiente
	int tam=10; //varibale que controla el tamaño de la serpiente
	int x=10;
	int y=12;
	int dir=3; //varibale direccion que empieza haciendo que la serpiente se  mueva hacia la izquierda
	int comidax=10;
	int comiday=15 ;
	int puntos=0;
	int velocidad=100;
	int h=1;
	char tecla;
	
//Funcion principal
int main(void) 
{	
	gotoxy(comidax,comiday);
	printf("%c",4);
	
	while(tecla!=esc&& game_over()) //bucle 
	{	
		
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
	
	system("PAUSE");
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

void dibujar_cuerpo()
{	
	for(int i=1;i<tam;i++)
	{
		gotoxy(cuerpo[i][0], cuerpo[i][1]);
		printf("*");
	}
}

void borrar_cuerpo()
{		
	for(int i=1;i<tam;i++)
	{
		gotoxy(cuerpo[i][0], cuerpo[i][1]);
		printf(" ");
	}	}
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
void puntuacion()
{
	gotoxy(3,1);
	printf("Puntuacion:%d",puntos);
}
void cambiar_velocidad()
{
	if(puntos==h*10)
	{
		velocidad=velocidad-10;
		h++;
	}
}
