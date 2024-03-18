#include "fila.h"
#include "lista.h"
#include "pilha.h"

#define CARDCOUNT 104

struct carta{
    int numero;
    int bois;
    int jogador;
};

typedef struct elemento{
    struct carta dados;
    struct elemento* prox;
}Elemento;

Lista* geraBarai();

Pilha* embaraiBarai(Lista*);
