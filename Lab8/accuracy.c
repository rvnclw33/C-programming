#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    double sum = 0.0;
    for(int i = 1; i < argc; i++)
    {
        sum += atof(argv[i]);
    }
    printf("%.2f", sum / (argc-1));

    return EXIT_SUCCESS;
}