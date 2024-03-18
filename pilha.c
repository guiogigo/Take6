#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "carta.h"

struct pilha{
    int qtd;
    struct elemento* topo;
};

Pilha* criar_Pilha(){
    Pilha* pil;
    pil = (Pilha*)malloc(sizeof(Pilha));
    if (pil){
       pil->topo = NULL;
       pil->qtd = 0;
    }
    return pil;
}

int inserir_Pilha(Pilha* pil, struct carta novosdados){
    if (!pil) return 0;

    Elemento* novo = (Elemento*)malloc(sizeof(Elemento));
    if (!novo) return 0;

    novo->dados = novosdados;

    novo->prox = pil->topo;
    pil->topo = novo;
    (pil->qtd)++;

    return 1;
}

int remover_Pilha(Pilha* pil, struct carta* c){
    if (!pil || pil->qtd == 0) return 0;

    Elemento* aux = pil->topo;

    pil->topo = aux->prox;
    *c = aux->dados;

    free(aux);
    (pil->qtd)--;
    return 1;
}

int exibir_Pilha(Pilha* pil){
    if (!pil || pil->qtd == 0) return 0;

    Elemento* aux = pil->topo;

    while (aux->prox){
        printf("[%3d| %d] -> ", aux->dados.numero, aux->dados.bois);
        aux = aux->prox;
    }
    printf("[%3d| %d]\n", aux->dados.numero, aux->dados.bois);

    return 1;
}
