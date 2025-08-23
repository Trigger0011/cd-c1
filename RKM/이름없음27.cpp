#include <stdio.h>
int main()
{
	
	int n;
	
	printf("숫자 입력:");
	scanf("%d", &n);
	
	
	
	
	
	switch(n)
	{
		
		case 1:
			printf("%d   ", n);
		case 2:
			printf("%d   ", ++n);
		case 3:
			printf("%d   ", ++n);
		case 4:
			printf("%d   ", ++n);
		case 5:
			printf("%d   ", ++n);
		case 6:
			printf("%d   ", ++n);
		case 7:
			printf("%d   ", ++n);
		case 8:
			printf("%d   ", ++n);
		case 9:
			printf("%d   ", ++n);
		case 10:
			printf("%d   ", ++n);
	}
	return 0;
}
