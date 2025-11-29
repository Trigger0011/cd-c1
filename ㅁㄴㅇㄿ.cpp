#include<stdio.h>
#include<string.h>

int MyStrcmp(char* fw, char* sw)
{
	int i;
	i = strcmp(fw,sw);
	return i;
}

int main() 
{
	char fw [10];
	char sw [10];
	int i;
	printf("첫번째 단어 입력: ");
	scanf("%s", &fw);
	printf("두번째 단어 입력: ");
	scanf("%s", &sw);
	
	i = MyStrcmp(fw, sw);
	
	if(i == -1)
	{
		
		printf("앞의 단어가 사전순으로 더 빠릅니다.\n 앞의 단어: % s", fw);
		
	}
	else if(i == 1)
	{
		
		printf("뒤의 단어가 사전순으로 더 빠릅니다.\n 뒤의 단어: % s", sw);
		
	}
	else if(i == 0)
	{
		
		printf("단어의 사전순이 같습니다.");
		
	}
	else
	{
		
		printf("※오류※");
		
	}
}
