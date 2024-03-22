#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "fila.h"
#include "lista.h"
#include "pilha.h"
#include "carta.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");
    color(15);
    Pilha* Baralho = embarai_Barai(gera_Barai()); // Cria as cartas e Embaralha as cartas
    struct carta aux;

    //Tela Inicial
    iniciar();

    //Escolha da quantidade de jogadores
    int qtd_player = config();
    int pontos[qtd_player];
    for (int i=0;i<qtd_player;i++)
        pontos[i]=0;

    // Criando a Mesa
    Fila* mesa[QTD_MESA];
    cria_Mesa(Baralho, mesa);

    //Criando as Maos
    Lista* maos[qtd_player];
    cria_Maos(Baralho,maos,qtd_player);

    // Criando as coleções
    Lista* colecoes[qtd_player];
    cria_Colecoes(Baralho,colecoes,qtd_player);

    Lista* cartasJogadas = criar_Lista();


    // Começando o jogo
    int tam = tam_Lista(maos[0]);
    while (tam){
        int n;

        //Mostra as informações na tela
        system("cls");
        printf("\n\n");
        exibe_Mesa(mesa);
        exibe_Pontos(pontos,qtd_player);


        //Mostra as coleções
        printf("Ver coleções?\n 1/0: ");
        scanf(" %d",&n);
        while (n!=0&&n!=1){
            error(1);
            scanf(" %d",&n);
        }
        if(n) exibe_Colecoes(colecoes,qtd_player);


        //Jogada
        exibe_Mao(maos,tam);
        printf("\nEscolha uma carta para jogar: ");
        scanf("%d", &n);
        while(n < 0 || n >= tam) {
            error(1);
            scanf("%d", &n);
        }

        removerInd_Lista(maos[0], n, &aux);
        inserirOrd_Lista(cartasJogadas, aux);

        for(int i=1; i<qtd_player; i++) {
            int nbot = jogada_bot(mesa,maos[i],0);
            removerInd_Lista(maos[i],nbot,&aux);
            inserirOrd_Lista(cartasJogadas,aux);
        }

        // Validação da lista em que a carta vai entrar
        inserir_Mesa(mesa,cartasJogadas,colecoes,pontos,qtd_player);

        tam = tam_Lista(maos[0]);
    }

    //Mostra as informações na tela
    system("cls");
    printf("\n\n");
    exibe_Mesa(mesa);
    exibe_Pontos(pontos,qtd_player);

    //Fim do jogo
    conta_Pontos(pontos,qtd_player);

    return 0;
}

