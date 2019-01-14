#include <stdio.h>
#include <stdlib.h>
#include "velha.h"



int main(){
    // vazio = 0, X = 1, O = 2
    int tabuleiro[3][3], vencedor, jogada_valida;
    char jogador_1, jogador_2, resposta;
    // 0 = FALSE, 1 = TRUE
    int game_over, quit_game;

    do{
        rest_tab(tabuleiro);
        define_jogadores(&jogador_1, &jogador_2);
        game_over = 0;

        while(!game_over){
            do{
                printf("Jogador 1 efetue sua jogada:\n");
                
                jogada_valida = efetua_jogada(jogador_1, tabuleiro);
                
                print_tab(tabuleiro);
                printf("\n");
            }while(!jogada_valida);

            vencedor = check_gameover(tabuleiro, &game_over);
            
            if(game_over){
                continue;
            }

            do{
                printf("Jogador 2 efetue sua jogada:\n");

                jogada_valida = efetua_jogada(jogador_2, tabuleiro);
                
                print_tab(tabuleiro);
                printf("\n");
            }while(!jogada_valida);
            
            vencedor = check_gameover(tabuleiro, &game_over);
        }

        display_gameover_screen(vencedor, jogador_1);
        printf("\n");

        printf("Deseja sair do jogo? (S/N)");
        scanf("\n%c", &resposta);
        (resposta == 'S' || resposta == 's') ? (quit_game = 1) : (quit_game = 0); 
    }while(!quit_game);

    return 0;
}

