#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "estado.h"
#include "interpretador.h"




ESTADO novojogo (ESTADO e,char *peca){
    int l,c;


    e=push(e);

    e.modo = 'M';

    for(l=0;l<8;l++){
        for(c=0;c<8;c++){
            if (l==3 && c==3) e.grelha[3][3]=VALOR_O;
            else if(l==4 && c==4) e.grelha[4][4]=VALOR_O;
            else if(l==3 && c==4) e.grelha[3][4]=VALOR_X;
            else if(l==4 && c==3) e.grelha[4][3]=VALOR_X;
            else e.grelha[l][c]=VAZIA;
        }
    }
    switch (toupper(peca[0])){
        case 'X':
            e.peca=VALOR_X;
            break;
        case 'O':
            e.peca=VALOR_O;
            break;
        default:

            printf("A peça nao é valida\n");
    }

    e=push(e);

    return e;
}



















ESTADO interpretar (ESTADO e,char *linha){
    char cmd[MAXBUFFER];  //variavel para guardar uma string
    char peca [MAXBUFFER]; // guarda a peça que vais jogar
    int n,contadorO,contadorX;
    char l [MAXBUFFER];
    char c [MAXBUFFER];
    sscanf(linha,"%s",cmd);
    switch (toupper(cmd[0])){
        case 'N':
            n = sscanf(linha, "%s %s", cmd, peca);
            if (n == 2) e = novojogo(e, peca); //se nao tiver dois argumentos nao é valido
            else printf("ERRO META 2 PARAMETROS\n");

            printa(e);

            break;
        case 'L':
            e=darload(e,linha);
            break;
        case 'E':
            guardaalteracao(e,linha);
            break;
        case 'J':
            n = sscanf(linha, "%s %s %s", cmd,l ,c);
            if (n == 3) {
                e=pontoparajogadas(e);
                e=trocarpecas(e,l[0],c[0]);
                contadorO = ContadorDeBola(e);
                contadorX = ContadorDeX(e);
                if (contadorO + contadorX < 64) printa(e);

                else {
                    if (contadorO > contadorX) printf("Jogador 'O' Ganhou com %d pontos\n",contadorO);
                    else if (contadorO < contadorX) printf("Jogador 'X Ganhou com %d pontos\n",contadorX);
                    else printf("Empate\n");
                }


            }
            else printf("ERRO META 3 PARAMETROS \n");
            break;
        case 'S':
            e = pontoparajogadas(e);
            printapontos(e);
            break;
        case 'H':
            e=pontoparajogadas(e);
            printamelhorjogada(e);
            break;
        case 'U':
            e=pop(e);
            printa(e);
            break;
        case 'A':
            break;
        case 'Q':
            exit(0);
        default:
            printf("ESCOLHA UM COMANDO VALIDO!\n");

    }
    return (e);
}

void printprompt(ESTADO e){
    switch (e.peca){
        case VALOR_X:
            printf ("reversi X > ");
            break;
        case VALOR_O:
            printf ("reversi O > ");
            break;
        default:
            printf ("reversi ? > ");
    }

}


void interpretador(ESTADO e){
    char linha[MAXBUFFER];
    printprompt (e);
    while (fgets (linha,MAXBUFFER,stdin)){
        e = interpretar(e,linha);
        //printa(e);
        printprompt(e);
    }
}






