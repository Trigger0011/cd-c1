#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<iostream>

int main()
{
	
	char *sp = "Hello String";
	char *name = "��ť���ڶ�";
	
	printf("%d %d\n", sp, "Hello String");
	printf("%d %d\n", name, "��ť���ڶ�");
	printf("%s %s\n", sp, "Hello String");
	printf("%s %s\n", name, "��ť���ڶ�");
	
}
