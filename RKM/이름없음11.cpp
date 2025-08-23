#include <stdio.h>
int main()

{
	int n;
	int i;
	
	int sum = 0;
	
	printf("숫자 입력\n\n\n");
	scanf("%d", &n);
	
	for( i=1; i<=n; i++)
	{
		if(i%3==0){
			printf("%d\n", i);
			sum++;
			
		}
	}
	
	printf("\n\n\n\n%d개", sum);
	
	
	
	
}	


