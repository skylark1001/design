#define _CRT_SECURE_NO_WARNINGS
#include "AddrBook.h"
#include "stdafx.h"

/*数据比较函数 */
int CompareByName(Data a, Data b)
{
	return strcmp(b.name, a.name);
}
/* 交换数据 */
void swap(Data* a, Data* b)
{
	Data t = *a;      *a = *b;       *b = t;
}

/* 找到最后的节点 */
Node *lastNode(Node *root)
{
	while (root && root->next)
		root = root->next;
	return root;
}

/*  */
Node* partition(Node *l, Node *h)
{
	// 将h作为枢轴
	Data x = h->data;

	// i = l-1 
	Node *i = l->prev;

	// for (int j = l; j <= h- 1; j++)
	for (Node *j = l; j != h; j = j->next)
	{
		if (CompareByName(j->data, x) >= 0)
		{
			// i++ 
			i = (i == NULL) ? l : i->next;
			swap(&(i->data), &(j->data));
		}
	}
	i = (i == NULL) ? l : i->next; //  i++
	swap(&(i->data), &(h->data));
	return i;
}

/* 链表快排的递归实现 */
void _quickSort(Node* l, Node *h)
{
	if (h != NULL && l != h && l != h->next)
	{
		Node *p = partition(l, h);
		_quickSort(l, p->prev);
		_quickSort(p->next, h);
	}
}

/* 快排 */
void quickSort(LinkList &head)
{
	// 找到最后节点
	Node *h = lastNode(head);

	// 调用快排
	_quickSort(head, h);
}



/* 插入数据到头节点 */
bool insert(AddrBook &head, Data data)
{
	Node* new_node = new Node;
	if (!new_node) return false;

	new_node->data = data;

	new_node->next = head->next;
	new_node->prev = NULL;

	if (head->next != NULL)
		head->next->prev = new_node;

	head->next = new_node;
	return true;
}

/* 输入数据，返回Data类型 */
Data *enter()
{
	Data *data = new Data;
	printf("请输入姓名：");scanf("%s",&data->name);
	printf("请输入街道：");scanf("%s",&data->street);
	printf("请输入城市：");scanf("%s",&data->city);
	printf("请输入邮编：");scanf("%s",&data->eip);
	printf("请输入国家：");scanf("%s",&data->state);
	return data;
}

/* 通讯录链表的初始化 */
void InitBook(LinkList &L)
{
	L = new Node;
	L->next = L->prev = NULL;
}

/* 根据通讯录中的名字 升序排序*/
void sort(AddrBook &book)
{
	quickSort(book->next);
}

/* 用于查找  显示通讯录信息 */
void display(AddrBook book)
{
	Node* head = book->next;
	Data data;
	printf("\n");
	while (head)
	{
		data = head->data;
		printf(" %5s | %6s | %4s | %7s | %4s \n", data.name, data.street, data.city, data.eip, data.state);
		head = head->next;
	}
}
/* 用于翻页显示的  显示通讯录数据*/
void display2(Node* array[], int idx)
{
	Data data;
	Node* head = array[idx];
	int order = idx * 5 + 1;
	printf("\n");
	for (int i = 0; i <5 && head; i++)
	{
		data = head->data;
		printf("%d. %5s | %6s | %4s | %7s | %4s \n", order + i, data.name, data.street, data.city, data.eip, data.state);
		head = head->next;
	}
}


/* 查找通讯录中符合 条件 的所有记录*/
AddrBook* Search(AddrBook book, char const *name)
{
	AddrBook *set= new AddrBook;
	InitBook(*set);

	Node* head = book->next;
	Data data;
	while (head)
	{
		data = head->data;
		if (strcmp(data.name, name) == 0)
			insert(*set, data);
		head = head->next;
	}
	return set;
}

/* 删除节点 */
bool Delete(AddrBook &book, Node* del)
{
	Node* head = book->next;
	if (head == NULL || del == NULL)
		return false;

	if (head == del)
		book->next = del->next;

	if (del->next != NULL)
		del->next->prev = del->prev;

	if (del->prev != NULL)
		del->prev->next = del->next;

	delete del;
	return true;
}


/* 删除链表 */
void DestroyBook(AddrBook &book)
{
	Node* cur = book->next;
	Node* next;

	while (cur)
	{
		next = cur->next;
		delete cur;
		cur = next;
	}
	book->next = NULL;
}

/* 获取第i个节点*/
Node* GetNode(AddrBook book, int i)
{
	Node* head = book->next;
	int j = 1;
	while (head && j < i)
	{
		head = head->next;
		j++;
	}
	if ( head==NULL || j>i) return NULL;
	else return head;
}