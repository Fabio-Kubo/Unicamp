#include <stdio.h>
#include <stdlib.h>

typedef struct Item {
    int Id;
    float Valor;
    float Peso;
    int Qtd;
    float RazaoValorPeso;
} Item;

//Metodo que retorna o valor total da mochila
float retornarValorTotalMochila(Item * mochila, int qtdItemMochila) {

    int i;
    float valorTotal;

    valorTotal = 0.00;
    for (i = 0; i < qtdItemMochila; i++)
    {
        valorTotal += mochila[i].Valor * mochila[i].Qtd;
    }

    return valorTotal;
}

//Metodo que imprimi os itens da mochila
void imprimirItensMochila(Item * mochila, int qtdItemMochila) {

    int i;

    for (i = 0; i < qtdItemMochila; i++)
    {
        printf("Item: %d  Quantidade: %d\n", mochila[i].Id, mochila[i].Qtd);
    }

    printf("Valor Total: %.2f\n", retornarValorTotalMochila(mochila, qtdItemMochila));
}

//Metodo que retorna a quantidade de itens
int retornarQuantidadeItens() {

    int qtd;
    scanf("%d", &qtd);
    return qtd;
}

//Metodo que retorna o peso maximo da mochila
float retornarPesoMaximoMochila() {

    float pesoMax;
    scanf(" %f", &pesoMax);

    return pesoMax;
}

//Metodo que inicializa um vetor de itens
Item * inicializarVetor(int qtd) {

    Item * itens;
    itens = (Item *)malloc(sizeof(Item) * qtd);

    if(itens == NULL) {

        printf("Erro ao alocar memoria\n");
        exit(EXIT_FAILURE);
    }

    return itens;
}

//Metodo que carrega os itens
Item * carregarItens(int qtd) {

    int i;
    Item * itens;

    itens = inicializarVetor(qtd);

    for(i = 0; i < qtd; i++) {

        scanf("%d %f %f %d", &itens[i].Id, &itens[i].Peso, &itens[i].Valor, &itens[i].Qtd);
        itens[i].RazaoValorPeso = itens[i].Valor / itens[i].Peso;
    }

    return itens;
}

//Metodo que faz o merge do mergeSort, juntando dois subvetores ordenados
void merge(Item * itens, int qtd) {
    
    int mid;
    int i, j, k;
    Item * aux;
 
    aux = inicializarVetor(qtd);

    mid = qtd / 2;
    i = 0;
    j = mid;
  
    for (k = 0; i < mid && j < qtd; k++) {

        if (itens[i].RazaoValorPeso >= itens[j].RazaoValorPeso)
          aux[k] = itens[i++];
        else
          aux[k] = itens[j++];
    }
  
    while (j < qtd) {
      aux[k++] = itens[j++];
    }

    while (i < mid) {
      aux[k++] = itens[i++];
    }

    //copia o auxiliar para o original
    for (i = 0; i < qtd; i++)
        itens[i] = aux[i];
 
    free(aux);
}

//Metodo que ordena o vetor de itens de forma decrescente, 
//considerando a razao entre o valor e Peso
void mergeSort(Item * itens, int qtd) {
    int mid;
 
    if (qtd > 1) {
        mid = qtd / 2;
        mergeSort(itens, mid);
        mergeSort(itens + mid, qtd - mid);
        merge(itens, qtd);
    }
}

//Metodo que retorna o menor valor
int minimo(int a, int b) {

    return a <= b? a : b;
}

//Metodo que adiciona os itens na mochila
Item * arranjarMochila(Item * itens, int qtdItens, float pesoMax, int * qtdItensMochila) {

    int qtdAdicionar, i;
    float pesoRestante;
    Item * mochila;

    mochila = inicializarVetor(qtdItens);
    pesoRestante = pesoMax;
    (* qtdItensMochila) = 0;
    
    //percorre todos os itens
    for (i = 0; i  < qtdItens; i++)
    {

        qtdAdicionar = minimo(pesoRestante / itens[i].Peso, itens[i].Qtd);

        if(qtdAdicionar > 0) {

            pesoRestante -= qtdAdicionar * itens[i].Peso;
            mochila[(* qtdItensMochila)].Id = itens[i].Id;
            mochila[(* qtdItensMochila)].Qtd = qtdAdicionar;
            mochila[(* qtdItensMochila)].Valor = itens[i].Valor;
            (* qtdItensMochila)++;

            //verifica se a mochila ainda possui espaco
            if(pesoRestante == 0)
                break;
        }
    }

    return mochila;
}

int main() {

    int qtdItens, qtdItensMochila;
    float pesoMax;
    Item * itens, * mochila;

    qtdItens = retornarQuantidadeItens();
    pesoMax = retornarPesoMaximoMochila();
    itens = carregarItens(qtdItens);
    mergeSort(itens, qtdItens);

    mochila = arranjarMochila(itens, qtdItens, pesoMax, &qtdItensMochila);

    imprimirItensMochila(mochila, qtdItensMochila);

    //libera os vetores da memoria
    free(mochila);
    free(itens);
    return 0;
}
