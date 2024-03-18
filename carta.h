#include "fila.h"
#include "lista.h"
#include "pilha.h"

#define QTD_CARTA 104
#define QTD_MAO 10
#define QTD_MESA 4
#define QTD_MAX_MESA 5

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

void monta_mesa(Pilha*, Fila**);

void exibe_mesa(Fila**);

