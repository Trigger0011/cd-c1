#include <stdio.h>
int main()
{
	
	int n;
	int m;
	
	printf("��¥ �Է�:");
	scanf("%d", &n);
	
	m = n % 7;
	

		switch(m)
		{
			case 1:
			
				printf("�����");
				break;
			
			
			case 0:
				printf("�ݿ���");
				break;
				
				
			case 6:
			
				printf("�����");
				break;
			
			
			case 5:
				printf("������");
				break;
			
			case 4:
			
				printf("ȭ����");
				break;
			
			
			case 3:
				printf("������");
				break;
			
			case 2:
			
				printf("������");
				break;
			
			
			
		}
		

}
