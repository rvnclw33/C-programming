#include <stdio.h>
#include <stdlib.h>

int main()
{
    int h, l;

    while(scanf("%d %d", &h, &l) != EOF)
    {
        int d = (l - 2*h)/2;
        int p = h - d;

        printf("%d %d\n", p, d);
    }
    
    return 0;
}
