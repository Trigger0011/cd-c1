#include<unistd.h>
#include<stdio.h>
int main(){
	int i;
	int n;
	int sum; 
	
	for(n = 1; n <= 10; n++){
	
		
		
		for( i = 1; i <= n; i++){
		
		
		
		printf("%d ", i);
		sum = sum + i;
		
		}
		
		printf("\n");
		
	}
	printf("%d", sum);
	
	
}
