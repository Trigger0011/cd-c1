#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{ 
	int i = 0;
	
	char str[ ] = "===========\ncoding is computer programming\n===========";
	
	while(str[i] != '\0')
	{
		
		printf("%c",str[i]);
		i++;
		sleep(1); 
		
	}
	
	
	
	
	
	
	
}
