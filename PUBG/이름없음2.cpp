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
		
		printf("���� ����:");
		scanf("%d",&sub[i]);
		system("cls");
				  }
		
		else if(i == 1){
			printf("���� ����:");
		scanf("%d",&sub[i]);
		system("cls");
		}
		
		else if(i == 2){
			printf("���� ����:");
		scanf("%d",&sub[i]);
		system("cls");
		}
		
		else if(i == 3){
			printf("��ȸ ����:");
		scanf("%d",&sub[i]);
		system("cls");
		}
		
		else if(i == 4){
			printf("���� ����:");
		scanf("%d",&sub[i]);
		system("cls");
		
		else if(i == 5){
			printf("���� ����:");
		scanf("%d",&sub[i]);
		system("cls");
		}
		
		else if(i == 6){
			printf("�̼� ����:");
		scanf("%d",&sub[i]);
		system("cls");
		}
		
		else if(i == 7){
			printf("ü�� ����:");
		scanf("%d",&sub[i]);
		system("cls");
		}
	
	}
	for(i = 0;  i < 7; i ++)
	{
		
		printf("%d\n", sub[i]);
		
	}
}
