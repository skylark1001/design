#define _CRT_SECURE_NO_WARNINGS
#include "tools.h"
#include "AddrBook.h"
#include "stdafx.h"
using namespace std;

/* 每隔5个指针保存一次链表的指针*/
Node* LinkArray[20];

void Show(AddrBook book, Node* array[])
{
	int len = ListToArray(book, LinkArray, 5);
	int ud = 0;
	char JK;
	while (true)
	{
		system("cls");
		cout << "                    查找                  " << endl;
		cout << "==========================================" << endl;
		cout << "  姓名    街道     城市      邮编    国家 " << endl;
		display2(LinkArray, ud);
		cout << "==========================================" << endl;
		cout << "J.上一页   L.下一页         D.删除  Q.返回" << endl;
		cout << "==========================================" << endl;
		JK = _getch();
		if (JK == 'q' || JK == 'Q') return;
		else if (JK == 'd' || JK == 'D')
		{
			int del = 0;
			cout << "输入要删除的序号:" << endl;
			cin >> del;
			Node *delNode = GetNode(book, del);
			if (delNode != NULL){ Delete(book, delNode); cout << "已删除" << endl; ListToArray(book, LinkArray, 5); }
			else cout << "序号不存在" << endl;
			check_return();
		}
		else if (JK == 'j' || JK == 'J') ud--;
		else if (JK == 'l' || JK == 'l') ud++;
		if (ud<0 || ud>len - 1) ud = 0;
	}
}
void menu(AddrBook book)
{
	system("title 通讯录系统");
	cout << "                  通讯录                  " << endl;
	cout << "==========================================" << endl;
	cout << "               1. 查找信息                 " << endl;
	cout << "               2. 添加信息                 " << endl;
	cout <<	"               3.查看通讯录               " << endl;
	cout << "               4.保存通讯录               " << endl;
	cout <<	"               5.   退出                    " << endl;
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
			cout << "请输入查找的姓名：";
			cin >> name;
			find = *Search(book, name);
			if (find->next == NULL)
				cout << "没有此纪录" << endl;
			else
			{
				cout << "==========================================" << endl;
				cout << "  姓名    街道     城市      邮编    国家 " << endl;
				display(find);
				cout << "==========================================" << endl;
			}
			DestroyBook(find);

			check_return();
			menu(book);
			break;


		case '2':
			system("cls");
			cout << "请输入添加的数据" << endl;
			data = *enter();
			if (insert(book, data))
				cout << "添加成功" << endl;
			else
				cout << "添加失败" << endl;
			ListToArray(book, LinkArray, 5);


			check_return();
			menu(book);
			break;


		case '3':
			system("cls");

sub_menu:	
			cout << "                    查看                  " << endl;
			cout << "==========================================" << endl;
			cout << "               1. 顺序查看                 " << endl;
			cout << "               2. 排序查看                 " << endl;
			cout << "               3.   返回                   " << endl;
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
				cout << "保存成功" << endl;
			else
				cout << "保存失败" << endl;

			check_return();
			menu(book);
			break;

		case '5':
			//save(book);
			exit(0);
			break;

		default:
			cout << "没有此选项" << endl;			
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
