#include <iostream>
#include <ctime>
#include <string>

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
  cout << "Brief Opening Statement, used to establish a sense of the setting. \n(Press Enter to Continue.)\n";
  while (cin.get() != '\n') {}
  
  gameTitle(title, subtitle);
  
  cout << "\nWelcome to (" << title<< "). Are you ready to play? \n(Press Enter to Continue.)"; 
  while (cin.get() != '\n') {}
  
  cout << "\nPlease type the full name of your character. After typing your name, press enter to continue. \n\n"; 
  getline(cin, name);
  
  cout << "\n" << name << ", Your adventure begins! \n(Press Enter to Continue.)" << endl;
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

// Used to let PC investigate doors
void investigateDoor()
{
  // Door investigation variables
  int door_num;                                                                           // holds user selected door number
  bool valid_input = false;                                                               // helps to test for input validity

  do {
    cout << "\nSelect a door to investigate. (1/2/3/4): ";
    cin >> door_num;

    switch(door_num)
    {
        case 1:
          cout << "TEMP: THe first door looks like (...)\n";
          valid_input = true;
          break;
        case 2:
          cout << "TEMP: The second door looks like (...)\n";
          valid_input = true;
          break;
        case 3:
          cout << "TEMP: The third door looks like (...)\n";
          valid_input = true;
          break;
      case 4:
          cout << "TEMP: We can't turn back now! Theres treasure to find!\n";
          break;
      default:
          cout << "Invalid input. Please enter a number between 1 and 4.\n";
          break;
    }
  } while (!valid_input);
}

// Used to let PC select door to enter
void selectDoor()
{
  // Door selection variables
  int door_num;                                                                        // holds user selected door number
  bool valid_input = false;                                                            // helps to test for input validity

  do {
    cout << "\nSelect a door to enter. (1/2/3/4): ";
    cin >> door_num;

    switch(door_num)
    {
        case 1:
          cout << "TEMP: You enter the first room (...)\n";
          valid_input = true;
          break;
        case 2:
          cout << "TEMP: You enter the second room (...)\n";
          valid_input = true;
          break;
        case 3:
          cout << "TEMP: You enter the third room (...)\n";
          valid_input = true;
          break;
      case 4:
          cout << "TEMP: We can't turn back now! Theres treasure to find!\n";
          break;
      default:
      cout << "Invalid input. Please enter a number between 1 and 4.\n";
      break;
    }
  } while (!valid_input);
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

using namespace std;

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
     cout << "TEMP: You descend into the dungeon. \n(Press Enter to Continue.)";
    while (cin.get() != '\n') {}
    cout << "\nTEMP: Cool Scene Setting Should Go Here. \n(Press Enter to Continue.)";
    while (cin.get() != '\n') {}
     cout << "\nTEMP: The first room looks like this (...). There are 3 new doors in the xth room.(...)\n(Press Enter to Continue.)";
    while (cin.get() != '\n') {}

    // Door function calls
    investigateDoor();
    selectDoor();

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

    // Begin battle
    bool gameOver = false;                                 // used for outer while loop condition to end the game
    while (!gameOver)
    {
        int levelMod = (level - 1) * 2;                        // used to scale game according to level
        int enemy_health = 70 + rand() % 45;                   // determines the enemies health for the start of the encounter (70 - 114)
        enemy_health += levelMod;                              // scale enemy health
        playerArmor = enemyArmor = 10;                         // set player and enemy armor values
        cout << "LEVEL: " << level << "\t\t\t";
        cout << "You encountered an enemy" << endl;
 
        // Start Turn
        do
        {
            // Prompt user for action
            cout << "\nEnemy: " << enemy_health << " hp    " << enemyArmor << " armor\tPlayer: " << health << " hp    " << playerArmor << " armor\n\n";
            cout << "Choose 1 for light attack\tChoose 2 for heavy attack\n\nChoose 3 to heal\t\tChoose 4 to throw grenade\n\nChoose any other number to rage quit lol\n\n";
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
                    cout << "You have chosen throw grenade.\n";
                    int chance1 = rand() % 4;                   // Get number between 0 and 3
                    if (chance1 <= 1)                           // 50% chance to hit
                    {
                        finalDamage = 60 + levelMod * 3;  // set damage and scaling high
                        enemyArmor = 0;                   // remove enemy armor
                        enemy_health -= finalDamage;
                        cout << "The attack was a success!  You dealt " << finalDamage << " damage.\n";
                    }
                    else
                    {
                        cout << "You missed.\n";
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
                        int l_att = 7 + rand() % 13;    // Enemy attack 7 - 19 damage
                        l_att += levelMod;
                        health -= l_att;
                        cout << "The enemy attacked! They dealt " << l_att << " damage.\n";

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
                        int h_att = 35 + rand() % 5;    // Enemy attack 35 - 39 damage
                        h_att += levelMod * 2;          // Scale damage, times 2 for heavy scaling
                        health -= h_att;
                        cout << "They actually hit you with a heavy attack and dealt " << h_att << " damage.\n";
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
                cout << "You now have " << health << " hp left, it is now your turn.\n";
            }
        } while (health > 0 && enemy_health > 0);  // Continue until player or enemy health is negative or 0

        level++;                // increment level if enemy defeated, maybe add line resetting player health to 100
    }
    // Placeholder for game over screen
    cout << endl;
    printDivider();
    cout << "\n\nYour health is now 0, you have been defeated.\n\n";
    cout << "Game over, you completed " << level - 1 << " levels.\n";
}