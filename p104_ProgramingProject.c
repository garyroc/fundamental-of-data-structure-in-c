#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define max_x 8
#define max_y 8


int ktmove1[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int ktmove2[] = {1, 2, 2, 1, -1, -2, -2, -1};

int main()
{
    /*initilize chess board*/
    int board[max_x][max_y];
    for (int i = 0; i < max_x;i++){
        for (int j = 0; j < max_y; j++)
            board[i][j] = 0;
    }

    /*set starting position*/
    int start_x, start_y;

    scanf("%d %d", &start_x, &start_y);
    printf("starting at (%d,%d)\n", start_x, start_y);

    /*loop*/
    for (int m = 1; m <= 63;m++){
        /*Form a set of possiable next squares*/
        int npos = 0,min = 1;
        int nexti[9], nextj[9];
        for (int k = 0; k < 8;k++){
            if(!board[start_x + ktmove1[k]][start_y + ktmove2[k]]){
                nexti[npos] = start_x + ktmove1[k];
                nextj[npos++] = start_y + ktmove2[k];
            }
        }

        /*Test special cases*/
        if(!npos) {
            fprintf(stderr, "Premature end!");
            break;
        }

        if(npos == 1){
            min = 1;
            break;
        }

        /*Find next square with minimum number of exits*/
        int exit[9];
        for (int l = 1; l <= npos;l++){
            exit[l] = 0;
            for (int k = 0; k < 8;k++){
                if (!(nexti[l] + ktmove1[k]) || (nexti[l] + ktmove1[k]) == 7 || !(nextj[l] + ktmove2[k]) || (nextj[l] + ktmove2[k]) == 7){
                    exit[l]++;
                }
            }
        }

        int min_t = 8;
        for (int l = 1; l <= npos;l++){
            if(exit[l] < min_t){
                min_t = exit[l];
                min = l;
            }
        }

        /*Move knight*/
        int i = nexti[min], j = nextj[min];
        board[i][j] = m;

    }
        
    /*Print*/
    printf("Solution:\n");

    for (int i = 0; i < max_x;i++){
        for (int j = 0; j < max_y;j++)
            printf("%5d ", board[i][j]);
        printf("\n");
    }

    return 0;
}