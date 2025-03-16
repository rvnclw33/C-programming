#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        int a, b;
        char op;

        scanf("%d %c %d", &a, &op, &b);

        if (op == '+')
            {
                printf("%d\n", a + b);
            }
        else if (op == '-')
            {
                printf("%d\n", a - b);
            }
        else if (op == '*')
            {
                printf("%d\n", a * b);
            }
        else if (op == '/') 
            {
                printf("%.2lf\n", (double)a / (double)b);
            }
        else
            {
                printf("%d\n", a % b);
            }
    }
    return 0;
}
