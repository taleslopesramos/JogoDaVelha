#pragma once

typedef struct {
    int x, y;
} Pos;


typedef struct {
    Pos jogada, jogada_anterior;
    
    // número do bot no tab lógico
    int num_tab_log;
    
    // rodada atual
    int rodada;
    
    // 0 - melhor caso ; 1 - caso médio ; 2 - pior caso
    int situacao_atual_bot;
} Bot;

void init_bot(Bot *bot, int bot_num);

// ANALIZA UM JOGO E DA UMA JOGADA
void analisa_jogo(Bot *bot, int tab[3][3]);

// COPIA O VALOR DA POS 2 E COLOCA NA POS 1
void cp_pos(Pos *p1,Pos *p2);

// COMPARA 2 POSIÇÕES
int cmp_pos(Pos p1, Pos p2);