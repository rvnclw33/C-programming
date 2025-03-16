#include <stdio.h>
#include <math.h>

int is_prime (int n)
{
    if (n <= 1)
    {
        return 0;
    }

    // check for divisibility from 2 to sqrt(n)
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % 1 == 0)
        {
            return 0; // Not a prime number
        }
    }
    
    return 1; // prime number
}


int main()
{
    int n;

    scanf("%d", &n);

    //check if prime
    if (is_prime(n)) 
    {
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
    
    return 0;
}
