#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char registration_number[11];
    int capacity;
    char model[21];
    double wing_span;
} AIRCRAFT;

int cmp(const void *a, const void *b)
{
    AIRCRAFT *left = (AIRCRAFT *)a;
    AIRCRAFT *right = (AIRCRAFT *)b;

    // double wing_span
    if (left->wing_span < right->wing_span)
    {
        return -1;
    }

    if (left->wing_span > right->wing_span)
    {
        return 1;
    }

    // char model
    if (strcmp(left->model, right->model))
    {
        return -strcmp(left->model, right->model);
    }

    // int capacity
    if (left->capacity - right->capacity)
    {
        return (left->capacity - right->capacity);
    }

    // char registration_number
    return -(strcmp(left->registration_number, right->registration_number));
}

int main(int argc, char *argv[])
{
    char line[48];
    AIRCRAFT aircraft[240];
    int length = 0;

    if (argc < 2)
    {
        fprintf(stderr, "Command-line is not presented.\n");
        return 9;
    }

    FILE *in = fopen(argv[1], "r");

    if (!in)
    {
        fprintf(stderr, "%s cannot be opened.\n", argv[1]);
        return 5;
    }

    while (fgets(line, sizeof(line), in))
    {
        line[strcspn(line, "\r\n")] = '\0';

        // break at "END"
        if (strcmp(line, "END") == 0)
        {
            break;
        }

        strcpy(aircraft[length].registration_number, strtok(line, ";"));
        aircraft[length].capacity = atoi(strtok(NULL, ";"));
        strcpy(aircraft[length].model, strtok(NULL, ";"));
        aircraft[length].wing_span = atof(strtok(NULL, ";"));
        length++;
    }

    fclose(in);

    qsort(aircraft, length, sizeof(AIRCRAFT), cmp);

    if (argc < 3)
    {
        fprintf(stderr, "Command-line is not present.\n");
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
        fprintf(out, "%s;%d;%s;%.2lf\n", aircraft[i].registration_number, aircraft[i].capacity, aircraft[i].model, aircraft[i].wing_span);
    }
    fprintf(out, "END\n");

    fclose(out);

    return 0;
}