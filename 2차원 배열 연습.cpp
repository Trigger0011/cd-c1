#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

int main()
{
	//2차원 배열 선언하기 & 채워넣기 
	int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
	
	
	
	//입력하기 
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			printf("입력해\n");
			scanf("%d", &arr[i][j]);
			
			
		}
		
		
		
		system("cls");
	}
	//하나 바꾸기 (5번째) 
	arr[1][1] = 0;
	
	//출력하기 
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			printf("%d ", arr[i][j]);
			
			
		}
		
		
		
		printf("\n");
	}
}
