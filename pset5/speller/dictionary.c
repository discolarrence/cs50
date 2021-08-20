// Implements a dictionary's functionality
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 143092;

// Hash table
node *table[N];

int entries = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    //Hash word to create a hash value
    int hash_value = hash(word);
    //access linked list at that index in the hash table
    node *cursor = table[hash_value];
    //traverse linked list, looking for the word
    while (cursor != NULL)
    {
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
       
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
//from https://cs50.stackexchange.com/questions/37209/pset5-speller-hash-function
unsigned int hash(const char *word)
{
    unsigned int hash_value = 0;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
         hash_value = (hash_value << 2) ^ word[i];
    }
    return hash_value % N; //N is size of hashtable
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    //OPEN DICTIONARY FILE
    FILE *file = fopen(dictionary, "r");
    if (dictionary  == NULL)
    {
        return false;
    }
    //READ STRINGS FROM FILE ONE AT A TIME
    char new_word[LENGTH +1];
    while (fscanf(file, "%s", new_word) != EOF)
    //CREATE A NEW NODE FOR EACH WORD
    {
        node *n = malloc(sizeof(node));
        //****equality vs non-equality
        if (n == NULL)
        {
            return false;
        }
        strcpy(n->word, new_word);
        n->next = NULL;
    //INSERT NODE INTO HASH TABLE AT THAT LOCATION
        int hash_value = hash(new_word);
        table[hash_value] = n;
        entries++;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return entries;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    //
    for (int i = 0; i< N; i++)
    {
        node *cursor = table[i];
        while (cursor != NULL)
        {
            node *tmp = cursor;
            free(cursor);
            cursor = tmp->next;
            free(tmp);
        }
        
        if (cursor == NULL && i == N - 1)
        {
            return true;
        }
    }
  
    return false;
}
