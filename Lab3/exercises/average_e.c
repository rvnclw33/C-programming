#include <stdio.h>
#include <stdlib.h>

int main () 
{
    int count = 0;
    double sum = 0;

    int num;
    while(scanf("%d", &num) != EOF)
    {
        sum += num;
        count++;
    }
    printf("%.2lf\n", sum / count);
    
    return 0;
}