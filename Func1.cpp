#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<iostream>
#include<ctime>
using namespace std;

//int func1(int a,int b)
//{
//	int c = a*a;
//	int d = b*b;
//	int ans = c + d;
//	return ans;
//}
// 출력타입 <함수이름>(입력타입들) 
bool func2(int tf)
{
	
	if (tf % 2 == 0)
	{
		
		return true;
		
	}
	else if (tf % 2 == 1)
	{
		
		return false;
		
	}
}

int func3(int arr[])
{
	int a = arr[0];
	int b = arr[1];
	int c = arr[2];
	int d = arr[3];
	int e = arr[4];
	
	
}
int main()
{
//	int a;
//	int b;
//	printf("정수 1번 입력:");
//	scanf("%d", &a);
//	
//	printf("\n정수 2번 입력:");
//	scanf("%d",&b); 
//	int ans = func1(a,b);
//	
//	
//	printf("%d", ans);
	int q;
	
	printf("정수 입력:");
	scanf("%d", &q);
	bool tf = func2(q);
	printf("%d", tf);
}
