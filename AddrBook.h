#ifndef _ADDRBOOK_H
#define _ADDRBOOK_H

typedef struct Person
{
    char name[50];
    char street[255];
    char city[30];
    char eip[7];
    char state[20];
}Data;

typedef struct DLNode
{
    Data data;
    struct DLNode *next;
    struct DLNode *prev;
}Node,*LinkList;

typedef LinkList AddrBook;


void enter();
void display();
int Search(char const *name);
void Delete();
void sort();
int CompareByName(Data a, Data b);


#endif




