#include<stdio.h>
#include<stdlib.h>

typedef struct Hidato{
	int ** Matriz;
	int Dimensao;
	int QtdPosicoes;
} Hidato;

int lerDimensao(){
	int n;
	scanf("%d", &n);
	return n;
}

void exibirErro(){
	printf("Erro ao alocar memoria.");
	exit(EXIT_FAILURE);
}

int * alocarMemoria(int qtdNumeros)
{
	int * v = (int *) malloc(sizeof(int) * qtdNumeros);

	if(v == NULL){
		exibirErro();
	}
	return v;
}


int ** lerDados(int n){
	int i, j, ** matriz;

	matriz = (int **) malloc(sizeof(int *) * n);

	if(matriz == NULL)	
		exibirErro();	

	for(i = 0; i < n; i++){
		matriz[i] = alocarMemoria(n);
	}

	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			scanf("%d",&matriz[i][j]);
		}
	}
	return matriz;
}

//Metodo que carrega o numero da posicao
//Metodo que retorna o numero da posicao e 0 caso seja passado alguma posicao inexistente
int carregarNumero(Hidato hidato, int i, int j){
	
	//Verficia apenas as posicoes validas
	if(i >= 0 && j >= 0 && i < hidato.Dimensao && j < hidato.Dimensao)
		return hidato.Matriz[i][j];
	else
		return 0;
}

//Metodo que indica se a posicao esta preenchida
//Caso seja passado alguma posicao inexistente, ele ignora
int estaPreenchido(Hidato hidato, int i, int j){
	
	//Verficia apenas as posicoes validas
	if(i >= 0 && j >= 0 && i < hidato.Dimensao && j < hidato.Dimensao){
		return  hidato.Matriz[i][j] != 0;
	}
	else
		return 1;
}

void adicionaNumero(int * numeroVizinhos, int *quantidade, int numero){
	if(numero != 0){
		numeroVizinhos[(*quantidade)] = numero;
		(*quantidade)++;
	}
}

int isVizinhancaPreenchida(Hidato hidato, int m, int n)
{
	return estaPreenchido(hidato, m - 1, n) //Verifica Norte	
	&& estaPreenchido(hidato, m - 1, n - 1) //Verifica Noroeste	
	&& estaPreenchido(hidato, m - 1, n + 1) //Verifica Nordeste	
	&& estaPreenchido(hidato, m, n - 1) //Verifica Oeste	
	&& estaPreenchido(hidato, m, n + 1) //Verifica Leste	
	&& estaPreenchido(hidato, m + 1, n - 1) //Verifica Sudoeste	
	&& estaPreenchido(hidato, m + 1, n + 1) //Verifica Sudeste
	&& estaPreenchido(hidato, m + 1, n); //Verifica Sul
}


int * carregarNumerosVizinhos(Hidato hidato, int m, int n, int * quantidade){
	int numero, * numeroVizinhos;
	numeroVizinhos = alocarMemoria(9);

	(*quantidade) = 0;

	//Verifica Norte
	numero = carregarNumero(hidato, m - 1, n);
	adicionaNumero(numeroVizinhos, quantidade, numero);

	//Verifica Noroeste
	numero = carregarNumero(hidato, m - 1, n - 1);
	adicionaNumero(numeroVizinhos, quantidade, numero);

	//Verifica Nordeste
	numero = carregarNumero(hidato, m - 1, n + 1);
	adicionaNumero(numeroVizinhos, quantidade, numero);

	//Verifica Oeste
	numero = carregarNumero(hidato, m, n - 1);
	adicionaNumero(numeroVizinhos, quantidade, numero);

	//Verifica Leste
	numero = carregarNumero(hidato, m, n + 1);
	adicionaNumero(numeroVizinhos, quantidade, numero);

	//Verifica Sudoeste
	numero = carregarNumero(hidato, m + 1, n - 1);
	adicionaNumero(numeroVizinhos, quantidade, numero);

	//Verifica Sudeste
	numero = carregarNumero(hidato, m + 1, n + 1);
	adicionaNumero(numeroVizinhos, quantidade, numero);

	//Verifica Sul
	numero = carregarNumero(hidato, m + 1, n);
	adicionaNumero(numeroVizinhos, quantidade, numero);

	return numeroVizinhos;
}

int possuiNumero(int * v, int tam, int numero)
{
	int i;
	for (i = 0; i < tam; i++)	
		if(v[i] == numero)
			return 1;
	return 0;
}

void imp(int  *v, int qtd){
	int i;
	printf("\n Print vetor: ");
	for (i = 0; i < qtd; i++)
	{
		printf("%d ", v[i]);
	}
	printf("Fim vetor");
}

int * copiarVetor(int * vetorBase, int tam){
	int i, *v;
	v = alocarMemoria(tam);
	for (i = 0; i < tam; i++)
	{
		v[i] = vetorBase[i];
	}

	return v;
}

void retirarNumerosAdjacentes(int * numeros, int numero, int qtdPosicoes){
	if(numero != 0){

		//acessa x - 1
		if(numero >= 2)
			numeros[numero - 2] = 0;

		//acessa x + 1
		if(numero < qtdPosicoes)
			numeros[numero] = 0;
	}
}

