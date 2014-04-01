#include <stdio.h>
#include <math.h>

float RetornarDistanciaClasseDoTeste(float classe[20], float teste[20], int dimensao)
{
	int i;
	float soma = 0;
	
	for(i = 0; i < dimensao; i++)
	{
		soma += pow((classe[i] - teste[i]), 2.0);
	}
	
	return sqrt(soma);
}

int main()
{
	int dimensaoVetor, qtdClasse, qtdTeste, indiceClasse, indiceDimensao, i, i2, indiceClasseMaisProxima;
	float matrizClasses[20][20], matrizTestes[20][20], menorDistancia, distanciaAtual;

	//Lendo a dimensão e as quantidades	
	scanf("%d %d %d", &dimensaoVetor, &qtdClasse, &qtdTeste);

	//Lendo as classes
	for(indiceClasse = 0; indiceClasse < qtdClasse; indiceClasse ++)
	{
		for(indiceDimensao = 0; indiceDimensao < dimensaoVetor; indiceDimensao++)
		{
			scanf("%f", &matrizClasses[indiceClasse][indiceDimensao]);
		} 
	}
	
	//Lendo os vetores de teste
	for(indiceClasse = 0; indiceClasse < qtdTeste; indiceClasse ++)
	{
		for(indiceDimensao = 0; indiceDimensao < dimensaoVetor; indiceDimensao++)
		{
			scanf("%f", &matrizTestes[indiceClasse][indiceDimensao]);
		} 
	}
	
	
	//Imprimindo as classes mais próximas dos casos de testes
	for(i = 0; i < qtdTeste; i++)
	{	
		menorDistancia = RetornarDistanciaClasseDoTeste(matrizClasses[0], matrizTestes[i], dimensaoVetor);
		indiceClasseMaisProxima = 0;
		for(i2 = 1; i2 < qtdClasse; i2++)
		{		

			distanciaAtual = RetornarDistanciaClasseDoTeste(matrizClasses[i2], matrizTestes[i], dimensaoVetor);
			if(menorDistancia > distanciaAtual)
			{
				indiceClasseMaisProxima = i2;
				menorDistancia = distanciaAtual;
			}
		}
		printf("%d\n", indiceClasseMaisProxima);
	}		
	
	return 0;
}
