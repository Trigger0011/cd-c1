#include<stdio.h>
#include<string.h>

char MyStrcpy(char username[10]);


int main()
{
	char username[10];
	
	printf("이름을 쓰세요. :");
	scanf("%s", username);
	
	MyStrcpy(username);
	
	printf("%s",MyStrcpy(username));
}

char MyStrcpy(char username[10])
{
	
	strcpy(username, "바보");
	
	printf("%s", username);
//	return username;
	
}

