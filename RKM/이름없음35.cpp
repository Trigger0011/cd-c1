#include<stdio.h>
#include<unistd.h>
int main(){
	
	int a;
	
	printf("3\n");
	sleep(1);
	printf(" 2\n");
	sleep(1);
	printf("  1\n");
	sleep(1);
	printf("   0\n");
	sleep(1);
	
	for(a = 1; a <= 10; a--)
	{
		printf("4");
	}
}
