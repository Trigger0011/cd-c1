#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

int main()
{
	//2���� �迭 �����ϱ� & ä���ֱ� 
	int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
	
	
	
	//�Է��ϱ� 
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			printf("�Է���\n");
			scanf("%d", &arr[i][j]);
			
			
		}
		
		
		
		system("cls");
	}
	//�ϳ� �ٲٱ� (5��°) 
	arr[1][1] = 0;
	
	//����ϱ� 
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			printf("%d ", arr[i][j]);
			
			
		}
		
		
		
		printf("\n");
	}
}
