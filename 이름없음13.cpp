#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<iostream>

int main()
{
	
	int arr[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
	int brr[7];
	
	printf("�迭�� �̸�: %d\n",   (arr + 5));
	printf("�迭�� �̸�: %d\n", (brr + 1));
	
	printf("1��° �ּ�%d\n", &arr[5]);
	printf("1��° �ּ�%d\n", &brr[1]);
	
	
}
