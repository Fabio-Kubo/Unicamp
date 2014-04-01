#include <stdio.h>
#include <string.h>

#define PAREDE_CHAR  '#'
#define VERTICAL_CHAR  '|'
#define HORIZONTAL_CHAR  '-'
#define MUDANCA_DIRECAO_CHAR  '+'
#define DIRECAO_HORIZONTAL  1
#define DIRECAO_VERTICAL  0
#define DIRECAO_INCIAL -1

struct Ponto{
	int Linha;
	int Coluna;	
};

typedef struct Ponto Ponto;

struct Labirinto{
	char Matriz[25][25];
	int TamLinha;
	int TamColuna;
	Ponto PontoInicial;
	Ponto PontoFinal;
	enum Situacao{NaoResolvido, Resolvido}Situacao;
};

typedef struct Labirinto Labirinto; 

void CarregarLabirinto(Labirinto *labirinto, char* nomeArquivo)
{
	FILE *file;
	file = fopen(nomeArquivo, "r");
	int i, j;
	if(file == NULL)
		printf("Nao foi possivel abrir o arquivo.");
	else
	{
		// Lê a dimensáo do Labirinto
		fscanf(file, "%d %d\n", &(*labirinto).TamLinha, &(*labirinto).TamColuna);
		
		//Lê o ponto inicial
		fscanf(file, "%d %d\n", &(*labirinto).PontoInicial.Linha, &(*labirinto).PontoInicial.Coluna);		

		for(i = 0; i < (*labirinto).TamLinha; i++)
		{
			for(j = 0; j < (*labirinto).TamColuna; j++)
			{
				fscanf(file, "%c", &(*labirinto).Matriz[i][j]);
				if((*labirinto).Matriz[i][j] == '\n')
					j--;
				else if((*labirinto).Matriz[i][j] == 'f')
				{
					(*labirinto).PontoFinal.Linha = i;
					(*labirinto).PontoFinal.Coluna = j;
				}
			}
		}

		//Seta o início no Labirinto
		(*labirinto).Matriz[(*labirinto).PontoInicial.Linha][(*labirinto).PontoInicial.Coluna] = 'i';

		fclose(file);
	}
}

int IsCaracterEspecial(Labirinto * labirinto, int linha, int coluna)
{
	return (((*labirinto).Matriz[linha][coluna] == PAREDE_CHAR)
		|| ((*labirinto).Matriz[linha][coluna] == VERTICAL_CHAR)
		|| ((*labirinto).Matriz[linha][coluna] == HORIZONTAL_CHAR)
		|| ((*labirinto).Matriz[linha][coluna] == MUDANCA_DIRECAO_CHAR)
		|| ((*labirinto).Matriz[linha][coluna] == 'i')
		|| ((*labirinto).Matriz[linha][coluna] == 'X'));
}

int  PodeIrPraCima(Labirinto * labirinto, int linha, int coluna)
{
	int linhaCima = linha - 1;
	return !IsCaracterEspecial(labirinto, linhaCima, coluna);
}

int  PodeIrPraBaixo(Labirinto * labirinto, int linha, int coluna)
{
	int linhaBaixo = linha + 1;
	return !IsCaracterEspecial(labirinto, linhaBaixo, coluna);
}

int  PodeIrPraEsquerda(Labirinto * labirinto, int linha, int coluna)
{
	int colunaEsquerda = coluna - 1;
	return !IsCaracterEspecial(labirinto, linha, colunaEsquerda);
}

int  PodeIrPraDireita(Labirinto * labirinto, int linha, int coluna)
{
	int colunaDireita = coluna + 1;
	return !IsCaracterEspecial(labirinto, linha, colunaDireita);
}

void MarcarCaminhoDirecaoVertical(Labirinto *labirinto, int linha, int coluna, int direcaoAnterior)
{
	if((*labirinto).Matriz[linha][coluna] != 'i')
	{
		if(direcaoAnterior == DIRECAO_HORIZONTAL)
			(*labirinto).Matriz[linha][coluna] = MUDANCA_DIRECAO_CHAR;
		else
			(*labirinto).Matriz[linha][coluna] = VERTICAL_CHAR;
	}
}

