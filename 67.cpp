#include <stdio.h>
#include <windows.h>

void GotoXY(int x, int y);


int main()
{
	
	char ch1[3] = "¢¼", ch2[3] = "¢À" ;
	int i, check = 1;
	
	for(i = 1; i < 40; i+= 2)
	{
		GotoXY(i, 5);
		if (check == 1)
		{
			printf("%s", ch1);
			check = 0;
		}
		else
		{
			printf("%s", ch2);
			check = 1;
		}
		Sleep(150);
		GotoXY(i, 5);
		printf(" ");
	}
	printf("\n");
}

void GotoXY(int x, int y)
{
	COORD Pos = {x - 1, y - 1};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
}
