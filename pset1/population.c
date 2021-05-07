#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int start;
    do
    {
        start = get_int("Starting population: ");
    }
    while (start < 9);
   
    // TODO: Prompt for end size
    int end;
    do
    {
        end = get_int("Ending population: "); 
    }
    while (end < start);
    
    // TODO: Calculate number of years until we reach threshold
    int years = 0;
    int llamas = start;
    while (llamas < end)
    {
        years ++;
        llamas += (llamas / 3) - (llamas / 4);
    }
    
    
    // TODO: Print number of years
    printf("Years: %i\n", years);
}