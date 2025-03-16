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
    int n;
    scanf("%d", &n);

    for (int t = 0; t < n; t++)
    {
        int length;
        scanf("%d", &length);

        int numbers[length];
        for (int i = 0; i < length; i++)
        {
            scanf("%d", &numbers[i]);
        }

        printf("%d\n", count_of_odds(numbers, length));
    }

    return EXIT_SUCCESS;
}