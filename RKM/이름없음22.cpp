#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

struct Player {
    string name;
    int hp;
    int maxHp;
    int attack;
    int gold;
    int potionHeal;
    int level;
    double critChance;
    double critDamage;
};

struct Monster {
    string name;
    int hp;
    int attack;
    double dodgeChance;
    int color; // 색깔 코드
};

void clearScreen() {
    system("cls");
}

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void printStatus(Player &player, Monster &monster) {
    cout << "=================================\n";

    // 플레이어 초록색
    setColor(10);
    cout << "플레이어: " << player.name << " (레벨 " << player.level << ")\n";
    setColor(7); // 원래 색으로 복원

    cout << "체력: " << player.hp << "/" << player.maxHp << "\n";
    cout << "공격력: " << player.attack << "\n";
    cout << "포션: ∞ (회복량 " << player.potionHeal << ")\n";
    cout << "크리티컬 확률: " << player.critChance * 100 << "% | 배율: x" << player.critDamage << "\n";
    cout << "골드: " << player.gold << "\n";
    cout << "=================================\n";

    setColor(monster.color); // 몬스터 색
    cout << monster.name << " 체력: " << monster.hp << "\n\n";
    setColor(7); // 복원
}

bool attackMonster(Player &player, Monster &monster) {
    int damage = player.attack;
    bool isCrit = (rand() % 100) < (player.critChance * 100);

    if (isCrit) {
        damage = (int)(damage * player.critDamage);
        cout << "회심의 일격! ";
    }

    if ((rand() % 100) < (monster.dodgeChance * 100)) {
        cout << monster.name << "이(가) 공격을 회피했다!\n";
        return false;
    }

    monster.hp -= damage;
    cout << monster.name << "에게 " << damage << " 데미지!\n";
    return monster.hp <= 0;
}

bool monsterAttack(Player &player, Monster &monster) {
    player.hp -= monster.attack;
    cout << monster.name << "의 공격! " << monster.attack << " 데미지!\n";
    return player.hp <= 0;
}

void shop(Player &player) {
    int choice;
    while (true) {
        clearScreen();
        cout << "===== 상점 =====\n";
        cout << "1. 공격력 +5 (2골드)\n";
        cout << "2. 포션 회복량 +5 (2골드)\n";
        cout << "3. 크리티컬 확률 -5% (5골드)\n";
        cout << "4. 크리티컬 배율 +5 (15골드)\n";
        cout << "0. 나가기\n";
        cout << "골드: " << player.gold << "\n선택: ";
        cin >> choice;

        if (choice == 0) break;
        if (choice == 1 && player.gold >= 3) { player.attack += 5; player.gold -= 2; }
        else if (choice == 2 && player.gold >= 2) { player.potionHeal += 5; player.gold -= 2; }
        else if (choice == 3 && player.gold >= 5) { player.critChance += 0.05; player.gold -= 5; }
        else if (choice == 4 && player.gold >= 15) { player.critDamage += 5; player.gold -= 15; }
        else { cout << "골드가 부족하거나 잘못된 선택!\n"; Sleep(1000); }
    }
}

int main() {
    srand((unsigned int)time(NULL));

    Player player;
    cout << "플레이어 이름을 입력하세요: ";
    cin >> player.name;
    player.hp = 100;
    player.maxHp = 100;
    player.attack = 10;
    player.gold = 10;
    player.potionHeal = 20;
    player.level = 1;
    player.critChance = 1;
    player.critDamage = 1.5;

    Monster monsters[10] = {
        {"[겁나게 빠른 슉슈슉 스피드하고 엘레강스한 귀여운 고양이 드래곤 마왕] 슬라임", 5, 1, 0.9, 14}, // 노랑
        {"고블린", 50, 8, 0.0, 2}, // 초록
        {"늑대", 70, 10, 0.0, 8}, // 회색
        {"트롤", 100, 12, 0.0, 6}, // 보라
        {"오우거", 130, 15, 0.0, 12}, // 빨강+흰색
        {"마법사", 160, 18, 0.0, 13}, // 분홍
        {"기사", 200, 20, 0.0, 11}, // 파랑+흰색
        {"드래곤", 300, 25, 0.0, 4}, // 빨강
        {"*[저주의 왕]* 스쿠나", 400, 80, 0.5, 12}, // 빨강+흰색
        {"*[무하한]* 고죠 사토루", 100, 100, 0.8, 9} // 파랑
    };

    for (int stage = 0; stage < 10; stage++) {
        Monster monster = monsters[stage];
        while (monster.hp > 0 && player.hp > 0) {
            clearScreen();           
            cout << "\n=== 스테이지 " << stage+1 << " ===\n";
            cout << monster.name << " 등장!\n\n";
            printStatus(player, monster);

            cout << "[1] 공격 [2] 포션 사용 [3] 도망 [5] 상점\n선택: ";
            int choice;
            cin >> choice;

            if (choice == 1) {
                if (attackMonster(player, monster)) {
                    cout << "\n***** " << monster.name << " 처치 성공!! *****\n";
                    player.gold += 20 + (stage * 5);
                    player.level++;
                    player.maxHp += 10;
                    player.hp = player.maxHp;
                    Sleep(1500);
                    break;
                }
                if (monsterAttack(player, monster)) {
                    clearScreen();
                    cout << "\n\n\n\n 당신은 쓰러졌다...\n";
                    return 0;
                }
                Sleep(1000);
            }
            else if (choice == 2) {
                player.hp += player.potionHeal;
                if (player.hp > player.maxHp) player.hp = player.maxHp;
                cout << "포션 사용! 체력 회복\n";
                Sleep(1000);
                if (monsterAttack(player, monster)) {
                    cout << "당신은 쓰러졌다...\n";
                    return 0;
                }
                Sleep(1000);
            }
            else if (choice == 3) {
                cout << "도망쳤다!\n";
                Sleep(1000);
                stage--; 
                break;
            }
            else if (choice == 5) {
                shop(player);
            }
            else {
                cout << "잘못된 선택!\n";
                Sleep(1000);
            }
        }
    }

    clearScreen();
    cout << "\n모든 몬스터를 물리쳤다! 게임 클리어!\n";
    return 0;
}

