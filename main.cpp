#define _CRT_SECURE_NO_WARNINGS
#include "tools.h"
#include "AddrBook.h"
#include "stdafx.h"
using namespace std;

/* ÿ��5��ָ�뱣��һ�������ָ��*/
Node* LinkArray[20];

void Show(AddrBook book, Node* array[])
{
	int len = ListToArray(book, LinkArray, 5);
	int ud = 0;
	char JK;
	while (true)
	{
		system("cls");
		cout << "                    ����                  " << endl;
		cout << "==========================================" << endl;
		cout << "  ����    �ֵ�     ����      �ʱ�    ���� " << endl;
		display2(LinkArray, ud);
		cout << "==========================================" << endl;
		cout << "J.��һҳ   L.��һҳ         D.ɾ��  Q.����" << endl;
		cout << "==========================================" << endl;
		JK = _getch();
		if (JK == 'q' || JK == 'Q') return;
		else if (JK == 'd' || JK == 'D')
		{
			int del = 0;
			cout << "����Ҫɾ�������:" << endl;
			cin >> del;
			Node *delNode = GetNode(book, del);
			if (delNode != NULL){ Delete(book, delNode); cout << "��ɾ��" << endl; ListToArray(book, LinkArray, 5); }
			else cout << "��Ų�����" << endl;
			check_return();
		}
		else if (JK == 'j' || JK == 'J') ud--;
		else if (JK == 'l' || JK == 'l') ud++;
		if (ud<0 || ud>len - 1) ud = 0;
	}
}
void menu(AddrBook book)
{
	system("title ͨѶ¼ϵͳ");
	cout << "                  ͨѶ¼                  " << endl;
	cout << "==========================================" << endl;
	cout << "               1. ������Ϣ                 " << endl;
	cout << "               2. �����Ϣ                 " << endl;
	cout <<	"               3.�鿴ͨѶ¼               " << endl;
	cout << "               4.����ͨѶ¼               " << endl;
	cout <<	"               5.   �˳�                    " << endl;
	cout << "==========================================" << endl;
	
	char choice = 0;
	AddrBook find;
	Data data;

	while (true)
	{
		cin >> choice;
		switch (choice)
		{
		case '1':
			system("cls");
			char name[50];
			cout << "��������ҵ�������";
			cin >> name;
			find = *Search(book, name);
			if (find->next == NULL)
				cout << "û�д˼�¼" << endl;
			else
			{
				cout << "==========================================" << endl;
				cout << "  ����    �ֵ�     ����      �ʱ�    ���� " << endl;
				display(find);
				cout << "==========================================" << endl;
			}
			DestroyBook(find);

			check_return();
			menu(book);
			break;


		case '2':
			system("cls");
			cout << "��������ӵ�����" << endl;
			data = *enter();
			if (insert(book, data))
				cout << "��ӳɹ�" << endl;
			else
				cout << "���ʧ��" << endl;
			ListToArray(book, LinkArray, 5);


			check_return();
			menu(book);
			break;


		case '3':
			system("cls");

sub_menu:	
			cout << "                    �鿴                  " << endl;
			cout << "==========================================" << endl;
			cout << "               1. ˳��鿴                 " << endl;
			cout << "               2. ����鿴                 " << endl;
			cout << "               3.   ����                   " << endl;
			cout << "==========================================" << endl;

			char sub_ch;			
			cin >> sub_ch;
			switch (sub_ch)
			{
			case '1':
				system("cls");
				Show(book, LinkArray);

				check_return();
				goto sub_menu;
				break;

			case '2':
				sort(book);

				system("cls");
				Show(book, LinkArray);

				check_return();
				goto sub_menu;
				break;

			case '3':
				system("cls");
				menu(book);
				break;
			
			default:
				system("cls");
				goto sub_menu;
				break;
			}

			break;

		case '4':
			if (save(book))
				cout << "����ɹ�" << endl;
			else
				cout << "����ʧ��" << endl;

			check_return();
			menu(book);
			break;

		case '5':
			//save(book);
			exit(0);
			break;

		default:
			cout << "û�д�ѡ��" << endl;			
			system("cls");
			menu(book);
		}

	}
}

int main(int argc, char const *argv[])
{
	/* code */
	AddrBook book;
	InitBook(book);
	load(book);

	menu(book);

	getchar();
	return 0;
}
