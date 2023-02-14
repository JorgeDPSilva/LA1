#include <stdio.h>
#include <stdlib.h>
#include "estado.h"
#include "interpretador.h"


/**
 * @param e
 * serve para printar o tabuleiro e chama outras funçoes que estao inseridas abaixo como o conta x e conta bola
 */
void printa(ESTADO e){
    char a = ' ';

    printf("\nX -> %d    O -> %d\n",ContadorDeX(e),ContadorDeBola(e));

    printf ("\n  1 2 3 4 5 6 7 8 \n");
    for (int l = 0; l < 8; l++) {
        printf("%d ",l+1);
        for (int c = 0; c < 8; c++) {
            switch (e.grelha[l][c]) {

                case VALOR_O:
                    a = 'O';
                    break;

                case VALOR_X:
                    a = 'X';
                    break;

                case VAZIA:
                    a = '-';
                    break;


            }

            printf("%c ", a);

        }
        printf("\n");
    }
    printf("\n");
}


/**
 * dá load ao jogo guardado por uma pessoa mostra o tabuleiro o modo em que joga e quem é o proximo jogador
 * @param e
 * @param linha
 * @return o estado
 */

ESTADO darload(ESTADO e,char *linha){
    FILE *f;
    int l,c,n;
    char cmd[MAXBUFFER],txt[MAXBUFFER];
    char jogador,a;

    n = sscanf(linha, "%s %s", cmd, txt);

    if (n==2) {

        if (f = fopen(txt, "r")) {

            fscanf(f,"%c %c\n",&e.modo,&jogador);

            if (jogador == 'X') e.peca = VALOR_X;
            else e.peca = VALOR_O;


            for (l = 0; l < 8; l++) {
                for (c = 0; c < 8; c++) {


                    fscanf(f, "%c ", &a);

                    if (a=='X') e.grelha[l][c] = VALOR_X;
                    else if (a=='O') e.grelha[l][c] = VALOR_O;
                    else e.grelha[l][c] = VAZIA;

                }
            }

            fclose(f);
            e=push(e);
            printa(e);

            return e;
        }

        else printf("ERRO FICHEIRO INEXISTENTE\n");
    }

    else printf("ERRO META 2 PARAMETROS\n");
}


/**
 * guarda num txt a forma como o tabuleiro está e ve o modo e peça a jogar para depois
 * quando a pessoa der load saber quem é a jogar e em que modo estava a jogar
 * @param e
 * @param linha
 */
void guardaalteracao(ESTADO e,char *linha) {
    int l, c, n;
    char a;
    char cmd[MAXBUFFER], txt[MAXBUFFER];

    n = sscanf(linha, "%s %s", cmd, txt);

    if (n == 2) {

        FILE *f = fopen(txt, "w");
        if (e.modo == 'M')  fprintf(f, "M ");  else fprintf(f, "A");
        if (e.peca == VALOR_X) { fprintf(f, "X\n"); } else fprintf(f, "O\n");

        for (l = 0; l < 8; l++) {
            for (c = 0; c < 8; c++) {

                switch (e.grelha[l][c]) {

                    case VALOR_X :
                        a = 'X';
                        break;

                    case VALOR_O :
                        a = 'O';
                        break;

                    default:
                        a = '-';
                        break;
                }

                fprintf(f, "%c ", a);      //%c é para por o caracter que quero mudar no ficheiro
            }

            fprintf(f, "\n");
        }

        fclose(f);

        printa(e);
    }

    else printf("ERRO META 2 PARAMETROS\n");
}

/**
 * Função para quando um jogador jogar trocar para a peça oposta para que seja o outro a jogar ou o bot
 * @param e
 * @return o estado
 */


ESTADO mudajogador(ESTADO e) {

    if (e.peca == VALOR_X) e.peca = VALOR_O;
    else e.peca = VALOR_X;

    e=pontoparajogadas(e);

    if (e.JogadasPossiveis[0].x == 200) {

        if (e.peca == VALOR_X) e.peca = VALOR_O;
        else e.peca = VALOR_X;

        e=pontoparajogadas(e);

        if (e.JogadasPossiveis[0].x == 200) {

            printf("game over\n");
        }

        else printf("passou a vez\n");


    }

    return e;


}

