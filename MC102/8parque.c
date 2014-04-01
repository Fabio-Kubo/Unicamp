#include<stdio.h>
#include<string.h>

struct Brinquedo
{
	char Nome[50];
	float Preco;
	int Prioridade;
};

typedef struct Brinquedo Brinquedo;

//Método que carrega os brinquedos
// param: brinquedos -> vetor de brinquedos que será carregado
// return: quantidade de brinquedos
int CarregarBrinquedos(Brinquedo* brinquedos)
{
	char linha[100];
	int i = 0;
	
	for(;;)
	{
		fgets(linha, 100, stdin);
		if(strcmp(linha, "0;0;0\n") == 0)
			return i;
		sscanf(linha, "%s ; %f ; %d", brinquedos[i].Nome, &brinquedos[i].Preco, &brinquedos[i].Prioridade);
		i++;
	}
}

//Método que ordena por insertion sort o vetor de brinquedos de acordo com a Prioridade
// param: brinquedos -> vetor com os brinquedos a serem ordenados
// param: qtdBrinquedos -> quantidade de brinquedos
void OrdenarBrinquedosPorPrioridade(Brinquedo* brinquedos, int qtdBrinquedos)
{
	int i, j;
	Brinquedo aux;
	for(i = 0; i < qtdBrinquedos; i++)
	{
		j = i;
		while((j != 0) && (brinquedos[j].Prioridade < brinquedos[j - 1].Prioridade))
		{
			aux = brinquedos[j];
			brinquedos[j] = brinquedos[j - 1];
			brinquedos[j - 1] = aux;
			j--;
		}
	}
}

//Método que carrega o resumo do dia de Rodka no Parque de diversão
void CarregarResumoParqueDiversao(float dinheiro, float* dinheiroRestante, Brinquedo* brinquedos, int qtdBrinquedos, int*brinquedosUtilizados)
{
	int i;
	*dinheiroRestante = dinheiro;
	for(i = 0; i < qtdBrinquedos; i++ )
	{
		//Se houver dinheiro suficiente, ele vai no brinquedo
		if(*dinheiroRestante >= brinquedos[i].Preco)
		{
			(*dinheiroRestante) -= brinquedos[i].Preco; // retira o valor do brinquedo
		}
		else
			break;
	}
	*brinquedosUtilizados = i;	
}

//Método que imprimi o resumo
void ImprimirResumo(int qtdBrinquedos, int brinquedosUtilizados, float dinheiroRestante)
{
	if(brinquedosUtilizados >= (2/3.0*qtdBrinquedos ))
	{
		printf("Rodka vai ao parque.\n");
		printf("Ira em %d brinquedos.\n", brinquedosUtilizados);
		printf("E lhe sobrarao %.2f reais.\n", dinheiroRestante);
	}
	else
	{
		printf("Rodka nao vai ao parque.\n");
	}
}

//Método que imprime o conteúdo do vetor de brinquedos
void ImprimirBrinquedos(Brinquedo *brinquedos, int qtd)
{
	int i;
	for(i = 0; i < qtd; i++)
	{
		printf("Nome %s - Preco: %f - Prioridade %d\n", brinquedos[i].Nome, brinquedos[i].Preco, brinquedos[i].Prioridade);
	}
}

int main()
{
	float dinheiro, dinheiroRestante;
	int qtdBrinquedos, brinquedosUtilizados;
	Brinquedo brinquedos[15];

	scanf("%f\n", &dinheiro);

	qtdBrinquedos = CarregarBrinquedos(brinquedos);
	OrdenarBrinquedosPorPrioridade(brinquedos, qtdBrinquedos);
	//ImprimirBrinquedos(brinquedos, qtdBrinquedos);
	CarregarResumoParqueDiversao(dinheiro, &dinheiroRestante, brinquedos, qtdBrinquedos, &brinquedosUtilizados);
	ImprimirResumo(qtdBrinquedos, brinquedosUtilizados, dinheiroRestante);

	return 0;
}
