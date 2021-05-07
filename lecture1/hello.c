#include <stdio.h>
#include <cs50.h>

int main(void)
{
        //Ask for name & greet user
        string answer = get_string("What is your name? ");
        printf("hello, %s\n", answer);
}



