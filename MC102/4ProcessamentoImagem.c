#include <stdio.h>
#define LINHAMAX 25
#define COLUNAMAX 25

void LerImagem(int imagem[LINHAMAX][COLUNAMAX], int nLinha, int nColuna);
void GerarImagemMediaLocal(int imagem[LINHAMAX][COLUNAMAX], int ImagemMediaLocal[LINHAMAX][COLUNAMAX], int nLinha, int nColuna);
void GerarImagemNegativa(int imagem[LINHAMAX][COLUNAMAX], int nLinha, int nColuna);
void GerarImagemLimiar(int imagem[LINHAMAX][COLUNAMAX], int nLinha, int nColuna, int nLimiar);
void ImprimirMatriz(int imagem[LINHAMAX][COLUNAMAX], int nLinha, int nColuna);

int main()
{
	int nLinha, nColuna, nLimiar, imagem[LINHAMAX][COLUNAMAX], imagemRetorno[LINHAMAX][COLUNAMAX];

	scanf("%d %d %d", &nColuna, &nLinha, &nLimiar);

	LerImagem(imagem, nLinha, nColuna);
	GerarImagemMediaLocal(imagem, imagemRetorno, nLinha, nColuna);
	GerarImagemNegativa(imagemRetorno, nLinha-2, nColuna-2);
	GerarImagemLimiar(imagemRetorno, nLinha-2, nColuna-2, nLimiar);
	ImprimirMatriz(imagemRetorno, nLinha-2, nColuna-2);

	return 0;
}

///
///Método que lê a matriz / imagem
///
void LerImagem(int imagem[LINHAMAX][COLUNAMAX], int nLinha, int nColuna)
{
	int i, j;
	for(i = 0; i < nLinha; i++)
	{
		for(j = 0; j < nColuna; j++)
		{
			scanf("%d", &imagem[i][j]);
		}
	}
}

///
///Método que a partir de uma imagem, gera uma imagem Media Local
/// |x1 x2 x3|
/// |x4  n x5|  -> n = (x1+x2+x3+x4+x5+x6+x7+x8+x9) / 9;
/// |x6 x7 x8| 
void GerarImagemMediaLocal(int imagem[LINHAMAX][COLUNAMAX], int ImagemMediaLocal[LINHAMAX][COLUNAMAX], int nLinha, int nColuna)
{
	int i, j;
	for(i = 1; i < nLinha -1; i++)
	{
		for(j = 1; j < nColuna -1; j++)
		{
			ImagemMediaLocal[i-1][j-1] = (imagem[i-1][j-1]+ imagem[i-1][j]+ imagem[i-1][j+1]+
							imagem[i][j-1]+ imagem[i][j] +imagem[i][j+1]+ 
							imagem[i+1][j-1]+ imagem[i+1][j]+ imagem[i+1][j+1])/9; 
		}
	}
}

///
///Método que a partir de uma imagem, gera uma imagem Negativa
///
void GerarImagemNegativa(int imagem[LINHAMAX][COLUNAMAX], int nLinha, int nColuna)
{
	int i, j;
	for(i = 0; i < nLinha; i++)
	{
		for(j = 0; j < nColuna; j++)
		{
			imagem[i][j] = 255 - imagem[i][j];
		}
	}
}

///
///Método que gera uma imagem Limiar
///
void GerarImagemLimiar(int imagem[LINHAMAX][COLUNAMAX], int nLinha, int nColuna, int nLimiar)
{
	int i, j;
	for(i = 0; i < nLinha; i++)
	{
		for(j = 0; j < nColuna; j++)
		{
			if(imagem[i][j] < nLimiar)
				imagem[i][j] = 0;
			else
				imagem[i][j] = 255;
		}
	}
}

///
///Método que imprime a matriz
///
void ImprimirMatriz(int imagem[LINHAMAX][COLUNAMAX], int nLinha, int nColuna)
{
	int i, j;
	for(i = 0; i < nLinha; i++)
	{
		for(j = 0; j < nColuna; j++)
		{
			printf("%d ", imagem[i][j]);
		}
		printf("\n");
	}
}
