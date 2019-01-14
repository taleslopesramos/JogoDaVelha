#include <stdio.h>
#include <stdlib.h>
#include "bot.h"
#include <time.h>

void analisa_jogo(Bot *bot, int tab[3][3]){
    int cantos_cord[] = {1, 3}, random;
    Pos pos;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(tab[i][j] != 0) bot->rodada++;
        }
    }


    srand (time(NULL));

    switch(bot->rodada){
        // BOT É O PRIMEIRO A JOGAR
        case 1:
        random = rand() % 2;
        bot->jogada.x = cantos_cord[random];

        random = rand() % 2;        
        bot->jogada.y = cantos_cord[random];        
        break;
        
        // BOT É O SEGUNDO A JOGAR
        case 2:
        // MELHOR CASO: jogador marcou um dos pontos da cruz, tirando o centro
        // REAÇÃO: jogar espelhado
        bot->situacao_atual_bot = 0;
        if(tab[0][1] != 0){
            bot->jogada.x = 2;
            bot->jogada.y = 1;
        }
        if(tab[1][0] != 0){
            bot->jogada.x = 1;
            bot->jogada.y = 2;
        }
        if(tab[2][1] != 0){
            bot->jogada.x = 0;
            bot->jogada.y = 1;
        }
        if(tab[1][2] != 0){
            bot->jogada.x = 1;
            bot->jogada.y = 0;
        }
        
        // CASO MÉDIO: jogador marcou o centro
        // REAÇÃO JOGAR EM UM DOS 4 CANTOS
        if(tab[2][2] != 0){
            bot->situacao_atual_bot = 1;

            random = rand() % 2;
            bot->jogada.x = cantos_cord[random];

            random = rand() % 2;        
            bot->jogada.y = cantos_cord[random];
        }
        
        // PIOR CASO: jogador começou pelos cantos
        // REAÇÃO: JOGAR NO CENTRO
        if(tab[0][0] != 0 || tab[0][2] != 0 || tab[2][0] != 0 || tab[2][2] != 0){
            bot->situacao_atual_bot = 2;        
            bot->jogada.x = 1; 
            bot->jogada.y = 1; 
        }
        break;
        // SEGUNDO ROUND DO BOT, 1 ROUND DO PLAYER JA SE PASSOU
        case 3:
        // MELHOR CASO: jogador marcou outro canto (AQUI O BOT JÁ GANHOU)
        if(tab[0][0] != 0 && (bot->jogada_anterior.x != 0 && bot->jogada_anterior.y != 0)){
            pos.x = 2;
            pos.y = 2;
            if(cmp_pos(pos, bot->jogada_anterior)){
                bot->jogada.x = 2; 
                bot->jogada.y = 0;
            }
            pos.x = 0;
            pos.y = 2;
            if(cmp_pos(pos, bot->jogada_anterior)){
                bot->jogada.x = 2; 
                bot->jogada.y = 2;
            }
            pos.x = 2;
            pos.y = 0;
            if(cmp_pos(pos, bot->jogada_anterior)){
                bot->jogada.x = 0; 
                bot->jogada.y = 2;
            }
        }
        if(tab[0][2] != 0 && (bot->jogada_anterior.x != 0 && bot->jogada_anterior.y != 2)){
            pos.x = 2;
            pos.y = 0;
            if(cmp_pos(pos, bot->jogada_anterior)){
                bot->jogada.x = 0; 
                bot->jogada.y = 0;
            }
            pos.x = 2;
            pos.y = 2;
            if(cmp_pos(pos, bot->jogada_anterior)){
                bot->jogada.x = 2; 
                bot->jogada.y = 0;
            }
            pos.x = 0;
            pos.y = 0;
            if(cmp_pos(pos, bot->jogada_anterior)){
                bot->jogada.x = 2; 
                bot->jogada.y = 2;
            }
        }
        if(tab[2][0] != 0 && (bot->jogada_anterior.x != 2 && bot->jogada_anterior.y != 0)){

        }
        if(tab[2][2] != 0 && (bot->jogada_anterior.x != 2 && bot->jogada_anterior.y != 2)){

        }

        // PIOR CASO: jogador marcou o centro
        // REAÇÃO JOGAR ESPELHADO DA JOGADA ANTERIOR PORÉM NO CENTRO da coluna ou linha
        if(tab[1][1] != 0){
            if(bot->jogada_anterior.x == 0){
                if(bot->jogada_anterior.y == 0){
                    bot->jogada.x = 2; 
                    bot->jogada.y = 1;
                }
                if(bot->jogada_anterior.y == 2){
                    bot->jogada.x = 1; 
                    bot->jogada.y = 0;
                }
            }
            if(bot->jogada_anterior.x == 2){
                if(bot->jogada_anterior.y == 0){
                    bot->jogada.x = 1; 
                    bot->jogada.y = 2;
                }
                if(bot->jogada_anterior.y == 2){
                    bot->jogada.x = 0; 
                    bot->jogada.y = 1;
                }
            }

        }

        break;
        case 4:
        break;
        case 5:
        break;
        case 6:
        break;
        case 7:
        break;
        case 8:
        break;
        case 9:
        break;
    }
    
    // SALVA A ULTIMA JOGADA
    cp_pos(&(bot->jogada_anterior), &(bot->jogada));

    // PASSA DUAS RODADAS A DO BOT E A DO PLAYER
    bot->rodada += 2;
}
void cp_pos(Pos *p1,Pos *p2){
    p1->x = p2->x;
    p1->y = p2->y;
}

int cmp_pos(Pos p1, Pos p2){
    if(p1.x == p2.x && p1.y == p2.y) return 1;
    return 0;
}