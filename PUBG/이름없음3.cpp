#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
	
	int ar[9999999];
	int br[ ] = {1,2,3,4,5};
	double dr[20];
	
	printf("%d %d %d", sizeof(ar),sizeof(br),sizeof(dr));
}
