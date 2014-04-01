#include<stdio.h>
#include<stdlib.h>

typedef struct Informacao {
        int valor;
        int linha;
        int coluna;
        int qtdElementos;
        int tamLinha;
        int tamColuna;
} Informacao;

typedef struct Lista {
        Informacao info;
        struct Lista * prox;
        struct Lista * abaixo;
} Lista;

Lista * iniciarLista(){

        Lista * novo;        
        novo = (Lista *) malloc(sizeof(Lista));
        (*novo).info.qtdElementos = 0;

        if(novo == NULL){

                printf("Faltou memoria");
                exit(EXIT_FAILURE);
        }

        return novo;
}

char lerTipoOperacao(){
        char tipoOperacao;
        scanf("%c\n", &tipoOperacao);
        return tipoOperacao;
}

void inserir(Lista* sent, Informacao info){

        Lista * elementoSuperior, * novo, * aux, *auxElementoAbaixo;
        
        if(info.valor == 0)
                return;

        novo = iniciarLista();
        (* novo).info = info;

        elementoSuperior = NULL;        
        (*sent).info.qtdElementos++;
        auxElementoAbaixo = (* sent).prox;

        //Aponta sent para o local onde deve ser incluido o novo elemento
        while((* sent).prox != NULL){

                if( info.linha < (*(* sent).prox).info.linha || 
                        (info.linha == (*(* sent).prox).info.linha && info.coluna < (*(* sent).prox).info.coluna))
                        break;

                sent = (* sent).prox;
        }

        //procura um elemento que esta na mesma coluna
        while(auxElementoAbaixo != NULL){
                if((*auxElementoAbaixo).info.coluna == info.coluna)
                        break;
                auxElementoAbaixo = (*auxElementoAbaixo).prox;
        }

        //Atualiza os ponteiros "abaixo"
        if(auxElementoAbaixo != NULL){

                while ((*auxElementoAbaixo).abaixo != NULL){
                        if((*(*auxElementoAbaixo).abaixo).info.linha > info.linha)
                                break;
                        auxElementoAbaixo = (*auxElementoAbaixo).abaixo;        
                }

                if((*auxElementoAbaixo).abaixo != NULL)
                {
                        aux = (*auxElementoAbaixo).abaixo;
                        (*auxElementoAbaixo).abaixo = novo;
                        (*novo).abaixo = aux;        
                }
                else
                        (*sent).abaixo = novo;
        }

        //Atualiza os ponteiros "prox"
        if((*sent).prox != NULL)
        {
                aux = (*sent).prox;
                (*sent).prox = novo;
                (*novo).prox = aux;        
        }
        else
                (*sent).prox = novo;
        
        if(elementoSuperior != NULL)
                (* elementoSuperior).abaixo = novo;
}

void carregarMatriz(Lista * sent, int n){
        int i;
        Informacao info;

        for (i = 0; i < n; i++) { 
                scanf("%d %d %d", &(info.linha), &(info.coluna), &(info.valor));
                inserir(sent, info);
        }
}

void lerDadosTransposta(Lista * sent){
        int nrLinhas, nrColunas, qtdElementos;
        scanf("%d %d %d", &nrLinhas,&nrColunas, &qtdElementos);

        (*sent).info.tamLinha = nrLinhas;
        (*sent).info.tamColuna = nrColunas;

        carregarMatriz(sent, qtdElementos);
}

void lerDadosAdicao(Lista * sent1, Lista * sent2){
        int nrLinhas, nrColunas, qtdElementosA, qtdElementosB;

        scanf("%d %d %d %d", &nrLinhas, &nrColunas, &qtdElementosA, &qtdElementosB);

        (*sent1).info.tamLinha = nrLinhas;
        (*sent2).info.tamLinha = nrLinhas;

        (*sent1).info.tamColuna = nrColunas;
        (*sent2).info.tamColuna = nrColunas;

        carregarMatriz(sent1, qtdElementosA);
        carregarMatriz(sent2, qtdElementosB);
}

void lerDadosMultiplicacao(Lista * sent1, Lista * sent2){
        int nrLinhas, nrColunas, qtdElementos;

        scanf("%d %d %d", &nrLinhas, &nrColunas, &qtdElementos);
        (*sent1).info.tamLinha = nrLinhas;
        (*sent1).info.tamColuna = nrColunas; 
        carregarMatriz(sent1, qtdElementos);

        scanf("%d %d %d", &nrLinhas, &nrColunas, &qtdElementos);
        (*sent2).info.tamLinha = nrLinhas;
        (*sent2).info.tamColuna = nrColunas;
        carregarMatriz(sent2, qtdElementos);
}

