// version terminating value "END"
// https://github.com/INBPA0211L/notes-2025/blob/main/week-10/exercises/P110203/sheet-end.md
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    char passport_number[16];
    int age;
    char full_name[51];
    double baggage_weight; 
} PASSENGERS;

int cmp(const void *a, const void *b)
{
    PASSENGERS *left = (PASSENGERS *)a;
    PASSENGERS *right = (PASSENGERS *)b;

    if(strcmp(left->full_name, right->full_name) != 0)
    {
        return -strcmp(left->full_name, right->full_name);
    }

    // comparing double value (ascending)
    if(left->baggage_weight < right->baggage_weight)
    {
        return -1;
    }

    if(left->baggage_weight > right->baggage_weight)
    {
        return 1;
    }

    if(left->age != right->age)
    {
        return left->age - right->age;
    }

    return -strcmp(left->passport_number, right->passport_number);

}

int main(int argc, char *argv[])
{
    char line[78];
    PASSENGERS passenger[180];
    int length = 0;

    if (argc < 2)
    {
        fprintf(stderr, "Input file is not presented.\n");
        return 3;
    }

    FILE *in = fopen(argv[1], "r");

    if(!in)
    {
        fprintf(stderr, "Input file cannot be opened.\n");
        return 4;
    }

    while(fgets(line, sizeof(line), in))
    {
        //line[strlen(line) - 1] = '\0';
        
        /* 

        \r - carriage return: moves cursor to the beginning of the line 
        \r - line feed: moves cursor down to the next line

        */
        line[strcspn(line, "\r\n")] = '\0';

        if(strcmp(line, "END") == 0)
        {
            break;
        }

        strcpy(passenger[length].passport_number, strtok(line, ";"));
        passenger[length].age = atoi(strtok(NULL, ";")); // atoi() - integer
        strcpy(passenger[length].full_name, strtok(NULL, ";"));
        passenger[length].baggage_weight = atof(strtok(NULL, ";")); // atof() - double 
        length++;
    }

    fclose(in);

    qsort(passenger, length, sizeof(PASSENGERS), cmp);

    if(argc < 3)
    {
        fprintf(stderr, "Output file is not presented.\n");
        return 5;
    }

    FILE *out = fopen(argv[2], "w");

    if(!out)
    {
        fprintf(stderr, "Output file cannot be opened.\n");
        return 7;
    }

    for(int i = 0; i < length; i++)
    {
        fprintf(out, "%s;%d;%s;%.2f\n", passenger[i].passport_number, passenger[i].age, passenger[i].full_name, passenger[i].baggage_weight);
    }
    fprintf(out, "END\n");

    fclose(out);

    return 0;
}
