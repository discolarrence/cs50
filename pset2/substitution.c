#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(int argc, string argv[])
{
    //Test validity of key
    if (argc == 2)
    {
        if (strlen(argv[1]) != 26)
        {
            printf("Key must contain 26 letters.\n");
            return 1;
        }
        for (int i = 0, n = strlen(argv[1]); i < n; i ++)
        {
            int count = 0;
            for (int j = 0, m = strlen(ALPHABET); j < m; j ++)
            {
                if (toupper(argv[1][j]) == ALPHABET[i])
                {
                    count += 1;
                }
            }
            if (count != 1)
            {
                printf("Key must contain 1 instance of each letter of the alphabet.\n");
                return 1;
            }
        }
    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
     
    //get text from user
    string plain_text = get_string("plaintext: ");
    printf("ciphertext: ");
    
    //find each character in key; preserve case
    for (int i = 0, n = strlen(plain_text); i < n; i ++)
    {
        int index = toupper(plain_text[i]) - 65;
        
        if ((int)plain_text[i] == 32)
        {
            printf(" ");
        }
        else if ((int)plain_text[i] >= 48 && (int)plain_text[i] <= 57)
        {
            printf("%c", plain_text[i]);
        }
        else if (islower(plain_text[i]))
        {
            printf("%c", tolower(argv[1][index]));
        }
        else
        {
            printf("%c", toupper(argv[1][index]));
        }
    }
    printf("\n");
    return 0;
}

    