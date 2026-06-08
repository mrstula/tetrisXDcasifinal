#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILAS 20
#define COLS 10

int tablero[FILAS][COLS];

typedef struct{
    int x, y;
    int forma[4][4];
}Pieza;

Pieza actual;

int piezas[4][4][4]={
{
{0,0,0,0},
{1,1,1,1},
{0,0,0,0},
{0,0,0,0}
},
{
{0,1,1,0},
{0,1,1,0},
{0,0,0,0},
{0,0,0,0}
},
{
{0,1,0,0},
{1,1,1,0},
{0,0,0,0},
{0,0,0,0}
},
{
{1,0,0,0},
{1,1,1,0},
{0,0,0,0},
{0,0,0,0}
}
};

void copiarPieza(int n){
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            actual.forma[i][j]=piezas[n][i][j];

    actual.x=3;
    actual.y=0;
}

void nuevaPieza(){
    copiarPieza(rand()%4);
}

int colision(int nx,int ny,int forma[4][4]){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(forma[i][j]){
                int x=nx+j;
                int y=ny+i;

                if(x<0 || x>=COLS || y>=FILAS)
                    return 1;

                if(y>=0 && tablero[y][x])
                    return 1;
            }
        }
    }
    return 0;
}

void fijarPieza(){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(actual.forma[i][j]){
                tablero[actual.y+i][actual.x+j]=1;
            }
        }
    }
}

void eliminarLineas(){
    for(int i=FILAS-1;i>=0;i--){
        int llena=1;

        for(int j=0;j<COLS;j++){
            if(tablero[i][j]==0){
                llena=0;
                break;
            }
        }

        if(llena){
            for(int k=i;k>0;k--){
                for(int j=0;j<COLS;j++)
                    tablero[k][j]=tablero[k-1][j];
            }

            for(int j=0;j<COLS;j++)
                tablero[0][j]=0;

            i++;
        }
    }
}

void rotar(){
    int temp[4][4];

    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            temp[j][3-i]=actual.forma[i][j];

    if(!colision(actual.x,actual.y,temp)){
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
                actual.forma[i][j]=temp[i][j];
    }
}

void dibujar(){
    system("clear");

    for(int i=0;i<FILAS;i++){
        printf("|");

        for(int j=0;j<COLS;j++){

            int ocupado=tablero[i][j];

            for(int r=0;r<4;r++){
                for(int c=0;c<4;c++){
                    if(actual.forma[r][c]){
                        if(i==actual.y+r &&
                           j==actual.x+c)
                            ocupado=1;
                    }
                }
            }

            printf(ocupado ? "1" : "0");
        }

        printf("|\n");
    }

    for(int i=0;i<COLS+2;i++)
        printf("-");
    printf("\n");
}

int main(){

    srand(time(NULL));

    nuevaPieza();

    while(1){

        dibujar();

        char op;
        scanf(" %c",&op);

        if(op=='q' || op=='Q')
            break;

        if(op=='a' || op=='A'){
            if(!colision(actual.x-1,actual.y,actual.forma))
                actual.x--;
        }

        if(op=='d' || op=='D'){
            if(!colision(actual.x+1,actual.y,actual.forma))
                actual.x++;
        }

        if(op=='w' || op=='W')
            rotar();

        if(op=='s' || op=='S'){

            if(!colision(actual.x,actual.y+1,actual.forma))
                actual.y++;

            else{
                fijarPieza();
                eliminarLineas();
                nuevaPieza();

                if(colision(actual.x,actual.y,actual.forma)){
                    printf("GAME OVER\n");
                    break;
                }
            }
        }
    }

    return 0;
}
