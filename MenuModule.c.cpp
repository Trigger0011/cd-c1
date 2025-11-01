
int MainMenu()
{
	int n;
	
	printf("\t### 사칙연산 ###\n");
	printf("\t1. 정수형 사칙연산\n");
	printf("\t2. 정수형 사칙연산\n");
	printf("\t3. 종료\n");
	printf("메뉴를 선텍");
	scanf("%d", &n);
	
	return 0;
}

int IntMenu( )
{
	int im;
	
	printf("\t@@ 정수형 계산기 @@\n");
	printf("\t1. 덧셈\n\t2.뺄셈\n\t3.곱셈\n\t4.나눗셈\n\t5.뒤로\n");
	printf("메뉴를 선텍");
	scanf("%d", &im);
}

int DouMenu( )
{
	int im;
	
	printf("\t@@ 실수형 계산기 @@\n");
	printf("\t1. 덧셈\n\t2.뺄셈\n\t3.곱셈\n\t4.나눗셈\n\t5.뒤로\n");
	printf("메뉴를 선텍");
	scanf("%d", &im);

	return im;
}
