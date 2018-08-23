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
}Node, *LinkList;

typedef LinkList AddrBook;

void InitBook(LinkList &L);/*��ʼ��ͨѶ¼*/
bool insert(AddrBook &book, Data data);/*��������*/
bool Delete(AddrBook &book, Node* del);/*ɾ������*/
AddrBook* Search(AddrBook book, char const *name);/*��������*/
Node* GetNode(AddrBook book, int i);/* ��ȡ��i���ڵ�*/
void DestroyBook(AddrBook &book);/*����ͨѶ¼*/

Data *enter();/*������Ϣ*/
void display(AddrBook book);/*��ʾ����*/
void display2(Node* array[], int idx);/*��ʾ����2*/
void sort(AddrBook &book);/*��������*/
#endif




