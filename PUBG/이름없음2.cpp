#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
	
	
	int i;
	int sub[8];
	
	
	for(i = 0;  i < 7; i ++)
	{
		if(i == 0){
		
		printf("국어 진도:");
		scanf("%d",&sub[i]);
		system("cls");
				  }
		
		else if(i == 1){
			printf("영어 진도:");
		scanf("%d",&sub[i]);
		system("cls");
		}
		
		else if(i == 2){
			printf("수학 진도:");
		scanf("%d",&sub[i]);
		system("cls");
		}
		
		else if(i == 3){
			printf("사회 진도:");
		scanf("%d",&sub[i]);
		system("cls");
		}
		
		else if(i == 4){
			printf("과학 진도:");
		scanf("%d",&sub[i]);
		system("cls");
		
		else if(i == 5){
			printf("음악 진도:");
		scanf("%d",&sub[i]);
		system("cls");
		}
		
		else if(i == 6){
			printf("미술 진도:");
		scanf("%d",&sub[i]);
		system("cls");
		}
		
		else if(i == 7){
			printf("체육 진도:");
		scanf("%d",&sub[i]);
		system("cls");
		}
	
	}
	for(i = 0;  i < 7; i ++)
	{
		
		printf("%d\n", sub[i]);
		
	}
}
