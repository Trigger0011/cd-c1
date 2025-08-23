#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <stdbool.h>

typedef struct {
    char name[20];
    int hp;
    int attack;
    int gold;
} Character;

typedef struct {
    char name[20];
    int hp;
    int attack;
    int rewardGold;
    bool isBoss;  // ���� ����
} Monster;

void battle(Character *player, Monster *monster, int *potionPower) {
    int choice;
    int monsterHp = monster->hp;

    while (monsterHp > 0 && player->hp > 0) {
        system("cls");

        printf("�÷��̾�: %s | HP: %d | ���ݷ�: %d | ���: %d\n", player->name, player->hp, player->attack, player->gold);
        printf("����: %s | HP: %d\n", monster->name, monsterHp);
        printf("------------------------\n");
        printf("1. ����\n2. ���� ���\n3. ����ġ��\n5. ���� ����\n����: ");
        scanf("%d", &choice);

        system("cls");

        if (choice == 1) {
            bool isCritical = (rand() % 100) < 20;
            int damage = player->attack;

            if (isCritical) {
                damage *= 2;
                printf("ȸ���� �ϰ�! ");
            }

            // ���� ȸ�� Ȯ�� ����
            if (monster->isBoss && (rand() % 100) < 80) {
                printf("%s�� ������ �Ϻ��� ȸ���ߴ�! ���� ����!\n", monster->name);
            } else {
                monsterHp -= damage;
                printf("%s�� ����! -%d\n", monster->name, damage);
            }

        } else if (choice == 2) {
            player->hp += *potionPower;
            printf("���� ���! ü�� +%d ȸ��\n", *potionPower);

        } else if (choice == 3) {
            printf("�����ƴ�! ���� ���ͷ�...\n");
            Sleep(1000);
            return;

        } else if (choice == 5) {
            int shopChoice;
            while (1) {
                printf("\n--- ���� ---\n");
                printf("1. ü�� +20 (30���)\n2. ���ݷ� +5 (40���)\n3. ���� ��ȭ +5 (50���)\n0. ������\n����: ");
                scanf("%d", &shopChoice);

                system("cls");

                if (shopChoice == 1 && player->gold >= 30) {
                    player->hp += 20;
                    player->gold -= 30;
                    printf("ü�� +20! ���� ü��: %d\n", player->hp);
                } else if (shopChoice == 2 && player->gold >= 40) {
                    player->attack += 5;
                    player->gold -= 40;
                    printf("���ݷ� +5! ���� ���ݷ�: %d\n", player->attack);
                } else if (shopChoice == 3 && player->gold >= 50) {
                    *potionPower += 5;
                    player->gold -= 50;
                    printf("���� ��ȭ��! ���� ȸ����: %d\n", *potionPower);
                } else if (shopChoice == 0) {
                    printf("�������� ���Խ��ϴ�.\n");
                    Sleep(700);
                    break;
                } else {
                    printf("��� ���� �Ǵ� �߸��� ����!\n");
                }
                Sleep(700);
            }

        } else {
            printf("�߸��� �����Դϴ�!\n");
            Sleep(700);
            continue;
        }

        if (monsterHp > 0 && choice != 3) {
            player->hp -= monster->attack;
            printf("%s�� �ݰ�! -%d\n", monster->name, monster->attack);
        }

        Sleep(1000);
    }

    if (player->hp <= 0) {
        printf("\n%s�� ���������ϴ�... ���� ����\n", player->name);
        exit(0);
    } else {
        printf("\n%s óġ ����! ��� +%d ȹ��!\n", monster->name, monster->rewardGold);
        player->gold += monster->rewardGold;
        Sleep(1000);
    }
}

int main() {
    srand(time(NULL));
    Character player;
    Monster monsters[] = {
        {"������", 25, 4, 15, false},
        {"���", 35, 6, 25, false},
        {"����", 40, 7, 30, false},
        {"��ũ", 55, 10, 45, false},
        {"������", 50, 12, 50, false},
        {"����", 60, 13, 55, false},
        {"�Ǹ�", 75, 15, 75, false},
        {"��", 80, 16, 80, false},
        {"�巡��", 100, 20, 120, false},
        {"���� �����", 100, 30, 500, true}
    };
    int potionPower = 20;

    printf("�÷��̾� �̸�: ");
    scanf("%s", player.name);
    player.hp = 100;
    player.attack = 10;
    player.gold = 0;

    for (int i = 0; i < 10; i++) {
        battle(&player, &monsters[i], &potionPower);
    }

    printf("\n��� ���͸� óġ�߽��ϴ�! �����մϴ� %s!\n", player.name);
    return 0;
}

