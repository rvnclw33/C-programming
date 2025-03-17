#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c;
    int opened = 0; // not opened (initiate as false value)

    while(1)
    {
        // one character will be processed one at a time and then put back with putchar()
        c = getchar();

        if (c == EOF)
        {
            break;
        }

        if (c == '"')
        {
            printf("%s", !opened? "``" : "''");
            // if(!opened) // condition becomes true(1) so it will open
            // {
            //     printf("``"); // opening
            // }
            // else // condition becomes false so we will close
            // {
            //     printf("''"); // closing
            // }
            opened = !opened; // switching the state to 1 for the next quote
        }
        else
        {
            putchar(c);
        }
    }
    return 0;
}

