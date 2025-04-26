#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    for(int i = 1; i < argc; i++)
    {
        if(strcmp(argv[i], "avadakedavra") == 0)
        {
            printf("%d\n", i);
        }
    }

    return 0;
}