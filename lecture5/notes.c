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

//adding a node between 2 nodes
n->next = list;
list = next;


//searching a tree
bool search(node *tree, int number)
{
    if (tree == NULL)
    {
        return false;
    }
    else if (number < tree->number)
    {
        return search(tree->left, number);
    }
    else if (number > tree->number)
    {
        return search(tree->right, number);
    }
    else
    {
        return true;
    }
}