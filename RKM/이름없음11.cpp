#include <stdio.h>
int main()

{
	int n;
	int i;
	
	int sum = 0;
	
	printf("���� �Է�\n\n\n");
	scanf("%d", &n);
	
	for( i=1; i<=n; i++)
	{
		if(i%3==0){
			printf("%d\n", i);
			sum++;
			
		}
	}
	
	printf("\n\n\n\n%d��", sum);
	
	
	
	
}	


