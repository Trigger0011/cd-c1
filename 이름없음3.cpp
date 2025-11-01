#include<stdio.h>

void PrintFun1(int m, int n);
void PrintFun2(int m, int n);

int main()
{
	int m, n;
	
	m = 10;
	n = 30;
	
	printf("main before : m = %d n = %d\n", m, n);
	PrintFun1(m, n);
	printf("main after : m = %d n = %d\n", m, n);
	
	return 0;
}

void PrintFun1(int m, int n)
{
	printf("Fun1 before : m = %d n = %d\n", m ,n);
	m = m + 50;
	n = n * 10;
	PrintFun2(m, n);
	printf("fun1 after : m = %d n = %d\n", m ,n);
}
void PrintFun2(int m, int n)
{
	printf("Fun2 before : m = %d n = %d\n", m ,n);
	m = m + 50;
	n = n * 10;
	printf("fun2 after : m = %d n = %d\n", m ,n);
}
