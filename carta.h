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

Lista* gera_Barai();
Pilha* embarai_Barai(Lista*);
void cria_Mesa(Pilha*, Fila*[]);
void exibe_Mesa(Fila*[]);
void cria_Maos(Pilha*, Lista*[],int);
void exibe_Mao(Lista*[],int);
void cria_Colecoes(Pilha*, Lista*[],int);
void exibe_Colecoes(Lista*[],int);
void exibe_Pontos(int[],int);

void inserir_Mesa(Fila*[],Lista*,Lista*[],int[],int);
int jogada_bot(Fila*[],Lista*,int);
void conta_Pontos(int[],int);

void iniciar();
int config();
void color(int);
void error(int);
