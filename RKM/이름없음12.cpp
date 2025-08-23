#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int answer, guess, tries = 0;

    srand(time(NULL)); // 랜덤 시드 설정
    answer = rand() % 100 + 1; // 1 ~ 100 사이 숫자 생성

    printf("=== 업다운 게임 ===\n");

    do {
        printf("숫자를 입력하세요 (1~100): ");
        scanf("%d", &guess);
        tries++;

        if (guess > answer) {
            printf("Down!\n");
        } else if (guess < answer) {
            printf("Up!\n");
        } else {
            printf("정답! %d번 만에 맞췄어요!\n", tries);
        }

    } while (guess != answer);

    return 0;
}



