#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{

    // determine least possible length of arguments 
    int min = strlen(argv[1]);

    for(int i = 2; i < argc; i++)
    {
        if(strlen(argv[i]) < min)
        {
            min = strlen(argv[i]);
        }
    }

    // determine which one is the shortest word
    for(int i = 1; i < argc; i++)
    {
        if(strlen(argv[i]) == min)
        {
            puts(argv[i]);
        }
    }

    //printf("%d\n", min);
    return 0;
}
