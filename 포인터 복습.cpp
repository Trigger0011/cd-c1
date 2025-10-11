#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

int main()
{
	
	int a = 10;

	int* b = &a;
	
	printf("%d\n",*b);
	printf("%d",&*b);
	printf("\n%d",&a);
	
	*b *= 2;	
	//+= -= *= /= %=
	printf("\n%d",a);
	
}
