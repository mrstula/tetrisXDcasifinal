#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include<ctype.h>
#include"teclado.h"
#include"proyectoF.h"

int figura[7][4][4]={//arreglo de las figuras:V
		         {{0,1,0,0},{0,1,0,0},{0,1,0,0},{0,1,0,0}}//|
			,{{0,0,0,0},{0,1,1,0},{0,1,1,0},{0,0,0,0}}//O
			,{{0,0,0,0},{0,1,1,0},{0,0,1,1},{0,0,0,0}}//S
			,{{0,0,0,0},{0,1,1,0},{1,1,0,0},{0,0,0,0}}//Z
			,{{0,0,1,0},{0,0,1,0},{0,1,1,1},{0,0,0,0}}//T
			,{{0,0,1,0},{0,0,1,0},{0,0,1,1},{0,0,0,0}}//L
			,{{0,0,1,0},{0,0,1,0},{0,1,1,0},{0,0,0,0}}//J
	};

void imprimir(int **m,int fil,int col);
int **pasarPieza(int **m,int pieza);
void juego();
int** crear(int fil,int col){
	int** matriz;
	matriz=(int**)calloc(fil,sizeof(int*));
	for(int i=0;i<fil;i++){
		matriz[i]=(int*)calloc(col,sizeof(int));
	}

	return matriz;
}

int  main(){
	
	//nota no olvidar implementar la musica
	srand(time(NULL));

	char p;
	int si=1;
	char carga[] = {'|', '/', '-', '\\'};

	while(si==1){//nota: no olvidar hacer intrucciones
	         void *a=musica((void *)(0));
		 printf("-----------------------------\n");
		 printf("MENU:::::::::::::::::::::::::\n");
		 printf("JUGAR:::::::::::::::::::::::J\n");
		 printf("MEJORES PUNTAJES::::::::::::M\n");
		 printf("INSTRUCCIONES:::::::::::::::I\n");
		 printf("SALIR:::::::::::::::::::::::Q\n");
		 printf("-----------------------------\n");
		 scanf("%c",&p);
		 p=tolower(p);
		switch(p){
			case 'j'://jugar o el juego en si 
				 juego();
				break;

			case 'm'://mejores punuajes
				 
				break;
			case 'i'://instrucciones
				 break;
			case 'q':  limpiarpantalla();
				 printf("Saliendo ");
				 for(int i = 0; i < 20; i++) {
					 printf("\b%c", carga[i % 4]);
					 fflush(stdout);//fuerzo la impresion de los caracteres para la carga
					 usleep(100000);
				 }
				 printf("\b \n");// \b es para que vuelva un caracter hacia atras o lo borre mejor dicho
				 si=0;
				 break;
			default:
				 break;
		}
	}

	return 0;	
}

void imprimir(int **m,int fil,int col){
	for(int i=0;i<fil;i++){
		for(int j=0;j<col;j++){
			printf("%d ",m[i][j]);
		}
		printf("\n");
		}
	printf("\n");
}

int **pasarPieza(int **m,int p){
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			//hola
			m[i][j+3]=figura[p][i][j];
		}
	}
	return m;
}
void juego(){

	char carga[] = {'|', '/', '-', '\\'};
	int pieza=0,posY=19;
	int filas=20,col=10;
	int **m;
	int **auxi;//posiblemente lo use como auxiliar

	m=crear(filas,col);
	pieza = rand()%7;

	while(1){
		
		
		m=pasarPieza(m,pieza);
		
		pieza=rand()%7;
		limpiarpantalla();
		imprimir(m,filas,col);
		sleep(1);
		//si le el teclado?
	       //si lo lee xd
	
	if(tecla_presionada()){


		char t=leer_tecla();
		if(t=='q'||t=='Q'){
			limpiarpantalla();
			printf("Saliendo ");
			for(int i = 0; i < 20; i++) {
				printf("\b%c", carga[i % 4]);
				fflush(stdout);//fuerzo la impresion de los caracteres para la carga
				usleep(100000);
			}printf("\b \n");
			
		break;
		}
	}
	}
	
	for(int i=0;i<filas;i++)free(m[i]);
	free(m);
}
/*
 *    _
       .__(.)< (MEOW)
        \___)   
 ~~~~~~~~~~~~~~~~~figura*/
