#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int userChoice, compChoice;
    char *choices[] = {"����", "����", "��"};

    srand(time(NULL));

    printf("���������� ���� ����!\n");
    while (1) {
        printf("\n����(0), ����(1), ��(2) �߿��� �����ϼ��� (-1 �Է� �� ����): ");
        scanf("%d", &userChoice);

        if (userChoice == -1) {
            printf("���� ����!\n");
            break;
        }

        if (userChoice < 0 || userChoice > 2) {
            printf("�߸��� �Է��Դϴ�. �ٽ� �Է��ϼ���.\n");
            continue;
        }

        compChoice = rand() % 3;

        printf("��: %s, ��ǻ��: %s\n", choices[userChoice], choices[compChoice]);

        if (userChoice == compChoice) {
            printf("����!\n");
        } else if ((userChoice + 1) % 3 == compChoice) {
            printf("���٤Ф�\n");
        } else {
            printf("�̰��! ¦¦\n");
        }
    }

    return 0;
}

