#include <stdio.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int main () 
{
    int a, b;

    scanf("%d %d", &a, &b);

    //check if gcd is 1
    if (gcd(a, b) == 1)
    {
        printf("IGEN\n");
    }
    else
    {
        printf("NEM\n");
    }
    
    return 0;
}