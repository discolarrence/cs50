// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 143091;

// Hash table
node *table[N];

int entries = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    //OPEN DICTIONARY FILE
    FILE *file = fopen(word, "r");
    if (word  == NULL)
    {
        return false;
    }
    //READ STRINGS FROM FILE ONE AT A TIME
    char new_word[LENGTH +1];
    while (fscanf(file, "%s", word) != EOF)
    //CREATE A NEW NODE FOR EACH WORD
        {
            node *n = malloc(size of (node));
            //****equality vs non-equality
            if (n != NULL)
            {
                strcpy(n->word, new_word);
            }
    //INSERT NODE INTO HASH TABLE AT THAT LOCATION
            int hash_value = hash(new_word);
            table[hash_value] = n;
            entries++;
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    return 0;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
