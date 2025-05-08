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
    if (strcmp(left->registration_number, right->registration_number))
    {
        return -(strcmp(left->registration_number, right->registration_number));
    }
}

int main(int argc, char *argv[])
{
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

    char line[48];
    int n = atoi(fgets(line, sizeof(line), in));
    AIRCRAFT aircraft[n];

    for (int i = 0; i < n; i++)
    {
        line[strcspn(line, "\r\n")] = '\0';

        fgets(line, sizeof(line), in);

        strcpy(aircraft[i].registration_number, strtok(line, ";"));
        aircraft[i].capacity = atoi(strtok(NULL, ";"));
        strcpy(aircraft[i].model, strtok(NULL, ";"));
        aircraft[i].wing_span = atof(strtok(NULL, ";"));
    }

    fclose(in);

    qsort(aircraft, n, sizeof(AIRCRAFT), cmp);

    if(argc < 3)
    {
        fprintf(stderr, "Command-line is not present.\n");
        return 3;
    }

    FILE *out = fopen(argv[2], "w");

    if(!out)
    {
        fprintf(stderr, "%s cannot be opened.\n", argv[2]);
        return 4;
    }

    fprintf(out, "%d\n", n);
    for(int i = 0; i < n; i++)
    {
        fprintf(out, "%s;%d;%s;%.2lf\n", aircraft[i].registration_number, aircraft[i].capacity, aircraft[i].model, aircraft[i].wing_span);
    }

    fclose(out);

    return 0;
}