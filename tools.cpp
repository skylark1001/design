#define _CRT_SECURE_NO_WARNINGS
#include "tools.h"
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

void save()
{

}

void load()
{
	char *path = "info_GBK.txt";
	FILE *f = fopen(path,"r");
    if(f==NULL)
        cout<<"打开失败"<<endl;
    else
    {
        char line[255];
        while(fgets(line,255,f)!=NULL)
        {
            cout<<line<<endl;
        }
        fclose(f);
    }
}

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