/**
 * a melhor jogada é definida atraves dos valores que criei na matriz auxiliar e ve qual das jogadas possiveis
 * tem maior valor
 * @param e
 */


void printamelhorjogada (ESTADO e) {
    int k,l,c,encontrado,maior;
    Posicao coordenadas;
    int mAxuliar[8][8] = {100, -20, 20, 5, 5, 20, -20, 100,
                          -20, -50, -5, -5, -5, -5, -50, -20,
                          20, -5, 15, 3, 3, 15, -5, 20,
                          5, -5, 3, 3, 3, 3, -5, 5,
                          5, -5, 3, 3, 3, 3, -5, 5,
                          20, -5, 15, 3, 3, 15, -5, 20,
                          -20, -50, -5, -5, -5, -5, -50, -20,
                          100, -20, 20, 5, 5, 20, -20, 100,};



    for (k=0 ; e.JogadasPossiveis[k].x < 200; k++) {

        if (k == 0) {
            maior = mAxuliar[e.JogadasPossiveis[0].x][e.JogadasPossiveis[0].y];
            coordenadas.x = e.JogadasPossiveis[0].x;
            coordenadas.y = e.JogadasPossiveis[0].y;
        }

        else if (maior < mAxuliar[e.JogadasPossiveis[k].x][e.JogadasPossiveis[k].y]) {
            maior = mAxuliar[e.JogadasPossiveis[k].x][e.JogadasPossiveis[k].y];
            coordenadas.x = e.JogadasPossiveis[k].x;
            coordenadas.y = e.JogadasPossiveis[k].y;
        }

    }

    printf ("\n  1 2 3 4 5 6 7 8 \n");
    for (l=0 ; l<8 ; l++) {
        printf("%d ",l+1);
        for (c=0 ; c<8 ; c++) {

            encontrado = 0;

            if (e.grelha[l][c] == VALOR_X) printf ("X ");
            else if (e.grelha[l][c] == VALOR_O) printf("O ");
            else {
                if (l ==coordenadas.x && c == coordenadas.y) {
                            printf("? ");
                            encontrado=1;

                }
                if (encontrado == 0) printf("- ");
            }

        }

        printf("\n");

    }

    }



/**
 * quando um jogador joga ele vai ganhar peças ao oponente e esta funçao trocas as peças que com a jogada dele conseguiu
 * @param e
 * @param linha
 * @param coluna
 * @return o estado e
 */

