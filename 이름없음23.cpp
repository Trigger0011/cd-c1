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
	char str2[] = "안녕 바보 주하야";
	
	if (out == NULL)
	{
		printf("파일업음\n");
		exit(1);
		
	}
	
	fputs("문자열 출력\n", out);
	fputs(str1, out);
	fputs("\n", out);
	fputs(str2, out);
	
	fclose(out);
}
