#include <stdio.h>
#include <stdlib.h>

int main () 
{
    int a, b;
    scanf("%d %d", &a, &b);

    while(b != 0) 
    {
        int num = a % b;
        a = b;
        b = num;
    }

    printf("%d\n", a); // a becomes the GCD of the two
    
    return 0;
}