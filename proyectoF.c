#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "proyectoF.h"

typedef struct Nota{
    int freq;
    int dur;
}Nota;

void reproducir(int f, int d){
    char cmd[100];
    sprintf(cmd,"beep -f %d -l %d",f,d);
    system(cmd);
}//nota para quien lo nesecite 
 //no se le puede bajar el volumen 
 //porque no se la verdad todo es culpa de pedro sanchez
 //nota 2 no le muevas a esta libreria nisiquiera yo se como funcionan los hilos 
 //aprendi a usarlos hace dos semanas XD

void *musica(void *arg){

    Nota tetris[]={
    {659,200},{494,200},{523,200},{587,200},
    {523,200},{494,200},{440,200},
    {440,200},{523,200},{659,200},
    {587,200},{523,200},{494,200},
    {523,200},{587,200},{659,200},
    {523,200},{440,200},{440,400},

    {587,200},{698,200},{880,200},
    {784,200},{698,200},{659,200},
    {523,200},{659,200},{587,200},
    {523,200},{494,200},{494,400},

    {523,200},{587,200},{659,200},
    {523,200},{440,200},{440,400},

    {587,200},{698,200},{880,200},
    {784,200},{698,200},{659,200},
    {523,200},{659,200},{587,200},
    {523,200},{494,200},{494,400}
    };

    int n = sizeof(tetris)/sizeof(Nota);

    while(1){// repetir la canción
        for(int i=0;i<n;i++){
            reproducir(tetris[i].freq,tetris[i].dur);
            usleep(5000);
        }

    }
    return NULL;
}
int sonido(){
	pthread_t hilo;
	pthread_create(&hilo, NULL, musica, NULL);
}
