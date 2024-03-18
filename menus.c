#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "fila.h"
#include "lista.h"
#include "pilha.h"
#include "carta.h"
#include "menus.h"

#define DIV 25
#define DEBUG 0

void color(int n) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, n);
}

void iniciar()  {
    int escolha;
    divisor(DIV);
    printf("[1] - JOGAR\n");
    Sleep(500);
    printf("[2] - REGRAS\n");
    Sleep(500);
    printf("[3] - CREDITOS\n");
    Sleep(500);
    divisor(DIV);
    printf("Insira sua escolha: ");
    scanf("%d", &escolha);
    while(escolha < 1 || escolha > 3) {
        error(1);
        scanf("%d", &escolha);
    };

    system("cls");

    switch(escolha) {
    case 1:
        return 1;
        break;
    case 2:
        break;
    case 3:
        break;
    return 0;
    }
}

int config_Jogo() {
    int escolha;
    divisor(DIV);
    printf("Insira a quantidade de jogadores (2 à 10): ");
    scanf("%d", &escolha);
    while(escolha < 2 || escolha > 10) {
        error(1);
        scanf("%d", &escolha);
    };
    system("cls");
    return escolha;
}

void divisor(int qtd) {
    for(int i=0; i<qtd; i++) {
        printf("=");
    }
    printf("\n");
}

int receber_Valor(int min, int max, int code, char text) {
    int valor;
    printf(text);
    scanf("%d", &valor);
    while(valor<min || valor > max) {
        error(code);
        printf(text);
        scanf("%d", &valor);
    }
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

void Hud(Fila* mesa[], int qtd_player, Lista* Maos[], Lista* colecao[]) {
    int i;
    int tam = tam_Lista(Maos[0]);

    printf("\n\n\n");
    color(10);
    for(i=0; i<QTD_MESA; i++)  {// Exibe a mesa
        if(DEBUG) printf("[[%d]]", tam_Fila(mesa[i])); //Mostra a quantidade de cartas em cada fila
        exibir_Fila(mesa[i]);
    }
    printf("\n");
    color(15);

    if(DEBUG) {// Exibe a mão de todos os jogadores
        for(i=1; i<qtd_player; i++) {
            exibir_Lista(Maos[i]);
        }
    }

    //Coleções
    color(11);
    if(DEBUG) {// Exibe todas as coleções do jogo
       for(i=0; i<qtd_player; i++) {
            printf("\n{%d}", i);
            exibir_Lista(colecao[i]);
        }
        printf("\n");
    }
    else {// Exibe apenas a coleção do jogador
        printf("Sua coleção: ");
        exibir_Lista(colecao[0]);
    }

    color(15);

    // Exibe a mão do jogador
    printf("\n");
    exibir_Lista(Maos[0]);
    for(i=0; i<tam; i++) {
        printf("   (%d)      ", i);
    }
}

