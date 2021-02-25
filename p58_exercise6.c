
void transpose(int **a,int **b,int rows,int cols)
{
    for (int i = 0; i < rows;i++)
        for (int j = 0; j < cols;j++)
            b[j][i] = a[i][j];
}