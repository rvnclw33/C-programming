#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter the value for n: ");
    scanf("%d", &n);

    int i = 0;
    while(i < n) 
    {
        printf("%d\n", i);
        i++;
    }

    return 0;
}
