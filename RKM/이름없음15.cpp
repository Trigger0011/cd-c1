#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define DIGITS 2  // 자리수 2자리로 줄임

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

    printf("숫자 야구 게임 시작! 2자리 숫자 맞춰봐 (중복 숫자 없음)\n");

    while (1) {
        strikes = 0;
        balls = 0;
        matched = 0;

        printf("숫자 입력: ");
        scanf("%s", input);

        if (strlen(input) != DIGITS) {
            printf("%d자리 숫자를 입력해야 합니다!\n", DIGITS);
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
            printf("숫자만 입력하세요!\n");
            continue;
        }

        // 스트라이크, 볼 계산
        for (int i = 0; i < DIGITS; i++) {
            for (int j = 0; j < DIGITS; j++) {
                if (guess[i] == answer[j]) {
                    matched++;
                    if (i == j) strikes++;
                    else balls++;
                }
            }
        }

        printf("%d 스트라이크, %d 볼\n", strikes, balls);
        printf("맞는 숫자 개수: %d\n", matched);

        if (strikes == DIGITS) {
            printf("정답! 게임 클리어!\n");
            break;
        }
    }

    return 0;
}

