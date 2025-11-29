#include<string.h>
#include<stdio.h>

int MyStrlen(char word[20],int wl);


int main()
{
	int wl;
	char fw [20];
	printf("단어 입력: ");
	scanf("%s", &fw);
	MyStrlen(fw, wl);
	printf("%d", MyStrlen(fw,wl));
	
}

int MyStrlen(char word[20],int wl)
{
	wl = strlen(word);
	
	return wl;
}
