#include<stdio.io>

typedef struct Carta {
	int valor,
	char naipe;
} Carta;

typedef struct Pilha {
	
	Carta carta;
	struct Pilha * prox;
} Pilha;

typedef struct Lista {
	Pilha * pilha;
	struct Lista * prox;
} Lista;

//Inserir da pilha
void inserir(Pilha ** head, int valor, char naipe) {
	
	Pilha * novo;

	novo = (Pilha*)malloc(sizeof(Pilha));

	if (novo == NULL) {
		printf("Erro ao alocar memoria");
		exit(EXIT_FAILURE);
	}

	(* novo).Carta.valor = valor;
	(* novo).Carta.naipe = naipe;
	(* novo).prox = (* head);
	(*head) = novo;
}

//Remover da pilha
Carta remover(Pilha** head) {
	
	Carta carta;
	Pilha * aux;

	if ((* head) == NULL) {
		printf("Pilha vazia");
		exit(EXIT_FAILURE);	
	}

	aux = (* head);
	(* head) = (* aux).prox;
	carta = (* aux).carta;
	free(aux);

	return carta;	
}

//Carrega as cartas da mesa
void carregarMesa(Lista * mesa) {
	int i, valor;
	char naipe;
	Lista * noAtual;
	for (i = 1; i <= 7; i++)
		noAtual = inserir(&mesa);
		for(j = 0; j < i; j++) {
			scanf("%d %c", &valor, &naipe);
			inserir(&(*noAtual).pilha, valor, naipe);
		}
}

//Inserir da Lista
//Retorno: um ponteiro para o no que foi adicionado
Lista * inserir(Lista ** head) {
	Lista * novo;

	novo = (Lista*)malloc(sizeof(Lista));

	if (novo == NULL) {
		printf("Erro ao alocar memoria");
		exit(EXIT_FAILURE);
	}

	if((*head) == NULL)
		(* head) = novo;
	else {
		//vai ate o ultimo elemento
		while((*head).prox != NULL)
			head = (*head).prox;
		(*head).prox = novo;
	}

	return novo;
}


int main() {
	Pilha * fuco;
	Lista * mesa, descarte;

	carregarMesa(mesa);
		

	return 0;
}


/*Ideia: ter duas lista de stacks, uma para o descarte, e outra para para as cartas da mesa*/
