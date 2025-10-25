#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<ctime>
#include<iostream>
using namespace std;


struct scan {
	
	char aname[10];
	int agrade;
	double aheight;
	int clas;
};

int main()
{
	struct scan p;
	
	printf("이름 입력:");
	scanf("%s", &p.aname);
	printf("학년 입력:");
	scanf("%d", &p.agrade);
	printf("반 입력:");
	scanf("%d", &p.clas);
	printf("키 입력:");
	scanf("%d", &p.aheight);
	
	system("cls");
	
	printf("%s님,\n", p.aname);
	printf("%d학년%d반\n", p.agrade, p.clas);
	printf("%dcm", p.aheight);
		
		
}
	
	
	

