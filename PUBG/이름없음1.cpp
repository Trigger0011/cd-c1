#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i = 0;
	char str[15] = {'H','I',' ','C','3',' ','C','O','D','I','N','G','\0'};
	
	while(str[i]!='\0')
	{
		
		printf("%c",str[i]);
		i++;
		sleep(1);
	}
	
}
