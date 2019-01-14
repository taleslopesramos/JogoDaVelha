#include "velha.h"
#include <stdio.h>
#include <stdlib.h>

int efetua_jogada(char jogador, int tab[3][3]){
    int jogador_int = (jogador == 'X') ? (1) : (2);
    int jogada_X, jogada_Y;
    
    scanf("%d %d", &jogada_X, &jogada_Y);
    --jogada_X;
    --jogada_Y;

    // VALIDA SE A POSIÇÃO É VÁLIDA
    if(tab[jogada_X][jogada_Y] == 0 && (jogada_X >= 0 && jogada_X < 3) && (jogada_Y >= 0 && jogada_Y < 3)){
        tab[jogada_X][jogada_Y] = jogador_int;
        return 1;
    }

    return 0;
}

void define_jogadores(char *jogador_1,char *jogador_2){
    do{
        printf("Jogador 1 escolha X ou O.\n");
        scanf("\n%c", jogador_1);
    }while(*jogador_1 != 'O' && *jogador_1 != 'X');

    if(*jogador_1 == 'O'){
        *jogador_2 = 'X';
    }else{
        *jogador_2 = 'O';
    }

    printf("Então jogador 2 é: %c\n", *jogador_2);
}

void rest_tab(int tab[3][3]){
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            tab[i][j] = 0;
        }        
    }
}

void print_tab(int tab[3][3]){
    char auxiliar; 
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            auxiliar = convert_posicao(tab[i][j]);

            printf("%c | ", auxiliar);
        }        
        auxiliar = convert_posicao(tab[i][2]);
        printf("%c\n", auxiliar);
    }
}

char convert_posicao(int posicao){
    if(posicao == 0) return ' ';
    return (posicao == 1) ? 'X' : 'O';
}

int check_gameover(int tab[3][3], int *game_over){
    int deu_velha = 1;

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(tab[i][j] == 0)
                deu_velha = 0;
        }
    }

    // SE DEU VELHA RETORNA O VENCEDOR COMO 0 E DA GAME OVER
    if(deu_velha){
        *game_over = 1;
        return 0;
    }
    
    int colunas = check_colunas(tab);

    // SE DEU ALGUMA COLUNA RETORNA O VENCEDOR E DA GAME OVER
    if(colunas){
        *game_over = 1;
        return colunas;
    }

    int linhas = check_linhas(tab);

    // SE DEU ALGUMA LINHA RETORNA O VENCEDOR E DA GAME OVER
    if(linhas){
        *game_over = 1;
        return linhas;
    }

    int diagonais = check_diagonais(tab);

    // SE DEU ALGUMA DIAGONAL RETORNA O VENCEDOR E DA GAME OVER    
    if(diagonais){
        *game_over = 1;
        return diagonais;
    }

    *game_over = 0;
    return 0;
}

int check_colunas(int tab[3][3]){
    for(int i = 0; i < 3; i++)
    {
        if((tab[0][i] == tab[1][i] && tab[1][i] == tab[2][i]) && tab[0][i] != 0){
            return tab[0][i];
        }
    }

    return 0;
}

int check_linhas(int tab[3][3]){
    for(int i = 0; i < 3; i++)
    {
        if((tab[i][0] == tab[i][1] && tab[i][1] == tab[i][2]) && tab[i][0] != 0){
            return tab[i][0];
        }
    }

    return 0;
}

int check_diagonais(int tab[3][3]){
    if((tab[0][0] == tab[1][1] && tab[0][0] == tab[2][2]) && (tab[0][0] != 0)){
        return tab[0][0];
    }

    if((tab[2][0] == tab[1][1] && tab[2][0] == tab[0][2]) && tab[2][0] != 0){
        return tab[2][0];
    }

    return 0;
}

void display_gameover_screen(int vencedor, char jogador_1){
    if(vencedor == 0){
        printf("Deu Velha!!\n");
    }else{
        char aux = convert_posicao(vencedor);
        
        if(aux == jogador_1){
            printf("Jogador 1 venceu!!\n");
        }else{
            printf("Jogador 2 venceu!!\n");
        }        
    }
}