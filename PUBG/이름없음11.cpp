#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<iostream>



int main()
{
	
	int ar1[50][50] = {0};
	int ar2[][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
	int ar3[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
	
	for(int i = 0;i < 50;++i){
		for(int j = 0;j < 50;++j){
			printf("%d ", ar1[i][j]);
		}
		printf("\n");
	}
}
