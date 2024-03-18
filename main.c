#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>

#include "fila.h"
#include "lista.h"
#include "pilha.h"
#include "carta.h"
#include "menus.h"

#define QTD_MESA 4
#define QTD_MAO 10
#define QTD_MESA_MAX 5
#define DEBUG 0


void validar_jogada(Lista*,Fila*[],Lista*[]);
void validar(Lista*,Fila*[],Lista*[]);
void contar_pontos(Lista*[], int);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    color(15);
    Lista* cartas = geraBarai(); // Cria as cartas
    Pilha* Baralho = embaraiBarai(cartas); // Embaralha as cartas
    int i, j;
    struct carta aux;
    int qtd_player;



    //Tela Inicial
    iniciar();

    //Escolha da quantidade de jogadores
    qtd_player = config_Jogo();

    // Criando a Mesa
    Fila* mesa[QTD_MESA];
    monta_mesa(Baralho, mesa);

    //Criando as Maos
    Lista* Maos[qtd_player];
    for(i=0; i<qtd_player; i++) {
        Maos[i] = criar_Lista();
        for(j=0; j<10; j++) {
            remover_Pilha(Baralho, &aux);
            aux.jogador = i;
            inserirOrd_Lista(Maos[i], aux);
        }
    }

    // Criando as coleções
    Lista* mao_da_rodada = criar_Lista();
    Lista* colecao[qtd_player];
    for(i=0; i<qtd_player; i++) {
        colecao[i] = criar_Lista();
    }

    // Começando o jogo
    while(tam_Lista(Maos[0]) != 0) {
        int tam = tam_Lista(Maos[0]);
        int escolha;

        Hud(mesa, qtd_player, Maos, colecao);//Mostra as informações na tela

        //Jogada
        printf("\nEscolha uma carta para jogar: ");
        scanf("%d", &escolha);
        while(escolha > tam-1 || escolha < 0) {
            error(1);
            scanf("%d", &escolha);
        }

        removerInd_Lista(Maos[0], escolha, &aux);
        inserirOrd_Lista(mao_da_rodada, aux);

        for(i=1; i<qtd_player; i++) {
            removerInd_Lista(Maos[i], 0, &aux);
            inserirOrd_Lista(mao_da_rodada, aux);
        }

        printf("\n");
        color(12);
        exibir_Lista(mao_da_rodada);
        color(15);

        // Validação da lista em que a carta vai entrar
        validar(mao_da_rodada,mesa,colecao);
    }
    contar_pontos(colecao, qtd_player);
}


void validar(Lista* cartas_Jogadas, Fila* mesa[], Lista* colecao[]) {
    struct carta aux, atual;
    int menor = 0, indice = -1, dis, contador_maior, escolha;
    int i, tamanho, dis_menor, dis_atual;
    while(tam_Lista(cartas_Jogadas) != 0) {// Enquanto tiver carta para ser colocada
        removerInd_Lista(cartas_Jogadas, 0, &atual);

        for(i=0; i<QTD_MESA; i++) {//Verifica onde a carta deve ser colocada

            acessar_Fila(mesa[i], 1, &aux);

            dis_atual = atual.numero - aux.numero;
            dis_menor = atual.numero - menor;

            if(aux.numero < atual.numero && dis_atual < dis_menor) {
                indice = i;
                menor = aux.numero;
            }
        }

        if(DEBUG) {
            color(14);
            printf("\n[-[%d]-][%d][%d][%d]\n", atual.numero,atual.jogador,indice, menor);
            color(15);
        }

        if(indice == -1 && atual.jogador == 0) {// Se a carta é menor que todas e é a carta do jogador
            printf("Escolha uma fila para trocar (1 a 4): ");
            scanf("%d", &escolha);
            while(escolha > QTD_MESA || escolha < 1) {
                error(1);
                scanf("%d", &escolha);
            }
            escolha--;
            while(tam_Fila(mesa[escolha]) != 0) {
                remover_Fila(mesa[escolha], &aux);
                inserirIni_Lista(colecao[atual.jogador], aux);
            }
            inserir_Fila(mesa[escolha], atual);
        }
        else if(indice == -1 && atual.jogador != 0) {// Se a carta é menor que todas e é a carta do bot
            int escolha_bot = 2;
            while(tam_Fila(mesa[escolha_bot]) != 0) {
                remover_Fila(mesa[escolha_bot], &aux);
                inserirIni_Lista(colecao[atual.jogador], aux);
            }
            inserir_Fila(mesa[escolha_bot], atual);
        }
        else if(tam_Fila(mesa[indice]) < QTD_MESA_MAX) {// Se a carta pode ser colocada normalmente
            inserir_Fila(mesa[indice], atual);
        }
        else {// Se o lugar onde a carta seria colocada está cheio
            while(tam_Fila(mesa[indice]) != 0) {
                remover_Fila(mesa[indice], &aux);
                inserirIni_Lista(colecao[atual.jogador], aux);
            }
            inserir_Fila(mesa[indice], atual);
        }

    }
}

void contar_pontos(Lista* colecao[], int qtd_player) {
    int i, j, pontos=0, tabela[qtd_player], vencedor;
    struct carta aux;
    for(i=0; i<qtd_player; i++) {
        while(tam_Lista(colecao[i]) != 0) {
            removerInd_Lista(colecao[i], 0, &aux);
            pontos += aux.bois;
        }
        tabela[i] = pontos;
        if(i==0) vencedor = i;
        if(pontos < tabela[vencedor]) vencedor = i;
        pontos = 0;
    }
    for(i=0; i<qtd_player; i++) {
        printf("Player {%d} = [%d]\n", i+1, tabela[i]);
    }
    printf("VENCEDOR: %d", vencedor + 1);
}
