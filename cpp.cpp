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
    cout << "방어력: " << player.protect << "\n";
    cout << "포션 회복량:" << player.potionHeal << "\n";
    cout << "크리티컬 확률: " << player.critChance * 100 << "% | 배율: x" << player.critDamage << "\n";
    cout << "골드: " << player.gold << "\n";
    cout << "@#$%?^%#@?# :" << a << "\n";
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
    cout << monster.name << "에게 " << damage << " 데미지를 입혔다!\n";
    return monster.hp <= 0;
}

bool monsterAttack(Player &player, Monster &monster) {
    player.hp -= monster.attack - player.protect;
    cout << monster.name << "의 공격! " << monster.attack - player.protect << " 데미지를 받았다!\n";
    return player.hp <= 0;  
}

void shop(Player &player) {
    int choice;
    while (true) {
        clearScreen();
        cout << "===== 상점 =====\n";
        cout << "1. 공격력 +5 (3골드)\n";
		cout << "2. 포션 회복량 +5 (2골드)\n";
        cout << "3. 크리티컬 확률 +50% (5골드)\n";
        cout << "4. 크리티컬 배율 X2 (15골드)\n";
        cout << "5. @#$%?^%#@?#	(100골드)\n";
        cout << "6. 방어력 +1 {최대 100} (10골드)\n";
		cout << "0. 나가기\n";
        cout << "골드: " << player.gold << "\n선택: ";
        cin >> choice;

        if (choice == 0) break;
        if (choice == 1 && player.gold >= 3) { player.attack += 5; player.gold -= 3; }
        else if (choice == 2 && player.gold >= 2) { player.potionHeal += 5; player.gold -= 2; }
        else if (choice == 3 && player.gold >= 5) { player.critChance += 0.5; player.gold -= 5; }
        else if (choice == 4 && player.gold >= 15) { player.critDamage += 2; player.gold -= 15; }
        else if (choice == 5 && player.gold >= 100) { a += 1; player.gold -= 100; }
        else if (choice == 6 && player.gold >= 10 && player.maxprotect > player.protect) { player.protect += 1; player.gold -= 10; }
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
		{"겁나게 빠르고 쎄고 무섭고 강력하고 엄청나고 엘레강스하고 단@단하고 눈에서 빛이나는 스피드하고 귀여운 고양이 드래곤 마왕 슬라임", 5, 15, 0.9, 4}, // 노랑
        {"고블린", 50, 8, 0.0, 2}, // 초록 2
        {"늑대", 70, 10, 0.0, 8}, // 회색 3
        {"트롤", 100, 12, 0.0, 6}, // 보라 4
        {"[*긴급 퀘스트*] 진오우거", 130, 15, 0.0, 14}, // 빨강+흰색 5
        {"마법사", 160, 18, 0.0, 13}, // 분홍 6
        {"기사", 200, 20, 0.0, 11}, // 파랑+흰색 7
        {"*[저주의 왕]* | 스쿠나", 400, 200, 0.5, 12}, // 빨강+흰색 8
        {"*[무하한]* | 고죠 사토루", 1000, 100, 0.8, 9},// 파랑 9
		{"[$#$%@#$] @#$?%#@?$", 99999999, 99999999, 0.0, 4} // 빨강 10
	
    };

    for (int stage = 0; stage < 10; stage++) {
        Monster monster = monsters[stage];
        while (monster.hp > 0 && player.hp > 0) {
            clearScreen();           
            cout << "\n=== 스테이지 " << stage+1 << " ===\n";
            cout << monster.name << " 등장!\n\n";
            printStatus(player, monster);

            cout << "[1] 공격 [2] 방어 [3] 포션 사용  [4] @#$%?^%#@?# [5] 상점\n선택: ";
            int choice;
            cin >> choice;
			
            if (choice == 1) {
                if (attackMonster(player, monster)) {
                    cout << "\n***** " << monster.name << " 처치 성공!! *****\n";
                    player.gold += 20 + (stage * 5);
                    player.level++;
                    player.maxHp += 25;
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
            else if (choice == 6)
            {
            	player.gold += 50; 
            	
			}
			else if (choice == 3) {
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
            else if (choice == 2) {
                cout << "방어!!\n";
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
                		cout << "@#$%?^%#@?# 사용! @#$%?^%#@?#의 효과는 굉장했다!";
                		player.attack = 999999999;
                		player.maxHp = 999999999;
                		player.hp = 999999999;
					}
					else
					{
						
						printf("[보스앞에서 사용하라 적혀있다.]");
						Sleep(2000);
						system("cls");
						
					}
				}
				 
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
	
    //clearScreen();
    system("cls");
    cout << "\n모든 몬스터를 물리쳤다! 게임 클리어!\n";
    return 0;
}