int * carregarNumerosPossiveisB(Hidato hidato, int m, int n, int * qtdPossiveis, int qtdNrRestantes, int * numerosRestantes){

	int  * numerosPossiveis, * auxNumeros, * numeroVizinhos, i, j, qtdVizinhos;

	(* qtdPossiveis) = 0;
	numerosPossiveis = alocarMemoria(qtdNrRestantes);
	
	if(!isVizinhancaPreenchida(hidato, m, n)){
		auxNumeros = copiarVetor(numerosRestantes, hidato.QtdPosicoes);

		//Retira os elementos adjacentes que sao necessarios na parte de baixo
		for (i = m + 2; i < hidato.Dimensao; i++)
			for (j = 0; j < hidato.Dimensao; j++)
				retirarNumerosAdjacentes(auxNumeros, hidato.Matriz[i][j], hidato.QtdPosicoes);

		//Retira os elementos adjacentes que sao necessarios na parte de cima
		for (i = m - 2; i >= 0; i++)
			for (j = 0; j < hidato.Dimensao; j++)
				retirarNumerosAdjacentes(auxNumeros, hidato.Matriz[i][j], hidato.QtdPosicoes);
		
		//Retira os elementos adjacentes que sao necessarios na parte direita
		for (j = n + 2; j < hidato.Dimensao; j++)	
			for (i = 0; i < hidato.Dimensao; i++)
				retirarNumerosAdjacentes(auxNumeros, hidato.Matriz[i][j], hidato.QtdPosicoes);

		//Retira os elementos adjacentes que sao necessarios na parte de esquerda
		for (j = n - 2; j >= 0; j++)
			for (i = 0; i < hidato.Dimensao; i++)			
				retirarNumerosAdjacentes(auxNumeros, hidato.Matriz[i][j], hidato.QtdPosicoes);

		for (i = 0; i < hidato.QtdPosicoes; i++){
			if(auxNumeros[i] != 0){
				numerosPossiveis[(* qtdPossiveis)] = auxNumeros[i];
				(* qtdPossiveis)++;
			}
		}

		free(auxNumeros);
	}
	else{
		numeroVizinhos = carregarNumerosVizinhos(hidato, m, n, &qtdVizinhos);
		for(i = 0, j = 0; i < hidato.QtdPosicoes && j < qtdNrRestantes; i++){
			if(numerosRestantes[i] != 0){				
				j++;
				if(numerosRestantes[i] == 1){
					if(possuiNumero(numeroVizinhos, qtdVizinhos, 2))		
						numerosPossiveis[(* qtdPossiveis)] = 2;
						(* qtdPossiveis)++;
				}
				else if(numerosRestantes[i] == hidato.QtdPosicoes){
					if(possuiNumero(numeroVizinhos, qtdVizinhos, hidato.QtdPosicoes - 1))		
						numerosPossiveis[(* qtdPossiveis)] = numerosRestantes[i];
						(* qtdPossiveis)++;
				}
				else
				{
					if(possuiNumero(numeroVizinhos, qtdVizinhos, numerosRestantes[i] - 1) && 
						possuiNumero(numeroVizinhos, qtdVizinhos, numerosRestantes[i] + 1))
					{
						numerosPossiveis[(* qtdPossiveis)] = numerosRestantes[i];
						(* qtdPossiveis)++;
					}
				}
					
			}

		}
	}
	return numerosPossiveis;
}

//Regra
//Cada numero tem q estar ao lado de seus adjacentes, com excecao dos extremos.
int * carregarNumerosPossiveis(Hidato hidato, int m, int n, int * qtdPossiveis, int qtdNrRestantes, int * numerosRestantes){
	int i, * numerosPossiveis, * numeroVizinhos, qtdVizinhos, j;

	numerosPossiveis = alocarMemoria(qtdNrRestantes);
	(* qtdPossiveis) = 0;
	if(!isVizinhancaPreenchida(hidato, m, n)){
		for (i = 0; i < hidato.QtdPosicoes; i++){
			if(numerosRestantes[i] != 0){
				numerosPossiveis[(* qtdPossiveis)] = numerosRestantes[i];
				(* qtdPossiveis)++;
			}
		}
	}
	else{
		numeroVizinhos = carregarNumerosVizinhos(hidato, m, n, &qtdVizinhos);
		for(i = 0, j = 0; i < hidato.QtdPosicoes && j < qtdNrRestantes; i++){
			if(numerosRestantes[i] != 0){				
				j++;
				if(numerosRestantes[i] == 1){
					if(possuiNumero(numeroVizinhos, qtdVizinhos, 2))		
						numerosPossiveis[(* qtdPossiveis)] = 2;
						(* qtdPossiveis)++;
				}
				else if(numerosRestantes[i] == hidato.QtdPosicoes){
					if(possuiNumero(numeroVizinhos, qtdVizinhos, hidato.QtdPosicoes - 1))		
						numerosPossiveis[(* qtdPossiveis)] = numerosRestantes[i];
						(* qtdPossiveis)++;
				}
				else
				{
					if(possuiNumero(numeroVizinhos, qtdVizinhos, numerosRestantes[i] - 1) && 
						possuiNumero(numeroVizinhos, qtdVizinhos, numerosRestantes[i] + 1))
					{
						numerosPossiveis[(* qtdPossiveis)] = numerosRestantes[i];
						(* qtdPossiveis)++;
					}
				}
					
			}

		}

	}
	return numerosPossiveis;
}


