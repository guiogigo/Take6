struct carta;

typedef struct fila Fila;

Fila* criar_Fila();
int inserir_Fila(Fila*, struct carta);
int remover_Fila(Fila*, struct carta *);
int acessar_Fila(Fila*,int, struct carta *); //o int é uma "flag", n=0 para acessar o inicio e n!=0 para acessar o fim...
int exibir_Fila(Fila*);
int tam_Fila(Fila*);
