#include<stdio.h>
#include<stdlib.h>
#include<ctime>
#include<iostream>
#include<windows.h>
using namespace std;


int main()
{
	int n, num;
	char *res, str[20];
	
	printf("���� �Է�:");
	n = getchar();
	printf("n = %d\n", n);
	
	printf("�������Է�:");
	res = gets(str);
	printf("res = %d\n", res);
	
	printf("����:");
	n = scanf("%s", &num);
	printf("n = %d", n);
	
	
}
