#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int n;
    scanf("%d", &n);

    int sum = 0;
    int num;
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        sum += num;
    }

    printf("%.2f\n", (double) sum / n);

    return EXIT_SUCCESS;
}