#include <stdio.h>
#include <stdlib.h>
#include "estado.h"
#include "interpretador.h"



/**
 * Sempre que se joga cria um novo nodo para guarda essa jogada e coloca no topo da stack
 * @param e
 * @return
 */
ESTADO push (ESTADO e) {
    int i,j;
    Stack novo;

    novo = malloc(sizeof(struct Stack));
    novo->peca = e.peca;

    for (i=0 ; i<8 ; i++) {
        for (j=0 ; j<8 ; j++) {

            novo->grelha[i][j] = e.grelha[i][j];

        }
    }

    if (e.stack == NULL) {
        novo->prox = NULL;
        e.stack = novo;
    }

    else {

        novo->prox = e.stack;
        e.stack = novo;

    }

    return e;

}

/**
 * retira o primeiro nodo da lista ligada
 * @param e
 * @return
 */

ESTADO pop (ESTADO e) {
    Stack top = e.stack;
    int i,j;

    if (e.stack == NULL) return e;


    else if (e.stack->prox == NULL) {

        free(top);
        e.stack = NULL;

    }

    else {

        e.stack = e.stack->prox;
        free(top);


        for (i=0 ; i<8 ; i++) {
            for (j=0 ; j<8 ; j++) {
                e.grelha[i][j] = e.stack->grelha[i][j];
            }
        }

        e.peca = e.stack->peca;

    }

    return e;

}