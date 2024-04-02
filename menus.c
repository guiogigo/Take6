#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>

#include "fila.h"
#include "lista.h"
#include "pilha.h"
#include "carta.h"
#include "menus.h"

// ARTHUR FEZ

void titulo() {
    int cor = 13;
    printf("-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n");
    Sleep(500);
    color(cor);
    printf("        ______  _______  _______  _______     _______  _______     ______ \n");
    printf("       |   __ \\|    ___||     __||   _   |   |    ___||   |   |   |    __| \n");
    printf("       |    __/|    ___||    |  ||       |   |    ___||       |   |  __  | \n");
    printf("       |___|   |_______||_______||___|___|   |_______||__|_|__|   |______| \n");
    color(15);
    Sleep(500);
    printf("                                      ,              ,\n");
    printf("                                     |\\            /|\n");
    printf("                                     \\ `-./\\/\\/-.' /\n");
    printf("                                      \\_ /      \\ _/\n");
    printf("                                   __.--/ __  __ \\--.__\n");
    printf("                                  `\\__.| (");
    color(cor);
    printf(".    .");
    color(15);
    printf(") |.__/`\n");
    printf("                                       |    /\\    |\n");
    printf("                                        \\  |  |  /\n");
    printf("                                         |_/\\_|_/\n");
    printf("                                        /         \\\n");
    printf("                                        \\  ^    ^ /\n");
    printf("                                         \\ .-''-./\n");
    Sleep(500);
    printf("-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n");
};

void creditos() {
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    color(13);
    printf("               ____  ____  _____ ____  _  _____  ____  ____\n");
    printf("              /   _\\/  __\\/  __//  _ \\/ \\/__ __\\/  _ \\/ ___\\\n");
    printf("              |  /  |  \\/||  \\  | | \\|| |  / \\  | / \\||    \\\n");
    printf("              |  \\_ |    /|  /_ | |_/|| |  | |  | \\_/|\\___ |\n");
    printf("              \\____/\\_/\\_\\\\____\\\\____/\\_/  \\_/  \\____/\\____/\n");
    color(15);
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    Sleep (1000);
    color(11);
    printf("        _______         __  __  __\n");
    printf("       |     __|.--.--.|__||  ||  |--..-----..----..--------..-----.\n");
    printf("       |    |  ||  |  ||  ||  ||     ||  -__||   _||        ||  -__|\n");
    printf("       |_______||_____||__||__||__|__||_____||__|  |__|__|__||_____|\n");
    color(15);
    Sleep(300);
    color(12);
    printf("        _______        __    __                     ____\n");
    printf("       |   _   |.----.|  |_ |  |--..--.--..----.   |_   |\n");
    printf("       |       ||   _||   _||     ||  |  ||   _|    _|  |\n");
    printf("       |___|___||__|  |____||__|__||_____||__|     |______|\n");
    color(15);
    Sleep(300);
    color(14);
    printf("        _______        __    __                     ______\n");
    printf("       |   _   |.----.|  |_ |  |--..--.--..----.   |__    |\n");
    printf("       |       ||   _||   _||     ||  |  ||   _|   |    __|\n");
    printf("       |___|___||__|  |____||__|__||_____||__|     |______|\n");
    color(15);
};

void vitoria(){
    int cor = 13;
    color(cor);
    printf("-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n");
    color(10);
    printf("                                                /)  (\\\n");
    printf("                                           .-._((,~~.))_.-,\n");
    printf("                                            `-.   ");
    color(cor);
    printf("@@   ");
    color(10);
    printf(",-'\n");
    printf("                                              / ,n--n. \\\n");
    printf("                                     (`'\\   ( ( .__. ) )  /`')\n");
    printf("                                       `.'\"._ ) `----' (_,\"`.`.\n");
    printf("                                         \"._             _,\"\n");
    printf("                                            /            \\\n");
    printf("                                           (              )\n");
    printf("                                           (`-.__    __.-')\n");
    printf("                                            \\   /`--'\\   /\n");
    printf("                                             ) /      \\ (\n");
    printf("                                            /._\\      /_,\\\n");
    printf("                 _     ____  ____  _____     _____ ____  _      _     ____  _     _  _  \n");
    printf("                / \\ |\\/  _ \\/   _\\/  __/    /  __//  _ \\/ \\  /|/ \\ /|/  _ \\/ \\ /\\/ \\/ \\\n");
    printf("                | | //| / \\||  /  |  \\      | |  _| / \\|| |\\ ||| |_|||| / \\|| | ||| || |\n");
    printf("                | \\// | \\_/||  \\_ |  /_     | |_//| |-||| | \\||| | ||| \\_/|| \\_/|\\_/\\_/\n");
    printf("                \\__/  \\____/\\____/\\____\\    \\____\\\\_/ \\|\\_/  \\|\\_/ \\|\\____/\\____/(_)(_)\n");
    color(cor);
    printf("-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n");
    color(15);
};