void MarcarPontoSemSaidaCaminho(Labirinto *labirinto, int linha, int coluna)
{
	if((*labirinto).Matriz[linha][coluna] != 'i')
	{
			(*labirinto).Matriz[linha][coluna] = 'X';
	}
}

void MarcarCaminhoDirecaoHorizontal(Labirinto *labirinto, int linha, int coluna, int direcaoAnterior)
{
	if((*labirinto).Matriz[linha][coluna] != 'i')
	{
		if(direcaoAnterior == DIRECAO_VERTICAL)
			(*labirinto).Matriz[linha][coluna] = MUDANCA_DIRECAO_CHAR;
		else
			(*labirinto).Matriz[linha][coluna] = HORIZONTAL_CHAR;
	}
}

void ImprimirResultado(Labirinto *labirinto, char * nomeArquivo)
{
	FILE *file;
	int i, j;
	file = fopen(nomeArquivo, "w");
	if(file == NULL)
		printf("Ocorreu um erro ao abrir o arquivo de saida.");
	else
	{
		if((*labirinto).Situacao == 0)
			fprintf(file, "Nao existe caminho.\n");
		else
		{
			for(i = 0; i < (*labirinto).TamLinha; i++)
			{
				for(j = 0; j < (*labirinto).TamColuna; j++)
				{
					fprintf(file, "%c", (*labirinto).Matriz[i][j]);
				}
				fprintf(file,"\n");
			}
		}
		fclose(file);
	}
}

void PrepararLabirintoParaImpressao(Labirinto *labirinto)
{
	int i, j;
	
	for(i = 0; i < (*labirinto).TamLinha; i++)
	{
		for(j = 0; j < (*labirinto).TamColuna; j++)
		{
			if((*labirinto).Matriz[i][j] == 'X')
				(*labirinto).Matriz[i][j] = ' ';
		}
	}
}

int CalcularCaminho(Labirinto *labirinto, int linha, int coluna, int direcaoAnterior)
{
	if((*labirinto).Matriz[linha][coluna] == 'f')
	{
		return 1;
	}
	if(PodeIrPraCima(labirinto, linha, coluna))
	{
		direcaoAnterior = direcaoAnterior * 1;
		MarcarCaminhoDirecaoVertical(labirinto, linha, coluna, direcaoAnterior);
		if(CalcularCaminho(labirinto, linha - 1, coluna, DIRECAO_VERTICAL))
			return 1;
	}
	if(PodeIrPraBaixo(labirinto, linha, coluna))
	{
		MarcarCaminhoDirecaoVertical(labirinto, linha, coluna, direcaoAnterior);
		if(CalcularCaminho(labirinto, linha + 1, coluna, DIRECAO_VERTICAL))
			return 1;
	}
    if(PodeIrPraEsquerda(labirinto, linha, coluna))
    {
		MarcarCaminhoDirecaoHorizontal(labirinto, linha, coluna, direcaoAnterior);
		if(CalcularCaminho(labirinto, linha, coluna - 1, DIRECAO_HORIZONTAL))		
			return 1;
	}
	if(PodeIrPraDireita(labirinto, linha, coluna))
    {
		MarcarCaminhoDirecaoHorizontal(labirinto, linha, coluna, direcaoAnterior);
		if(CalcularCaminho(labirinto, linha, coluna + 1, DIRECAO_HORIZONTAL))		
			return 1;		
	}

	MarcarPontoSemSaidaCaminho(labirinto, linha, coluna);
	return 0;
}

int main (int argc, char *argv[])
{
	Labirinto labirinto;

	CarregarLabirinto(&labirinto, argv[1]);
	labirinto.Situacao = CalcularCaminho(&labirinto, labirinto.PontoInicial.Linha, labirinto.PontoInicial.Coluna, DIRECAO_INCIAL);
	PrepararLabirintoParaImpressao(&labirinto);
	ImprimirResultado(&labirinto, argv[2]);
	return 0;
}
