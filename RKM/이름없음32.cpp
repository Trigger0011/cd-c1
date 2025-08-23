#include <stdio.h>
int main()
{
	
	int i;
	int num; 
	int max = 0;
	
	for(i = 0 ; i < 10 ; i++)
	{
		
		printf("정수 입력(10번 반복):");
		scanf("%d", &num);
		
		if (num>max)
	{
		max = num;
	}
	}	
	printf("%d", max);2
	3
	12
}
