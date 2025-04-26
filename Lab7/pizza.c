// program that reads input and print pizza name with the most ingredients(seperated by ";")
/*  -- Sample Input --

Seafood;Tomato;Mozzarella;Shrimp;Tuna;Onions;32;12
Four Cheese;Tomato;Mozzarella;Parmesan;Blue Cheese;Ricotta;30;10
Buffalo Chicken;Buffalo Sauce;Mozzarella;Chicken;Celery;32;11
Tandoori Chicken;Tomato;Mozzarella;Tandoori Chicken;Red Onions;30;10
Mexican;Tomato;Mozzarella;Beef;Jalapenos;Red Onions;Corn;32;12
Carbonara;White Sauce;Mozzarella;Bacon;Egg;Parmesan;30;10
Pesto Pizza;Pesto Sauce;Mozzarella;Tomatoes;Pine Nuts;30;9
Spinach Feta;Tomato;Mozzarella;Spinach;Feta;Garlic;30;9
Truffle Mushroom;White Sauce;Mozzarella;Mushrooms;Truffle Oil;32;14
Capricciosa;Tomato;Mozzarella;Ham;Artichokes;Mushrooms;Olives;30;11
Sausage Feast;Tomato;Mozzarella;Sausage;Onions;Bell Peppers;30;10
Zesty Veggie;Tomato;Mozzarella;Zucchini;Cherry Tomatoes;Olives;30;9

*/ 


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int max = 0;
    char max_name[33];

    while (1)
    {
        char name[33];
        name[0] = getchar();

        if (name[0] == EOF)
        {
            break;
        }

        for (int i = 1; i < 33; i++)
        {
            name[i] = getchar();
            if (name[i] == ';')
            {
                name[i] = '\0';
                break;
            }
        }

        int count = 0;
        while (1)
        {
            char c = getchar();

            if (c == ';')
            {
                count++;
            }

            
            // break out the loop and read new pizza line
            else if (c == '\n')
            {
                break;
            }
        }

        if (count > max)
        {
            max = count;
            strcpy(max_name, name);
        }
    }
    puts(max_name);
    return 0;
}