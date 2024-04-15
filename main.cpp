#include <iostream>
#include <ctime>
#include <string>
#include <iomanip>

using namespace std;

// Used to format ASCII art
void printCharacters(int num, char character) 
{
  for (int i = 0; i < num; i++) {
    cout << character;
  }
}

// Used to print ASCII art game title
void gameTitle(const string& title, const string& subtitle) 
{
  // Game title variables 
  int title_length = title.length();                                                              // gets title length
  int subtitle_length = subtitle.length();                                                        // gets subtitle length
  int line_width = 77;                                                                            // sets width of title line
  int sub_line_width = subtitle_length +2;                                                        // sets width of subtitle
  int title_left_padding = (line_width - title_length) / 2;                                       // maintains ASCII art by padding to the left of the title
  int title_right_padding = line_width - title_left_padding - title_length;                       // maintains ASCII art by padding to the right of the title
  int subtitle_left_padding = (sub_line_width - subtitle_length) / 2;                             // maintains ASCII art by padding to the left of the subtitle
  int subtitle_right_padding = sub_line_width - subtitle_left_padding - subtitle_length;          // maintains ASCII art by padding the the right of the subtitle
  
  cout << "          0";
  printCharacters(title_left_padding, ' ');
  cout << title;
  printCharacters(title_right_padding, ' ');
  cout << "0";
  cout << "\n         //";
  printCharacters(line_width, ' ');
  cout << "\\\\" << endl;
  cout << "o[//////(@)::]======================> ";
  printCharacters(subtitle_left_padding, ' ');
  cout << subtitle;
  printCharacters(subtitle_right_padding, ' ');
  cout << " <======================[::(@)//////]o\n"; 
  cout << "         \\\\";
  printCharacters(line_width, ' ');
  cout << "//" << endl;
  cout << "          0";
  printCharacters(line_width, ' ');
  cout << "0" << endl;
}

// Used to introduce the game and get the PC's name
void Intro(const string& title, const string& subtitle, string& name)
{
    cout << "The year is 28966. The Emperor has violated the galactic armistice. His prized interstellar armada has surrounded Gertra-376 with the intention of eliminating all members of a rival familial bloodline, who’s existence threatens his reign. \n(Press Enter to Continue.)\n";
  while (cin.get() != '\n') {}
  
  gameTitle(title, subtitle);
  
  cout << "\nWelcome to (" << title<< "). Are you ready to play? \n(Press Enter to Continue.)"; 
  while (cin.get() != '\n') {}
  
  cout << "\nPlease type the full name of your character. After typing your name, press enter to continue. \n\n"; 
  getline(cin, name);
  
  cout << "\n" << name << ", Your adventure begins! \n(Press Enter to Continue.)" << endl;
  while (cin.get() != '\n') {}

    cout << "\nPlasma cannons rain fire down upon the citizenry of Gertra-376. Explosions BOOM in the distance, their intensity increasing as the bombardment narrowns in on its primary target. A shockwave tears through the Planetary Defense bunker, accompanied by a blinding light.\n";
    while (cin.get() != '\n') {}

    cout << "\nYou are the highest ranking officer of Gertra-376's Planetary Defense Force left alive. You have stayed behind to protect the planet's shield generating systems. If the system's console is destroyed, evacuating ships will be torn apart before they can they can complete their jump into Hyperspace.\n";
    while (cin.get() != '\n') {}

    cout << "\nSoon, the Emperor's Schock Troopers will decend upon your location. For every round of combat that you manage to survive, 1 ship of Gertran refugees will achieve Hyperspace and 50,000 lives will be saved. To complete a round of combat, defeat your enemy.\n";
    while (cin.get() != '\n') {}
}

// Used to print ASCII art banner
void printBanner(const string& sentence) 
{
  // Art banner variables
  int padding = (65 - sentence.length()) / 2;                                                    // establishes padding to center sentence
  
  if (padding < 0) {
    padding = 0;
  }
  
  cout << "\n  ( ~ )";
  printCharacters(64, ' ');
  cout << "( ~ )" << endl;
  cout << "  / /";
  printCharacters(66, 'u');
  cout << " / /" << endl;
  cout << " ( (";
  printCharacters(65, ' ');
  cout << "  ( (" << endl;
  cout << "  ) )";
  printCharacters(padding, ' ');
  cout << sentence;
  printCharacters(padding, ' ');
  cout << "  ) )" << endl;
  cout << " ( (";
  printCharacters(65, ' ');
  cout << "  ( (" << endl;
  cout << "  \\ \\";
  printCharacters(66, 'n');
  cout << " \\ \\" << endl;
  cout << "  ( ~ )";
  printCharacters(64, ' ');
  cout << " ( ~ )" << endl;
}

