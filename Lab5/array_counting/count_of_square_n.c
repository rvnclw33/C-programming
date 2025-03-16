#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_square(int n)
{
    if (n < 0) 
    {
        return 0; // Negative numbers can't be perfect squares
    }

    int sqrt_n = (int)sqrt(n); // Calculate the square root and cast it to an integer
    return (sqrt_n * sqrt_n == n); // Check if the square of sqrt_n equals n
}

int count_of_squares(int *numbers, int length)
{
    int count = 0;
    for (int i = 0; i < length; i++)
    {
        if (is_square(numbers[i]))
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

    if (n < 3 || n > 10)
    {
        printf("Number of test cases must be between 3 and 10.\n");
        return EXIT_FAILURE;
    }

    for (int t = 0; t < n; t++)
    {
        int length;
        scanf("%d", &length);

        // Dynamically allocate memory for the numbers array
        int *numbers = (int *)malloc(length * sizeof(int));
        if (numbers == NULL) 
        {
            printf("Memory allocation failed.\n");
            return EXIT_FAILURE;
        }

        for (int i = 0; i < length; i++)
        {
            scanf("%d", &numbers[i]);
        }

        // Call the function to count perfect squares and print the result
        printf("%d\n", count_of_squares(numbers, length));

        // Free the dynamically allocated memory
        free(numbers);
    }

    return EXIT_SUCCESS;
}
