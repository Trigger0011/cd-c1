#include <stdio.h>
#include <conio.h>
#include <windows.h>

#define WIDTH 40
#define HEIGHT 21

char maze[HEIGHT][WIDTH+1] = {
    "########################################",
    "#       #          #       #           #",
    "# ##### # #######    ##### # ####### # #",
    "# #     #       #          #     #   # #",
    "# # ######### # ####### # ##### # ### #",
    "# #         # #       # #     # #     #",
    "# ######### # ####### # ##### # #######",
    "#         # #       # #     #         E#",
    "####### # # ####### # ##### ######### #",
    "#     # # #       # #     #         # #",
    "# ### # # ####### # ##### ######### # #",
    "# #   # #       # #     #         # # #",
    "# # ### ####### # ##### ######### # # #",
    "# #   #       # #     #         # #   #",
    "# ### ####### # ##### ######### # #####",
    "#   #       # #     #         # #     #",
    "### ####### # ##### ######### # ##### #",
    "#         # #     #         # #     # #",
    "# ####### # ##### ######### # ##### # #",
    "#S       #           #        d        #",
	"#######################################",

};

int playerX = 1, playerY = 19; // ���� ��ġ (S ��ġ)

void gotoxy(int x, int y) {
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void drawMaze() {
    for(int y = 0; y < HEIGHT; y++) {
        gotoxy(0, y);
        printf("%s", maze[y]);
    }
}

int main() {
    char ch;

    system("cls");
    drawMaze();

    while(1) {
        gotoxy(playerX, playerY);
        printf("P");
        fflush(stdout);

        ch = _getch();
        int newX = playerX;
        int newY = playerY;

        switch(ch) {
            case 'w': case 'W': newY--; break; // ��
            case 's': case 'S': newY++; break; // �Ʒ�
            case 'a': case 'A': newX--; break; // ����
            case 'd': case 'D': newX++; break; // ������
            case 'q': // q ������ ���� ����
                gotoxy(0, HEIGHT + 2);
                printf("���� ����\n");
                return 0;
        }

        // ��('#') �ƴϸ� �̵�
        if(maze[newY][newX] != '#') {
            gotoxy(playerX, playerY);
            printf(" ");
            playerX = newX;
            playerY = newY;
        }

        // �ⱸ ���� üũ
        if(maze[playerY][playerX] == 'E') {
            gotoxy(0, HEIGHT + 1);
            printf("�ⱸ ����! ������!\n");
            break;
        }
    }

    return 0;
}


