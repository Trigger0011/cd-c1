#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

int main()
{
	// �ڷ��� �迭�̸�[��Ұ���];
	int arr[10];
	for(int i = 0; i < 10; i++)
	{
		printf("�迭�� ���� ���� �Է��ϼ���.");
		scanf("%d", &arr[i]);
		
	} 
	for(int i = 0; i < 10; i++)
	{
		
		printf("%d ",arr[i]);
		
	}
	
	arr [3] = 100;
	
	
	
	for(int i = 0; i < 10; i++)
	{
		
		printf("%d ",arr[i]);
		
	}
	
	for(int i = 0; i < 10 && i % 2 == 0; i++)
	{
		
		arr[i] = arr[i] * 2;
		
	}
	printf("\n");
	
	for(int i = 0; i < 10; i++)
	{
		
		printf("%d ",arr[i]);
		
	}
}
