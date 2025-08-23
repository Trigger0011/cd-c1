#include<stdio.h>
int main()
{
	int num;
	int sum = 0;
	int numnum = 0;
	int nigger;
	int gab;
	
	printf("100 이상의 자연수 입력하기\n");
	scanf("%d", &num);
	
	
	
	while(numnum <= num){
		
		numnum++;
		if(numnum % 3 == 0 || numnum % 7 == 0){
			
			gab++;
			sum = numnum + sum;
		}
		
	}
	printf("\n\n%d\n\n", gab);
	printf("\n\n%d\n\n", sum);
}
