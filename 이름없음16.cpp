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
	printf("ù��° ��:");
	scanf("%d",&p.a);
	printf("�ι�° ��:");
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