int * carregarNumerosRestantes(Hidato *hidato, int * qtdNrRestantes){
	int i, j, * numerosRestantes;
	(* qtdNrRestantes) = (* hidato).QtdPosicoes;

	numerosRestantes= alocarMemoria((* hidato).QtdPosicoes);
	
	for (i = 0; i < (* hidato).QtdPosicoes; i++)
		numerosRestantes[i] = i + 1;

	for (i = 0; i < (* hidato).Dimensao; i++){
		for (j = 0; j < (* hidato).Dimensao; j++){
			if((* hidato).Matriz[i][j] != 0){
				numerosRestantes[(* hidato).Matriz[i][j] - 1] = 0;
				(* qtdNrRestantes)--;
			}
		}
	}

	return numerosRestantes;
}

void imprimirMatriz(int ** matriz, int n){
	int i, j;
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}
}

int avancarPosicao(Hidato* hidato, int * m, int * n){
	(*n)++;

	if((*n) == (*hidato).Dimensao)
	{
		(*m)++;
		(*n) = 0;
	}

	if((*m) == (*hidato).Dimensao)
		return 0;
	else
		return 1;
}

void removerNumeroDosRestantes(int * numerosRestantes, int * qtdNrRestantes, int numero){
	numerosRestantes[numero - 1] = 0;
	(* qtdNrRestantes)--;
}

void liberarMemoria(Hidato hidato, int ** matriz){
	int i;

	for (i = 0; i < hidato.Dimensao; i++){
		free(hidato.Matriz[i]);
		free(matriz[i]);
	}

	free(hidato.Matriz);
	free(matriz);
}

void copiarMatriz(int ** matriz, int ** matrizBase, int n)
{
	int i, j;
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			matriz[i][j] = matrizBase[i][j];
		}
	}
}

void resolverHidato(Hidato * hidato, int m, int n, int * qtdSolucoes, int ** matrizResolvida){
	int qtdNrPossiveis, * numerosPossiveis, i, * numerosRestantes, qtdNrRestantes;
	numerosRestantes = carregarNumerosRestantes(hidato, &qtdNrRestantes);
	if(qtdNrRestantes == 0){
		copiarMatriz(matrizResolvida, (*hidato).Matriz,(*hidato).Dimensao);
		(*qtdSolucoes)++;
	}
	else if((*hidato).Matriz[m][n] != 0)
	{
		if(avancarPosicao(hidato, &m, &n)){
			resolverHidato(hidato, m, n, qtdSolucoes, matrizResolvida);
		}
	}
	else{	
		numerosPossiveis = carregarNumerosPossiveisB(*hidato, m, n, &qtdNrPossiveis, qtdNrRestantes, numerosRestantes);
		imp(numerosPossiveis, qtdNrPossiveis);
		for (i = 0; i < qtdNrPossiveis; i++){
			(*hidato).Matriz[m][n] = numerosPossiveis[i];
			removerNumeroDosRestantes(numerosRestantes, &qtdNrRestantes, numerosPossiveis[i]);
			resolverHidato(hidato, m, n, qtdSolucoes, matrizResolvida);
			(*hidato).Matriz[m][n] = 0;
		}
		free(numerosPossiveis);	
	}

}

void imprimirResultado(int qtdSolucoes, int ** matriz, int dimensao)
{
	if(qtdSolucoes == 0)
		printf("Problema insoluvel.\n");
	else if(qtdSolucoes > 1)
		printf("O problema possui %d solucoes.\n", qtdSolucoes);
	else
	{
		printf("Solucao unica do problema:\n");
		imprimirMatriz(matriz, dimensao);
	}
}

int ** iniciarMatriz(int n){
	int i, ** matriz;

	matriz = (int **) malloc(sizeof(int *) * n);

	if(matriz == NULL)	
		exibirErro();	

	for(i = 0; i < n; i++){
		matriz[i] = alocarMemoria(n);
	}

	return matriz;
}

int main(){
	
	int **matrizSolucao, qtdSolucoes;
	Hidato hidato;

	matrizSolucao = NULL;
	hidato.Dimensao = lerDimensao();
	qtdSolucoes = 0;
	hidato.QtdPosicoes = hidato.Dimensao * hidato.Dimensao;
	printf("Sou peao");
	hidato.Matriz = lerDados(hidato.Dimensao);
	printf("Sou bispo");
	matrizSolucao = iniciarMatriz(hidato.Dimensao);
	printf("Sou rei");
	resolverHidato(&hidato, 0, 0, &qtdSolucoes, matrizSolucao);
	imprimirResultado(qtdSolucoes, matrizSolucao, hidato.Dimensao);

	liberarMemoria(hidato, matrizSolucao);
	return 0;
}

