#include <stdio.h>
int main()
{
	
	int n;
	
	printf("�ڿ��� �Է�:");
	scanf("%d", &n);
	
	if(n % 2 == 1)
	{
		
			switch(n)
		{
			case 1:
				printf("Ȧ��");//break;
			break;
			
			case 3:
				printf("Ȧ��");
			break;
			
			case 5:
				printf("Ȧ��");
			break;
			
			case 7:
				printf("Ȧ��");
			break;
			
			case 9:
				printf("Ȧ��");
			break;	
		} 
		
	}
	
	else if(n % 2 == 0)
	{
		
			switch(n)
			{
				case 2:
				printf("¦��");
			break;
			
			case 4:
				printf("¦��");
			break;
			
			case 6:
				printf("¦��");
			break;
			
			case 8:
				printf("¦��");
			break;
			}
	}
	
	if( n > 10)
	{
		
		printf("�ڿ��� ");
		
	}
	
	
	
}
