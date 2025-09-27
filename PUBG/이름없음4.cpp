#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
int main()
{
	
	int random[10];
	int m;
	int size = sizeof(random) / sizeof(random[0]);
	
	srand(time(NULL));
	
	for (int i = 0; i < size; i++)
	{
		
		m = rand() % 10;
		
		random[i] = m;
		
		printf("%d\n", random[i]);
		
		sleep(1);
		
		system("cls");
	}
}
