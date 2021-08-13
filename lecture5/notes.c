#include <stdio.h>

//making a struct that can point at the next list item
typedef struct node
{
    int number;
    struct node *next;
}
node;

//making space for a new node
node *n = malloc(size of (node));

//assigning a value to the node at this address
if (n != NULL)
{
    (*n).number = 1;
}

//replace garbage value at the end of the list with NULL
if (n != NULL)
{
    n->next = NULL;
}

//(*n).number SAME AS n->number

//attach node to list
list = n


//adding 2 & 3 to the list
node *n = malloc(sizeof(node));
if (n != NULL)
{
    n->number = 2;
    n->next = NULL;
}

list->next = n

node *n = malloc(sizeof(node));
if (n != NULL)
{
    n->number = 3;
    n->next = NULL;
}
list->next->next = n;

