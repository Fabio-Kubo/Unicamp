#include<stdio.h>
#include<stdlib.h>

/*
    Fabio Tadashi Kaneiwa Kubo RA: 145979
*/

typedef struct Carta {

    int valor;
    char naipe;
    struct Carta * prox;
} Carta;

typedef struct Lista {
    
    Carta * pilha;
    Carta * ultimaCartaVirada;
    Carta * primeiraCartaVirada;

    struct Lista * prox;
} Lista;

//Metodo que aloca dinamicamente uma carta e inicializa com o valor e o naipe
Carta * inicializarCarta(int valor, char naipe) {

    Carta * novo;
    novo = (Carta *) malloc(sizeof(Carta));

    if (novo == NULL) {
        printf("Erro ao alocar memoria");
        exit(EXIT_FAILURE);
    }

    (* novo).valor = valor;
    (* novo).naipe = naipe; 

    return novo;
}

//Metodo que retorna se o naipe eh vermelho
int isNaipeVermelho(char naipe) {
    
    return naipe == 'o' || naipe == 'c';
}

//Metodo que retorna se o naipe eh preto
int isNaipePreto(char naipe) {
    
    return naipe == 'e' || naipe == 'p';
}

//Metodo que insere um unico elemento na pilha
void inserirElementoPilha(Carta ** head, Carta * novo) {

    (* novo).prox = (* head);
    (* head) = novo;
}

//Metodo que insere um ou mais elementos na pilha
void inserirElementosPilha(Lista * noLista, Carta * primeiro, Carta * ultimo) {

    (* ultimo).prox = (* noLista).pilha;
    (* noLista).pilha = primeiro;
    (* noLista).primeiraCartaVirada = primeiro;

    if((* noLista).ultimaCartaVirada == NULL)
        (* noLista).ultimaCartaVirada = ultimo;
}

//Metodo que remove um item da pilha
Carta * removerPilha(Carta ** head) {

    Carta * aux;

    if ((* head) == NULL) {
            printf("Pilha vazia");
            exit(EXIT_FAILURE);
    }

    aux = (* head);
    (* head) = (* aux).prox;

    return aux;
}

//metodo que remove as cartas viradas de uma pilha
void removerCartasViradas(Lista * lista) {
    
    (* lista).pilha = (* (* lista).ultimaCartaVirada).prox;
    (* lista).primeiraCartaVirada = NULL;
    (* lista).ultimaCartaVirada = NULL;
}

//Metodo que remove o item no monte
Carta * removerMonte(Carta ** head) {

    Carta * cartaRemovida;

    if((* head) == NULL) {

        printf("Monte vazio\n");
        exit(EXIT_FAILURE);
    }

    cartaRemovida = (* head);
    (* head) = (** head).prox;

    return cartaRemovida;
}

//Metodo que insere um item no Monte
void inserirMonte(Carta ** head, Carta * novo) {

    Carta * aux;    
    (* novo).prox = NULL;

    if ((* head) == NULL)
        (* head) = novo;
    else {

        aux = (* head);
        //vai ate o ultimo elemento
        while((* aux).prox != NULL)
            aux = (* aux).prox;

        (* aux).prox = novo;
    }
}

//Inserir da Lista
//Retorno: um ponteiro do no que foi adicionado
Lista * inserirLista(Lista ** head) {

    Lista * novo, * aux;
    novo = (Lista *) malloc(sizeof(Lista));

    if (novo == NULL) {
        printf("Erro ao alocar memoria");
        exit(EXIT_FAILURE);
    }

    (* novo).pilha = NULL;
    (* novo).prox = NULL;

    if((* head) == NULL)
        (* head) = novo;
    else {
        aux = (* head);
        //vai ate o ultimo elemento
        while((* aux).prox != NULL)
                aux = (* aux).prox;

        (* aux).prox = novo;
    }

    return novo;
}

//Metodo que retorna se eh possivel realizar a movimentacao das cartas
int podeManipular(Carta * carta, Carta * cartaDeBaixo, int isDoMonte) {

    int manipulavel = 0;

    if(cartaDeBaixo == NULL){

        manipulavel = (* carta).valor == 13 && (isDoMonte || (* carta).prox != NULL);
    }
    else if((* cartaDeBaixo).valor == (* carta).valor + 1) {

        if(isNaipeVermelho((* carta).naipe))
            manipulavel = isNaipePreto((* cartaDeBaixo).naipe);
        
        else
            manipulavel = isNaipeVermelho((* cartaDeBaixo).naipe);
    }

    return manipulavel;
}

//Metodo que adiciona a carta na mesa
int adicionarCartaDoMonteNaMesa(Lista * mesa, Carta * carta) {

    while(mesa != NULL) {

        if(podeManipular(carta, (* mesa).primeiraCartaVirada, 1)){

            inserirElementoPilha(&(* mesa).pilha, carta);

            (* mesa).primeiraCartaVirada = carta;

            if((* mesa).ultimaCartaVirada == NULL)
                (* mesa).ultimaCartaVirada = carta;

            return 1;
        }

        mesa = (* mesa).prox;
    }

    return 0;
}

