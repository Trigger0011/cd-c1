#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<iostream>

int main()
{
	
	int arr[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
	int brr[7];
	
	printf("배열의 이름: %d\n",   (arr + 5));
	printf("배열의 이름: %d\n", (brr + 1));
	
	printf("1번째 주소%d\n", &arr[5]);
	printf("1번째 주소%d\n", &brr[1]);
	
	
}
