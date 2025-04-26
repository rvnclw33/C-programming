#include <stdio.h>
#include <stdlib.h>

void print_matrix(int *numbers, int rows, int cols)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            printf("%3d", numbers[i * cols +j]);
        }
        putchar('\n');
    }
}

int main()
{
    int numbers[3][4];

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            numbers[i][j] = i * 10 + j;
        }
    }

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            printf("%3d", numbers[i][j]);
        }
        putchar('\n');
    }
  
    print_matrix(&numbers[0][0], 3, 4);
    return EXIT_SUCCESS;
}