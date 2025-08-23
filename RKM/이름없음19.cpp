#include <stdio.h>
#include <conio.h>    // 키보드 입력 함수 _kbhit(), _getch()
#include <windows.h>  // Sleep(), 콘솔 커서 위치 함수
#include <stdlib.h>   // 랜덤 함수
#include <time.h>     // 시간 관련 함수

#define WIDTH 20
#define HEIGHT 10

typedef struct {
    int x, y;
} Point;

// 뱀 몸통 좌표 저장할 배열
Point snake[100];
int snakeLength = 3;      // 뱀 초기 길이
int direction = 0;        // 방향 (0:오른쪽, 1:아래, 2:왼쪽, 3:위)
Point food;               // 먹이 좌표

// 커서를 (x, y) 위치로 이동시키는 함수
void gotoxy(int x, int y) {
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// 화면 테두리 그리기
void drawBorder() {
    for (int i = 0; i <= WIDTH + 1; i++) {
        gotoxy(i, 0);
        printf("#");
        gotoxy(i, HEIGHT + 1);
        printf("#");
    }
    for (int i = 0; i <= HEIGHT + 1; i++) {
        gotoxy(0, i);
        printf("#");
        gotoxy(WIDTH + 1, i);
        printf("#");
    }
}

// 뱀 그리기
void drawSnake() {
    for (int i = 0; i < snakeLength; i++) {
        gotoxy(snake[i].x, snake[i].y);
        if (i == 0) printf("O"); // 머리
        else printf("o");        // 몸통
    }
}

// 먹이 생성 (랜덤 위치)
void generateFood() {
    food.x = rand() % WIDTH + 1;
    food.y = rand() % HEIGHT + 1;
}

// 충돌 검사 (벽, 자기 몸)
int collision() {
    // 벽과 충돌했으면 1 반환
    if (snake[0].x <= 0 || snake[0].x > WIDTH || snake[0].y <= 0 || snake[0].y > HEIGHT) 
        return 1;
    // 자기 몸과 충돌했으면 1 반환
    for (int i = 1; i < snakeLength; i++) {
        if (snake[0].x == snake[i].x && snake[0].y == snake[i].y)
            return 1;
    }
    return 0; // 충돌 없으면 0 반환
}

// 뱀 이동 함수
void moveSnake() {
    // 몸통을 앞부분으로 한 칸씩 이동
    for (int i = snakeLength - 1; i > 0; i--) {
        snake[i] = snake[i - 1];
    }

    // 머리 이동 방향에 따라 좌표 변경
    switch(direction) {
        case 0: snake[0].x++; break; // 오른쪽
        case 1: snake[0].y++; break; // 아래
        case 2: snake[0].x--; break; // 왼쪽
        case 3: snake[0].y--; break; // 위
    }
}

int main() {
    srand(time(NULL));  // 랜덤 초기화

    // 뱀 초기 위치 설정 (가로 5, 세로 5부터 시작)
    snake[0].x = 5; snake[0].y = 5;
    snake[1].x = 4; snake[1].y = 5;
    snake[2].x = 3; snake[2].y = 5;

    generateFood();  // 첫 먹이 생성
    drawBorder();    // 테두리 그리기

    while (1) {
        // 키 입력 체크
        if (_kbhit()) {
            int ch = _getch();

            // 화살표 키 입력 처리 (특수키는 두 번 받음)
            if (ch == 0 || ch == 224) {
                ch = _getch();
                switch(ch) {
                    case 72: if(direction != 1) direction = 3; break; // ↑
                    case 80: if(direction != 3) direction = 1; break; // ↓
                    case 75: if(direction != 0) direction = 2; break; // ←
                    case 77: if(direction != 2) direction = 0; break; // →
                }
            }
        }

        moveSnake();  // 뱀 이동

        if (collision()) {
            gotoxy(0, HEIGHT + 3);
            printf("게임 오버! 점수: %d\n", snakeLength - 3);
            break;
        }

        // 먹이 먹었으면 길이 증가 + 새 먹이 생성
        if (snake[0].x == food.x && snake[0].y == food.y) {
            snakeLength++;
            snake[snakeLength - 1] = snake[snakeLength - 2];  // 새 몸통 생성
            generateFood();
        }

        system("cls");    // 화면 초기화
        drawBorder();     // 테두리 다시 그리기
        drawSnake();      // 뱀 다시 그리기

        // 먹이 위치에 @ 표시
        gotoxy(food.x, food.y);
        printf("@");

        Sleep(150);       // 게임 속도 조절
    }

    return 0;
}

