#include <stdio.h>
#include <conio.h>    // Ű���� �Է� �Լ� _kbhit(), _getch()
#include <windows.h>  // Sleep(), �ܼ� Ŀ�� ��ġ �Լ�
#include <stdlib.h>   // ���� �Լ�
#include <time.h>     // �ð� ���� �Լ�

#define WIDTH 20
#define HEIGHT 10

typedef struct {
    int x, y;
} Point;

// �� ���� ��ǥ ������ �迭
Point snake[100];
int snakeLength = 3;      // �� �ʱ� ����
int direction = 0;        // ���� (0:������, 1:�Ʒ�, 2:����, 3:��)
Point food;               // ���� ��ǥ

// Ŀ���� (x, y) ��ġ�� �̵���Ű�� �Լ�
void gotoxy(int x, int y) {
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// ȭ�� �׵θ� �׸���
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

// �� �׸���
void drawSnake() {
    for (int i = 0; i < snakeLength; i++) {
        gotoxy(snake[i].x, snake[i].y);
        if (i == 0) printf("O"); // �Ӹ�
        else printf("o");        // ����
    }
}

// ���� ���� (���� ��ġ)
void generateFood() {
    food.x = rand() % WIDTH + 1;
    food.y = rand() % HEIGHT + 1;
}

// �浹 �˻� (��, �ڱ� ��)
int collision() {
    // ���� �浹������ 1 ��ȯ
    if (snake[0].x <= 0 || snake[0].x > WIDTH || snake[0].y <= 0 || snake[0].y > HEIGHT) 
        return 1;
    // �ڱ� ���� �浹������ 1 ��ȯ
    for (int i = 1; i < snakeLength; i++) {
        if (snake[0].x == snake[i].x && snake[0].y == snake[i].y)
            return 1;
    }
    return 0; // �浹 ������ 0 ��ȯ
}

// �� �̵� �Լ�
void moveSnake() {
    // ������ �պκ����� �� ĭ�� �̵�
    for (int i = snakeLength - 1; i > 0; i--) {
        snake[i] = snake[i - 1];
    }

    // �Ӹ� �̵� ���⿡ ���� ��ǥ ����
    switch(direction) {
        case 0: snake[0].x++; break; // ������
        case 1: snake[0].y++; break; // �Ʒ�
        case 2: snake[0].x--; break; // ����
        case 3: snake[0].y--; break; // ��
    }
}

int main() {
    srand(time(NULL));  // ���� �ʱ�ȭ

    // �� �ʱ� ��ġ ���� (���� 5, ���� 5���� ����)
    snake[0].x = 5; snake[0].y = 5;
    snake[1].x = 4; snake[1].y = 5;
    snake[2].x = 3; snake[2].y = 5;

    generateFood();  // ù ���� ����
    drawBorder();    // �׵θ� �׸���

    while (1) {
        // Ű �Է� üũ
        if (_kbhit()) {
            int ch = _getch();

            // ȭ��ǥ Ű �Է� ó�� (Ư��Ű�� �� �� ����)
            if (ch == 0 || ch == 224) {
                ch = _getch();
                switch(ch) {
                    case 72: if(direction != 1) direction = 3; break; // ��
                    case 80: if(direction != 3) direction = 1; break; // ��
                    case 75: if(direction != 0) direction = 2; break; // ��
                    case 77: if(direction != 2) direction = 0; break; // ��
                }
            }
        }

        moveSnake();  // �� �̵�

        if (collision()) {
            gotoxy(0, HEIGHT + 3);
            printf("���� ����! ����: %d\n", snakeLength - 3);
            break;
        }

        // ���� �Ծ����� ���� ���� + �� ���� ����
        if (snake[0].x == food.x && snake[0].y == food.y) {
            snakeLength++;
            snake[snakeLength - 1] = snake[snakeLength - 2];  // �� ���� ����
            generateFood();
        }

        system("cls");    // ȭ�� �ʱ�ȭ
        drawBorder();     // �׵θ� �ٽ� �׸���
        drawSnake();      // �� �ٽ� �׸���

        // ���� ��ġ�� @ ǥ��
        gotoxy(food.x, food.y);
        printf("@");

        Sleep(150);       // ���� �ӵ� ����
    }

    return 0;
}

