#include <stdio.h>
#include <stdlib.h>

int count_of_local_min(int *numbers, int length)
{
    int count = 0;

    if (length > 1 && numbers[0] < numbers[1])
    {
        count++;
    }

    for (int i = 1; i < length - 1; i++)
    {
        if (numbers[i] < numbers[i - 1] && numbers[i] < numbers[i + 1])
        {
            count++;
        }
    }

    if (length > 1 && numbers[length - 1] < numbers[length - 2])
    {
        count++;
    }
    return count;
}

int main()
{
    int length;
    while (scanf("%d", &length) != EOF)
    {
        int *numbers = (int *)malloc(length * sizeof(int)); // dynamically allocate memory for the array
        if (numbers == NULL)
        {
            printf("Memory allocation failed.\n");
            return EXIT_FAILURE;
        }

        for (int i = 0; i < length; i++)
        {
            scanf("%d", &numbers[i]);
        }

        printf("%d\n", count_of_local_min(numbers, length));
        free(numbers); // Free dynamically allocated memory
    }

    return EXIT_SUCCESS;
}