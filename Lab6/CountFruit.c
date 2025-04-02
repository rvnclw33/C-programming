#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char first[31];
    gets(first);

    int count = 0;

    while (1)
    {
        char current[31];
        gets(current);
        count++;

        if (strcmp(first, current) == 0) // if equal
        {
            break;
        }
    }
    printf("%d\n", count);

    return 0;
}