#include <stdio.h>
int main()
{

	int num;
	int num2;
	
	
	printf("값을 입력하세요\n");
	scanf("%d", &num);
	
	
	if(num > 0) 
	{
		if(num % 2 == 0 && num % 3 == 0)
		{
			if(num > 0) 
			{
			printf("2 와 3의 공배수가 맞다.");
			}
		}
		else
		{
			if(num > 0) 
			{
			printf("2 와 3의 공배수가 아니다.");
			}
	
		}
	
	}
	
	
	
	

	else
	{
		printf("숫자 입력하라고 멍청아 대가리에 든게 없냐?\n\n\n\n ");
	
	
		printf("\n\n\n\n숫자를 입력해\n\n\n\n\n\n\n\n\n");
		scanf("%d", &num2);
	
		
		if(num2 % 2 == 0 && num2 % 3 == 0)
		{
		printf("2 와 3의 공배수가 맞아.");
		}
		else
		{
			printf("2 와 3의 공배수가 아니야.");
		}
	
 	}

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
