#include <stdio.h>
int main()
{
	int old;
	int n;
	printf("나이 입력:");
	scanf("%d", &old);
	
	n = old / 10;
	 
	
	if( old >= 0 && old <= 9)
	{
		
		printf("유소련");
		
	}
	if( old >= 10 && old <= 19)
	{
		
		printf("청소련");
		
	}
	if( old >= 20 && old <= 39)
	{
		
		printf("청련");
		
	}
	if( old >= 40 && old <= 59)
	{
		
		printf("중련");
		
	}
	if( old >= 60 && old <= 69)
	{
		
		printf("장련");
		
	}
	if( old >= 70 && old <= 89)
	{
		
		printf("노련");
		
	}
	if( old >= 90 && old <= 99)
	{
		
		printf("도 100");
		
	}
	if( old >= 100)
	{
		
		printf("성 100");
		
	}
}
