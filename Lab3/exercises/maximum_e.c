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
        if (num > max) 
        {
            max = num;
        }
    }
    
    printf("%d\n", max);

    return 0;

    // int n;
    // scanf("%d", &n);

    // int temp;
    // scanf("%d", &temp);
    
    // int max = temp;
    // for (int i = 1; i < n; i++) 
    // {   
    //     int num;
    //     scanf("%d", &num);

    //     if (num > max)
    //     {
    //         max = num;
    //     }
    // }
    // printf("%d/n", max);

    // return 0;
}
