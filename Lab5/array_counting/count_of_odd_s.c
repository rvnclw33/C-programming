#include <stdio.h>
#include <stdlib.h>

int count_of_odds(int *numbers, int length)
{
    int count = 0;
    for (int i = 0; i < length; i++)
    {
        if (numbers[i] % 2 != 0)
        {
            count++;
        }
    }
    return count;
}

int main ()
{
    int length;

    while(scanf("%d", &length) == 1)
    {
        if(length == 0)
        {
            break;
        }

        int numbers[length];
        for (int i = 0; i < length; i++)
        {
            scanf("%d", &numbers[i]);
        }

        printf("%d\n", count_of_odds(numbers, length));
    }

    return EXIT_SUCCESS;
}