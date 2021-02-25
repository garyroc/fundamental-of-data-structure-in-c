/*

program 1.20

void mul(int a[][MAX_SIZE],int b[][MAX_SIZE],int c[][MAX_SIZE])
{
    for (int i = 0; i < MAX_SIZE;i++)
        for (int j = 0; j < MAX_SIZE;j++){
            c[i][j] = 0;
            for (int k = 0; k < MAX_SIZE;k++)
                c[i][j] += a[i][k] * b[k][j];
        }
}

*/

void mul(int **a,int **b,int **c,int rows)
{
    for (int i = 0; i < rows;i++)
        for (int j = 0; j < rows;j++){
            c[i][j] = 0;
            for (int k = 0; k < rows;k++)
                c[i][j] += a[i][k] * b[k][j];
        }

}