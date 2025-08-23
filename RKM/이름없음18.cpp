#include<stdio.h>
int main(){
	
	int a;
	int b;
	int c;
	int d;
	
	
	int A;
	int B;
	int C;
	int D;
	
	printf("정수 4개를 입력해주세요.");
	scanf("%d %d %d %d", &a, &b, &c, &d);
	
	if(a % 2 == 1)
	{
		int A = a;	
	}
	else{
		int A = 0;
		
	}
	
	if(b % 2 == 1)
	{
		int B = b;	
	}
	else{
		int B = 0;
		
	}
	if(c % 2 == 1)
	{
		int C = c;	
	}
	else{
		int C = 0;
		
	}
	if(d % 2 == 1)
	{
		int D = d;	
	}
	else{
		int D = 0;
		
	} 
	 printf("%d",A+B+C+D);



}

