#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<ctime>
#include<iostream>
using namespace std;

struct people {
	
	int mathmatics;
	int english;
	
};

int main()
{
	struct people arr[5] = {{100, 100},{90,93},{66,78},{65,43},{98,89}};
	for(int i = 0; i < 5; i++)
	{
		arr[i].english = 0;
		arr[i].mathmatics = 0;
		
	}
	for(int i = 0; i < 5; i++)
	{
		printf("%d ", arr[i].english);
		printf("%d\n", arr[i].mathmatics);
		
		
	}
	system("cls");
	for(int i = 0; i < 5; i++)
	{
		
		printf("\n\n");
		printf("%d��° �л� ", i + 1);
		printf("���� ����:");
		scanf("%d",&arr[i].english); 
		printf("���� ����:");
		scanf("%d",&arr[i].mathmatics); 
		system("cls");
		
	}
	
	for(int i; i < 5; i++)
	{
		printf("\n%d��° �л���,\n���� %d��,\n���� %d��\n",i+1, arr[i].english, arr[i].mathmatics);
		
		
	}
	
	
}
