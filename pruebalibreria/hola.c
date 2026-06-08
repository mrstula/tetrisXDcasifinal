#include"teclado.h"
#include<stdio.h>
#include <unistd.h>

int main(){
	while(1){
	if(tecla_presionada()){
		char t=leer_tecla();

		printf("%c",t);
	}}
}
