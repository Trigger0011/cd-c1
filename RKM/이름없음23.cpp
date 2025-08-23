#include<stdio.h>
int main()
{
	int n;
	int sk;
	
	printf("수 1개 입력하세요.\n");
	scanf("%d", &n);
	printf("그 수를 나눌 수를 입력하세요.");
	scanf("%d", &sk);
	int sum = n/sk;
	printf("답은...%d!", sum);
	
	
}
