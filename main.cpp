#include <iostream>
#include <ctime>




void printDivider(void)
{
    std::cout << "***************************************************************************\n";
}

bool deathCheck(int currentHealth)
{
    if (currentHealth <= 0)
    {
        return true;
    }
    else
    {
        return false;
    }

}

using namespace std;

int main()
{
    srand(time(nullptr)); // Seed the random number generator with the current time

    // Placeholders for display functions
    cout << "DISPLAY TITLE SCREEN\n";
    cout << "DISPLAY INTRODUCTION\n\n";
    printDivider();

    // Battle variables
    int decisions, l_att, h_att, block, heal, enemy_turn;
    int chance1;                                           // used to store chance to hit for player and enemy
    int health = 100;
    int enemy_health = 70 + rand() % 45;                   // determines the enemies health for the start of the encounter (70 - 114)
    int health1 = 100;

    // Start battle
    cout << "You encountered an enemy" << endl;
    do {
        // Prompt user for action
        cout << "\nEnemy has " << enemy_health << " hp left.\n\n";
        cout << "Choose 1 for light attack\tChoose 2 for heavy attack\n\nChoose 3 to heal\t\tChoose any other number to rage quit lol\n\n";
        printDivider();
        cout << "Your action: ";
        cin >> decisions;
        cout << endl;

        // Determine player action
        switch (decisions) 
        {
            // Perform light attack
            case 1: 
            {
                cout << "You have chosen light attack\n" << endl;
                int chance1 = 1 + rand() % 10;                    // Get number between 1 and 10 inclusive 
                if (chance1 <= 9)                                 // 90% chance to hit
                {
                    int l_att = 7 + rand() % 13;                  // Player damage output 7 - 19
                    enemy_health = enemy_health - l_att;
                    cout << "The attack was a success!  You dealt " << l_att << " damage.\n";
                }
                else 
                {
                    cout << "Your attack missed.\n"; // 10% chance to miss
                }
                break; 
            }
            // Perform heavy attack
            case 2: 
            {
                cout << "You have chosen heavy attack.\n";
                int chance1 = rand() % 4;                   // Get number between 0 and 3
                if (chance1 <= 1)                           // 50% chance to hit
                {
                    int h_att = 30 + rand() % 10;           // Player damage output 30 - 39
                    enemy_health = enemy_health - h_att;
                    cout << "The attack was a success!  You dealt " << h_att << " damage.\n";
                }
                else 
                {
                    cout << "Your attack missed.\n";
                }
                break; 
            }
            // Heal player
            case 3: 
            {
                cout << "You have chosen to heal.\n";
                if (health != 100) 
                {
                    int chance1 = 1 + rand() % 2;  // Get number 1 or 2
                    if (chance1 == 2)              // 50% chance
                    {
                        int heal = 15 + rand() % 5;  // Heal for 15 to 19
                        health = health + heal;
                        cout << "You healed " << heal << " health.\n";
                        cout << "\n\n\nYou have " << health << " left\n\n\n";
                    }
                    else 
                    {
                        int heal = rand() % 14;  // Heal for 0 to 13
                        health = health + heal;
                        cout << "You healed " << heal << " health.\n";
                        cout << "\n\n\nYou have " << health << " left\n\n\n";
                    }
                }
                // Display if player is at full health
                else 
                {
                    cout << "You just wasted your turn, better luck next time.\n";
                }

                // Show player health after action
                if (health > 100) {
                    health = 100;               // Update player health so never greater than 100
                    cout << "\n\n\nYou have " << health << " left\n\n\n";
                }
                break; 
            }

            // Display if player enters a number besides 1, 2, or 3
            default: 
            {
                cout << "Rage quitter lol, hope the game was worth it.";
                return 0;
            }
        }
        // If enemy is dead, end battle
        if (deathCheck(enemy_health))
        {
            break;
        }
        else
        {
            cout << "Enemy has " << enemy_health << " hp left, it is now the enemy's turn.\n";
        }

        // Start enemy turn
        int enemy_turn = 1 + rand() % 3;                // Get number 1, 2, or 3. Used to determine enemy action
        switch (enemy_turn) 
        {
            // Enemy light attack
            case 1: 
            {
                int chance1 = rand() % 2;  // Get number 0 or 1
                if (chance1 == 1)          // 50% chance to hit
                {
                    int l_att = 7 + rand() % 13;    // Enemy attack 7 - 19 damage
                    health = health - l_att;
                    cout << "The enemy attacked! They dealt " << l_att << " damage.\n";
                    cout << "You now have " << health << " hp left, you might want to heal next turn.\n";
                }
                else 
                {
                    cout << "Their attack missed, it is now the your turn.\n";
                }
                break; 
            }

            // Enemy heavy attack
            case 2: 
            {
                int chance1 = rand() % 4;     // Get number between 0 and 3
                if (chance1 == 0)             // Chance to hit is 25%
                {
                    int h_att = 35 + rand() % 5;    // Enemy attack 35 - 39 damage
                    health = health - h_att;
                    cout << "They actually hit you with a heavy attack and dealt " << h_att << " damage.\n";
                    cout << "You now have " << health << " left, it is now the your turn.\n";
                }
                else 
                {
                    cout << "The dumbass missed a heavy attack, lets show them how its done.\n";
                }
                break; 
            }

            // Chance for enemy to waste turn
            case 3: 
            {
                cout << "The enemy is just standing there... menacingly!\n";
                break; 
            }
        }
        // If player is dead, end battle
        if (deathCheck(health))
        {
            break;
        }
    } 
    while (health >= 0 && enemy_health >= 0);  // Continue until player or enemy health is negative or 0

    // Placeholder for game over screen
    cout << "Game over" << endl;
}