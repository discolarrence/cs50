#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int alpha_count(string text);
int word_count(string text);
int sentence_count(string text);

int main(void)
{
    string text = get_string("Text: ");
    
    //Compute grade level using index = 0.0588 * L - 0.296 * S - 15.8 
    //Here, L is the average number of letters per 100 words in the text, and S is the average number of sentences per 100 words in the text.
    int coleman_liau = round(0.0588 * (alpha_count(text) * (100 / (float) word_count(text))) - 0.296 * (sentence_count(text) * (100 /
                            (float) word_count(text))) - 15.8);
    
    if (coleman_liau < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (coleman_liau >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", coleman_liau);
    }
}

int alpha_count(string text)
{
    int alphas = 0;
    for (int i = 0, n = strlen(text); i < n; i ++)
    {
        if (isalpha(text[i]))
        {
            alphas += 1;
        }
    }
    return alphas;
}

//Word count assumes that a sentence will not start or end with a space, and that a sentence will not have multiple spaces in a row
int word_count(string text)
{
    int words = 1;
    for (int i = 0, n = strlen(text); i < n; i ++)
    {
        if (isspace(text[i]))
        {
            words += 1;
        }
    }
    return words;
}

//Ignoring that not every "." is the end of a sentence
int sentence_count(string text)
{
    int sentences = 0;
    for (int i = 0, n = strlen(text); i < n; i ++)
    {
        if (text[i] == 63 || text[i] == 46 || text[i] == 33)
        {
            sentences += 1;
        }
    }
    return sentences;
}

