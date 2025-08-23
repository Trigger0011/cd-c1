#include<stdio.h>
int main()
{
	int ts;
	int Ts;
	
	printf("점수 입력\n\n");
	scanf("      %d", &ts);
	
	Ts = ts / 10;
	
	if(Ts <= 10 && Ts >= 9){
		
		printf("A");
		
	}
			
	else if	(Ts < 9 && Ts >= 8){
		
		printf("B");
		
	}
	
	else if	(Ts < 8 && Ts >= 7){
		
		printf("C");
		
	}
	
	else if	(Ts < 7 && Ts >= 6){
		
		printf("D");
	}
		
	else{
		printf("F");
		
		
	}	
	
}
