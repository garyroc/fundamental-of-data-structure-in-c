#include <stdlib.h>
#include <stdio.h>

#define MAX_I 8
#define MAX_J 8


int ktmove1[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int ktmove2[] = {1, 2, 2, 1, -1, -2, -2, -1};
int board[MAX_I][MAX_J];


_Bool isLegal(int i,int j)
{/*board boundry check*/
    if(i < MAX_I && i > -1 && j < MAX_J && j >-1)
        return 1;
    else
    {
        return 0;
    }  
}

void warnsdorffs(int start_i,int start_j)
{

    /*initilize chess board*/
    for (int i = 0; i <MAX_I;i++){
        for (int j = 0; j < MAX_J; j++)
            board[i][j] = 0;
    }

    /*set starting position*/
    printf("starting at (%d,%d)\n", start_i, start_j);
    board[start_i][start_j] = 1;

    /*loop*/
    for (int m = 2; m <= 64;m++){
        /*Form a set of possiable next squares*/
        int npos = 0,min = 0;
        int nexti[9], nextj[9];
        for (int k = 0; k < 8;k++){
            if(isLegal(start_i + ktmove1[k],start_j + ktmove2[k])){
                if(!board[start_i + ktmove1[k]][start_j + ktmove2[k]]){
                    nexti[npos] = start_i + ktmove1[k];
                    nextj[npos++] = start_j + ktmove2[k];
                }
            }
        }

        /*Test special cases*/
        if(!npos) {
            fprintf(stderr, "Premature end!\n");
            return;
        }

        if(npos == 1){
            min = 0;
            board[nexti[min]][nextj[min]] = m;
            start_i = nexti[min];
            start_j = nextj[min];
            continue;
        }

        /*Find next square with minimum number of exits*/
        int exit[8];
        for (int l = 0; l < npos;l++){
            exit[l] = 0;
            for (int k = 0; k < 8;k++){
                if(isLegal(nexti[l] + ktmove1[k],nextj[l] + ktmove2[k])){
                    if (!board[nexti[l] + ktmove1[k]][nextj[l] + ktmove2[k]]){
                        exit[l]++;
                    }
                }
            }
        }

        int min_t = 8;
        for (int l = 0; l < npos;l++){
            if(exit[l] < min_t){
                min_t = exit[l];
                min = l;
            }
        }

        /*Move knight*/
        int i = nexti[min], j = nextj[min];
        board[i][j] = m;
        start_i = nexti[min];
        start_j = nextj[min];
    }
        
    /*Print*/
    printf("Solution:\n");
    for (int i = 0; i < MAX_I;i++){
        for (int j = 0; j < MAX_J;j++)
            printf("%5d ", board[i][j]);
        printf("\n");
    }

    return;
}

int main()
{
    for (int i = 0; i < MAX_I;i++){
        for (int j = 0; j < MAX_J;j++)
            warnsdorffs(i, j);
    }
        
    return 0;
}