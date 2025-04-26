#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *delete_spaces(char *original)
{
    char * result = (char *)
        calloc(strlen(original)+1, sizeof(char));

    int pos = 0;

    for(int i = 0; i < strlen(original); i++)
    {
        if(original[i] != ' ')
        {
            result[pos] = original[i];
            pos++;
        }
    }
    return result;
}

int main()
{
    char line[101];

    while(gets(line))
    {
        char *result = delete_spaces(line);
        puts(result);
        free(result);
    }

    return EXIT_SUCCESS;
}