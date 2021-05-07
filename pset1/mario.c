#include <stdio.h>
#include <cs50.h>

void print_hash(int hash);
void print_space(int space);

int main(void)
{
    int height;
    do
    {
        height = get_int("Height (between 1-8): ");
    }
    while (height < 1 || height > 8);


    for (int i = 0; i < height; i++)
    {
        int space = height - i - 1;
        int hash = i + 1;

        print_space(space);
        print_hash(hash);
        printf("  ");
        print_hash(hash);
        printf("\n");
    }
}

void print_hash(int hash)
{
    for (int j = 0; j < hash; j++)
    {
        printf("#");
    }
         
}

void print_space(int space)
{
    for (int j = 0; j < space; j++)
    {
        printf(" ");
    }   
}
