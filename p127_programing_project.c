/* Search a maze,and print out path from entrance to exit */

#include <stdbool.h>
#include <stdio.h>

#define MAZE_ROW_SIZE 12
#define MAZE_COL_SIZE 15
#define EXIT_ROW  12
#define EXIT_COL  15
#define ENTRANCE_ROW 1
#define ENTRANCE_COLl 1

/*Figure 3.8*/
bool maze[MAZE_ROW_SIZE + 2][MAZE_COL_SIZE + 2] = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,1,0,0,0,1,1,0,0,0,1,1,1,1,1,1},
    {1,1,0,0,0,1,1,0,1,1,1,0,0,1,1,1,1},
    {1,0,1,1,0,0,0,0,1,1,1,1,0,0,1,1,1},
    {1,1,1,0,1,1,1,1,0,1,1,0,1,1,0,0,1},
    {1,1,1,0,1,0,0,1,0,1,1,1,1,1,1,1,1},
    {1,0,0,1,1,0,1,1,1,0,1,0,0,1,0,1,1},
    {1,0,0,1,1,0,1,1,1,0,1,0,0,1,0,1,1},
    {1,0,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1},
    {1,0,0,1,1,0,1,1,0,1,1,1,1,1,0,1,1},
    {1,1,1,0,0,0,1,1,0,1,1,0,0,0,0,0,1},
    {1,0,0,1,1,1,1,1,0,0,0,1,1,1,1,0,1},
    {1,0,1,0,0,1,1,1,1,1,0,1,1,1,1,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};


typedef struct{
    int vert;
    int horiz;
} offset;

/*N NE E SE S SW W NW*/
offset move[8] = {{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};

typedef struct{
    int row;
    int col;
    int dir;
} element;

/*Record path*/
element path[MAZE_ROW_SIZE * MAZE_COL_SIZE];
int step = 0;

/*flag*/
bool exitFound = false;


/*Print out recording path*/
void printPath()
{
    printf("Success!\n");
        for (int i = 0; i < step;i++){
            printf("step %2d : %2d,%2d", i, path[i].row, path[i].col);
            switch(path[i].dir){
                case 0 : printf("     N\n");
                    break;
                case 1 : printf("     NE\n");
                    break;
                case 2 : printf("     E\n");
                    break;
                case 3 : printf("     SE\n");
                    break;
                case 4 : printf("     S\n");
                    break;
                case 5 : printf("     SW\n");
                    break;
                case 6 : printf("     W\n");
                    break;
                case 7 : printf("     NW\n");
            }
        }
        printf("step %2d : %2d,%2d", step, EXIT_ROW, EXIT_COL);
}


/*Recursively depth first travel the maze*/
void dfs(int row, int col)
{

    if(row == EXIT_ROW && col == EXIT_COL){
        printPath();
        exitFound = true;
        return;
    }

    int nextRow;
    int nextCol;    
    for (int i = 0; i < 8; i++){
        nextRow = row + move[i].vert;
        nextCol = col + move[i].horiz;

        if(!maze[nextRow][nextCol]){
            maze[nextRow][nextCol] = 1;
            path[step].row = row;
            path[step].col = col;
            path[step++].dir = i;
            dfs(nextRow, nextCol);
            if(exitFound)
                return;
            step--;
            maze[nextRow][nextCol] = 0;
        }
    }
}

int main()
{
    maze[ENTRANCE_ROW][ENTRANCE_COLl] = 1;
    dfs(ENTRANCE_ROW, ENTRANCE_COLl);

    if(!exitFound)
        printf("The maze does not have a path.\n");

    return 0;
}