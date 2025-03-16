#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);

    while(b)
    {
        int num = a % b;
        a = b;
        b = num;
    }

    printf("%d\n", a);

    return 0;
}
