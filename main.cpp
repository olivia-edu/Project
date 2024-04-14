#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    srand(time(nullptr));


    int decisions, l_att, h_att, block, heal, chance1, enemy_turn;
    int health = 100;

    int enemy_health = 70 + rand() % 45; // determines the enemies health for the start of the encounter
    cout << "You encountered an enemy" << endl;
    int health1 = 100;
    do {

        cout << "\nEnemy has " << enemy_health << " hp left.\n\n";
        cout << "Choose 1 for light attack\tChoose 2 for heavy attack\n\nChoose 3 to heal\t\tChoose any other number to rage quit lol\n";
        cin >> decisions;
        int enemy_turn = 1 + rand() % 3;
        switch (decisions) {
        case 1: {
            cout << "You have chosen light attack\n" << endl;
            int chance1 = rand() % 2;
            if (chance1 <= 1) {
                int l_att = 7 + rand() % 13;
                enemy_health = enemy_health - l_att;
                cout << "The attack was a success!  You dealt " << l_att << " damage.\n";
                cout << "Enemy has " << enemy_health << " left, it is now the enemy's turn.\n";
            }
            else {
                cout << "Your attack missed, it is now the enemy's turn.\n";
            }
            break; }
        case 2: {
            cout << "You have chosen heavy attack.\n";
            int chance1 = rand() % 4;
            if (chance1 <= 1) {
                int h_att = 30 + rand() % 10;
                enemy_health = enemy_health - h_att;
                cout << "The attack was a success!  You dealt " << h_att << " damage.\n";
                cout << "Enemy has " << enemy_health << " left, it is now the enemy's turn.\n";
            }
            else {
                cout << "Your attack missed, it is now the enemy's turn.\n";
            }
            break; }
        case 3: {
            cout << "You have chosen to heal.\n";
            if (health != 100) {
                int chance1 = rand() % 2;
                if (chance1 == 2) {
                    int heal = 15 + rand() % 5;
                    health = health + heal;
                    cout << "You healed " << heal << " health.\n";
                    cout << "\n\n\nYou have " << health << " left\n\n\n";
                }
                else {
                    int heal = rand() % 14;
                    health = health + heal;
                    cout << "You healed " << heal << " health.\n";
                    cout << "\n\n\nYou have " << health << " left\n\n\n";
                }
            }
            else {
                cout << "You just wasted your turn, better luck next time.\n";
            }
            if (health > 100) {
                health = 100;
                cout << "\n\n\nYou have " << health << " left\n\n\n";
            }
            break; }
        default: {
            cout << "Rage quitter lol, hope the game was worth it.";
            return 0;
        }
        }

        cout << "\n\nIt is now the enemy's turn\n\n";
        switch (enemy_turn) {
        case 1: {

            int chance1 = rand() % 1;
            if (chance1 == 1) {
                int l_att = 7 + rand() % 13;
                health = health - l_att;
                cout << "The enemy attacked! They dealt " << l_att << " damage.\n";
                cout << "You now have " << health << " left, you might want to heal next turn.\n";
            }
            else {
                cout << "Their attack missed, it is now the your turn.\n";
            }
            break; }
        case 2: {

            int chance1 = rand() % 4;
            if (chance1 <= 1) {
                int h_att = 35 + rand() % 5;
                health = health - h_att;
                cout << "They actually hit you with a heavy attack and dealt " << h_att << " damage.\n";
                cout << "You now have " << health << " left, it is now the your turn.\n";
            }
            else {
                cout << "The dumbass missed a heavy attack, lets show them how its done.\n";
            }
            break; }
        case 3: {
            cout << "The enemy is just standing there... menacingly!\n";

            break; }
        }
    } while (health >= 0 && enemy_health >= 0);
    cout << "Game over" << endl;
}