ESTADO trocarpecas(ESTADO e,char linha,char coluna) {
    int i, l, c, k, descoberto = 0, bandeira = 0;


    l = linha-'0'-1;
    c = coluna-'0'-1;



    for (k = 0 ; e.JogadasPossiveis[k].x < 200 && descoberto == 0 ; k++) {

        if (e.JogadasPossiveis[k].x == l && e.JogadasPossiveis[k].y == c) descoberto = 1;

    }

    if (descoberto == 1) {


        if (e.peca == VALOR_X) {

            e.grelha[l][c] = VALOR_X;

            bandeira = 0;
            i = 1;
            while (e.grelha[l + i][c] != VAZIA && l + i <= 7 && e.grelha[l + i][c] != VALOR_X) {
                if (e.grelha[l + i][c] == VALOR_O) bandeira = 1;
                i++;
            }

            if (e.grelha[l + i][c] == VALOR_X && bandeira == 1) {

                i = 1;
                while (e.grelha[l + i][c] != VALOR_X) {
                    e.grelha[l + i][c] = VALOR_X;
                    i++;
                }

            }


            bandeira = 0;
            i = 1;
            while (e.grelha[l - i][c] != VAZIA && l - i >= 0 && e.grelha[l - i][c] != VALOR_X) {
                if (e.grelha[l - i][c] == VALOR_O) bandeira = 1;
                i++;
            }

            if (e.grelha[l - i][c] == VALOR_X && bandeira == 1) {

                i = 1;
                while (e.grelha[l - i][c] != VALOR_X) {
                    e.grelha[l - i][c] = VALOR_X;
                    i++;
                }

            }


            bandeira = 0;
            i = 1;
            while (e.grelha[l][c + i] != VAZIA && c + i <= 7 && e.grelha[l][c + i] != VALOR_X) {
                if (e.grelha[l][c + i] == VALOR_O) bandeira = 1;
                i++;
            }

            if (e.grelha[l][c + i] == VALOR_X && bandeira == 1) {

                i = 1;
                while (e.grelha[l][c + i] != VALOR_X) {
                    e.grelha[l][c + i] = VALOR_X;
                    i++;
                }

            }


            bandeira = 0;
            i = 1;
            while (e.grelha[l][c - i] != VAZIA && c - i >= 0 && e.grelha[l][c - i] != VALOR_X) {
                if (e.grelha[l][c - i] == VALOR_O) bandeira = 1;
                i++;
            }

            if (e.grelha[l][c - i] == VALOR_X && bandeira == 1) {

                i = 1;
                while (e.grelha[l][c - i] != VALOR_X) {
                    e.grelha[l][c - i] = VALOR_X;
                    i++;
                }

            }


            bandeira = 0;
            i = 1;
            while (e.grelha[l + i][c + i] != VAZIA && l + i <= 7 && c + i <= 7 && e.grelha[l + i][c + i] != VALOR_X) {
                if (e.grelha[l + i][c + i] == VALOR_O) bandeira = 1;
                i++;
            }

            if (e.grelha[l + i][c + i] == VALOR_X && bandeira == 1) {

                i = 1;
                while (e.grelha[l + i][c + i] != VALOR_X) {
                    e.grelha[l + i][c + i] = VALOR_X;
                    i++;
                }

            }


            bandeira = 0;
            i = 1;
            while (e.grelha[l + i][c - i] != VAZIA && l + i <= 7 && c - i >= 0 && e.grelha[l + i][c - i] != VALOR_X) {
                if (e.grelha[l + i][c - i] == VALOR_O) bandeira = 1;
                i++;
            }

            if (e.grelha[l + i][c - i] == VALOR_X && bandeira == 1) {

                i = 1;
                while (e.grelha[l + i][c - i] != VALOR_X) {
                    e.grelha[l + i][c - i] = VALOR_X;
                    i++;
                }

            }


            bandeira = 0;
            i = 1;
            while (e.grelha[l - i][c + i] != VAZIA && l - i >= 0 && c + i <= 7 && e.grelha[l - i][c + i] != VALOR_X) {
                if (e.grelha[l - i][c + i] == VALOR_O) bandeira = 1;
                i++;
            }

            if (e.grelha[l - i][c + i] == VALOR_X && bandeira == 1) {

                i = 1;
                while (e.grelha[l - i][c + i] != VALOR_X) {
                    e.grelha[l - i][c + i] = VALOR_X;
                    i++;
                }

            }


            bandeira = 0;
            i = 1;
            while (e.grelha[l - i][c - i] != VAZIA && l - i >= 0 && c - i >= 0 && e.grelha[l - i][c - i] != VALOR_X) {
                if (e.grelha[l - i][c - i] == VALOR_O) bandeira = 1;
                i++;
            }

            if (e.grelha[l - i][c - i] == VALOR_X && bandeira == 1) {

                i = 1;
                while (e.grelha[l - i][c - i] != VALOR_X) {
                    e.grelha[l - i][c - i] = VALOR_X;
                    i++;
                }

            }
        }

        else {

            e.grelha[l][c] = VALOR_O;


            bandeira = 0;
            i = 1;
            while (e.grelha[l + i][c] != VAZIA && l + i <= 7 && e.grelha[l + i][c] != VALOR_O) {
                if (e.grelha[l + i][c] == VALOR_X) bandeira = 1;
                i++;
            }

            if (e.grelha[l + i][c] == VALOR_O && bandeira == 1) {

                i = 1;
                while (e.grelha[l + i][c] != VALOR_O) {
                    e.grelha[l + i][c] = VALOR_O;
                    i++;
                }

            }


            bandeira = 0;
            i = 1;
            while (e.grelha[l - i][c] != VAZIA && l - i >= 0 && e.grelha[l - i][c] != VALOR_O) {
                if (e.grelha[l - i][c] == VALOR_X) bandeira = 1;
                i++;
            }

            if (e.grelha[l - i][c] == VALOR_O && bandeira == 1) {

                i = 1;
                while (e.grelha[l - i][c] != VALOR_O) {
                    e.grelha[l - i][c] = VALOR_O;
                    i++;
                }

            }


            bandeira = 0;
            i = 1;
            while (e.grelha[l][c + i] != VAZIA && c + i <= 7 && e.grelha[l][c + i] != VALOR_O) {
                if (e.grelha[l][c + i] == VALOR_X) bandeira = 1;
                i++;
            }

            if (e.grelha[l][c + i] == VALOR_O && bandeira == 1) {

                i = 1;
                while (e.grelha[l][c + i] != VALOR_O) {
                    e.grelha[l][c + i] = VALOR_O;
                    i++;
                }

            }


            bandeira = 0;
            i = 1;
            while (e.grelha[l][c - i] != VAZIA && c - i >= 0 && e.grelha[l][c - i] != VALOR_O) {
                if (e.grelha[l][c- i] == VALOR_X) bandeira = 1;
                i++;
            }

            if (e.grelha[l][c - i] == VALOR_O && bandeira == 1) {

                i = 1;
                while (e.grelha[l][c - i] != VALOR_O) {
                    e.grelha[l][c - i] = VALOR_O;
                    i++;
                }

            }


            bandeira = 0;
            i = 1;
            while (e.grelha[l + i][c + i] != VAZIA && l + i <= 7 && c + i <= 7 && e.grelha[l + i][c + i] != VALOR_O) {
                if (e.grelha[l + i][c + i] == VALOR_X) bandeira = 1;
                i++;
            }

            if (e.grelha[l + i][c + i] == VALOR_O && bandeira == 1) {

                i = 1;
                while (e.grelha[l + i][c + i] != VALOR_O) {
                    e.grelha[l + i][c + i] = VALOR_O;
                    i++;
                }

            }


            bandeira = 0;
            i = 1;
            while (e.grelha[l + i][c - i] != VAZIA && l + i <= 7 && c - i >= 0 && e.grelha[l + i][c - i] != VALOR_O) {
                if (e.grelha[l + i][c - i] == VALOR_X) bandeira = 1;
                i++;
            }

            if (e.grelha[l + i][c - i] == VALOR_X && bandeira == 1) {

                i = 1;
                while (e.grelha[l + i][c - i] != VALOR_O) {
                    e.grelha[l + i][c - i] = VALOR_O;
                    i++;
                }

            }


            bandeira = 0;
            i = 1;
            while (e.grelha[l - i][c + i] != VAZIA && l - i >= 0 && c + i <= 7 && e.grelha[l - i][c + i] != VALOR_O) {
                if (e.grelha[l - i][c + i] == VALOR_X) bandeira = 1;
                i++;
            }

            if (e.grelha[l - i][c + i] == VALOR_O && bandeira == 1) {

                i = 1;
                while (e.grelha[l - i][c + i] != VALOR_O) {
                    e.grelha[l - i][c + i] = VALOR_O;
                    i++;
                }

            }


            bandeira = 0;
            i = 1;
            while (e.grelha[l - i][c - i] != VAZIA && l - i >= 0 && c - i >= 0 && e.grelha[l - i][c - i] != VALOR_O) {
                if (e.grelha[l - i][c - i] == VALOR_X) bandeira = 1;
                i++;
            }

            if (e.grelha[l - i][c - i] == VALOR_O && bandeira == 1) {

                i = 1;
                while (e.grelha[l - i][c - i] != VALOR_O) {
                    e.grelha[l - i][c - i] = VALOR_O;
                    i++;
                }

            }
        }

        e=mudajogador(e);
        e=push(e);

    }

    else printf("\nJogada impossivel\n");



    return e;
}

