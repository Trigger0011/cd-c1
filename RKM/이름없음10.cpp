#include <stdio.h>
int main()
{

	int num;
	int num2;
	
	
	printf("���� �Է��ϼ���\n");
	scanf("%d", &num);
	
	
	if(num > 0) 
	{
		if(num % 2 == 0 && num % 3 == 0)
		{
			if(num > 0) 
			{
			printf("2 �� 3�� ������� �´�.");
			}
		}
		else
		{
			if(num > 0) 
			{
			printf("2 �� 3�� ������� �ƴϴ�.");
			}
	
		}
	
	}
	
	
	
	

	else
	{
		printf("���� �Է��϶�� ��û�� �밡���� ��� ����?\n\n\n\n ");
	
	
		printf("\n\n\n\n���ڸ� �Է���\n\n\n\n\n\n\n\n\n");
		scanf("%d", &num2);
	
		
		if(num2 % 2 == 0 && num2 % 3 == 0)
		{
		printf("2 �� 3�� ������� �¾�.");
		}
		else
		{
			printf("2 �� 3�� ������� �ƴϾ�.");
		}
	
 	}

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
