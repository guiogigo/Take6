#include <stdio.h>
#include <stdlib.h>

#include "fila.h"
#include "lista.h"
#include "pilha.h"
#include "carta.h"
#include "macros.h"

int main()
{
    Lista* lis = geraBarai();
    //exibir_Lista(lis);

    Pilha* pil = embaraiBarai(lis);
    Lista* Mao = criar_Lista();
    for(int i=0; i<5; i++) {
        struct carta att;
        remover_Pilha(pil, &att);
        printf("%d\n", att.numero);
        //inserirOrd_Lista(Mao, att);
        inserirIni_Lista(Mao, att);
    }
    exibir_Lista(Mao);
    //printf("\n\n\n");
    //exibir_Pilha(pil);
}
