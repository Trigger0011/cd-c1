#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
	int i;
	int sub[8];
	
	sub[0] = 1;
	sub[1] = 2;
	sub[0] = 1;
	sub[1] = 2;
	sub[0] = 1;
	sub[1] = 2;
	sub[0] = 1;
	sub[1] = 2;
	printf("진도");
	scanf("%d",&sub[2]);
	system("cls");
	printf("진도");
	scanf("%d",&sub[3]);
	system("cls");
	for(i = 0;  i < 4; i ++)
	{
		
		
		printf("%d\n", sub[i]);
	}
	
	
	
	
}
