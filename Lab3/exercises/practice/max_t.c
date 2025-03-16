#include <stdio.h>
#include <stdlib.h>

int main()
{
    int temp;
    scanf("%d", &temp);

    int max = temp;
    int num;
    while(scanf("%d", &num) != EOF)
    {
        if ( num > max)
        {
            max = num;
        }
    }

    printf("%d\n", max);
    return 0;
}
