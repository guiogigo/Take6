#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include "carta.h"

struct fila{
    int qtd;
    struct elemento* inicio;
    struct elemento* fim;
};

Fila* criar_Fila(){
    Fila* fil;
    fil = (Fila*)malloc(sizeof(Fila));
    if (fil){
        fil->inicio = NULL;
        fil->fim = NULL;
        fil->qtd = 0;
    }
    return fil;
}

int inserir_Fila(Fila* fil, struct carta novosdados){
    if (!fil) return 0;

    Elemento* novo = (Elemento*)malloc(sizeof(Elemento));
    if (!novo) return 0;

    novo->dados = novosdados;
    novo->prox = NULL;

    if (!fil->fim){
        fil->inicio = novo;
    }
    else {
        fil->fim->prox = novo;
    }

    fil->fim = novo;

    (fil->qtd)++;
    return 1;
}

int remover_Fila(Fila* fil, struct carta* c){
    if (!fil || fil->qtd == 0) return 0;

    Elemento* aux = fil->inicio;
    fil->inicio = fil->inicio->prox;
    if(!fil->inicio)
        fil->fim = NULL;
    *c = aux->dados;

    free(aux);
    (fil->qtd)--;
    return 1;
}

int acessar_Fila(Fila* fil, int n, struct carta* c){
    if (!fil || fil->qtd == 0) return 0;

    *c = (n==0)? fil->inicio->dados : fil->fim->dados;
    return 1;
}

int exibir_Fila(Fila* fil){
    if (!fil || fil->qtd == 0) return 0;

    Elemento* aux = fil->inicio;

    while (aux->prox){
        printf("[%3d| %d] -> ", aux->dados.numero, aux->dados.bois);
        aux = aux->prox;
    }
    printf("[%3d| %d]\n", aux->dados.numero, aux->dados.bois);

    return 1;
}

