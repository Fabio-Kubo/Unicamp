#include <stdio.h>
#include <stdlib.h>

void multpoly_quad(int n, double A[], double B[], double C[]){

}

void multpoly_fft(int n, double A[], double B[], double C[]){

}

void carregarPolinomios(char * nomeArquivo){

	FILE * file;
	file = fopen(nomeArquivo, "r");
	if(file == NULL){
		printf("Erro ao abrir o arquivo");
		exit(EXIT_FAILURE);
	}
}

int main(){


}
