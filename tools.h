#ifndef _TOOLS_H
#define _TOOLS_H

#include "AddrBook.h"
bool save(AddrBook book);/*���浽�ļ�*/
bool load(AddrBook book);/*���뵽ͨѶ¼*/
int split(char dst[][255], char* str, const char* spl);/*�����ַ���*/
void trim(char *s);/*ȥ�����з�*/
int ListToArray(LinkList L, Node* arr[], int len);/*�洢����ڵ�*/
void check_return();/*ȷ�Ϸ���*/

#endif