void imprimirResultado(Lista * resultado){

        if((*resultado).info.qtdElementos == 0)
                printf("Matriz resultado vazia\n");
        else{
                printf("%d %d %d\n", (*resultado).info.tamLinha, (*resultado).info.tamColuna, (*resultado).info.qtdElementos);
                resultado = (*resultado).prox;
                while(resultado != NULL)
                {
                        printf("%d %d %d.00\n", (*resultado).info.linha, (*resultado).info.coluna, (*resultado).info.valor);
                        resultado = (*resultado).prox;
                }
        }
}

void efetuarAdicao(Lista * sent1, Lista * sent2, Lista * resultado){

        Informacao info;
        (*resultado).info.tamLinha = (*sent1).info.tamLinha;
        (*resultado).info.tamColuna = (*sent1).info.tamColuna;
        sent1 = (*sent1).prox;
        sent2 = (*sent2).prox;

        while(sent1 != NULL){

                //Caso haja algum elemento na outra matriz que esteja em posicoes inferiores a atual
                while((*sent2).info.linha <= (*sent1).info.linha && (*sent2).info.coluna < (*sent1).info.coluna){
                        inserir(resultado,(*sent2).info);
                        sent2 = (* sent2).prox;
                }

                if((*sent1).info.linha == (*sent2).info.linha && (*sent1).info.coluna == (*sent2).info.coluna)
                {
                        info.linha = (*sent2).info.linha;
                        info.coluna = (*sent2).info.coluna;
                        info.valor = (*sent1).info.valor + (*sent2).info.valor;

                        inserir(resultado, info);

                        sent2 = (* sent2).prox;
                }
                else
                {
                        inserir(resultado,(*sent1).info);
                }

                sent1 = (*sent1).prox;
        }

        while (sent2 != NULL)
        {
                inserir(resultado,(*sent2).info);
                sent2 = (* sent2).prox;
        }
}

void efetuarTransposta(Lista * sent1, Lista * resultado){
        Informacao info;
        (*resultado).info.tamLinha = (*sent1).info.tamColuna;
        (*resultado).info.tamColuna = (*sent1).info.tamLinha;

        sent1 = (*sent1).prox;
        while(sent1 != NULL)
        {
                info.linha = (*sent1).info.coluna;
                info.coluna = (*sent1).info.linha;
                info.valor = (*sent1).info.valor;

                inserir(resultado, info);

                sent1 = (*sent1).prox;
        }
}

int retornarValor(Lista * sent, int linha){

        while(sent != NULL) {
                if((*sent).info.linha == linha)
                        return (*sent).info.valor;
                sent = (*sent).abaixo;
        }

        return 0;
}

void efetuarMultiplicacao(Lista * sent1, Lista * sent2, Lista * resultado){
        Informacao info;
        Lista * auxColuna, *auxLinha;
        int i, soma, j;


        (*resultado).info.tamLinha = (*sent1).info.tamLinha;
        (*resultado).info.tamColuna = (*sent2).info.tamColuna;

        auxLinha = (*sent1).prox;

        for (j = 0; j < (*sent2).info.tamColuna; j++){
                for (i = 0; i < (*sent1).info.tamLinha; i++){
                        soma = 0;
                        auxColuna = (*sent2).prox;
                        
                        //posiciona na coluna correta
                        while(auxColuna != NULL){
                                if((*auxColuna).info.coluna == j)
                                        break;
                                auxColuna = (*auxColuna).prox;
                        }

                        while(auxLinha != NULL && (*auxLinha).info.linha == i){
                                soma += (*auxLinha).info.valor *  retornarValor(auxColuna, (*auxLinha).info.coluna);
                                auxLinha = (*auxLinha).prox;
                        }

                        info.valor = soma;
                        info.linha = i;
                        info.coluna = j;
                        inserir(resultado, info);
                }
                auxLinha = (*sent1).prox;
        }
}

void liberarMemoria(Lista * lista){

        if((*lista).prox != NULL)
                liberarMemoria((*lista).prox);
        free(lista);
}

int main(){

        Lista * matrizA, * matrizB, *resultado;

        matrizA = iniciarLista();
        matrizB = iniciarLista();
        resultado = iniciarLista();

        switch(lerTipoOperacao()){
                case 't':
                        lerDadosTransposta(matrizA);
                        efetuarTransposta(matrizA, resultado);
                        imprimirResultado(resultado);
                        break;
                case '+': 
                        lerDadosAdicao(matrizA, matrizB);
                        efetuarAdicao(matrizA, matrizB, resultado);
                        imprimirResultado(resultado);
                        break;
                case 'x': 
                        lerDadosMultiplicacao(matrizA, matrizB);
                        efetuarMultiplicacao(matrizA, matrizB, resultado);
                        imprimirResultado(resultado);
                        break;
        }

        liberarMemoria(matrizA);
        liberarMemoria(matrizB);
        liberarMemoria(resultado);

        return 0;
}

