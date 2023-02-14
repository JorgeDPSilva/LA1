//
// Created by Jorge Silva on 2019-03-25.
//

#ifndef PROJ_ESTADO_H
#define PROJ_ESTADO_H

#define MAXBUFFER 1024




/**
estado.h
Definição do estado i.e. tabuleiro. Representação matricial do tabuleiro.
*/


// definição de valores possiveis no tabuleiro
typedef enum {VAZIA, VALOR_X, VALOR_O} VALOR;

/**
Estrutura que armazena o estado do jogo
*/


typedef struct Stack {
    VALOR peca;
    VALOR grelha[8][8];
    struct Stack *prox;

};

typedef struct Stack *Stack;



typedef struct Posicao {
    int x, y;
} Posicao;



typedef struct estado {



    VALOR peca; // peça do jogador que vai jogar!
    VALOR grelha[8][8];
    char modo; // modo em que se está a jogar! 0-> manual, 1-> contra computador


    Posicao JogadasPossiveis[60];


    Stack stack;


} ESTADO;











void printa(ESTADO);
ESTADO pontoparajogadas(ESTADO e);
void guardaalteracao(ESTADO e,char *linha);
ESTADO darload(ESTADO e,char *linha);
ESTADO trocarpecas(ESTADO e,char l,char c);
void printapontos(ESTADO e);
ESTADO mudajogador(ESTADO e);
ESTADO push (ESTADO e);
ESTADO pop (ESTADO e);
int ContadorDeX(ESTADO e);
int ContadorDeBola(ESTADO e);
void printamelhorjogada(ESTADO e);

#endif //PROJ_ESTADO_H
