#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<iostream>

int main()
{
	
	int arr[100];
	int i = 0;
	for(i = 0; i < 100; i++)
	{
		arr[i] = i;
	}
	int j;
	printf("�� �Է�:");
	scanf("%d",&j);
	int num = 0;
	for(i = 0; i < 100; i++)
	{
		if(i == j)
		{
			num++;
			
		}
		
	}
	printf("%d", num);
}
