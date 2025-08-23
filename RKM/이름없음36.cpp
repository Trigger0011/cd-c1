#include<stdio.h>
#include<unistd.h>
int main(){
	
	
	
	int a;
	
	printf("===== TIMER =====\n\n");
	printf("시간 입력:");
	scanf("%d", &a);
	
	printf("===== TIMER START =====\n\n");
	sleep(a);
	
	printf("\n\n===== TIMER OVER =====");
	
}
