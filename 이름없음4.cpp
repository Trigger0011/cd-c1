#include<stdio.h> 

int ga;
int gb;

void Sum();
void Diffence();

int main()
{
	
	printf("Á¤¼ö 2°³:");
	scanf("%d %d", &ga, &gb); 
	Sum();
	Diffence();
}

void Sum()
{
	printf("%d + %d = %d\n", ga, gb, ga + gb);	
}

void Diffence()
{
	int diff;
	
	if (ga > gb)
	{
		diff = ga - gb;
		printf("%d - %d = ", ga, gb);
	}
	else
	{
		diff = gb - ga;
		printf("%d - %d = ", gb, ga);
	}
	printf("%d ", diff);
}
