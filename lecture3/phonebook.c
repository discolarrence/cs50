#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    string name;
    string number;
}
person;

const int NUMBER = 10;

int main(void)
{
    person people[NUMBER];

   for (int i = 0; i < NUMBER; i++)
   {
       people[i].name = get_string("What is the name? ");
       people[i].number = get_string("What's the number? ");
   }

    for (int i = 0; i < NUMBER; i++)
    {
        if (strcmp(people[i].name, "Laura") == 0)
        {
            printf("Found %s\n", people[i].number);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}