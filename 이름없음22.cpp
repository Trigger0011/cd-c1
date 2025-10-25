#include<stdio.h>
#include<stdlib.h>
#include<ctime>
#include<iostream>
#include<windows.h>
using namespace std;


int main()
{
	FILE *fp;
	fp = fopen("datafile.txt", "r");
	char ch;
	if (fp == NULL)
	{
		printf("no file babo juha");
		exit(1);
		
	}
	
	ch = fgetc(fp);
	printf("%c", ch);
	ch = fgetc(fp);
	putchar(ch);
	
	fputc('B', fp);
	fputc('\n', fp);
	fputc(97 , fp);
	fputc(98, fp);
	
	
	fclose(fp);
}
