#include "AddrBook.h"
#include <stdio.h>
#include <string.h>

//数据比较函数
int CompareByName(Data a, Data b)
{
    return strcmp(a.name,b.name);
}

/* A utility function to swap two elements */
void swap ( Data* a, Data* b )
{   Data t = *a;      *a = *b;       *b = t;   }
 
// A utility function to find last node of linked list
Node *lastNode(Node *root)
{
    while (root && root->next)
        root = root->next;
    return root;
}
 
/* Considers last element as pivot, places the pivot element at its
   correct position in sorted array, and places all smaller (smaller than
   pivot) to left of pivot and all greater elements to right of pivot */
Node* partition(Node *l, Node *h)
{
    // set pivot as h element
    Data x  = h->data;
 
    // similar to i = l-1 for array implementation
    Node *i = l->prev;
 
    // Similar to "for (int j = l; j <= h- 1; j++)"
    for (Node *j = l; j != h; j = j->next)
    {
        if (CompareByName(j->data,x)>=0)
        {
            // Similar to i++ for array
            i = (i == NULL)? l : i->next;
            swap(&(i->data), &(j->data));
        }
    }
    i = (i == NULL)? l : i->next; // Similar to i++
    swap(&(i->data), &(h->data));
    return i;
}
 
/* A recursive implementation of quicksort for linked list */
void _quickSort(Node* l,Node *h)
{
    if (h != NULL && l != h && l != h->next)
    {
        Node *p = partition(l, h);
        _quickSort(l, p->prev);
        _quickSort(p->next, h);
    }
}
 
// The main function to sort a linked list. It mainly calls _quickSort()
void quickSort(LinkList head)
{
    // Find last node
    Node *h = lastNode(head);
 
    // Call the recursive QuickSort
    _quickSort(head, h);
}