// Used to seperate UI elements
void printDivider(void)
{
    std::cout << "***************************************************************************\n";
}

// Used to check if player or enemy is alive
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


int main()
{
    srand(time(nullptr)); // Seed the random number generator with the current time

    // Opening variables
    string name, working_title, working_subtitle, variable_sentence;
    working_title = "ZENO's DUNGEON:";
    working_subtitle = "A DICHOTOMY OF SOULS";
    variable_sentence = "We can use this banner to stylistically inform PC of events.";

    // Opening function call
    Intro(working_title, working_subtitle, name);

    // Describe dungeon to user
    cout << "You dust yourself off and prepare for combat. The recent shockwave has disoriented and disarmed you. Clangs and shouts echo down the hallway. The Emperor's Shock Troppers have breached the first door of the Planetary Defence Bunker. \n(Press Enter to Continue.)";
    while (cin.get() != '\n') {}
    cout << "\nYou search the bodies of your compatriats for a functional weapon. You find a (gun name) and (quantity) grenade(s). \n(Press Enter to Continue.)";
    while (cin.get() != '\n') {}
    cout << "\nTEMP: (quantity =0) ships have reached Hyperspace. Your beloved pet rabbit, Pansy, is on ship (num ship randomly selected between 1-10). (Alternating phrase could be used here: We MUST keep her SAFE! / Pansy's ship has escaped, but we can't give up now! Keep the enemy occupies so they can't give chase!). INCLUDE: (Footsteps echo down the hallway, the xth round has begun! \n(Press Enter to Continue.)";
    while (cin.get() != '\n') {}

    // ASCII art for display
    printBanner(variable_sentence);
    
    // Divides opening and combat
    printDivider();

    // Battle variables
    int decisions, enemy_turn;                             // used in switch statements to determine player and enemy action
    int l_att, h_att, heal;                                // used to store battle values
    int chance1;                                           // used to store chance to hit for player and enemy
    int health = 100;                                      // player health
    int level = 1;                                         // used to store current player level
    int playerArmor, enemyArmor, finalDamage;              // used in calculation of damage values

    // Used in case 4 Throw Grenade action
    const int maxGrenades = 2;
    int grenadeCount = maxGrenades;

    // Begin battle
    bool gameOver = false;                                 // used for outer while loop condition to end the game
    while (!gameOver)
    {
        int levelMod = (level - 1) * 2;                        // used to scale game according to level
        int enemy_health = 70 + rand() % 45;                   // determines the enemies health for the start of the encounter (70 - 114)
        enemy_health += levelMod;                              // scale enemy health
        playerArmor = enemyArmor = 10;                         // set player and enemy armor values
        cout << "LEVEL: " << level << "\t\t\t";
        cout << "You encountered an enemy" << endl << endl;
 
        // Start Turn
        do
        {
            // Display UI
            cout << "Enemy: " << setw(3) << right << enemy_health << " hp"
                << setw(9) << right << "Armor: " << setw(2) << right << enemyArmor
                << setw(16) << right << "Player: " << setw(3) << right << health << " hp"
                << setw(9) << right << "Armor: " << setw(2) << right << playerArmor << endl << endl;
            cout << "Choose 1 for light attack\tChoose 2 for heavy attack\n\nChoose 3 to heal\t\tChoose 4 to throw grenade " << grenadeCount << "/" << maxGrenades << "\n\nChoose any other number to rage quit lol\n\n";
            printDivider();

            // Prompt user
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
                        int l_att = 10 + rand() % 13;                 // Player damage output 10 - 22
                        l_att += levelMod;                            // Scale damage
                        finalDamage = l_att - enemyArmor;             // Apply Armor to calculation
                        enemy_health -= finalDamage;                  // Subtract final damage from enemy health
                        cout << "The attack was a success!  You dealt " << finalDamage << " damage.\n";
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
                        h_att += levelMod * 2;                  // Scale damage, multiplied by 2 again for heavy scaling
                        enemyArmor -= 5;                        // Reduce enemy armor
                        finalDamage = h_att - enemyArmor;       // Apply Armor to calculation
                        enemy_health -=  finalDamage;
                        cout << "The attack was a success!  You dealt " << finalDamage << " damage.\n";
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
                            health += heal;
                            cout << "You healed " << heal << " health.\n";
                            cout << "You have " << health << " hp left.\n";
                        }
                        else
                        {
                            int heal = rand() % 14;  // Heal for 0 to 13
                            health += heal;
                            cout << "You healed " << heal << " health.\n";
                            cout << "You have " << health << " hp left.\n";
                        }
                    }
                    // Display if player is at full health
                    else
                    {
                        cout << "You just wasted your turn, better luck next time.\n";
                    }

                    // Show player health after action
                    if (health > 100) 
                    {
                        health = 100;               // Update player health so never greater than 100
                        cout << "\n\n\nYou have " << health << " left\n\n\n";
                    }
                    break;
                }
                // Throw grenade
                case 4:
                {
                    // Check player has available grenade
                    if (grenadeCount > 0)
                    {
                        cout << "You have chosen throw grenade.\n";
                        int chance1 = 1 + rand() % 10;                   // Get number between 1 and 10
                        if (chance1 <= 8)                                // 80% chance to hit
                        {
                            finalDamage = 60 + levelMod * 3;  // set damage and scaling high
                            enemyArmor = 0;                   // remove enemy armor
                            enemy_health -= finalDamage;
                            cout << "The attack was a success!  You dealt " << finalDamage << " damage.\n";
                            grenadeCount -= 1;
                        }
                        // 10% chance to blow yourself up
                        else if (chance1 == 9)
                        {
                            finalDamage = 60 + levelMod * 3;  // set damage and scaling high
                            playerArmor = 0;                  // remove player armor
                            health -= finalDamage;
                            cout << "Oops, the grenade slipped out of your hand. **BOOM!**\n";
                            cout << "You have taken " << finalDamage << " self inflicted damage.\n";
                            grenadeCount -= 1;

                            // If player is dead, end battle
                            if (deathCheck(health))
                            {
                                gameOver = true;
                                break;
                            }
                            else
                            {
                                cout << "You now have " << health << " hp left.\n";
                            }
                        }
                        // 10% chance to miss
                        else
                        {
                            cout << "Your attack missed.\n";
                            grenadeCount -= 1;
                        }
                    }
                    // Display if no grenades remaining
                    else
                    {
                        cout << "Your search your equipment for grenades and none are found.\n" << "You have just wasted your turn.\n";
                    }
                    break;
                }

                // Display if player enters a number besides 1, 2, or 3
                default:
                {
                    cout << "Rage quitter lol, hope the game was worth it.\n\n";
                    return 0;
                }
            }
            // If enemy is dead, end battle
            if (deathCheck(enemy_health))
            {
                cout << "\nThe enemy has 0 health remaining. They have been defeated.\n\n";
                printDivider();
                cout << endl;
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
                        int l_att = 10 + rand() % 13;                  // Enemy attack 10 - 22 damage
                        l_att += levelMod;
                        finalDamage = l_att - playerArmor;             // Apply Armor to calculation
                        health -= finalDamage;
                        cout << "The enemy attacked! They dealt " << finalDamage << " damage.\n";

                    }
                    else
                    {
                        cout << "Their attack missed, it is now your turn.\n";
                    }
                    break;
                }

                // Enemy heavy attack
                case 2:
                {
                    int chance1 = rand() % 4;     // Get number between 0 and 3
                    if (chance1 == 0)             // Chance to hit is 25%
                    {
                        int h_att = 35 + rand() % 5;        // Enemy attack 35 - 39 damage
                        h_att += levelMod * 2;              // Scale damage, times 2 for heavy scaling
                        playerArmor -= 5;                   // Weaken player armor
                        finalDamage = h_att - playerArmor;  // Apply Armor to calculation
                        health -= finalDamage;
                        cout << "They actually hit you with a heavy attack and dealt " << finalDamage << " damage.\n";
                        cout << "They also removed 5 armor.\n";
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
                gameOver = true;
                break;
            }
            else
            {
                cout << "You now have " << health << " hp left, it is now your turn.\n\n";
            }
        } while (health > 0 && enemy_health > 0);  // Continue until player or enemy health is negative or 0

        level++;                // increment level if enemy defeated, maybe add line resetting player health to 100

        // 50% chance to find a grenade after battle, if grenadeCount is not at max value, and player is not defeated
        chance1 = rand() % 2;
        if (chance1 == 0 && grenadeCount < maxGrenades && !gameOver)
        {
            grenadeCount++;
            cout << "You search the room for supplies. On a defeated enemy, you find 1 grenade\n\n";
        }
        // Exit battle if player is dead
        else if (gameOver)
        {
            break;
        }
        else
        {
            cout << "You hear the sound of footsteps approaching...\n" << "You don't have any time left to search for supplies. Get ready for battle\n\n";
        }
    }
    // Placeholder for game over screen
    cout << endl;
    printDivider();
    cout << "\n\nYour health is now 0, you have been defeated.\n\n";
    cout << "Game over, you completed " << level - 1 << " levels.\n";
}