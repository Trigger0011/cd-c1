#include<stdio.h>
#include<string.h>

char* MyStrcat(char* fw, char* sw)
{
	
	strcat(fw, sw);
	
	return fw;
	
}

int main()
{
	char fw [10];
	char sw [10];
	
	printf("1번째 단어 입력");
	scanf("%s", &fw); 
	printf("2번째 단어 입력");
	scanf("%s", &sw); 
	
	MyStrcat(fw, sw);
	
	printf("합친 단어: %s", MyStrcat(fw, sw));
	
}