/**
 * vê as posições validas onde é possivel jogar
 * @param e
 * @return o estado
 */

ESTADO pontoparajogadas(ESTADO e) {
    int i, l, c, k = 0, descoberto = 0, bandeira = 0, verifica = 0;



    for (l = 0; l < 8; l++) {
        for (c = 0; c < 8; c++) {


            if (e.grelha[l][c] == e.peca) {

                if (e.peca == VALOR_X) {


                    descoberto = 0; bandeira = 0; verifica = 0;

                    for (i = 1; l + i <= 7 && descoberto == 0 && verifica == 0; i++) {
                        if (e.grelha[l + i][c] == VALOR_O) bandeira = 1;
                        else if (e.grelha[l + i][c] == VAZIA) descoberto = 1;
                        else verifica = 1; //se for um X nao é jogada possivel e vai logo embora
                    }



                    i--;
                    if (l + i <= 7 && descoberto == 1 && bandeira == 1 && verifica == 0) {

                        e.JogadasPossiveis[k].x = l+i;
                        e.JogadasPossiveis[k].y = c;
                        k++;

                    }




                    descoberto = 0; bandeira = 0; verifica = 0;

                    for (i = 1; l - i <= 7 && descoberto == 0 && verifica == 0; i++) {
                        if (e.grelha[l - i][c] == VALOR_O) bandeira = 1;
                        else if (e.grelha[l - i][c] == VAZIA ) descoberto = 1;
                        else verifica = 1;
                    }


                    i--;
                    if (l - i <= 7 && descoberto == 1 && bandeira == 1 && verifica == 0) {

                        e.JogadasPossiveis[k].x = l-i;
                        e.JogadasPossiveis[k].y = c;
                        k++;

                    }



                    descoberto = 0; bandeira = 0; verifica = 0;

                    for (i = 1; c + i <= 7 && descoberto == 0 && verifica == 0; i++) {
                        if (e.grelha[l][c + i] == VALOR_O) bandeira = 1;
                        else if (e.grelha[l][c + i] == VAZIA) descoberto = 1;
                        else verifica = 1;

                    }

                    i--;
                    if (c + i <= 7 && descoberto == 1 && bandeira == 1 && verifica == 0) {

                        e.JogadasPossiveis[k].x = l;
                        e.JogadasPossiveis[k].y = c+i;
                        k++;

                    }



                    descoberto = 0; bandeira = 0; verifica = 0;

                    for (i = 1; c - i <= 7 && descoberto == 0 && verifica == 0; i++) {

                        if (e.grelha[l][c - i] == VALOR_O) bandeira = 1;
                        else if (e.grelha[l][c +i] == VAZIA) descoberto = 1;
                        else verifica = 1;

                    }

                    i--;
                    if (c - i <= 7 && descoberto == 1 && bandeira == 1 && verifica == 0) {

                        e.JogadasPossiveis[k].x = l;
                        e.JogadasPossiveis[k].y = c-i;
                        k++;

                    }




                    descoberto = 0; bandeira = 0; verifica = 0;

                    for (i = 1; l + i <= 7 && c + i <= 7 && descoberto == 0 && verifica == 0; i++) {
                        if (e.grelha[l + i][c + i] == VALOR_O) bandeira = 1;
                        else if (e.grelha[l+i][c+i] == VAZIA) descoberto = 1;
                        else verifica = 1;
                    }

                    i--;
                    if (l + i <= 7 && c + i <= 7 && descoberto == 1 && bandeira == 1 && verifica == 0) {
                        e.JogadasPossiveis[k].x = l+i;
                        e.JogadasPossiveis[k].y = c+i;
                        k++;
                    }




                    descoberto = 0; bandeira = 0; verifica = 0;

                    for (i = 1; l - i <= 7 && c - i <= 7 && descoberto == 0 && verifica == 0; i++) {
                        if (e.grelha[l - i][c - i] == VALOR_O) bandeira = 1;
                        else if (e.grelha[l-i][c-i] == VAZIA)descoberto = 1;
                        else verifica = 1;
                    }

                    i--;
                    if (l - i <= 7 && c - i <= 7 && descoberto == 1 && bandeira == 1 && verifica == 0) {

                        e.JogadasPossiveis[k].x = l-i;
                        e.JogadasPossiveis[k].y = c-i;
                        k++;

                    }




                    descoberto = 0; bandeira = 0; verifica = 0;

                    for (i = 1; l + i <= 7 && c - i <= 7 && descoberto == 0 && verifica == 0; i++) {

                        if (e.grelha[l + i][c - i] == VALOR_O) bandeira = 1;
                        else if (e.grelha[l + i][c - i] == VAZIA )descoberto = 1;
                        else verifica = 1;

                    }
                    i--;
                    if (l + i <= 7 && c - i <= 7 && descoberto == 1 && bandeira == 1 && verifica == 0 ) {

                        e.JogadasPossiveis[k].x = l+i;
                        e.JogadasPossiveis[k].y = c-i;
                        k++;

                    }




                    descoberto = 0; bandeira = 0; verifica = 0;

                    for (i = 1; l - i <= 7 && c + i <= 7 && descoberto == 0 && verifica == 0; i++) {
                        if (e.grelha[l - i][c + i] == VALOR_O) bandeira = 1;
                        else if (e.grelha[l-i][c+i] == VAZIA)descoberto = 1;
                        else verifica = 1;
                    }
                    i--;
                    if (l - i <= 7 && c + i <= 7 && descoberto == 1 && bandeira == 1 && verifica == 0) {
                        e.JogadasPossiveis[k].x = l-i;
                        e.JogadasPossiveis[k].y = c+i;
                        k++;
                    }
                }







                else {

                    descoberto = 0; bandeira = 0; verifica = 0;

                    for (i = 1; l + i <= 7 && descoberto == 0 && verifica == 0; i++) {
                        if (e.grelha[l + i][c] == VALOR_X) bandeira = 1;
                        else if (e.grelha[l + i][c] == VAZIA) descoberto = 1;
                        else verifica = 1;
                    }

                    i--;
                    if (l + i <= 7 && descoberto == 1 && bandeira == 1 && verifica == 0) {

                        e.JogadasPossiveis[k].x = l+i;
                        e.JogadasPossiveis[k].y = c;
                        k++;

                    }



                    descoberto = 0; bandeira = 0; verifica = 0;

                    for (i = 1; l - i <= 7 && descoberto == 0 && verifica == 0; i++) {
                        if (e.grelha[l - i][c] == VALOR_X) bandeira = 1;
                        else if (e.grelha[l - i][c] == VAZIA ) descoberto = 1;
                        else verifica = 1;
                    }
                    i--;
                    if (l - i <= 7 && descoberto == 1 && bandeira == 1 && verifica == 0) {

                        e.JogadasPossiveis[k].x = l-i;
                        e.JogadasPossiveis[k].y = c;
                        k++;

                    }



                    descoberto = 0; bandeira = 0; verifica = 0;

                    for (i = 1; c + i <= 7 && descoberto == 0 && verifica == 0; i++) {
                        if (e.grelha[l][c + i] == VALOR_X) bandeira = 1;
                        else if (e.grelha[l][c + i] == VAZIA) descoberto = 1;
                        else verifica = 1;

                    }

                    i--;
                    if (c + i <= 7 && descoberto == 1 && bandeira == 1 && verifica == 0) {

                        e.JogadasPossiveis[k].x = l;
                        e.JogadasPossiveis[k].y = c+i;
                        k++;

                    }



                    descoberto = 0; bandeira = 0; verifica = 0;

                    for (i = 1; c - i <= 7 && descoberto == 0 && verifica == 0; i++) {

                        if (e.grelha[l][c - i] == VALOR_X) bandeira = 1;
                        else if (e.grelha[l][c +i] == VAZIA) descoberto = 1;
                        else verifica = 1;

                    }

                    i--;
                    if (c - i <= 7 && descoberto == 1 && bandeira == 1 && verifica == 0) {

                        e.JogadasPossiveis[k].x = l;
                        e.JogadasPossiveis[k].y = c-i;
                        k++;

                    }




                    descoberto = 0; bandeira = 0; verifica = 0;

                    for (i = 1; l + i <= 7 && c + i <= 7 && descoberto == 0 && verifica == 0; i++) {
                        if (e.grelha[l + i][c + i] == VALOR_X) bandeira = 1;
                        else if (e.grelha[l+i][c+i] == VAZIA) descoberto = 1;
                        else verifica = 1;
                    }

                    i--;
                    if (l + i <= 7 && c + i <= 7 && descoberto == 1 && bandeira == 1 && verifica == 0) {
                        e.JogadasPossiveis[k].x = l+i;
                        e.JogadasPossiveis[k].y = c+i;
                        k++;
                    }




                    descoberto = 0; bandeira = 0; verifica = 0;

                    for (i = 1; l - i <= 7 && c - i <= 7 && descoberto == 0 && verifica == 0; i++) {
                        if (e.grelha[l - i][c - i] == VALOR_X) bandeira = 1;
                        else if (e.grelha[l-i][c-i] == VAZIA)descoberto = 1;
                        else verifica = 1;
                    }

                    i--;
                    if (l - i <= 7 && c - i <= 7 && descoberto == 1 && bandeira == 1 && verifica == 0) {

                        e.JogadasPossiveis[k].x = l-i;
                        e.JogadasPossiveis[k].y = c-i;
                        k++;

                    }




                    descoberto = 0; bandeira = 0; verifica = 0;

                    for (i = 1; l + i <= 7 && c - i <= 7 && descoberto == 0 && verifica == 0; i++) {

                        if (e.grelha[l + i][c - i] == VALOR_X) bandeira = 1;
                        else if (e.grelha[l + i][c - i] == VAZIA )descoberto = 1;
                        else verifica = 1;

                    }
                    i--;
                    if (l + i <= 7 && c - i <= 7 && descoberto == 1 && bandeira == 1 && verifica == 0 ) {

                        e.JogadasPossiveis[k].x = l+i;
                        e.JogadasPossiveis[k].y = c-i;
                        k++;

                    }



                    descoberto = 0; bandeira = 0; verifica = 0;

                    for (i = 1; l - i <= 7 && c + i <= 7 && descoberto == 0 && verifica == 0; i++) {
                        if (e.grelha[l - i][c + i] == VALOR_X) bandeira = 1;
                        else if (e.grelha[l-i][c+i] == VAZIA) descoberto = 1;
                        else verifica = 1;
                    }
                    i--;
                    if (l - i <= 7 && c + i <= 7 && descoberto == 1 && bandeira == 1 && verifica == 0) {
                        e.JogadasPossiveis[k].x = l-i;
                        e.JogadasPossiveis[k].y = c+i;
                        k++;
                    }
                }



            }


        }
    }

    e.JogadasPossiveis[k].x = 200;
    e.JogadasPossiveis[k].y = 200;

    return e;
}

