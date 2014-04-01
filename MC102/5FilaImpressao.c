#include <stdio.h>
#include <string.h>

/*
 * Verifica se a fila está cheia.
 * Retorna 1, caso positivo, ou 0, caso contrário.
 */
int cheia (int *fila, int *inicio, int *fim, int tamvetor)
{
	if(*fim == (tamvetor - 1))
		return (*inicio == 0);
	else
		return (*fim +1) == *inicio;
}

/*
 * Verifica se a fila está vazia.
 * Retorna 1, caso positivo, ou 0, caso contrário.
 */
int vazia (int *fila, int *inicio, int *fim, int tamvetor)
{
	return (*inicio == *fim);
}

/*
 * Imprime o estado atual da fila.
 */
void imprimir (int *fila, int *inicio, int *fim, int tamvetor)
{	
	int auxInicio;
	if(!vazia(fila, inicio, fim, tamvetor))
	{
		auxInicio = *inicio;

		printf("Fila de impressao:");

		while(auxInicio != *fim)
		{
			printf(" %d", fila[auxInicio]);
			if(auxInicio == tamvetor-1)
				auxInicio = 0;
			else
				auxInicio++;
		}
		printf(".\n");
	}
	else
		printf("Fila de impressao vazia.");
}

/*
 * Tenta inserir um elemento na fila.
 * Retorna o número do elemento ou -1 caso a fila esteja cheia.
 */
int inserir (int requisicao, int *fila, int *inicio, int *fim, int tamvetor)
{
	if(!cheia(fila, inicio, fim, tamvetor))
	{
		fila[*fim] = requisicao;
		if(*fim == (tamvetor -1))
			*fim = 0;
		else
			*fim = *fim +1;
		return requisicao;		
	}
	else
		return -1;
}

/*
 * Tenta remover um elemento da fila.
 * Retorna o número do elemento ou -1 caso a fila esteja vazia.
 */
int remover (int *fila, int *inicio, int *fim, int tamvetor)
{
	int valor;
	if(!vazia(fila, inicio, fim, tamvetor))
	{
		valor = fila[*inicio];
		if(*inicio == tamvetor-1)
			*inicio = 0;
		else
			*inicio = *inicio+1;	
		return valor;
	}
	return -1;
}

int main()
{
	// Vetor onde é armazenada a fila
	int fila[50];
	// Indicadores de início e de fim de fila
	int inicio = 0, fim = 0;
	// Guarda o tamanho máximo da fila de impressão
	int tamvetor;

	char acao[20];
	int requisicao;
	scanf("%d", &tamvetor);
	
	for(;;)
	{
		scanf("%s", acao);

		if(strcmp(acao, "enviar") == 0)
		{
				scanf("%d", &requisicao);
				if(inserir(requisicao, fila, &inicio, &fim, tamvetor) != -1)
					printf("Requisicao %d enviada para a fila de impressao.\n", requisicao);
				else
					printf("Nao foi possivel enviar a requisicao %d: fila cheia.\n", requisicao);
		}
		else if (strcmp(acao,"iniciar") == 0)
		{
				requisicao = remover(fila, &inicio, &fim, tamvetor);
				if(requisicao != -1)
					printf("Imprimindo requisicao %d.\n",requisicao);
				else
					printf("Fila de impressao vazia.\n");
		}
		else if(strcmp(acao, "imprimir") == 0) 
		{
				scanf("%s", acao); // retira o lixo: " fila"
				imprimir(fila, &inicio, &fim, tamvetor);
		}
		else if(strcmp(acao, "FIM") == 0)
			return 0;
		else
			printf("Entrada inválida!");

	}

	return 0;
}

