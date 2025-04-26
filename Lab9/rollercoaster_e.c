#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[31];
    char world[31];
    int height;
    int time;
} ROLLERCOASTER;

int cmp(const void *a, const void *b)
{
    ROLLERCOASTER *left = (ROLLERCOASTER *)a;
    ROLLERCOASTER *right = (ROLLERCOASTER *)b;

    if (left->time != right->time)
    {
        return (left->time - right->time);
    }

    if (left->height != right->height)
    {
        return -(left->height - right->height);
    }

    return strcmp(left->name, right->name);
}

int main()
{
    char line[101];

    ROLLERCOASTER rollercoaster[20];
    int length = 0;

    while (gets(line))
    {
        strcpy(rollercoaster[length].name, strtok(line, ";"));
        strcpy(rollercoaster[length].world, strtok(NULL, ";"));
        rollercoaster[length].height = atoi(strtok(NULL, ";"));
        rollercoaster[length].time = atoi(strtok(NULL, ";"));
        length++;
    }

    qsort(rollercoaster, length, sizeof(ROLLERCOASTER), cmp);

    for (int i = 0; i < length; i++)
    {
        printf("%s (%s): %d\n", rollercoaster[i].name, rollercoaster[i].world, rollercoaster[i].time);
    }
    return EXIT_SUCCESS;
}