#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[31];
    char city[31];
    int runways;
    int time;
} AIRPORT;

int cmp(const void *a, const void *b)
{
    AIRPORT *left = (AIRPORT *) a;
    AIRPORT *right = (AIRPORT *) b;

    if(left -> runways != right -> runways)
    {
        return -(left ->runways - right ->runways);
    }

    if(left->time != right ->time)
    {
        return -(left->time - right->time);
    }

    return -strcmp(left->name, right->name);
}

int main()
{
    char line[101];
    int n = atoi(gets(line));
    AIRPORT airport[n];

    for(int i = 0; i < n; i++)
    {
        // char* strcpy(char* destination, const char* source);
        gets(line);
        strcpy(airport[i].name, strtok(line, ";"));
        strcpy(airport[i].city, strtok(NULL, ";"));
        airport[i].runways = atoi((strtok(NULL, ";")));
        airport[i].time = atoi(strtok(NULL, ";"));
    }

    qsort(airport, n, sizeof(AIRPORT), cmp);

    for(int i = 0; i < n; i++)
    {
        printf("%s (%s): %d\n", airport[i].name, airport[i].city, airport[i].time);
    }
    return 0;
}