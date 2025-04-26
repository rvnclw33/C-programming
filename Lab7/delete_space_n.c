#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *delete_spaces(char *original)
{
    char * result = (char *)
        calloc(strlen(original)+1, sizeof(char));

    int pos = 0;

    for(int i = 0; i <= strlen(original); i++)
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
    // Alternative way for n-times decoration

    // 1
    // int n;
    // scanf("%d\n", &n);

    // 2
    // int n;
    // scanf("%d\n", &n);
    // gets(line);

    // 3
    // char line[101];
    // gets(line);
    // int n = atoi(line);

    // 4 
    // char line[101];
    // int n = atoi(gets(line));

    // 5
    char line[101];
    gets(line);
    int n;
    sscanf(line, "%d", &n);

    for(int i = 0; i < n; i++)
    {
        char line[101];
        gets(line);
        char *result = delete_spaces(line);
        puts(result);
        free(result);
    }

    return EXIT_SUCCESS;
}