#include<stdio.h>
#include<stdlib.h>

typedef struct Placar
{
	char Time1;
	char Time2;
	int Gol1;
	int Gol2; 
} Placar;


int retornarNumeroTimes()
{
	int n;
	scanf("%d\n", &n);
	return n;
}

int hasMenosTimesQueMinimo(int n)
{
	return n < 2;
}

int hasMaisTimesQueMaximo(int n)
{
	return n > 20;
}

int retornarQuantidadeJogos(int qtdTimes)
{
	return (qtdTimes - 1)*(qtdTimes)/2;
}

char * carregarTimes(int qtdTimes)
{
	int i, indiceTime = 0;
	char linha [50];
	
	char * times = (char *)malloc(sizeof(char)*qtdTimes);

	if(times != NULL)
	{
		fgets(linha, 50, stdin);
		
		for (i = 0; indiceTime < qtdTimes; i++)
		{
			if(linha[i] != ' ')
			{
				times[indiceTime] = linha[i];
				indiceTime++;
			}
		}
	}

	return times;
}

void carregarPlacares(Placar * placares, int qtdJogos)
{
	char linha [20];
	int i;

	for(i = 0; i < qtdJogos; i++)
	{
		fgets(linha, 20, stdin);
		sscanf(linha,"%c %c %d %d\n", &(placares[i].Time1), &(placares[i].Time2), 
			&(placares[i].Gol1), &(placares[i].Gol2));
	}	
}


Placar acessoMatriz(int i, int j, Placar * placares)
{
	if(i < j)
		return placares[j*(j + 1)/2 + i - j];
	else
		return placares[i*(i + 1)/2 + j - i];
}

void imprimirCabecalho(int qtdTimes, char *times)
{
	int i;
	printf("X");
	for(i = 0; i < qtdTimes; i++)
		printf("|  %c  ", times[i]);
	printf("\n");
}

void imprimirTabelaJogos(int qtdTimes, char * times, Placar * placares)
{
	int i, j;
	Placar placar;
	imprimirCabecalho(qtdTimes, times);

	for(i = 0; i < qtdTimes; i++)
	{
		for( j = 0; j < qtdTimes; j++)
		{
			if(j == 0)
				printf("%c",times[i]);
			if(i == j)
				printf("|  x  ");
			else
			{
				placar = acessoMatriz(i, j, placares);
				if(i < j)
					printf("| %d:%d ", placar.Gol2, placar.Gol1);	
				else
					printf("| %d:%d ", placar.Gol1, placar.Gol2);
			}
		}
		printf("\n");
	}
}

int main()
{
	char * times;
	int qtdJogos, qtdTimes;
	qtdTimes = retornarNumeroTimes();

	if(hasMenosTimesQueMinimo(qtdTimes))
		printf("Erro: Nao ha campeonato com menos de 2 times\n");
	
	else if(hasMaisTimesQueMaximo(qtdTimes))
		printf("Erro: Numero maximo de times excedido\n");

	else
	{
		qtdJogos = retornarQuantidadeJogos(qtdTimes);
		Placar * placares = (Placar *) malloc(sizeof(Placar) * qtdJogos);
		if(placares != NULL)
		{
			times = carregarTimes(qtdTimes);
			carregarPlacares(placares, qtdJogos);
			imprimirTabelaJogos(qtdTimes, times, placares);
		}
		free(placares);
		free(times);
	}

	return 0;	
}
