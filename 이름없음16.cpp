#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<ctime>
#include<iostream>
using namespace std;

struct abcd
{
	int a;
	int b;
};
int second(int q)
{
	
	struct abcd p;
	printf("첫번째 수:");
	scanf("%d",&p.a);
	printf("두번째 수:");
	scanf("%d",&p.b);
	q = p.a/p.b;
	return q;
} 

int main()
{	
	int second(int q);
	int q;
	printf("%d", second(q));
}
