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
	
	printf("문자 입력:");
	n = getchar();
	printf("n = %d\n", n);
	
	printf("무나열입력:");
	res = gets(str);
	printf("res = %d\n", res);
	
	printf("형식:");
	n = scanf("%s", &num);
	printf("n = %d", n);
	
	
}
