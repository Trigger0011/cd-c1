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

int playerX = 1, playerY = 19; // 시작 위치 (S 위치)

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
            case 'w': case 'W': newY--; break; // 위
            case 's': case 'S': newY++; break; // 아래
            case 'a': case 'A': newX--; break; // 왼쪽
            case 'd': case 'D': newX++; break; // 오른쪽
            case 'q': // q 누르면 게임 종료
                gotoxy(0, HEIGHT + 2);
                printf("게임 종료\n");
                return 0;
        }

        // 벽('#') 아니면 이동
        if(maze[newY][newX] != '#') {
            gotoxy(playerX, playerY);
            printf(" ");
            playerX = newX;
            playerY = newY;
        }

        // 출구 도착 체크
        if(maze[playerY][playerX] == 'E') {
            gotoxy(0, HEIGHT + 1);
            printf("출구 도착! 축하해!\n");
            break;
        }
    }

    return 0;
}


