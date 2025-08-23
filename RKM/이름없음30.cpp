#include <stdio.h>
int main()
{
	int day;
	
	printf("2025년 11월의 날짜:");
	scanf("%d", &day);
	if(day % 7 == 0)
	{
		
		printf("금요일");
		
	}
	if(day % 7 == 1)
	{
		
		printf("토요일");
		
	}
	if(day % 7 == 2)
	{
		
		printf("일요일");
		
	}
	if(day % 7 == 3)
	{
		
		printf("월요일");
		
	}
	if(day % 7 == 4)
	{
		
		printf("화요일");
		
	}
	if(day % 7 == 5)
	{
		
		printf("수요일");
		
	}
	if(day % 7 == 6)
	{
		
		printf("목요일");
		
	}
	
}
