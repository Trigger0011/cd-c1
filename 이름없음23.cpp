#include<stdio.h>
#include<stdlib.h>
#include<ctime>
#include<iostream>
#include<windows.h>
using namespace std;


int main()
{
	FILE *out = fopen("StringFile.txt", "w");
	char str1[] = "zz";
	char str2[] = "�ȳ� �ٺ� ���Ͼ�";
	
	if (out == NULL)
	{
		printf("���Ͼ���\n");
		exit(1);
		
	}
	
	fputs("���ڿ� ���\n", out);
	fputs(str1, out);
	fputs("\n", out);
	fputs(str2, out);
	
	fclose(out);
}