//Metodo que carrega as cartas da mesa
Lista * carregarMesa() {

    int i, j, valor;
    char naipe;
    Lista * head, * noAtual;     
    Carta * novo;
    
    head = NULL;
    for (i = 1; i <= 7; i++) {
        
        noAtual = inserirLista(&head);
        for(j = 0; j < i; j++) {
                scanf("%d %c", &valor, &naipe);

                novo = inicializarCarta(valor, naipe);
                inserirElementoPilha(&(* noAtual).pilha, novo);
        }

        (* noAtual).primeiraCartaVirada = (* noAtual).pilha;
        (* noAtual).ultimaCartaVirada = (* noAtual).pilha;
    }

    return head;
}

//Metodo que carrega o monte
Carta * carregarMonte() {
        
    int j, valor;
    char naipe;
    Carta * head, * novo;

    head = NULL;
    for(j = 0; j < 24; j++) {
            scanf("%d %c", &valor, &naipe);
            
            novo = inicializarCarta(valor, naipe);
            inserirMonte(&head, novo);
    }

    return head;
}

//Metodo que retorna a quantidade de cartas existentes no Monte
int retornarQuantidadeMonte(Carta * monte) {

    int qtd = 0;       

    while(monte != NULL) {
        qtd++;
        monte = (* monte).prox;        
    }

    return qtd;
}

//Metodo que carrega o descarte
int * carregarDescarte() {

    int i;
    int * descarte = (int *)malloc(sizeof(int) * 4);
    
    if(descarte == NULL) {
        printf("Sem memoria");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < 4; i++) {
        descarte[i] = 0;  
    }

    return descarte;
}

//Metodo que retorna o indice do vetor descarte para um determinado naipe
int retornarIndiceDescarte(char naipe) {

    int indice = -1;
    switch(naipe) {
        case 'o': indice = 0; break;
        case 'e': indice = 1; break;
        case 'c': indice = 2; break;
        case 'p': indice = 3; break;
    }

    return indice;
}

//Metodo que retorna se a carta pode ou nao ser  descartada
int podeDescartar(int * descarte, Carta * carta) {

    return descarte[retornarIndiceDescarte((* carta).naipe)] + 1 == (* carta).valor;
}

//Metodo que altera o valor do vetor de descarte
void atualizarDescarte(int * descarte, Carta * carta, int * qtdDescarte) {
    
    (* qtdDescarte)++;
    descarte[retornarIndiceDescarte((* carta).naipe)] = (* carta).valor;
}

//Metodo que descartas as cartas do topo da pilha quando possivel
int descartar(Lista * mesa, int * descarte, int * qtdDescarte) {

	Carta * itemRemovido;

	while(mesa != NULL){

		if((* mesa).primeiraCartaVirada != NULL) {

	        if(podeDescartar(descarte, (* mesa).primeiraCartaVirada)) {
				
                itemRemovido = removerPilha(&(* mesa).pilha);
                
                if((* mesa).ultimaCartaVirada == itemRemovido) {

                    (* mesa).primeiraCartaVirada = NULL;
                    (* mesa).ultimaCartaVirada = NULL;
                }
                else {

                    (* mesa).primeiraCartaVirada = (* itemRemovido).prox;
                }					

                atualizarDescarte(descarte, itemRemovido, qtdDescarte);
				free(itemRemovido);
				
                return 1;
	        }

		}

        mesa = (* mesa).prox;
	}

	return 0;
}

//Metodo que abre as cartas fechadas
int abrirCartasFechadas(Lista * mesa) {

	while(mesa != NULL){

	    if((* mesa).primeiraCartaVirada == NULL && (* mesa).pilha != NULL) {
        	(* mesa).primeiraCartaVirada = (* mesa).pilha;
			(* mesa).ultimaCartaVirada = (* mesa).pilha;
			return 1;
        }

        mesa = (* mesa).prox;
	}
	return 0;
}

//Metodo que executa as movimentacoes entre as pilhas
int manipularCartasMesa(Lista * mesa) {

    Lista * itemLento, * itemRapido;
    Carta * auxPrimeiraCarta, * auxUltimaCarta;

    itemLento = mesa;

    //percorre a lista de pilhas
    while(itemLento != NULL){

        if((* itemLento).pilha != NULL){ 

            itemRapido = mesa;
            while(itemRapido != NULL) {

                if(itemRapido != itemLento && podeManipular((* itemLento).ultimaCartaVirada, (* itemRapido).primeiraCartaVirada, 0)){

                    auxPrimeiraCarta = (* itemLento).primeiraCartaVirada;
                    auxUltimaCarta = (* itemLento).ultimaCartaVirada;
                    removerCartasViradas(itemLento);
                    inserirElementosPilha(itemRapido, auxPrimeiraCarta, auxUltimaCarta);
                    
                    return 1;
                }

                itemRapido = (* itemRapido).prox;
            }            

        }

        itemLento = (* itemLento).prox;
    }
	return 0;
}

