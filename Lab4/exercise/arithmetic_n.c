#include <stdio.h>

int addition(int a, int b)
{
    return a + b;
}

int subtraction(int a, int b)
{
    return a - b;
}

int multiplication(int a, int b)
{
    return a * b;
}

double division(double a, double b)
{
    if (b==0)
    {
        printf("Error: Division by zero\n");
        return 0;
    }
    return a / b; 
}

int modulo(int a, int b)
{
    if (b==0)
    {
        printf("Error: Modulo by zero\n");
        return 0;
    }
    return a % b;
}


int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int a, b;
        char op;
        scanf("%d %c %d", &a, &op, &b);

        switch(op)
        {
            case '+':
                printf("%d\n", addition(a, b));
                break;
            case '-':
                printf("%d\n", subtraction(a, b));
                break;
            case '*':
                printf("%d\n", multiplication(a, b));
                break;
            case '/':
                printf("%.2lf\n", division(a , b));
                break;
            case '%':
                printf("%d\n", modulo(a, b));
                break;
            default:
                printf("Error: Invalid operator\n");
        }
    }
    
    return 0;
}
