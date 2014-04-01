#include<stdio.h>
#include<stdlib.h>

/*
	FABIO TADASHI KANEIWA KUBO RA:145979
*/

typedef struct ArvBin {

	char valor;
	struct ArvBin * esq;
	struct ArvBin * dir;
} ArvBin;

#define AND '&'
#define OR '|'
#define NOT '!'

//metodo inicializa um no
ArvBin * inicializarNo(char valor) {

	ArvBin * arv;
	
	arv = (ArvBin *) malloc(sizeof(ArvBin));
	if(arv == NULL) {

		printf("Erro ao alocar a memoria\n");
		exit(EXIT_FAILURE);
	}

	(* arv).esq = NULL;
	(* arv).dir = NULL;
	(* arv).valor = valor;

	return arv;
}

int isOperador(char c) {

	return c == AND || c == OR || c == NOT;
}

int isRaizComAndOuOr(ArvBin * arv) {

	return (* arv).valor == AND || (* arv).valor == OR;
}

int isVazia(ArvBin * arvore) {

	return arvore == NULL;
}

ArvBin * carregarArvore(ArvBin * noAtual, char * expressao, int * i){

	if(expressao[* i] == '\n')
		return NULL;

	noAtual = inicializarNo(expressao[* i]);

	if(isOperador(expressao[* i])) {
		
		(* i)++;
		(* noAtual).esq = carregarArvore((* noAtual).esq, expressao, i);

		//Caso o no da esquerda estiver vazia, a expressao chegou ao fim
		//Caso o no atual for o NOT, nao precisa preencher o no direito
		if((* noAtual).valor != NOT && (* noAtual).esq != NULL) {

			(* i)++;
			(* noAtual).dir = carregarArvore((* noAtual).dir, expressao, i);
		}
		else
			(* noAtual).dir = NULL;
	}

	return noAtual;
}

char * getExpressao() {

	char * expressao;
	expressao = (char *) malloc(sizeof(char) * 101);

	fgets(expressao, 101, stdin);

	return expressao;
}

//Metodo que retorna a quantidade de letras de uma expressao
int getQtdLetras(char * expressao) {

	int i, qtdLetras;
	
	for (i = 0, qtdLetras = 0; expressao[i] != '\n' && expressao[i] != '\0'; i++)
		if(!isOperador(expressao[i])) 
			qtdLetras++;	

	return qtdLetras;
}

int * retornarResolucao(int qtdLetras) {

	int * resolucao, i;

	resolucao = (int *) malloc(sizeof(int) * qtdLetras);
	
	for (i = 0; i < qtdLetras; i++) {
		/* code */
	}

	return resolucao;
} 

void imprimirExpressaoArvore(ArvBin * arv) {

	int colocarParenteses;

	if(arv == NULL)
		return; 

	if((* arv).valor == NOT)
		printf("%c", (* arv).valor);

	colocarParenteses = (* arv).esq != NULL && isRaizComAndOuOr((* arv).esq);

	if(colocarParenteses)
		printf("(");

	if(!isOperador((* arv).valor))
		printf("%c", (* arv).valor);

	imprimirExpressaoArvore((* arv).esq);
	
	if(colocarParenteses)
		printf(")");

	if((* arv).valor == AND)
		printf(" && ");
	else if((* arv).valor == OR)
		printf(" || ");

	colocarParenteses = (* arv).dir != NULL && isRaizComAndOuOr((* arv).dir);
	
	if(colocarParenteses)
		printf("(");
	imprimirExpressaoArvore((* arv).dir);
	if(colocarParenteses)
		printf(")");
}

void imprimirExpressao(ArvBin * arv) {

	imprimirExpressaoArvore(arv);
	printf("\n");
}

int main() {

	ArvBin * arvore;
	char * expressao;
	int i, qtdLetras, * resolucao;

	expressao = getExpressao();
	arvore = carregarArvore(NULL, expressao, &i);
	qtdLetras = getQtdLetras(expressao);
	resolucao = retornarResolucao(qtdLetras);
	imprimirExpressao(arvore);

	return 0;
}