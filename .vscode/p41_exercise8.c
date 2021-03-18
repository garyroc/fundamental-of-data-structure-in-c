//Write an equivalent recursive version of the magic square program(Program 1.23).

#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 15 

int square[MAX_SIZE][MAX_SIZE];
int i, j, column, row;
int size;

void magicSquare(int count);

int main()
{

    printf("Enter the size of the square:");
    scanf("%d", &size);

    if(size <1 || size > MAX_SIZE +1)
    {
        fprintf(stderr, "ERROR! size is out of range!");
        exit(EXIT_FAILURE);
    }

    if(!(size % 2))
    {
        fprintf(stderr, "ERROR! size is even");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < MAX_SIZE;i++)
    {
        for (int j = 0; j < MAX_SIZE;j++)
        {
            square[i][j] = 0;
        }
    }

    square[0][(size - 1) / 2] = 1;
    i = 0;
    j = (size - 1) / 2;

    magicSquare(1);
    printf("\n\n");
    return 0;
}

void magicSquare(int count)
{
    if(count == size * size)
    {
        printf("Magic Square of size %d : \n\n", size);

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
                printf("%5d", square[i][j]);
            printf("\n");
        }
    }

    else
    {
        row = (i - 1 < 0) ? size - 1 : i - 1;
        column = (j - 1 < 0) ? size - 1 : j - 1;
        if (square[row][column])
            i = (++i) % size;
        else
        {
            i = row;
            j = (j - 1 < 0) ? size - 1 : --j;
        }
        
        square[i][j] = ++count;
        magicSquare(count);
    }
    
}