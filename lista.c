#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "carta.h"

struct lista{
    int qtd;
    struct elemento* inicio;
};

Lista* criar_Lista(){
    Lista* lis;
    lis = (Lista*)malloc(sizeof(Lista));
    if (lis){
        lis->inicio = NULL;
        lis->qtd = 0;
    }
    return lis;
}

int inserirIni_Lista(Lista* lis, struct carta novosdados){
    if (!lis) return 0;

    Elemento* novo = (Elemento*)malloc(sizeof(Elemento));
    if (!novo) return 0;
    novo->dados = novosdados;

    novo->prox = lis->inicio;
    lis->inicio = novo;

    (lis->qtd)++;
    return 1;
}

int inserirOrd_Lista(Lista* lis, struct carta novosdados){
    if (!lis) return 0;

    Elemento* novo = (Elemento*)malloc(sizeof(Elemento));
    if (!novo) return 0;
    novo->dados = novosdados;

    if (lis->qtd == 0 || lis->inicio->dados.numero > novo->dados.numero){
        novo->prox = lis->inicio;
        lis->inicio = novo;
    }
    else {
        Elemento* ant = lis->inicio;
        Elemento* aux = ant->prox;

        while (aux && aux->dados.numero < novo->dados.numero){
            ant = aux;
            aux = aux->prox;
        }
        ant->prox = novo;
        novo->prox = aux;
    }
    (lis->qtd)++;
    return 1;
}

int acessarInd_Lista(Lista* lis, int pos, struct carta* c){
    if (!lis || lis->qtd == 0 || pos<0) return 0;

    int cont = 0;
    Elemento* aux = lis->inicio;

    while (aux && cont != pos){
        aux = aux->prox;
        cont++;
    }
    if (!aux) return 0;

    *c = aux->dados;
    return 1;
}

int removerInd_Lista(Lista* lis, int pos, struct carta* c){
    if (!lis || lis->qtd == 0 || pos<0) return 0;

    if (pos == 0){
        Elemento* aux = lis->inicio;
        lis->inicio = aux->prox;
        *c = aux->dados;
        free(aux);
        (lis->qtd)--;
        return 1;
    }

    int cont = 1;
    Elemento* ant = lis->inicio;
    Elemento* aux = ant->prox;

    while (aux && cont != pos){
        ant = aux;
        aux = aux->prox;
        cont++;
    }

    if (!aux) return 0;
    *c = aux->dados;

    ant->prox = aux->prox;
    free(aux);
    (lis->qtd)--;
    return 1;
}

int exibir_Lista(Lista* lis){
    if (!lis || lis->qtd == 0){
        printf("\n");
        return 0;
    }

    Elemento* aux = lis->inicio;

    while (aux->prox){
        printf("[%3d| %d] -> ", aux->dados.numero, aux->dados.bois);
        aux = aux->prox;
    }
    printf("[%3d| %d]\n", aux->dados.numero, aux->dados.bois);

    return 1;
}

int tam_Lista(Lista* lis){
    if (!lis || lis->qtd==0) return 0;
    return lis->qtd;
}

