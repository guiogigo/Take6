#include <stdio.h>
#include <stdlib.h>

#include "fila.h"
#include "lista.h"
#include "pilha.h"
#include "carta.h"
#include "macros.h"

int main()
{
    Lista* cartas = geraBarai();
    Pilha* Baralho = embaraiBarai(cartas);
    int i;
    struct carta att;

    // Criando a Mesa
    int qtd_mesa = 4;
    Fila* mesa[qtd_mesa];
    for(i=0; i<qtd_mesa; i++) {
        mesa[i] = criar_Fila();
        remover_Pilha(Baralho, &att);
        inserir_Fila(mesa[i], att);
        //exibir_Fila(mesa[i]);
    }

    // Criando a Mao
    Lista* Mao = criar_Lista();
    for(i=0; i<10; i++) {
        remover_Pilha(Baralho, &att);
        att.jogador = 0;
        inserirOrd_Lista(Mao, att);
    }

    // Criando as coleções
    int qtd_player = 4;
    Lista* colecao[qtd_player];
    for(i=0; i<qtd_player; i++) {
        colecao[i] = criar_Lista();
    }

    // Começando o jogo

    while(tamanho_Lista(Mao) != 0) {
        int tamanho_Mao = tamanho_Lista(Mao);
        printf("{cont = %d}\n", tamanho_Mao);
        int escolha;

        for(i=0; i<4; i++) exibir_Fila(mesa[i]);
        printf("\n");
        exibir_Lista(Mao);
        for(i=0; i<tamanho_Mao; i++) {
            printf("   (%d)      ", i);
        }
        printf("\nEscolha uma carta para jogar: ");
        scanf("%d", &escolha);

        while(escolha > tamanho_Mao-1 || escolha < 0) {
            printf("Valor invalido...");
            printf("\nEscolha uma carta para jogar: ");
            scanf("%d", &escolha);
        }

        // Validação da lista em que a carta vai entrar
        int dis_max, dis_i, contador_menor = 0;
        int inicio = 0, fim = 1;
        struct carta seletor;

        removerInd_Lista(Mao, escolha, &att);
        att.jogador = NULL;


        for(i=0; i<qtd_mesa; i++) {
            acessar_Fila(mesa[i], 1, &seletor);

            if(i==0) {
                dis_max = att.numero-seletor.numero;
                dis_i = i;
            }

            if(seletor.numero > att.numero) {
                contador_menor++;
                continue;
            }

            if(att.numero-seletor.numero < dis_max) {
                dis_max = att.numero-seletor.numero;
                dis_i = i;
            }
        }
        if(contador_menor == qtd_mesa) {
            printf("Sua carta é menor que todas as que estão na mesa, escolha uma para trocar (1 à 4): ");
            scanf("%d", &escolha);
            while(escolha > qtd_mesa || escolha < 1) {
                printf("\nValor invalido...");
                printf("\nSua carta é menor que todas as que estão na mesa, escolha uma para trocar (1 à 4): ");
                scanf("%d", &escolha);
            }

        } else inserir_Fila(mesa[dis_i], att);



        system("cls");
    }
}
