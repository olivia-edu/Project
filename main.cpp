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
    int sub_line_width = subtitle_length + 2;                                                        // sets width of subtitle
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

// Used to print ASCII art banner
void printBanner(const string& sentence)
{
    // Art banner variables
    int padding = (65 - sentence.length()) / 2;                                                    // establishes padding to center sentence

    if (padding < 0) {
        padding = 0;
    }

  cout << "\n\n  ( ~ )";
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

// Used to introduce the game and get the PC's name
void Intro(const string& title, const string& subtitle, string& name)
{
    string enter_title = " Press Enter to Continue ";
  
  cout << "The year is 28966. The Emperor has violated the galactic armistice.\n(Press Enter to Continue.)";
  while (cin.get() != '\n') {
    cin.ignore();
  }
  
  cout << "\nHis prized interstellar armada has surrounded Gertra-376 with the intention of eliminating all members of a rival family bloodline, whose existence threatens his reign.\n(Press Enter to Continue.)";
  while (cin.get() != '\n') {
    cin.ignore();
  }  
  gameTitle(title, subtitle);
  
  cout << "\nWelcome to (" << title<< "). Are you ready to play?\n(Press Enter to Continue.)"; 
  while (cin.get() != '\n') {
    cin.ignore();
  }
  
  cout << "\nPlease type the full name of your character. After typing your name, press enter to continue. \n\n"; 
  getline(cin, name);
  
  cout << "\n" << name << ", Your adventure begins!";  
  printBanner(enter_title);
  while (cin.get() != '\n') {
    cin.ignore();
  }
  
  cout << "\nAn orbital lazer BLASTS down upon the citizenry of Gertra-376. Explosions BOOM in the distance. They increase in both rate and decibel,\n as the bombardment narrows in on its primary target.\n(Press Enter to Continue.)";
  while (cin.get() != '\n') {
    cin.ignore();
  } 
  
  cout << "\nA shockwave TEARS through the Planetary Defense Bunker, accompanied by a BLINDING light. \n(Press Enter to Continue.)";  
  while (cin.get() != '\n') {
    cin.ignore();
  }

  cout << "\nYou are the highest ranking officer of Gertra-376's Planetary Defense Force left alive. You have stayed behind to protect the planet's shield generating systems.\n(Press Enter to Continue.)";   
  while (cin.get() != '\n') {
    cin.ignore();
  }
  
  cout << "\nIf the system's console is destroyed, evacuating ships will be torn apart before they can complete the jump into Hyperspace.\n(Press Enter to Continue.)";
  while (cin.get() != '\n') {
    cin.ignore();
  }

  cout << "\nSoon, the Emperor's SHOCK TROOPERS will decend upon your location. To complete a round of combat, defeat your enemy.\n(Press Enter to Continue.)";
  while (cin.get() != '\n') {
    cin.ignore();
  }

  cout << "\nFor every round of combat that you manage to survive, 1 ship of Gertran refugees will achieve Hyperspace and 50,000 lives will be saved.";
  printBanner(enter_title);
  while (cin.get() != '\n') {
    cin.ignore();
  }
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

// Used to print commas for large numbers
string numCommaFormat(int num)
{
    string comma_num; 
    int counting_dig = 0;

    do {
        if ((counting_dig % 3 == 0) && (counting_dig !=0)) {
            comma_num = "," + comma_num;
        }
            comma_num = to_string(num % 10) + comma_num;
            num /= 10;
            counting_dig++;
        } while (num != 0);
    
     return comma_num;
    
    }

int main()
{
    srand(time(nullptr)); // Seed the random number generator with the current time

    // Opening variables
    string name, working_title, working_subtitle, enter_title, game_over;
    enter_title = "Press Enter to Continue";
    working_title = "EMPEROR's FURY:";
    working_subtitle = "DEFENDING GERTRA-376";
    game_over = "GAME OVER";

    // Opening function call
    Intro(working_title, working_subtitle, name);

    // Describe dungeon to user
    cout << "\nThe recent shockwave has disoriented and disarmed you. You dust yourself off and prepare for combat. \n(Press Enter to Continue.)";
    while (cin.get() != '\n') {}
    
    cout << "\nCLANGS and SHOUTS echo down the hallway. The Emperor's SHOCK TROOPERS have breached the first door of the Planetary Defence Bunker. \n(Press Enter to Continue.)";
    while (cin.get() != '\n') {}
    
    cout << "\nYou search the bodies of your comrades for a functional weapon. You find a blaster cannon and 2 grenade(s). \n(Press Enter to Continue.)";
    while (cin.get() != '\n') {}

    cout << "\nNONE of the ships have reached Hyperspace. YOU MUST HOLD OUT as LONG as YOU CAN!!\n(Press Enter to Continue.)";
    while (cin.get() != '\n') {}
    
    cout << "\nThe soft hum of a PROTON-BLASTER indicates your enemy's approach. PREPARE YOURSELF," << name << ", the 1st round has begun! \n(Press Enter to Continue.)";
    printBanner(enter_title);
    while (cin.get() != '\n') {}


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
        cout << (level - 1) << " ship(s) have reached Hyperspace, we can't stop now!\n\n";
        cout << "Footsteps echo down the hallway,\n\n";
        cout << "Round: " << level << "\n\n";

        // Start Turn
        do
        {
            // Display UI
            cout << "Enemy: " << setw(3) << right << enemy_health << " hp"
                 << setw(9) << right << "Armor: " << setw(2) << right << enemyArmor
                 << setw(16) << right << "Player: " << setw(3) << right << health << " hp"
                 << setw(9) << right << "Armor: " << setw(2) << right << playerArmor << endl << endl;
            cout << "Choose 1 for light attack\tChoose 2 for heavy attack\n\nChoose 3 to heal\t\tChoose 4 to throw grenade " << grenadeCount << "/" << maxGrenades << "\n\nChoose any other number to surrender.\n\n";
            printDivider();

            // Prompt user
            cout << (level - 1) << " ship(s) have reached Hyperspace, we can't stop now!\n\n";
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
                    enemy_health -= finalDamage;
                    cout << "The attack was a success!  You dealt " << finalDamage << " damage.\n";
                    cout << "You also removed 5 armor.\n";
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
                cout << "You have surrendered to the enemy. You spend the rest of your days as a foot stool for the emperor\n\n";
                return 0;
            }
            }
            // If enemy is dead, end battle
            if (deathCheck(enemy_health))
            {
                cout << "\nThe enemy has 0 health remaining. They have been defeated.\n\n";
                printDivider();
                cout << endl;
                level++;                // increment level if enemy defeated, maybe add line resetting player health to 100
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
                    cout << "The enemy missed a heavy attack, lets show them how its done.\n";
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
            cout << "You don't have any time left to search for supplies. Get ready for battle\n\n";
        }
    }
    // Placeholder for game over screen
    cout << endl;
    printDivider();
    
    // Determine player ending
    cout << "You have fallen in battle.\n";
    if ((level -1) >= 1 && (level - 1) < 6)
    {
        cout << "\nYou protected " << (level -1) << " ships! " << numCommaFormat((50000 * (level -1))) << " Gertrans survived the planetary onslaught.\nBut the guile of the Emperor is not to be underestimated, you did not save enough ships to make a difference.\n(Press Enter to Continue.)";  // put_money() from <iomanip> adds commas to large numbers 
        while (cin.get() != '\n') {}

        cout << "\n\nAfter the destruction of the planet, the Emperor's dreaded SHOCK TROOPERS hunted down and destroyed all " << (level -1) << " of the refugee vessels.\nOnly rumors remain of the Emperor's misdeeds on Gertra-376....\n";
        printBanner(game_over);
    }

    else 
    {
        cout << "\nYou protected " << (level - 1) << " ships! " << numCommaFormat(50000 * (level - 1)) << " Gertrans survived the galactic bombardment.\n(Press Enter to Continue.)";
        while (cin.get() != '\n') {}

        cout << "\n\nNot only did you protect " << (level - 1) << " ships, but you saved so many refugees, that the Emperor could not stamp out the fires of rebellion stoked by his malice and greed.\nThe whole Galaxy knows what happened here today, the royal family of Gertra-376 embarks on a campaign to end the tyranny of the Galactic Empire\n(Press Enter to Continue.)";
        while (cin.get() != '\n') {}

        cout << "\n\nAfter 10 long zorpthons, a Gertran Emperor ascends to the throne. 5 more zorpthons pass, and an heir is produced. Born with bright eyes and great promise. \nThe Emperor bestows the baby with the name of hero. Their name?\n(Press Enter to Reveal the Baby's Name.)";
        while (cin.get() != '\n') {}

        printBanner(name);
    }
    level--; 
    return 0;
}