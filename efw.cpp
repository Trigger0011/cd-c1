#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
//함수는 5개의 요소 가 있는 정수 배열과 정수형 변수 1개 을 입력받는다 입력받은 정수 변수 보다 큰거 개수  
int big(int i, int arr[]) 
{
	int sum = 0;
	for(int j = 0; j < 5; j++)
	{
		if(arr[j] > i)
		{
			
			sum++;
			
		}
		
		
	}
	return sum;
}

int main()
{
	int siu = 0;
	int arr[5];
	printf("정수 입력:");
	scanf("%d", &siu);
	
	for(int j = 0; j < 5; j++)
	{
		
		printf("%d번째 정수 입력:", j + 1);
		scanf("%d", &arr[j]);
		
	}
	
	int de = big(siu, arr);
	
	printf("%d", de);
}
