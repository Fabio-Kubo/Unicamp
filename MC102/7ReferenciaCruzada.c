#include <string.h>
#include <stdio.h>

// Método que realiza a inicialização do contador
void InicializarContador(int contador[6][26])
{
	int i, j;
	
	//Adicionando uma "chave" que associa a linha com a palavra
	for(i = 0; i < 6; i++)
		contador[i][0] = i;
	
	//Zera os contadores e as localizações(linhas)
	for(i = 0; i < 6; i++)
		for(j = 1; j < 26; j++)
			contador[i][j] = 0;
}

int RetornarIndicePalavraReservada(char palavra[30], char palavrasReservadas[6][10])
{
	int i;
	for(i = 0; i < 6; i++)
	{
		if(strcmp(palavrasReservadas[i], palavra) == 0)
			return i;
	}
	return  -1;
}

void RetirarBarraN(char palavra [100])
{
	int i;
	for(i = 0; ; i++)
		if(palavra[i]=='\n')
		{
			palavra[i] = '\0';
			return;
		}
}

void ProcessarContagemPalavras(int contador[6][26], char palavrasReservadas[6][10])
{
	char linha[100];
	char* palavra;
	int numeroLinha, indicePalavra = 0, posicaoInsercaoLinha;

	setbuf(stdin,0);

	for(numeroLinha = 1; fgets(linha, 100, stdin) != NULL ; numeroLinha++)
	{
		RetirarBarraN(linha);
		
		if(strcmp(linha, "fim") == 0)
			return;
		
		palavra = strtok(linha, " 	");

		while(palavra != NULL)
		{
			indicePalavra = RetornarIndicePalavraReservada(palavra, palavrasReservadas);
			
			if(indicePalavra != -1)	
			{
				posicaoInsercaoLinha = 2;
				//Acha a posição para ser inserida a nova linha
				while(contador[indicePalavra][posicaoInsercaoLinha] != 0)
					posicaoInsercaoLinha++;
			
				//Verifica se a palavra já apareceu na  linha
				if(contador[indicePalavra][posicaoInsercaoLinha-1] != numeroLinha)
				{
					contador[indicePalavra][posicaoInsercaoLinha] = numeroLinha;
				}
				contador[indicePalavra][1]++;
			}
			palavra = strtok(NULL, " 	");
		}
	}
}

void OrdenarContadorInsertionSort(int contador[6][26])
{
	int vetorAux[26], i, j, z;

	for(i = 1; i < 6; i++)
	{
		for(j = i; (j != 0) && (contador[j][1] < contador[j-1][1]); j--)
		{
			for(z = 0; z < 26; z++)
				vetorAux[z] = contador[j-1][z];

			for(z = 0; z < 26; z++ )
				contador[j-1][z] = contador[j][z];

			for(z = 0; z < 26; z++)
				contador[j][z] = vetorAux[z];			
		}
	}
}

void ImprimirContador(int contador[6][26], char palavrasReservadas[6][10])
{
	int i, j;
	for(i = 0; i < 6; i++)
	{
		printf("%s\n", palavrasReservadas[contador[i][0]]);
		printf("\t%d", contador[i][1]);
		
		if(contador[i][1] > 0)
		{
			printf(" - ");
		
			for(j = 2; contador[i][j] != 0; j++)
			{
				printf("%d, ", contador[i][j]);
			}
		}
		printf("\n");
	}
}

void imprimir(int c[6][26])
{
	int i, j;
	for(i = 0; i < 6; i++ )
	{
		for(j = 0; j < 26; j++)
			printf(" %d ", c[i][j]);
	printf("\n");
	}
}

int main()
{
	char palavrasReservadas[6][10] = {"char", "for", "int", "return", "void", "while"};
	int contadorPalavras[6][26];

	InicializarContador(contadorPalavras);
	ProcessarContagemPalavras(contadorPalavras, palavrasReservadas);
	OrdenarContadorInsertionSort(contadorPalavras);
	ImprimirContador(contadorPalavras, palavrasReservadas);
	return 0;
}
