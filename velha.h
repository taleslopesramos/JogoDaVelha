#pragma once

// RESETA O TABULEIRO
void rest_tab(int tab[3][3]);
// PRINTA O TABULEIRO
void print_tab(int tab[3][3]);
// DEFINE OS CARACTERES DOS JOGADORES
void define_jogadores(char *jogador_1,char *jogador_2);
// EFETUA A JOGADA DE UM JOGADOR NO TABULEIRO
int efetua_jogada(char jogador, int tab[3][3]);
// CONVERTE UMA POSIÇÃO DO TABULEIRO DE INTEIRO PARA CHAR
char convert_posicao(int posicao);
// RETORNA O VENCEDOR, CASO NÃO TENHA UM RETORNA 0
//{
int check_gameover(int tab[3][3], int *game_over);
int check_colunas(int tab[3][3]);
int check_linhas(int tab[3][3]);
int check_diagonais(int tab[3][3]);
//}
// MOSTRA A TELA DE GAME OVER
void display_gameover_screen(int vencedor, char jogador_1);