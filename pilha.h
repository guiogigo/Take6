struct carta;

typedef struct pilha Pilha;

Pilha* criar_Pilha();
int inserir_Pilha(Pilha*, struct carta);
int remover_Pilha(Pilha*, struct carta *);
int exibir_Pilha(Pilha*);
