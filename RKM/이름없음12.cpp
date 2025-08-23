#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int answer, guess, tries = 0;

    srand(time(NULL)); // ���� �õ� ����
    answer = rand() % 100 + 1; // 1 ~ 100 ���� ���� ����

    printf("=== ���ٿ� ���� ===\n");

    do {
        printf("���ڸ� �Է��ϼ��� (1~100): ");
        scanf("%d", &guess);
        tries++;

        if (guess > answer) {
            printf("Down!\n");
        } else if (guess < answer) {
            printf("Up!\n");
        } else {
            printf("����! %d�� ���� ������!\n", tries);
        }

    } while (guess != answer);

    return 0;
}



