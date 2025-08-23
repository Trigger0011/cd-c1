#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;

struct Card {
    string suit;
    string rank;
    int value;
};

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

vector<Card> createDeck() {
    vector<Card> deck;
    string suits[] = {"Spades", "Hearts", "Diamonds", "Clubs"};
    string ranks[] = {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    int values[]   = {2,3,4,5,6,7,8,9,10,10,10,10,11};

    for (int s = 0; s < 4; s++) {
        for (int r = 0; r < 13; r++) {
            Card c;
            c.suit = suits[s];
            c.rank = ranks[r];
            c.value = values[r];
            deck.push_back(c);
        }
    }
    random_shuffle(deck.begin(), deck.end());
    return deck;
}

int getHandValue(vector<Card> &hand) {
    int total = 0, aceCount = 0;
    for (size_t i = 0; i < hand.size(); i++) {
        total += hand[i].value;
        if (hand[i].rank == "A") aceCount++;
    }
    while (total > 21 && aceCount > 0) {
        total -= 10;
        aceCount--;
    }
    return total;
}

void showHand(string name, vector<Card> &hand, bool hideFirst = false) {
    cout << name << ": ";
    for (size_t i = 0; i < hand.size(); i++) {
        if (i == 0 && hideFirst)
            cout << "[??] ";
        else
            cout << hand[i].rank << " of " << hand[i].suit << " | ";
    }
    if (!hideFirst)
        cout << "Total: " << getHandValue(hand);
    cout << "\n";
}

int main() {
    srand(time(0));
    int money = 1000000000;
    char again = 'y';

    while (money > 0 && (again == 'y' || again == 'Y')) {
        vector<Card> deck = createDeck();
        vector<Card> player, dealer;

        int bet;
        while (true) {
            clearScreen();
            cout << "Your money: " << money << "\nBet amount: ";
            cin >> bet;
            if (bet > 0 && bet <= money) break;
            cout << "Invalid bet! Try again.\n";
            system("pause");
        }

        player.push_back(deck.back()); deck.pop_back();
        dealer.push_back(deck.back()); deck.pop_back();
        player.push_back(deck.back()); deck.pop_back();
        dealer.push_back(deck.back()); deck.pop_back();

        bool playerBust = false;
        bool playerTurn = true;

        while (playerTurn) {
            clearScreen();
            cout << "Bet: " << bet << " / Money: " << money << "\n\n";
            showHand("Dealer", dealer, true);
            showHand("Player", player);

            if (getHandValue(player) > 21) {
                playerBust = true;
                break;
            }

            cout << "\nHit(h) / Stand(s): ";
            char choice;
            cin >> choice;

            if (choice == 'h' || choice == 'H') {
                player.push_back(deck.back());
                deck.pop_back();
            } else if (choice == 's' || choice == 'S') {
                playerTurn = false;
            }
        }

        if (!playerBust) {
            while (getHandValue(dealer) < 17) {
                dealer.push_back(deck.back());
                deck.pop_back();
            }
        }

        clearScreen();
        cout << "=== °á°ú ===\n";
        showHand("Dealer", dealer);
        showHand("Player", player);

        int pVal = getHandValue(player);
        int dVal = getHandValue(dealer);

        if (playerBust) {
            cout << "\nPlayer bust! You lose.\n";
            money -= bet;
        } else if (dVal > 21 || pVal > dVal) {
            cout << "\nYou win!\n";
            money += bet;
        } else if (pVal < dVal) {
            cout << "\nYou lose!\n";
            money -= bet;
        } else {
            cout << "\nPush (Draw)\n";
        }

        if (money <= 0) {
            cout << "You're out of money! \n\n Game over.\n";
            break;
        }

        cout << "\nPlay again? (y/n): ";
        cin >> again;
    }

    return 0;
}