void derrota(){
    int cor = 13;
    color(cor);
    printf("-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n");
    color(12);
    printf("                                      ,              ,\n");
    printf("                                       |\\            /|\n");
    printf("                                       \\ `-./\\/\\/-.' /\n");
    printf("                                        \\_ /      \\ _/\n");
    printf("                                     __.--/ __  __ \\--.__\n");
    printf("                                    `\\__.| (x    x) |.__/`\n");
    printf("                                         |    /\\    |\n");
    printf("                                          \\  |  |  /\n");
    printf("                                           |_/\\_|_/\n");
    printf("                                          /         \\\n");
    printf("                                          \\  ^    ^ /\n");
    printf("                                           \\ .-''-./\n");
    color(cor);
    printf("                      _     ____  ____  _____   ____  _____ ____  ____  _____ _\n");
    printf("                    / \\ |\\/  _ \\/   _\\/  __/  /  __\\/  __//  __\\/  _ \\/  __// \\ /\\\n");
    printf("                    | | //| / \\||  /  |  \\    |  \\/||  \\  |  \\/|| | \\||  \\  | | ||\n");
    printf("                    | \\// | \\_/||  \\_ |  /_   |  __/|  /_ |    /| |_/||  /_ | \\_/\n");
    printf("                    \\__/  \\____/\\____/\\____\\  \\_/   \\____\\\\_/\\_\\\\____/\\____\\\\____/\n");
    printf("\n");
    color(12);
    printf("                                      .-. .-. .-.   .-.   .\n");
    printf("                                      |-  |-   /    | |   |\n");
    printf("                                      '   `-' `-'   `-'   `-'\n");
    color(cor);
    printf("-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n");
    color(15);
};

void regras(){
    int cor = 13;
    color(cor);
    printf("-=-=-=>OBEJETIVO DO JOGO<=-=-=-\n");
    color(15);
    printf("    O objetivo do jogo é evitar cartas. Cada   \n");
    printf(" carta que você pega lhe rende um ponto  \n");
    printf(" negativo para cada cabeça de boi impressa sobre  \n");
    printf(" a carta. O jogador com menos pontos após  \n");
    printf(" algumas rodadas é o vencedor.                  \n");
    Sleep (200);
    color(cor);
    printf("-=-=-=>PEGANDO UMA FILEIRA<=-=-=-\n");
    color(15);
    printf("Enquanto for possível incluir uma carta numa fileira\n");
    printf("existente, o jogo segue normalmente. Porém, o que\n");
    printf("acontece se a fileira onde a carta do jogador se\n");
    printf("encaixa está completa ou a carta do jogador não \n");
    printf("servir em nenhuma fileira? Nestes casos, ele deve\n");
    printf("pegar todas as cartas da fileira.\n");
    Sleep(200);
    color(cor);
    printf("-=-=-=>COMO JOGAR<=-=-=-\n");
    color(15);
    printf("Cada jogador escolhe uma carta de sua mão e\n");
    printf("coloca-a virada para baixo sobre a mesa. Quando\n");
    printf("todos tiverem escolhido, os jogadores revelam as\n");
    printf("cartas ao mesmo tempo e colocam nas suas respectivas\n");
    printf("filas em ordem crescente.\n");

};

