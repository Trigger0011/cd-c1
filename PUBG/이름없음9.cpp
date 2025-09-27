#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int main()
{
	
	int a, b;
	int add, sub, mul, div;
	int *pa, *pb;
	
	
	pa = &a;
	pb = &b;
	
	a = 30;
	b = 55;
	add = *pa + *pb;
	printf("add = %d\n", add);
	
	*pa = 9;
	*pb = 7;
	sub = *pa - *pb;
	printf("add = %d\n", sub);
	
	*pa = 12;
	b = 3;
	mul = *pa * *pb;
	printf("add = %d\n", mul);
	
	a = 45;
	*pb = 5;
	div = *pa / *pb;
	printf("add = %d\n", div);
	
}
