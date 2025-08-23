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
    int color; // ���� �ڵ�
};

void clearScreen() {
    system("cls");
}

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void printStatus(Player &player, Monster &monster) {
    cout << "=================================\n";

    // �÷��̾� �ʷϻ�
    setColor(10);
    cout << "�÷��̾�: " << player.name << " (���� " << player.level << ")\n";
    setColor(7); // ���� ������ ����

    cout << "ü��: " << player.hp << "/" << player.maxHp << "\n";
    cout << "���ݷ�: " << player.attack << "\n";
    cout << "����: �� (ȸ���� " << player.potionHeal << ")\n";
    cout << "ũ��Ƽ�� Ȯ��: " << player.critChance * 100 << "% | ����: x" << player.critDamage << "\n";
    cout << "���: " << player.gold << "\n";
    cout << "=================================\n";

    setColor(monster.color); // ���� ��
    cout << monster.name << " ü��: " << monster.hp << "\n\n";
    setColor(7); // ����
}

bool attackMonster(Player &player, Monster &monster) {
    int damage = player.attack;
    bool isCrit = (rand() % 100) < (player.critChance * 100);

    if (isCrit) {
        damage = (int)(damage * player.critDamage);
        cout << "ȸ���� �ϰ�! ";
    }

    if ((rand() % 100) < (monster.dodgeChance * 100)) {
        cout << monster.name << "��(��) ������ ȸ���ߴ�!\n";
        return false;
    }

    monster.hp -= damage;
    cout << monster.name << "���� " << damage << " ������!\n";
    return monster.hp <= 0;
}

bool monsterAttack(Player &player, Monster &monster) {
    player.hp -= monster.attack;
    cout << monster.name << "�� ����! " << monster.attack << " ������!\n";
    return player.hp <= 0;
}

void shop(Player &player) {
    int choice;
    while (true) {
        clearScreen();
        cout << "===== ���� =====\n";
        cout << "1. ���ݷ� +5 (2���)\n";
        cout << "2. ���� ȸ���� +5 (2���)\n";
        cout << "3. ũ��Ƽ�� Ȯ�� -5% (5���)\n";
        cout << "4. ũ��Ƽ�� ���� +5 (15���)\n";
        cout << "0. ������\n";
        cout << "���: " << player.gold << "\n����: ";
        cin >> choice;

        if (choice == 0) break;
        if (choice == 1 && player.gold >= 3) { player.attack += 5; player.gold -= 2; }
        else if (choice == 2 && player.gold >= 2) { player.potionHeal += 5; player.gold -= 2; }
        else if (choice == 3 && player.gold >= 5) { player.critChance += 0.05; player.gold -= 5; }
        else if (choice == 4 && player.gold >= 15) { player.critDamage += 5; player.gold -= 15; }
        else { cout << "��尡 �����ϰų� �߸��� ����!\n"; Sleep(1000); }
    }
}

int main() {
    srand((unsigned int)time(NULL));

    Player player;
    cout << "�÷��̾� �̸��� �Է��ϼ���: ";
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
        {"[�̳��� ���� ������ ���ǵ��ϰ� ���������� �Ϳ��� ����� �巡�� ����] ������", 5, 1, 0.9, 14}, // ���
        {"���", 50, 8, 0.0, 2}, // �ʷ�
        {"����", 70, 10, 0.0, 8}, // ȸ��
        {"Ʈ��", 100, 12, 0.0, 6}, // ����
        {"�����", 130, 15, 0.0, 12}, // ����+���
        {"������", 160, 18, 0.0, 13}, // ��ȫ
        {"���", 200, 20, 0.0, 11}, // �Ķ�+���
        {"�巡��", 300, 25, 0.0, 4}, // ����
        {"*[������ ��]* ����", 400, 80, 0.5, 12}, // ����+���
        {"*[������]* ���� �����", 100, 100, 0.8, 9} // �Ķ�
    };

    for (int stage = 0; stage < 10; stage++) {
        Monster monster = monsters[stage];
        while (monster.hp > 0 && player.hp > 0) {
            clearScreen();           
            cout << "\n=== �������� " << stage+1 << " ===\n";
            cout << monster.name << " ����!\n\n";
            printStatus(player, monster);

            cout << "[1] ���� [2] ���� ��� [3] ���� [5] ����\n����: ";
            int choice;
            cin >> choice;

            if (choice == 1) {
                if (attackMonster(player, monster)) {
                    cout << "\n***** " << monster.name << " óġ ����!! *****\n";
                    player.gold += 20 + (stage * 5);
                    player.level++;
                    player.maxHp += 10;
                    player.hp = player.maxHp;
                    Sleep(1500);
                    break;
                }
                if (monsterAttack(player, monster)) {
                    clearScreen();
                    cout << "\n\n\n\n ����� ��������...\n";
                    return 0;
                }
                Sleep(1000);
            }
            else if (choice == 2) {
                player.hp += player.potionHeal;
                if (player.hp > player.maxHp) player.hp = player.maxHp;
                cout << "���� ���! ü�� ȸ��\n";
                Sleep(1000);
                if (monsterAttack(player, monster)) {
                    cout << "����� ��������...\n";
                    return 0;
                }
                Sleep(1000);
            }
            else if (choice == 3) {
                cout << "�����ƴ�!\n";
                Sleep(1000);
                stage--; 
                break;
            }
            else if (choice == 5) {
                shop(player);
            }
            else {
                cout << "�߸��� ����!\n";
                Sleep(1000);
            }
        }
    }

    clearScreen();
    cout << "\n��� ���͸� �����ƴ�! ���� Ŭ����!\n";
    return 0;
}

