#include <stdio.h>
#include <stdlib.h>

int main()
{
    int temp;
    scanf("%d", &temp);
    int min = temp;

    int num;
    while(scanf("%d", &num) != EOF)
    {
        if (num < min) 
        {
            min = num;
        }
    }
    
    printf("%d\n", min);

    return 0;
}
