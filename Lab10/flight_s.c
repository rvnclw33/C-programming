#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char flight_number[11];
    double flight_duration;
    char destination[31];
    int passenger_count;
} FLIGHT;

int cmp(const void *a, const void *b)
{
    FLIGHT *left = (FLIGHT *)a;
    FLIGHT *right = (FLIGHT *)b;

    // int passenger_count desc
    if (left->passenger_count - right->passenger_count)
    {
        return -(left->passenger_count - right->passenger_count);
    }
    // char destination asc
    if (strcmp(left->destination, right->destination))
    {
        return strcmp(left->destination, right->destination);
    }

    // double flight_duration desc
    if (left->flight_duration > right->flight_duration)
    {
        return -1;
    }

    if (left->flight_duration < right->flight_duration)
    {
        return 1;
    }

    // char flight_number asc
    return strcmp(left->flight_number, right->flight_number);
}

int main(int argc, char *argv[])
{
    char line[57];
    FLIGHT flight[180];

    if (argc < 2)
    {
        fprintf(stderr, "Command-line is not presented.\n");
        return 7;
    }

    FILE *in = fopen(argv[1], "r");

    if (!in)
    {
        fprintf(stderr, "%s cannot be opened.\n", argv[1]);
        return 8;
    }

    int length = 0;
    while (fgets(line, sizeof(line), in))
    {
        line[strcspn(line, "\r\n")] = '\0';

        if (strcmp(line, "END") == 0)
        {
            break;
        }

        strcpy(flight[length].flight_number, strtok(line, ";"));
        flight[length].flight_duration = atof(strtok(NULL, ";"));
        strcpy(flight[length].destination, strtok(NULL, ";"));
        flight[length].passenger_count = atoi(strtok(NULL, ";"));
        length++;
    }

    fclose(in);

    qsort(flight, length, sizeof(FLIGHT), cmp);

    if (argc < 3)
    {
        fprintf(stderr, "Command-line is not presented.\n");
        return 9;
    }

    FILE *out = fopen(argv[2], "w");

    if (!out)
    {
        fprintf(stderr, "%s cannot be opened.\n", argv[2]);
        return 5;
    }

    for (int i = 0; i < length; i++)
    {
        fprintf(out, "%s;%.2lf;%s;%d\n", flight[i].flight_number, flight[i].flight_duration, flight[i].destination, flight[i].passenger_count);
    }

    fprintf(out, "END\n");

    fclose(out);

    return 0;
}