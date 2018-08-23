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

void InitBook(LinkList &L);/*初始化通讯录*/
bool insert(AddrBook &book, Data data);/*插入数据*/
bool Delete(AddrBook &book, Node* del);/*删除数据*/
AddrBook* Search(AddrBook book, char const *name);/*搜索数据*/
Node* GetNode(AddrBook book, int i);/* 获取第i个节点*/
void DestroyBook(AddrBook &book);/*销毁通讯录*/

Data *enter();/*输入信息*/
void display(AddrBook book);/*显示数据*/
void display2(Node* array[], int idx);/*显示数据2*/
void sort(AddrBook &book);/*数据排序*/
#endif