//Metodo que imprime o resultado
void imprimirResultado(int qtdMonte, int qtdDescarte) {

    if(qtdDescarte == 52) {

        printf("O jogo acabou com sucesso\n");
    }
    else {
        printf("Monte: %d\n", qtdMonte);
        printf("Descarte: %d\n", qtdDescarte);  
    }
}

//Metodo de auxilio que imprime os dados das estruturas
void imprimirSituacaoJogo(Lista * mesa, Carta * monte, int * descarte) {

    int i; Carta * aux;

    printf("\n");
    printf("Descarte: ");
    for (i = 0; i < 4; i++) {
        printf("%d\t", descarte[i]);
    }
    printf("\n\n");
    printf("Monte: ");

    while(monte != NULL) {

        printf("%d%c\t", (* monte).valor, (* monte).naipe);
        monte = (* monte).prox;
    }
    printf("\n\n");

    i = 1;
    printf("Mesa: \n");
    while(mesa != NULL) {
        printf("%d Pilha: ", i);

        aux = (* mesa).pilha;
        while(aux != NULL) {

            printf("%d%c\t", (* aux).valor, (* aux).naipe);
            aux = (* aux).prox;
        }
        printf("\n");
        mesa = (* mesa).prox;
        i++;
    }

    printf("\n\n");
}

//Metodo que realiza os fluxos com o monte
//retorno: 1 - Interromper jogo; 0 - continuar jogo
int utilizarMonte(int * descarte, Lista * mesa, Carta ** monte, int * qtdDescarte, Carta ** primeiraCarta) {

    Carta * cartaMonte;
    int interromperJogo = 0;

    for(;;) {

        //para o fluxo se ja tiver dado uma volta
        if((* monte) == (* primeiraCarta)) {

            interromperJogo = 1;
            break;
        };

        cartaMonte = removerMonte(monte);

        if(podeDescartar(descarte, cartaMonte)) {

            atualizarDescarte(descarte, cartaMonte, qtdDescarte);
            free(cartaMonte);
            (* primeiraCarta) = NULL;
            break;
        }
        else if(adicionarCartaDoMonteNaMesa(mesa, cartaMonte)){

            (* primeiraCarta) = NULL;
            break;
        }
        else {

            if((* primeiraCarta) == NULL)
                (* primeiraCarta) = cartaMonte;

            inserirMonte(monte, cartaMonte);            
        }

    }

    return interromperJogo;
}

//Metodo que resolve o jogo
void resolver(int * descarte, Lista * mesa, Carta ** monte, int * qtdDescarte) {

    Carta * primeiraCarta;

    primeiraCarta = NULL;

	for(;;) {


		if(descartar(mesa, descarte, qtdDescarte)) {
            
            primeiraCarta = NULL;
		}
		else if(abrirCartasFechadas(mesa)) {
            
            primeiraCarta = NULL;
		}
		else if(manipularCartasMesa(mesa)) {
            
            primeiraCarta = NULL;
		}
        else if ((* monte) == NULL){ // se acabou o monte, acabou o jogo

            return;
        }
		else {            
            
            if(utilizarMonte(descarte, mesa, monte, qtdDescarte, &primeiraCarta))
                return;
        }
	}
}

//metodo que libera a memoria dinamicamente alocada pelo programa
void liberarMemoria(Lista * mesa, Carta * monte, int * descarte) {

    Carta * aux;
    Lista * auxLista;

    free(descarte);

    //percorre todo o monte e desaloca da memoria
    while(monte != NULL) {

        aux = monte;
        monte = (* monte).prox;
        free(aux);
    }

    //percorre todos os itens da mesa (Nos da lista)
    while(mesa != NULL) {

        auxLista = mesa;

        //remove os itens da pilha e desaloca da memoria
        while((* mesa).pilha != NULL) {

            aux = removerPilha(&(* mesa).pilha);
            free(aux);
        }

        mesa = (* mesa).prox;
        free(auxLista);
    }

}

int main() {

	int qtdDescarte;
    int * descarte; // 0-ouros 1-espadas 2-copas 3-paus
    Carta * monte;
    Lista * mesa;

    qtdDescarte = 0;
    descarte = carregarDescarte();
    mesa = carregarMesa();
    monte = carregarMonte();
    
    resolver(descarte, mesa, &monte, &qtdDescarte);

    imprimirResultado(retornarQuantidadeMonte(monte), qtdDescarte);
    liberarMemoria(mesa, monte, descarte);
    return 0;
}