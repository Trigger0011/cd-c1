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
	
	printf("�̸� �Է�:");
	scanf("%s", &p.aname);
	printf("�г� �Է�:");
	scanf("%d", &p.agrade);
	printf("�� �Է�:");
	scanf("%d", &p.clas);
	printf("Ű �Է�:");
	scanf("%d", &p.aheight);
	
	system("cls");
	
	printf("%s��,\n", p.aname);
	printf("%d�г�%d��\n", p.agrade, p.clas);
	printf("%dcm", p.aheight);
		
		
}
	
	
	

