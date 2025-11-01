#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <stdio.h>

using namespace std;
int a;
struct Player {
    string name;
    int hp;
    int maxHp;
    int attack;
    int protect; 
    int maxprotect; 
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
    cout << "����: " << player.protect << "\n";
    cout << "���� ȸ����:" << player.potionHeal << "\n";
    cout << "ũ��Ƽ�� Ȯ��: " << player.critChance * 100 << "% | ����: x" << player.critDamage << "\n";
    cout << "���: " << player.gold << "\n";
    cout << "@#$%?^%#@?# :" << a << "\n";
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
    cout << monster.name << "���� " << damage << " �������� ������!\n";
    return monster.hp <= 0;
}

bool monsterAttack(Player &player, Monster &monster) {
    player.hp -= monster.attack - player.protect;
    cout << monster.name << "�� ����! " << monster.attack - player.protect << " �������� �޾Ҵ�!\n";
    return player.hp <= 0;  
}

void shop(Player &player) {
    int choice;
    while (true) {
        clearScreen();
        cout << "===== ���� =====\n";
        cout << "1. ���ݷ� +5 (3���)\n";
		cout << "2. ���� ȸ���� +5 (2���)\n";
        cout << "3. ũ��Ƽ�� Ȯ�� +50% (5���)\n";
        cout << "4. ũ��Ƽ�� ���� X2 (15���)\n";
        cout << "5. @#$%?^%#@?#	(100���)\n";
        cout << "6. ���� +1 {�ִ� 100} (10���)\n";
		cout << "0. ������\n";
        cout << "���: " << player.gold << "\n����: ";
        cin >> choice;

        if (choice == 0) break;
        if (choice == 1 && player.gold >= 3) { player.attack += 5; player.gold -= 3; }
        else if (choice == 2 && player.gold >= 2) { player.potionHeal += 5; player.gold -= 2; }
        else if (choice == 3 && player.gold >= 5) { player.critChance += 0.5; player.gold -= 5; }
        else if (choice == 4 && player.gold >= 15) { player.critDamage += 2; player.gold -= 15; }
        else if (choice == 5 && player.gold >= 100) { a += 1; player.gold -= 100; }
        else if (choice == 6 && player.gold >= 10 && player.maxprotect > player.protect) { player.protect += 1; player.gold -= 10; }
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
    player.maxprotect = 100;
	player.protect = 0;
	player.gold = 25;
    player.potionHeal = 20;
    player.level = 1;
    player.critChance = 0;
    player.critDamage = 1.5;
	a = 0;
	
    Monster monsters[10] = {
        //1 
		{"�̳��� ������ ��� ������ �����ϰ� ��û���� ���������ϰ� ��@���ϰ� ������ ���̳��� ���ǵ��ϰ� �Ϳ��� ����� �巡�� ���� ������", 5, 15, 0.9, 4}, // ���
        {"���", 50, 8, 0.0, 2}, // �ʷ� 2
        {"����", 70, 10, 0.0, 8}, // ȸ�� 3
        {"Ʈ��", 100, 12, 0.0, 6}, // ���� 4
        {"[*��� ����Ʈ*] �������", 130, 15, 0.0, 14}, // ����+��� 5
        {"������", 160, 18, 0.0, 13}, // ��ȫ 6
        {"���", 200, 20, 0.0, 11}, // �Ķ�+��� 7
        {"*[������ ��]* | ����", 400, 200, 0.5, 12}, // ����+��� 8
        {"*[������]* | ���� �����", 1000, 100, 0.8, 9},// �Ķ� 9
		{"[$#$%@#$] @#$?%#@?$", 99999999, 99999999, 0.0, 4} // ���� 10
	
    };

    for (int stage = 0; stage < 10; stage++) {
        Monster monster = monsters[stage];
        while (monster.hp > 0 && player.hp > 0) {
            clearScreen();           
            cout << "\n=== �������� " << stage+1 << " ===\n";
            cout << monster.name << " ����!\n\n";
            printStatus(player, monster);

            cout << "[1] ���� [2] ��� [3] ���� ���  [4] @#$%?^%#@?# [5] ����\n����: ";
            int choice;
            cin >> choice;
			
            if (choice == 1) {
                if (attackMonster(player, monster)) {
                    cout << "\n***** " << monster.name << " óġ ����!! *****\n";
                    player.gold += 20 + (stage * 5);
                    player.level++;
                    player.maxHp += 25;
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
            else if (choice == 6)
            {
            	player.gold += 50; 
            	
			}
			else if (choice == 3) {
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
            else if (choice == 2) {
                cout << "���!!\n";
                Sleep(1000);
                stage--; 
                break;
            }
            else if (choice == 4) {
                if(a > 0)
                {
                	
                	Sleep(1000);
                	if (monster.name == "[$#$%@#$] @#$?%#@?$")
					{
                		cout << "@#$%?^%#@?# ���! @#$%?^%#@?#�� ȿ���� �����ߴ�!";
                		player.attack = 999999999;
                		player.maxHp = 999999999;
                		player.hp = 999999999;
					}
					else
					{
						
						printf("[�����տ��� ����϶� �����ִ�.]");
						Sleep(2000);
						system("cls");
						
					}
				}
				 
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
	
    //clearScreen();
    system("cls");
    cout << "\n��� ���͸� �����ƴ�! ���� Ŭ����!\n";
    return 0;
}

