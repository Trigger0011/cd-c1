#include<stdio.h>
int main()
{
	int num;
	int sum = 0;
	int numnum = 0;
	
	int gab;
	
	printf("100 �̻��� �ڿ��� �Է��ϱ�\n");
	scanf("%d", &num);
	
	
	
	while(numnum <= num){
		
		numnum++;
		if(numnum % 3 == 0 || numnum % 7 == 0){
			
			gab++;
			sum = numnum + sum;
		}
		
	}
	printf("%d\n", gab);
	printf("%d", sum);









}




