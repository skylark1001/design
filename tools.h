#ifndef _TOOLS_H
#define _TOOLS_H

#include "AddrBook.h"
bool save(AddrBook book);/*保存到文件*/
bool load(AddrBook book);/*载入到通讯录*/
int split(char dst[][255], char* str, const char* spl);/*分离字符串*/
void trim(char *s);/*去除换行符*/
int ListToArray(LinkList L, Node* arr[], int len);/*存储链表节点*/
void check_return();/*确认返回*/

#endif