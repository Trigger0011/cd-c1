
int MainMenu()
{
	int n;
	
	printf("\t### ��Ģ���� ###\n");
	printf("\t1. ������ ��Ģ����\n");
	printf("\t2. ������ ��Ģ����\n");
	printf("\t3. ����\n");
	printf("�޴��� ����");
	scanf("%d", &n);
	
	return 0;
}

int IntMenu( )
{
	int im;
	
	printf("\t@@ ������ ���� @@\n");
	printf("\t1. ����\n\t2.����\n\t3.����\n\t4.������\n\t5.�ڷ�\n");
	printf("�޴��� ����");
	scanf("%d", &im);
}

int DouMenu( )
{
	int im;
	
	printf("\t@@ �Ǽ��� ���� @@\n");
	printf("\t1. ����\n\t2.����\n\t3.����\n\t4.������\n\t5.�ڷ�\n");
	printf("�޴��� ����");
	scanf("%d", &im);

	return im;
}
