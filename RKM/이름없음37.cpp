#include<unistd.h>
#include<stdio.h>
int main(){
	int n = 0;
	int clas = 1;
	int grade = 1;
	

	
	do
	{
	
	printf("%d�г�	", grade);
	
	do{
		
		printf("%d��	", clas);
		clas++;
	sleep(1);
	} while(clas <= 13);
	
	printf("\n");
	grade++;
	n++;
	clas = 1;
	} while(n <= 5);
	
	
	
	
}
