#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "lista.h"
#include "pilha.h"
#include "fila.h"
#include "carta.h"

Lista* geraBarai(){
    Lista* lis = criar_Lista();

    for (int i=1; i<=QTD_CARTA; i++){
            struct carta novacarta;
            novacarta.numero = i;
            novacarta.jogador = 0;

            int bois = 0;
            if (i%5 == 0 && i%10 != 0)
                bois+=2;
            if (i%10 == 0)
                bois+=3;
            if (i%11 == 0)
                bois+=5;
            if (!bois)
                bois+=1;

            novacarta.bois = bois;

            inserirIni_Lista(lis,novacarta);
    }
    return lis;
}

Pilha* embaraiBarai(Lista* lis){
    Pilha* pil = criar_Pilha();

    struct carta c;

    srand(time(0));
    for (int i=0; i<QTD_CARTA; i++){
        int pos = rand() % (QTD_CARTA-i);
        removerInd_Lista(lis,pos,&c);

        inserir_Pilha(pil,c);
    }
    free(lis);
    return pil;
}

void monta_mesa(Pilha* pil, Fila* mesa[]){
    struct carta aux;
    for(int i=0;i<QTD_MESA;i++){
        mesa[i] = criar_Fila();
        remover_Pilha(pil,&aux);
        inserir_Fila(mesa[i],aux);
    }
    return mesa;
}


void exibe_mesa(Fila* mesa[]){
    for(int i=0;i<QTD_MESA;i++){
        exibir_Fila(mesa[i]);
        printf("\n");
    }
}
