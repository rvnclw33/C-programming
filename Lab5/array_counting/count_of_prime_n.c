#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_prime(int n)
{
    if (n <= 1)
        {
            return 0;
        }
    else if (n == 2)
        {
           return 1; 
        }
    else if (n % 2 == 0)
        {
           return 0; 
        }

    for(int i = 3; i <= sqrt(n); i += 2)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int count_of_primes(int *numbers, int length)
{
    int count = 0; 
    for (int i = 0; i < length; i++)
    {
        if (is_prime(numbers[i]))
        {
            count++;
        }
    }
    return count;
}

int main ()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int length;
        scanf("%d", &length);
        int numbers[length];

        for (int t = 0; t < length; t++)
        {
            scanf("%d", &numbers[t]);
        }
        printf("%d\n", count_of_primes(numbers, length));
    }



    return EXIT_SUCCESS;
}

