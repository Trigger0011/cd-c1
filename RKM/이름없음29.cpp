#include <stdio.h>
int main()
{
	
	int n;
	
	printf("ÀÚ¿¬¼ö ÀÔ·Â:");
	scanf("%d", &n);
	
	if(n % 2 == 1)
	{
		
			switch(n)
		{
			case 1:
				printf("È¦¼ö");//break;
			break;
			
			case 3:
				printf("È¦¼ö");
			break;
			
			case 5:
				printf("È¦¼ö");
			break;
			
			case 7:
				printf("È¦¼ö");
			break;
			
			case 9:
				printf("È¦¼ö");
			break;	
		} 
		
	}
	
	else if(n % 2 == 0)
	{
		
			switch(n)
			{
				case 2:
				printf("Â¦¼ö");
			break;
			
			case 4:
				printf("Â¦¼ö");
			break;
			
			case 6:
				printf("Â¦¼ö");
			break;
			
			case 8:
				printf("Â¦¼ö");
			break;
			}
	}
	
	if( n > 10)
	{
		
		printf("ÀÚ¿¬¼ö ");
		
	}
	
	
	
}
