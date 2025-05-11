#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char title[41];
    int length;
    int plays;
} TRACK;

int cmp(const void *a, const void *b)
{
    TRACK *left = (TRACK *)a;
    TRACK *right = (TRACK *)b;

    if (left->plays != right->plays)
    {
        return -(left->plays - right->plays);
    }

    if (left->length != right->length)
    {
        return left->length - right->length;
    }

    return strcmp(left->title, right->title);
}

int main(int argc, char *argv[])
{
    char line[62];
    TRACK track[20];

    if (argc < 2)
    {
        fprintf(stderr, "Command-line argument is not presented.\n");
        return 1;
    }

    FILE *in = fopen(argv[1], "r");

    if (!in)
    {
        fprintf(stderr, "%s cannot be opened.\n", argv[1]);
        return 2;
    }

    int length = 0;
    while(fgets(line, sizeof(line), in))
    {
        line[strcspn(line, "\n\r")] = '\0';

        if(!strcmp(line, "END"))
        {
            break;
        }

        strcpy(track[length].title, strtok(line, ";"));
        track[length].length = atoi(strtok(NULL, ";"));
        track[length].plays = atoi(strtok(NULL, ";"));
        length++;
    }

    fclose(in);

    qsort(track, length, sizeof(TRACK), cmp);

    if (argc < 3)
    {
        fprintf(stderr, "Command-line argument is not presented.\n");
        return 3;
    }

    FILE *out = fopen(argv[2], "w");

    if (!out)
    {
        fprintf(stderr, "%s cannot be opened.\n", argv[2]);
        return 4;
    }

    for (int i = 0; i < length; i++)
    {
        fprintf(out, "%s;%d;%d\n", track[i].title, track[i].length, track[i].plays);
    }
    fprintf(out, "END\n");

    fclose(out);

    return 0;
}