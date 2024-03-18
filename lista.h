struct carta;

typedef struct lista Lista;

Lista* criar_Lista();
int inserirIni_Lista(Lista*, struct carta);
int inserirOrd_Lista(Lista*, struct carta);
int acessarInd_Lista(Lista*, int, struct carta*);
int removerInd_Lista(Lista*, int, struct carta*);
int exibir_Lista(Lista *);
int tam_Lista(Lista*);
