#include <stdio.h>
#include <stdlib.h>

void pointer_test(int *iptr)
{
    printf("Passed value: %d\n", *iptr);

    printf("Passed address: %p\n", iptr);

    printf("Pointer's address: %p\n", &iptr);
}

int main ()
{
    int i = 1234;
    int *foo = &i;
    pointer_test(foo);

    return EXIT_SUCCESS;
}