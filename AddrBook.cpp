#define _CRT_SECURE_NO_WARNINGS
#include "AddrBook.h"
#include "stdafx.h"

/*���ݱȽϺ��� */
int CompareByName(Data a, Data b)
{
	return strcmp(b.name, a.name);
}
/* �������� */
void swap(Data* a, Data* b)
{
	Data t = *a;      *a = *b;       *b = t;
}

/* �ҵ����Ľڵ� */
Node *lastNode(Node *root)
{
	while (root && root->next)
		root = root->next;
	return root;
}

/*  */
Node* partition(Node *l, Node *h)
{
	// ��h��Ϊ����
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

/* ������ŵĵݹ�ʵ�� */
void _quickSort(Node* l, Node *h)
{
	if (h != NULL && l != h && l != h->next)
	{
		Node *p = partition(l, h);
		_quickSort(l, p->prev);
		_quickSort(p->next, h);
	}
}

/* ���� */
void quickSort(LinkList &head)
{
	// �ҵ����ڵ�
	Node *h = lastNode(head);

	// ���ÿ���
	_quickSort(head, h);
}



/* �������ݵ�ͷ�ڵ� */
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

/* �������ݣ�����Data���� */
Data *enter()
{
	Data *data = new Data;
	printf("������������");scanf("%s",&data->name);
	printf("������ֵ���");scanf("%s",&data->street);
	printf("��������У�");scanf("%s",&data->city);
	printf("�������ʱࣺ");scanf("%s",&data->eip);
	printf("��������ң�");scanf("%s",&data->state);
	return data;
}

/* ͨѶ¼����ĳ�ʼ�� */
void InitBook(LinkList &L)
{
	L = new Node;
	L->next = L->prev = NULL;
}

/* ����ͨѶ¼�е����� ��������*/
void sort(AddrBook &book)
{
	quickSort(book->next);
}

/* ���ڲ���  ��ʾͨѶ¼��Ϣ */
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
/* ���ڷ�ҳ��ʾ��  ��ʾͨѶ¼����*/
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


/* ����ͨѶ¼�з��� ���� �����м�¼*/
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

/* ɾ���ڵ� */
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


/* ɾ������ */
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

/* ��ȡ��i���ڵ�*/
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