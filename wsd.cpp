#include<stdio.h>
#include<string.h>

int main()
{
	
	char fw [20];
	char sw [20];
	int wl = 0;\
	
	printf("첫번째 단어 입력: ");
	scanf("%s", &fw);
	printf("\n두번째 단어 입력: ");
	scanf("%s", &sw);
	
	strcat(fw, sw);
	
	printf("두 단어를 합친 단어: %s", fw);
	
	printf("\n그 단어의 길이: %d", strlen(fw));
}
