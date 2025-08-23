#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int userChoice, compChoice;
    char *choices[] = {"가위", "바위", "보"};

    srand(time(NULL));

    printf("가위바위보 게임 시작!\n");
    while (1) {
        printf("\n가위(0), 바위(1), 보(2) 중에서 선택하세요 (-1 입력 시 종료): ");
        scanf("%d", &userChoice);

        if (userChoice == -1) {
            printf("게임 종료!\n");
            break;
        }

        if (userChoice < 0 || userChoice > 2) {
            printf("잘못된 입력입니다. 다시 입력하세요.\n");
            continue;
        }

        compChoice = rand() % 3;

        printf("너: %s, 컴퓨터: %s\n", choices[userChoice], choices[compChoice]);

        if (userChoice == compChoice) {
            printf("비겼다!\n");
        } else if ((userChoice + 1) % 3 == compChoice) {
            printf("졌다ㅠㅠ\n");
        } else {
            printf("이겼다! 짝짝\n");
        }
    }

    return 0;
}