/**
 * printa pontos nas posições possiveis
 * @param e
 */
void printapontos(ESTADO e) {
    int l,c,k,encontrado = 0;

    printf ("\n  1 2 3 4 5 6 7 8 \n");
    for (l=0 ; l<8 ; l++) {
        printf("%d ",l+1);
        for (c=0 ; c<8 ; c++) {

            encontrado = 0;

            if (e.grelha[l][c] == VALOR_X) printf ("X ");
            else if (e.grelha[l][c] == VALOR_O) printf("O ");
            else {

                for (k=0 ; e.JogadasPossiveis[k].x < 200 && encontrado == 0; k++) {

                    if (l == e.JogadasPossiveis[k].x && c == e.JogadasPossiveis[k].y) {
                        printf(". ");
                        encontrado = 1;
                    }

                }

                if (encontrado == 0) printf("- ");


            }


        }
        printf("\n");
    }
}



/**
 * conta o numero de X num tabuleiro
 * @param e
 * @return o resultado do numero de X
 */
int ContadorDeX(ESTADO e) {
    int i,j,resultado=0;


    for (i=0 ; i<8 ; i++) {
        for (j=0 ; j<8 ; j++) {

            if (e.grelha[i][j] == VALOR_X) resultado = resultado + 1;

        }
    }

    return resultado;
}

/**
 * conta o numero 'O' num tabuleiro
 * @param e
 * @return  o resultado no numero de bolas
 */
int ContadorDeBola(ESTADO e) {
    int i,j,resultado=0;


    for (i=0 ; i<8 ; i++) {
        for (j=0 ; j<8 ; j++) {

            if (e.grelha[i][j] == VALOR_O) resultado = resultado + 1;

        }
    }

    return resultado;
}









