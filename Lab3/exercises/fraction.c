#include <stdio.h>
#include <stdlib.h>

int main ()
{   
    int a, b, c, d;
    printf("Enter value for a, b, c, d\n");

    while(1)
    {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        
        if (a == 0 && b == 0 && c == 0 && d == 0) 
        {
            break;
        }

        int left = a * d;
        int right = b * c;

        if (left < right)
        {
            printf("\n<\n");
        }
        else if (left > right)
        {
            printf(">\n");
        }
        else
        {
            printf("=\n");
        }
    }

    return EXIT_SUCCESS;
}