#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <conio.h>
using namespace std;

int func1(int arr[])
{
	int sum = 0;
	for(int i = 0; i < 5; i++)
	{// 8 4 9 1 2
		
		if(arr[i] > sum)
		{
			
			sum = arr[i];
			
		}
		
		
	}
	
	return sum;
}

int main()
{
	int arr[5];
	for(int i = 0; i < 5; i++)
	{
		printf("%d번째 정수 입력", i + 1);
		scanf("%d", &arr[i]);	
	}
	printf("%d",func1(arr));
}
