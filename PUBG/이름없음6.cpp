#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
//	int cha;
//	char cha;
//	
//
//	printf("so mun ja dan a reul th t o\n");
	
//	printf("%s",cha);
//	cha  = cha - 32;



	char a[5];
	scanf("%s", &a);
	for(int i = 0; i < sizeof(a)/sizeof(a[0]); i++){
		char cha = a[i] - 32;
		printf("%c", cha);
	}

}
