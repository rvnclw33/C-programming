#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b;
    char op;

    while(scanf("%d %c %d", &a, &op, &b) != EOF)
    {
        switch (op)
        {
        case '+':
            printf("%d\n", a + b);
            break;
        case '-':
            printf("%d\n", a - b);
            break;
        case '*':
            printf("%d\n", a * b);
            break;
        case '/':
            if (b == 0)
            {
                printf("Error Division by zero\n");
            }
            else
            {
                printf("%d\n", a / b);
            }
            break;
        case '%':
            if (b == 0)
            {
                printf("Error Modulo by zero\n");
            }
            else
            {
                printf("%d\n", a % b);
            }
            break;
        }
    }

    return EXIT_SUCCESS;
}