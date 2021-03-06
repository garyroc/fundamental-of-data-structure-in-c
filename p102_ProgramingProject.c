#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define max_x 40
#define max_y 20
#define start_x 10
#define start_y 10

#define max_steps 50000


int imove[] = {-1, 0, 1, 1, 1, 0, -1, -1};
int jmove[] = {1, 1, 1, 0, -1, -1, -1, 0};

int main()
{

    int base_x, base_y;
    printf("Plz input the number of n and m in the n * m matrix:");
    scanf("%d %d", &base_x, &base_y);

    if(base_x > max_x || base_x <=2 || base_y > max_y || base_y <=2){
        fprintf(stderr, "Invalid matrix size!");
        exit(EXIT_FAILURE);
    }

    /*Initialize maze*/
    int maze[base_x][base_y];
    for (int i = 0; i < base_x;i++){
        for (int j = 0; j < base_y; j++)
            maze[i][j] = 0;
    }

    
    int step = 1, touch = 1,x = start_x , y = start_y;
    maze[x][y]++;
    srand(time(NULL));

    while(step < 50000 && touch < base_x * base_y ){
        int move = rand() % 8;
        x += imove[move], y += jmove[move];
        if(x == base_x || x < 0 || y == base_y  || y <0){
            x -= imove[move], y -= jmove[move];
            continue;
        }
        step++;
        if(!maze[x][y])
            touch++;
        maze[x][y]++;
    }

    printf("\nsteps:%d\ntouched density:\n", step);

    for (int i = 0; i < base_x;i++){
        for (int j = 0; j < base_y;j++)
            printf("%5d ", maze[i][j]);
        printf("\n");
    }

    return 0;
}