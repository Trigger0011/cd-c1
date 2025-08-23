#include <stdio.h>
int main()
{
	
	int n;
	int m;
	
	printf("날짜 입력:");
	scanf("%d", &n);
	
	m = n % 7;
	

		switch(m)
		{
			case 1:
			
				printf("토요일");
				break;
			
			
			case 0:
				printf("금요일");
				break;
				
				
			case 6:
			
				printf("목요일");
				break;
			
			
			case 5:
				printf("수요일");
				break;
			
			case 4:
			
				printf("화요일");
				break;
			
			
			case 3:
				printf("월요일");
				break;
			
			case 2:
			
				printf("월요일");
				break;
			
			
			
		}
		

}
