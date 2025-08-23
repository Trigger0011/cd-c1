#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define DIGITS 2  // �ڸ��� 2�ڸ��� ����

void generateNumber(int num[DIGITS]) {
    int used[10] = {0};
    for (int i = 0; i < DIGITS; ) {
        int digit = rand() % 10;
        if (!used[digit]) {
            num[i] = digit;
            used[digit] = 1;
            i++;
        }
    }
}

int main() {
    int answer[DIGITS];
    int guess[DIGITS];
    int strikes, balls, matched;
    char input[10];

    srand(time(NULL));
    generateNumber(answer);

    printf("���� �߱� ���� ����! 2�ڸ� ���� ����� (�ߺ� ���� ����)\n");

    while (1) {
        strikes = 0;
        balls = 0;
        matched = 0;

        printf("���� �Է�: ");
        scanf("%s", input);

        if (strlen(input) != DIGITS) {
            printf("%d�ڸ� ���ڸ� �Է��ؾ� �մϴ�!\n", DIGITS);
            continue;
        }

        int valid = 1;
        for (int i = 0; i < DIGITS; i++) {
            if (input[i] < '0' || input[i] > '9') {
                valid = 0;
                break;
            }
            guess[i] = input[i] - '0';
        }
        if (!valid) {
            printf("���ڸ� �Է��ϼ���!\n");
            continue;
        }

        // ��Ʈ����ũ, �� ���
        for (int i = 0; i < DIGITS; i++) {
            for (int j = 0; j < DIGITS; j++) {
                if (guess[i] == answer[j]) {
                    matched++;
                    if (i == j) strikes++;
                    else balls++;
                }
            }
        }

        printf("%d ��Ʈ����ũ, %d ��\n", strikes, balls);
        printf("�´� ���� ����: %d\n", matched);

        if (strikes == DIGITS) {
            printf("����! ���� Ŭ����!\n");
            break;
        }
    }

    return 0;
}

