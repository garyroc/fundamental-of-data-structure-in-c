
/*

program  1.22

#define SWAP(a,b) a^=b^=a^=b

void tranpose(int a[][MAX_SIZE])
{
    for (int i = 0; i < MAX_SIZE;i++)
        for (int j = 0; j < MAX_SIZE;j++)
            SWAP(a[i][j],a[j][i])
}

*/

#define SWAP(a,b) a^=b^=a^=b

void transpose(int **a,int rows)
{
    for (int i = 0; i < rows;i++)
        for (int j = 0; j < rows;j++)
            SWAP(a[i][j], a[j][i]);

}