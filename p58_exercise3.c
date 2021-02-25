/*

program 1.16

void add(int a[][MAX_SIZE], int b[][MAN_SIZE],
                int c[][MAX_SIZE], int rows,int cols)
{
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            c[i][j] = a[i][j] + b[i][j];
}

*/


void add(int **a, int **b,int **c,int rows,int cols)
{
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            c[i][j] = a[i][j] + b[i][j];
}

