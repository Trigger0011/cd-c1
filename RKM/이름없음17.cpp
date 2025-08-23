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
    bool isBoss;  // 보스 여부
} Monster;

void battle(Character *player, Monster *monster, int *potionPower) {
    int choice;
    int monsterHp = monster->hp;

    while (monsterHp > 0 && player->hp > 0) {
        system("cls");

        printf("플레이어: %s | HP: %d | 공격력: %d | 골드: %d\n", player->name, player->hp, player->attack, player->gold);
        printf("몬스터: %s | HP: %d\n", monster->name, monsterHp);
        printf("------------------------\n");
        printf("1. 공격\n2. 포션 사용\n3. 도망치기\n5. 상점 열기\n선택: ");
        scanf("%d", &choice);

        system("cls");

        if (choice == 1) {
            bool isCritical = (rand() % 100) < 20;
            int damage = player->attack;

            if (isCritical) {
                damage *= 2;
                printf("회심의 일격! ");
            }

            // 보스 회피 확률 적용
            if (monster->isBoss && (rand() % 100) < 80) {
                printf("%s가 공격을 완벽히 회피했다! 피해 없음!\n", monster->name);
            } else {
                monsterHp -= damage;
                printf("%s를 공격! -%d\n", monster->name, damage);
            }

        } else if (choice == 2) {
            player->hp += *potionPower;
            printf("포션 사용! 체력 +%d 회복\n", *potionPower);

        } else if (choice == 3) {
            printf("도망쳤다! 다음 몬스터로...\n");
            Sleep(1000);
            return;

        } else if (choice == 5) {
            int shopChoice;
            while (1) {
                printf("\n--- 상점 ---\n");
                printf("1. 체력 +20 (30골드)\n2. 공격력 +5 (40골드)\n3. 포션 강화 +5 (50골드)\n0. 나가기\n선택: ");
                scanf("%d", &shopChoice);

                system("cls");

                if (shopChoice == 1 && player->gold >= 30) {
                    player->hp += 20;
                    player->gold -= 30;
                    printf("체력 +20! 현재 체력: %d\n", player->hp);
                } else if (shopChoice == 2 && player->gold >= 40) {
                    player->attack += 5;
                    player->gold -= 40;
                    printf("공격력 +5! 현재 공격력: %d\n", player->attack);
                } else if (shopChoice == 3 && player->gold >= 50) {
                    *potionPower += 5;
                    player->gold -= 50;
                    printf("포션 강화됨! 현재 회복량: %d\n", *potionPower);
                } else if (shopChoice == 0) {
                    printf("상점에서 나왔습니다.\n");
                    Sleep(700);
                    break;
                } else {
                    printf("골드 부족 또는 잘못된 선택!\n");
                }
                Sleep(700);
            }

        } else {
            printf("잘못된 선택입니다!\n");
            Sleep(700);
            continue;
        }

        if (monsterHp > 0 && choice != 3) {
            player->hp -= monster->attack;
            printf("%s의 반격! -%d\n", monster->name, monster->attack);
        }

        Sleep(1000);
    }

    if (player->hp <= 0) {
        printf("\n%s는 쓰러졌습니다... 게임 오버\n", player->name);
        exit(0);
    } else {
        printf("\n%s 처치 성공! 골드 +%d 획득!\n", monster->name, monster->rewardGold);
        player->gold += monster->rewardGold;
        Sleep(1000);
    }
}

int main() {
    srand(time(NULL));
    Character player;
    Monster monsters[] = {
        {"슬라임", 25, 4, 15, false},
        {"고블린", 35, 6, 25, false},
        {"늑대", 40, 7, 30, false},
        {"오크", 55, 10, 45, false},
        {"마법사", 50, 12, 50, false},
        {"좀비", 60, 13, 55, false},
        {"악마", 75, 15, 75, false},
        {"골렘", 80, 16, 80, false},
        {"드래곤", 100, 20, 120, false},
        {"고죠 사토루", 100, 30, 500, true}
    };
    int potionPower = 20;

    printf("플레이어 이름: ");
    scanf("%s", player.name);
    player.hp = 100;
    player.attack = 10;
    player.gold = 0;

    for (int i = 0; i < 10; i++) {
        battle(&player, &monsters[i], &potionPower);
    }

    printf("\n모든 몬스터를 처치했습니다! 축하합니다 %s!\n", player.name);
    return 0;
}

