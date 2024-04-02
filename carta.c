#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <locale.h>

#include "lista.h"
#include "pilha.h"
#include "fila.h"
#include "carta.h"
#include "menus.h"

Lista* gera_Barai(){
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

Pilha* embarai_Barai(Lista* lis){
    Pilha* pil = criar_Pilha();

    struct carta aux;

    srand(time(0));
    for (int i=0; i<QTD_CARTA; i++){
        int pos = rand() % (QTD_CARTA-i);
        removerInd_Lista(lis,pos,&aux);

        inserir_Pilha(pil,aux);
    }
    free(lis);
    return pil;
}

void cria_Mesa(Pilha* pil, Fila* mesa[]){
    struct carta aux;
    for(int i=0;i<QTD_MESA;i++){
        mesa[i] = criar_Fila();
        remover_Pilha(pil,&aux);
        inserir_Fila(mesa[i],aux);
    }
}

void exibe_Mesa(Fila* mesa[]){
    printf("\n");
    for(int i=0;i<QTD_MESA;i++){
        color(13);
        exibir_Fila(mesa[i]);
        printf("\n");
        color(15);
    }
}

void cria_Maos(Pilha* pil, Lista* maos[], int qtd_player){
    struct carta aux;
    for(int i=0; i<qtd_player; i++) {
        maos[i] = criar_Lista();
        for(int j=0; j<QTD_MAO; j++) {
            remover_Pilha(pil, &aux);
            aux.jogador = i;
            inserirOrd_Lista(maos[i], aux);
        }
    }
}

void exibe_Mao(Lista* maos[],int tam){
    color(11);
    printf("Sua Mão:\n");
    exibir_Lista(maos[0]);
    for(int i=0;i<tam;i++)
        printf("   (%d)      ",i);
    printf("\n");
    color(15);
}

void cria_Colecoes(Pilha* pil, Lista* colecoes[],int qtd_player){

     for(int i=0; i<qtd_player; i++)
        colecoes[i] = criar_Lista();

}

void exibe_Colecoes(Lista* colecoes[],int qtd_player){
    printf("\nTodas as coleções:\n\n");
    for (int i=0;i<qtd_player;i++){
        printf("Player %d - ",i);
        exibir_Lista(colecoes[i]);
    }
    printf("\n");
}

void exibe_Pontos(int pontos[], int qtd_player){
    for(int i=0;i<qtd_player;i++){
        printf("=>-<=",pontos[i]);
    }
    printf("\n");
    for(int i=0;i<qtd_player;i++){
        printf("P.%d: ",i);
    }
    printf("\n");
    for(int i=0;i<qtd_player;i++){
        printf("%3d  ",pontos[i]);
    }
    printf("\n");
    for(int i=0;i<qtd_player;i++){
        printf("=>-<=",pontos[i]);
    }
    printf("\n");
}

void inserir_Mesa(Fila* mesa[], Lista* cartasJogadas, Lista* colecoes[], int pontos[], int qtd_player){
    struct carta aux, atual;
    int dif_menor, indice = -1;

    // Enquanto tiver carta para ser colocada
    while (tam_Lista(cartasJogadas)){
        system("cls");
        color(12);
        exibir_Lista(cartasJogadas);
        color(15);
        printf("\n");
        exibe_Mesa(mesa);
        exibe_Pontos(pontos,qtd_player);

        removerInd_Lista(cartasJogadas,0,&atual);

        //Verifica onde a carta deve ser colocada
        dif_menor = QTD_CARTA;
        for (int i=0;i<QTD_MESA;i++){
            acessar_Fila(mesa[i],1,&aux);

            if (aux.numero<atual.numero && atual.numero-aux.numero<dif_menor){
                dif_menor = atual.numero-aux.numero;
                indice = i;
            }
        }
        // Se a carta é menor que todas
        if (indice == -1){
            //Se é a carta do jogador
            if (atual.jogador == 0){
                int n;
                printf("Sua carta foi a menor.\nEscolha uma fila para trocar (0 a 3): ");
                scanf("%d", &n);
                while(n >= QTD_MESA || n < 0) {
                    error(1);
                    scanf("%d", &n);
                }
                while(tam_Fila(mesa[n]) != 0) {
                    remover_Fila(mesa[n], &aux);
                    inserirIni_Lista(colecoes[atual.jogador], aux);
                    pontos[atual.jogador] += aux.bois;
                }
                inserir_Fila(mesa[n], atual);
            }
            //Se é a carta do bot
            else{
                int nbot = jogada_bot(mesa,NULL,1);
                while(tam_Fila(mesa[nbot]) != 0) {
                    remover_Fila(mesa[nbot], &aux);
                    inserirIni_Lista(colecoes[atual.jogador], aux);
                    pontos[atual.jogador] += aux.bois;
                }
                inserir_Fila(mesa[nbot], atual);
            }
        }
        // Se o lugar onde a carta seria colocada está cheio
        else if(tam_Fila(mesa[indice]) == QTD_MAX_MESA) {
            while(tam_Fila(mesa[indice]) != 0) {
                remover_Fila(mesa[indice], &aux);
                inserirIni_Lista(colecoes[atual.jogador], aux);
                pontos[atual.jogador] += aux.bois;
            }
            inserir_Fila(mesa[indice], atual);
        }
        // Se a carta pode ser colocada normalmente
        else {
            inserir_Fila(mesa[indice], atual);
        }
        Sleep(500);
    }
}

int jogada_bot(Fila* mesa[],Lista* mao, int mode){
    struct carta aux, atual;
    int dif_menor = QTD_CARTA, indice = -1;
    int bois, min_bois;

    switch (mode){
    case 0:
        for (int i=0;i<QTD_MESA;i++){
            acessar_Fila(mesa[i],1,&aux);

            for (int j=0;j<tam_Lista(mao);j++){
                acessarInd_Lista(mao,j,&atual);
                if (aux.numero<atual.numero && atual.numero-aux.numero<dif_menor){
                    dif_menor = atual.numero-aux.numero;
                    indice = j;
                }
            }
        }
        indice = (indice==-1)? 0:indice;
        return indice;
    case 1:
        indice = 0;
        min_bois = qtd_bois(mesa[0]);

        for (int i=1;i<QTD_MESA;i++){
            bois = qtd_bois(mesa[i]);
            if(bois<min_bois){
                min_bois = bois;
                indice = i;
            }
        }
        return indice;
    }
    return 0;
}

void conta_Pontos(int pontos[], int qtd_player){

    printf("Ranking final:\n");

    int pImpressos = 0;
    int menos_pontos = 0;
    int p0 = 0;

    while(pImpressos!=qtd_player){
        for (int i=0;i<qtd_player;i++)
            menos_pontos = (pontos[i]>menos_pontos)? pontos[i]:menos_pontos;

        for (int i=0;i<qtd_player;i++)
            menos_pontos = (pontos[i]<menos_pontos && pontos[i]!=-1)? pontos[i]:menos_pontos;

        printf("%dº -", pImpressos+1);
        for (int i=0;i<qtd_player;i++){
            if (pontos[i]==menos_pontos){

                if(pImpressos == 0 && i == 0) {
                    p0 = 1;
                }
                printf(" P.%d ",i);
                pontos[i]=-1;
                pImpressos++;
            }
        }
        printf("\n");

    }
    if(p0)vitoria();
    else derrota();
}


int iniciar()  {
    int n;
    titulo();
    color(13);
    printf("[1] - JOGAR\n");
    Sleep(500);
    printf("[2] - REGRAS\n");
    Sleep(500);
    printf("[3] - CREDITOS\n");
    Sleep(250);
    color(15);
    printf("Insira sua escolha: ");
    scanf("%d", &n);
    while(n < 1 || n > 3) {
        error(1);
        scanf("%d", &n);
    };

    system("cls");

    switch(n) {
    case 1:
        return 1;
        break;
    case 2:
        color(13);
        printf("-=-=-=>OBEJETIVO DO JOGO<=-=-=-\n");
        color(15);
        printf("    O objetivo do jogo é evitar cartas. Cada   \n");
        printf(" carta que você pega lhe rende um ponto  \n");
        printf(" negativo para cada cabeça de boi impressa sobre  \n");
        printf(" a carta. O jogador com menos pontos após  \n");
        printf(" algumas rodadas é o vencedor.                  \n");
        Sleep (200);
        color(13);
        printf("-=-=-=>PEGANDO UMA FILEIRA<=-=-=-\n");
        color(15);
        printf("Enquanto for possível incluir uma carta numa fileira\n");
        printf("existente, o jogo segue normalmente. Porém, o que\n");
        printf("acontece se a fileira onde a carta do jogador se\n");
        printf("encaixa está completa ou a carta do jogador não \n");
        printf("servir em nenhuma fileira? Nestes casos, ele deve\n");
        printf("pegar todas as cartas da fileira.\n");
        Sleep(200);
        color(13);
        printf("-=-=-=>COMO JOGAR<=-=-=-\n");
        color(15);
        printf("Cada jogador escolhe uma carta de sua mão e\n");
        printf("coloca-a virada para baixo sobre a mesa. Quando\n");
        printf("todos tiverem escolhido, os jogadores revelam as\n");
        printf("cartas ao mesmo tempo e colocam nas suas respectivas\n");
        printf("filas em ordem crescente.\n");
        continuar();
        system("cls");
        break;
    case 3:
        creditos();
        continuar();
        system("cls");
        break;
    return 0;
    }
}

int config() {
    int n;
    printf("Insira a quantidade de oponentes (1 à 9): ");
    scanf("%d", &n);
    while(n < 1 || n > 9) {
        error(1);
        scanf("%d", &n);
    };
    system("cls");
    return n+1;
}

void color(int n){
    HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hconsole,n);
}

void error(int code) {
    switch (code) {
    case 1:
        color(12);
        printf("Insira um valor válido: ");
        color(15);
        break;
    }
}

void continuar() {
    printf("Pressione ENTER para continuar:");
    fflush(stdin);
    getchar();
}
