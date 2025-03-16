#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);

    int temp;
    scanf("%d", &temp);
    int min = temp;

    for(int i = 1; i < n; i++)
    {
        int num;
        scanf("%d", &num);

        if (num < min) 
        {
            min = num;
        }
    }
    
    printf("%d\n", min);

    return 0;
}
