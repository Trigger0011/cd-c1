#include <stdio.h>
int main()
{
	int old;
	int n;
	printf("���� �Է�:");
	scanf("%d", &old);
	
	n = old / 10;
	 
	
	if( old >= 0 && old <= 9)
	{
		
		printf("���ҷ�");
		
	}
	if( old >= 10 && old <= 19)
	{
		
		printf("û�ҷ�");
		
	}
	if( old >= 20 && old <= 39)
	{
		
		printf("û��");
		
	}
	if( old >= 40 && old <= 59)
	{
		
		printf("�߷�");
		
	}
	if( old >= 60 && old <= 69)
	{
		
		printf("���");
		
	}
	if( old >= 70 && old <= 89)
	{
		
		printf("���");
		
	}
	if( old >= 90 && old <= 99)
	{
		
		printf("�� 100");
		
	}
	if( old >= 100)
	{
		
		printf("�� 100");
		
	}
}
