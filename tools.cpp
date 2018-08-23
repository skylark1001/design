#define _CRT_SECURE_NO_WARNINGS
#include "tools.h"
#include "AddrBook.h"
#include "stdafx.h"

using namespace std;

/* ��ͨѶ¼���ݱ��浽�ļ�info.txt��*/
bool save(AddrBook book)
{
	char *path = "info_save.txt";
	FILE *fw = fopen(path, "w");
	if (fw == NULL)
		return false;
	else
	{
		Node *head = book->next;
		while (head && head->next) head = head->next;
		while (head)
		{
			Data data = head->data;
			fputs(data.name, fw); fputc(' ', fw);
			fputs(data.street, fw); fputc(' ', fw);
			fputs(data.city, fw); fputc(' ', fw);
			fputs(data.eip, fw); fputc(' ', fw);
			fputs(data.state,fw);fputc('\n' ,fw);
			head = head->prev;
		}
	}
	if (fw != NULL)
		fclose(fw);
	return true;
}

/*��ȡ�ļ�info.txt�е����� �������뵽ͨѶ¼������*/
bool load(AddrBook book)
{
	char *path = "info_save.txt";
	FILE *f = fopen(path, "r");
	if (f == NULL)
		return false;
	else
	{
		char line[255];
		char dst[5][255];Data data;
		while (fgets(line, 255, f) != NULL)
		{
			trim(line);
			split(dst, line, " ");
			strcpy(data.name, dst[0]);
			strcpy(data.street, dst[1]);
			strcpy(data.city, dst[2]);
			strcpy(data.eip, dst[3]);
			strcpy(data.state, dst[4]);
			insert(book, data);
		}
		fclose(f);
	}
	return true;
}

/* ��������һ���ַ� ���ָ����ָ�*/
int split(char dst[][255], char* str, const char* spl)
{
	int n = 0;
	char *result = NULL;
	result = strtok(str, spl);
	while (result != NULL)
	{
		strcpy(dst[n++], result);
		result = strtok(NULL, spl);
	}
	return n;
}

/* ȥ���ַ�����Ļ��� */
void trim(char *s)
{
	strtok(s, "\n");
}

/*��������Ľڵ㣬���������������*/
int ListToArray(LinkList L, Node* arr[], int len)
{
	Node* head = L->next;
	int cnt = 0, i = 0;
	while (head)
	{
		if (cnt%len == 0)
		{
			arr[i++] = head;
		}
		head = head->next;
		cnt++;
	}
	return i;
}

void check_return()
{
	cout << endl << "���ո񷵻�" << endl;
	while (_getch() != ' ');
	system("cls");
}

