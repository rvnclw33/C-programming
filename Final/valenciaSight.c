#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1 - define the structure
typedef struct
{
    char name[41]; // + terminator \0
    char type[81]; // + terminator \0
    int built;
} SIGHT;

// 3.1 - comparing function (only work with void and pointer)
int cmp(const void *a, const void *b)
{
    SIGHT *left = (SIGHT *)a;
    SIGHT *right = (SIGHT *)b;

    if (strcmp(left->type, right->type) != 0)
    {
        return strcmp(left->type, right->type); // ascending remains the same
    }

    if (left->built != right->built) // for int, descending just -(a - b)
    {
        return -(left->built - right->built);
    }

    return strcmp(right->name, left->name); // for string, descending just switch side
}

// 2 - read file
int main(int argc, char *argv[])
{
    char line[130];

    int length = 0;
    SIGHT sight[150];

    FILE *in = fopen(argv[1], "r");

    while (1)
    {
        fgets(line, 150, in);

        if (strcmp(line, "END") == 0) // optional line during the previous exam
        {
            break;
        }
        line[strlen(line) - 1] = '\0'; // replace \n with /0;

        strcpy(sight[length].name, strtok(line, ","));
        strcpy(sight[length].type, strtok(NULL, ","));
        sight[length].built = atoi(strtok(NULL, ","));
        length++;
    }
    fclose(in);

    // 3 - sorting
    qsort(sight, length, sizeof(SIGHT), cmp);



    // 4 - printing result to the output.csv file
    FILE *out = fopen(argv[2], "w");

    for (int i = 0; i < length; i++)
    {
        fprintf(out, "%s,%s,%d\n", sight[i].name, sight[i].type, sight[i].built);
    }

    fprintf(out, "END\n");
    fclose(out);

    return 0;
}
