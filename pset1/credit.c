#include <stdio.h>
#include <cs50.h>

int get_length(long cc_number);

int main(void)
{
    long cc_number = get_long("CC Number: ");
    int length = get_length(cc_number);
    
    /* build array of numbers from cc_number */
    int cc_array[length];
    long num = cc_number;
    int index;
    for (int i = 0; i < length; i++)
    {
        index = length - i - 1;
        cc_array[index] = num % 10;
        num = num / 10;
    }
    
    /*get every other number, add & store in 2 variables, check if double digit*/
    int singles = 0;
    int doubles = 0;
    int d;
    num = cc_number;
    
    for (int i = 0; i < length; i ++)
    {
        index = length - i - 1;
        if (i % 2 == 0)/*add together*/
        {
            singles += cc_array[index]; 
        }
        else /*multiply by 2 and add together*/
        {
            d = cc_array[index] * 2;
            if (d > 9) /*add together digits of double-digit numbers*/
            {
                doubles += (d % 10) + (d / 10);
            }
            else
            {
                doubles += d;
            }
        }
    }
    /* check if last number of sum is 0 */
    int sum = singles + doubles;
    int is_zero = sum % 10;
    if (is_zero == 0)
    {
        if ((length == 15 && cc_array[0] == 3) && (cc_array[1] == 4 || cc_array[1] == 7))
        {
            printf("AMEX\n");
        } 
        else if ((length == 13 || length == 16) && (cc_array[0] == 4))
        {
            printf("VISA\n");  
        }
        else if (length == 16 && cc_array[0] == 5 && cc_array[1] > 0 && cc_array[1] < 6)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }    
    else
    {
        printf("INVALID\n");
    }
}
 
int get_length(long cc_number)
{
    int length = 0;
    do
    {
        length ++;
        cc_number = cc_number / 10;
    }
    while (cc_number > 0);
    return length;   
}

