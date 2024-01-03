#include <iostream>
#include <string>
#include <ctime>
using namespace std;
static int score = 0;
int flag = 0;
static int gold = 50;
struct User
{
    int health;
    int exp;
    int level;
    string name;
    string Class;
};
struct quest
{
    int serialno;
    string name;
    string difficulty;
};
quest infoquest1()
{
    quest quest1;
    quest1.serialno = 1;
    cout << "\n\n\n\n\n\n\n\n";
    quest1.name = ") Battle royale";
    quest1.difficulty = "\t\t\t Difficulty: Medium";
    return quest1;
}
quest infoquest2()
{
    quest quest2;
    quest2.serialno = 2;
    quest2.name = ") Princess Elara";
    quest2.difficulty = "\t\t\t Difficulty: Low";
    return quest2;
}
void displayquest1()
{
    quest quest1 = infoquest1();
    cout << "\t\t\t      ---> Select quest to embark" << endl;
    cout << "\t\t\t\t" << quest1.serialno << quest1.name << quest1.difficulty << endl;

}
void displayquest2()
{
    quest quest2 = infoquest2();
    cout << "\t\t\t\t" << quest2.serialno << quest2.name << quest2.difficulty << endl;
    
}
struct Creature {
    string name;
    int health;
    int difficulty;
};

User createUser() {
    User player;
    char classs;
    cout << "\n\n\n\n\n\n\n\n\n";
    cout << "\t\t\t\t---> Enter your information to create a chracter <---" << endl;
    cout << "\t\t\t\t---> Enter Name: ";
    cin >> player.name;
    do {
        int flagclass = 0;
        cout << "\t\t\t\t---> Enter class \n\t\t\t\t  -> W. Warrior\n\t\t\t\t  -> M. Mage\n\t\t\t\t  -> R. Rogue\n ";
        cout << "\t\t\t\tSelect (W , M or R)\n\t\t\t\t";
        cin >> classs;
        if (classs == 'w' || classs == 'W')
        {
            player.Class = "Warrior";
        }
        else if (classs == 'm' || classs == 'M')
        {
            player.Class = "Mage";
        }
        else if (classs == 'r' || classs == 'R')
        {
            player.Class = "Rogue";
        }
        else
        {
            cout << "Wrong choice.Enter again.\n";
        }

    } while (!(classs == 'w' || classs == 'W' || classs == 'm' || classs == 'M' || classs == 'r' || classs == 'R'));



    player.health = 100;
    player.exp = 0;
    player.level = 0;
    system("cls");
    return player;
}

void displayUser(User& player)
{

    cout << "\n\n\n\n\n\n\n\n";
    cout << "\t\t\t\t\t ---->  Player Information  <----" << endl;
    cout << "\t\t\t\t\t\tName: " << player.name << endl;
    cout << "\t\t\t\t\t\tClass: " << player.Class << endl;
    cout << "\t\t\t\t\t\tHealth: " << player.health << endl;
    cout << "\t\t\t\t\t\tLevel: " << player.level << endl;
    cout << "\t\t\t\t\t\tScore: " << score << endl;
    cout << "\t\t\t\t\t\tExperience point: " << player.exp << endl;
    system("pause");
    system("cls");

}

void displayCreatureInfo(char choice)
{
    Creature info;
    info.health = 100;

    if (choice == 't' || choice == 'T' || choice == '1') {
        info.name = "Tasmanian Devil";
        info.difficulty = 1;
        cout << "\t\t\t---> Name: " << info.name << endl;
        cout << "\t\t\t---> Health: " << info.health << endl;
        cout << "\t\t\t---> Difficulty Level: " << info.difficulty << endl;
    }
    else if (choice == 's' || choice == 'S' || choice == '2') {
        info.name = "Superman";
        info.difficulty = 2;
        cout << "\t\t\t\t\t---> Name: " << info.name << endl;
        cout << "\t\t\t\t\t---> Health: " << info.health << endl;
        cout << "\t\t\t\t\t---> Difficulty Level: " << info.difficulty << endl;
    }
    else if (choice == 'd' || choice == 'D' || choice == '3') {
        info.name = "Dragothorn";
        info.difficulty = 3;
        cout << "\t\t\t\t\t---> Name: " << info.name << endl;
        cout << "\t\t\t\t\t---> Health: " << info.health << endl;
        cout << "\t\t\t\t\t---> Difficulty Level: " << info.difficulty << endl;
    }
}

int damageofwarrior(int currentHealth)
{
    srand(time(0));
    //user damage given to the creature
    int damage = rand() % 21;
    return currentHealth - damage;
}
int damageofmage(int currentHealth)
{
    srand(time(0));
    //user damage given to the creature
    int damage = rand() % 31;
    return currentHealth - damage;
}
int damageofrogue(int currentHealth)
{
    srand(time(0));
    //user damage given to the creature
    int damage = rand() % 41;
    return currentHealth - damage;
}
int damageofdragothorn(int currentHealth)
{
    srand(time(0));
    //user damage given to the creature
    int damage = rand() % 46;
    return currentHealth - damage;
}
int damageofsuperman(int currentHealth)
{
    srand(time(0));
    //user damage given to the creature
    int damage = rand() % 36;
    return currentHealth - damage;
}
int damageoftasmaniandevil(int currentHealth)
{
    srand(time(0));
    //creature damage given to the user
    int damage = rand() % 26;
    return currentHealth - damage;
}
void damagecreatureselection(char& enemychoice, int& userHealth)
{

    switch (enemychoice)
    {
    case 't':
    case'T':
    
    {
        userHealth = damageoftasmaniandevil(userHealth);
        break;
    }
    case 'S':
    case 's':
    {
        userHealth = damageofsuperman(userHealth);
        break;
    }
    case 'd':
    case'D':
    {
        userHealth = damageofdragothorn(userHealth);
        break;
    }
    }
}
void fight(char& enemychoice, int& userHealth, int &creatureHealth, User &player)
{
    if (player.Class == "Warrior")
    {
        creatureHealth = damageofwarrior(creatureHealth);
        damagecreatureselection(enemychoice, userHealth);
    }
    else if (player.Class == "Mage")
    {
        creatureHealth = damageofmage(creatureHealth);
        damagecreatureselection(enemychoice, userHealth);
    }
    else if (player.Class == "Rogue")
    {
        creatureHealth = damageofrogue(creatureHealth);
        damagecreatureselection(enemychoice, userHealth);
    }
    cout << "\n\n\n\n\n\n\n";
    cout << "\t\t\t\t---> Your Health: " << userHealth << endl;
    cout << "\t\t\t\t---> Creature Health: " << creatureHealth << endl;

        if (userHealth <= 0) {

            system("cls");
            cout << R"(
                                    __   _____  _   _   _     ___  ____ _____ 
                                    \ \ / / _ \| | | | | |   / _ \/ ___|_   _|
                                     \ V / | | | | | | | |  | | | \___ \ | |  
                                      | || |_| | |_| | | |__| |_| |___) || |  
                                      |_| \___/ \___/  |_____\___/|____/ |_|
                                     \
                                     /                                 />
                                     \__+_____________________/\/\___/ /|
                                     ()______________________      / /|/\
                                                 /0 0  ---- |----    /---\
                                                |0 o 0 ----|| - \ --|      \
                                                 \0_0/____/ |    |  |\      \
                                                             \__/__/  |      \
                                    Bang! Bang!                       |       \
                                                                      |         \
                                                                      |__________|
             )" << endl;
            flag++;
            score -= 10;
            player.exp -= 50;
        }
        else if(creatureHealth<=0)
        {

            system("cls");
            cout << R"(
                                        __   _____  _   _  __        _____  _   _ 
                                        \ \ / / _ \| | | | \ \      / / _ \| \ | |
                                         \ V / | | | | | |  \ \ /\ / / | | |  \| |
                                          | || |_| | |_| |   \ V  V /| |_| | |\  |
                                          |_| \___/ \___/     \_/\_/  \___/|_| \_|
                                                     _______________
                                                    |@@@@|     |####|
                                                    |@@@@|     |####|
                                                    |@@@@|     |####|
                                                    \@@@@|     |####/
                                                     \@@@|     |###/
                                                      `@@|_____|##'
                                                           (O)
                                                        .-'''''-.
                                                      .'  * * *  `.
                                                     :  *       *  :
                                                    : ~ A S C I I ~ :
                                                    : ~ A W A R D ~ :
                                                     :  *       *  :
                                                      `.  * * *  .'
                                                        `-.....-')" << endl;
            flag++;
            score += 10;
            player.exp += 50;
        }
}



void inventory(int& healthuser, int& healthcreature, User& player)
{
    int inventory;

    cout << "\n\n\n\n\n";
    cout << "\t\t\t\t\t     ---> Golds : " << gold << " <---\n\n";
    cout << "\t\t\t\t1. Poison \t  Price: 20G \t Damage: +20" << endl;
    cout << "\t\t\t\t2. Health Portion  Price: 30G \t Health: +20" << endl;


    cout << "Enter (1 or 2) to select " << endl;
    cin >> inventory;
    system("cls");
    if (inventory == 1)
    {
        if (gold >= 20)
        {
            gold = gold - 20;
            healthcreature -= 20;
            cout << "\n\n\n\n\n\n\n\n";
            cout << "Enemy have dealt with 20 damage" << endl;
            cout << "\t\t\t\t---> Your Health: " << healthuser << endl;
            cout << "\t\t\t\t---> Creature Health: " << healthcreature << endl;


            if (healthuser <= 0)
            {
               
                cout << R"(
                                    __   _____  _   _   _     ___  ____ _____ 
                                    \ \ / / _ \| | | | | |   / _ \/ ___|_   _|
                                     \ V / | | | | | | | |  | | | \___ \ | |  
                                      | || |_| | |_| | | |__| |_| |___) || |  
                                      |_| \___/ \___/  |_____\___/|____/ |_| 
                                         \
                                     /                                 />
                                     \__+_____________________/\/\___/ /|
                                     ()______________________      / /|/\
                                                 /0 0  ---- |----    /---\
                                                |0 o 0 ----|| - \ --|      \
                                                 \0_0/____/ |    |  |\      \
                                                             \__/__/  |      \
                                    Bang! Bang!                       |       \
                                                                      |         \
                                                                      |__________|
 )" << endl;    score -= 10;
                player.exp -= 50;
                flag++; 
            }
            else if (healthcreature <= 0)
            {
                
                cout << R"(
                                        __   _____  _   _  __        _____  _   _ 
                                        \ \ / / _ \| | | | \ \      / / _ \| \ | |
                                         \ V / | | | | | |  \ \ /\ / / | | |  \| |
                                          | || |_| | |_| |   \ V  V /| |_| | |\  |
                                          |_| \___/ \___/     \_/\_/  \___/|_| \_|
                                                     _______________
                                                    |@@@@|     |####|
                                                    |@@@@|     |####|
                                                    |@@@@|     |####|
                                                    \@@@@|     |####/
                                                     \@@@|     |###/
                                                      `@@|_____|##'
                                                           (O)
                                                        .-'''''-.
                                                      .'  * * *  `.
                                                     :  *       *  :
                                                    : ~ A S C I I ~ :
                                                    : ~ A W A R D ~ :
                                                     :  *       *  :
                                                      `.  * * *  .'
                                                        `-.....-')" << endl;
                score += 10;
                player.exp += 50;
               flag++;
               
            }

        }
        else if (gold < 11)
        {
            cout << "\n\n\n\n\n";
            cout << "\t\t\t\t\t*------------------------------------*"<<endl;
            cout << "\t\t\t\t\t|  Insufficient Gold to purchase     |\n" ;
            cout << "\t\t\t\t\t|  Save the Princess to get Gold     |\n";
            cout << "\t\t\t\t\t*------------------------------------*"<<endl;
            cout << "\t\t\t\t---> Your Health: " << healthuser << endl;
            cout << "\t\t\t\t---> Creature Health: " << healthcreature << endl;

        }
    }
    else if (inventory == 2)
    {
        if (gold >= 30)
        {
            gold -= 30;
            healthuser = healthuser + 20;
            cout << "\n\n\n\n\n\n\n\n";
            cout << "You have gained 20 health" << endl;
            cout << "\t\t\t\t---> Your Health: " << healthuser << endl;
            cout << "\t\t\t\t---> Creature Health: " << healthcreature << endl;

        }
        else if (gold < 11)
        {
            cout << "\n\n\n\n\n";
            cout << "\t\t\t\t\t*------------------------------------*" << endl;
            cout << "\t\t\t\t\t|  Insufficient Gold to purchase     |\n";
            cout << "\t\t\t\t\t|  Save the Princess to get Gold     |\n";
            cout << "\t\t\t\t\t*------------------------------------*" << endl;
            cout << "\t\t\t\t---> Your Health: " << healthuser << endl;
            cout << "\t\t\t\t---> Creature Health: " << healthcreature << endl;

        }
    }
}
void fight_selection(char &choice1ofcreature, int &userHealth, int &creatureHealth, User &player)
{
    
    do {
        int choice;
        cout << "1. Fight" << endl;
        cout << "2. Inventory" << endl;
        cout << "0. Back " << endl;
        cout << "Enter choice: ";
        cin >> choice;
        system("cls");
        if (choice == 1)
        {
            fight(choice1ofcreature, userHealth, creatureHealth, player);
        }
        else if (choice == 2)
        {
            inventory(userHealth, creatureHealth, player);
        }
        else if (choice == 0)
        {
            break;
        }
        else if (!(choice == 0 || choice == 2 || choice == 1))
        {
            cout << "\n\nWrong choice, Enter again." << endl;
            cout << "\n\n\n\n\n\n\n";
            continue;
        }
        if (flag != 0)
        {
            // flag-- to avoid repeating it again in next time after winning or lose.
            flag--;
            char continueChoice;
            cout << "\n\nDo you want to continue fighting? (y/n): ";
            cin >> continueChoice;
            system("cls");
            if (continueChoice != 'y' && continueChoice != 'Y') {
                if (player.exp == 100)
                {
                    player.exp = 0;
                    player.level++;
                }

                displayUser(player);
                
                break;
                // Break out of the inner loop to go back to the main menu
            }
            else {
                // Reset health for the next fight

                userHealth = player.health;
                creatureHealth = 100;

                cout << "\n\n\n\n\n\n\n";
                cout << "\t\t\t\t---> Your Health: " << userHealth << endl;
                cout << "\t\t\t\t---> Creature Health: " << creatureHealth << endl;
            }
        }
    } while (1);

}
void chracterinformation()
{
    int back;
    do {
        system("cls");
        cout << "\n\n\n\n\n\n\n\n";
        cout << "\t\t\tCharacters:\n";
        cout << "\t\t\t1) Warrior" << endl;
        cout << "\t\t\t2) Mage" << endl;
        cout << "\t\t\t3) Rogue" << endl;
        cout << "\t\t\t0) Back" << endl;
        char choice;
        cout << "\t\t\tEnter choice (1,2,3 or 0)" << endl;
        cin >> choice;
        system("cls");
        if (choice == '1' || choice == 'w' || choice == 'W')
        {
            cout << R"( 
                             ,dM
                             dMMP
                            dMMM'
                            \MM/
                            dMMm.
                           dMMP'_\---.
                          _| _  p ;88;`.       HP  : 100
                        ,db; p >  ;8P|  `.     ATK : 20
                       (``T8b,__,'dP |   |
                       |   `Y8b..dP  ;_  |
                       |    |`T88P_ /  `\;
                       :_.-~|d8P'`Y/    /
                        \_   TP    ;   7`\
             ,,__        >   `._  /'  /   `\_
             `._ """"~~~~------|`\;' ;     ,'
                """~~~-----~~~'\__[|;' _.-'  `\
                        ;--..._     .-'-._     ;
                       /      /`~~"'   ,'`\_ ,/
                      ;_    /'        /    ,/
                      | `~-l         ;    /
                      `\    ;       /\.._|
                        \    \      \     \
                        /`---';      `----'
                       (     /            
                        `---'
)" << endl;
            cout<< "0) Back" << endl;
            do 
            {
                cout << "Enter 0 to back" << endl;
                cin >> back;
                if (back == 0)
                {
                    break;
                }
                else 
                {
                    system("cls");
                    cout << "Wrong choice , Enter again" << endl;
                    continue;
                }
            } while (1);
            if (back == 0)
            {
                continue;
            }
        }
        else if (choice == '2' || choice == 'm' || choice == 'M')
        {
            cout << R"(  
                    /\
                    ||
                    ||
                    ||
                    ||           {}
                    ||          .--.
                    ||         /.--.\
                    ||         |====|
                    ||         |`::`|
                   _||_    .-;`\..../`;_.-^-._
                    /\\   /  |...::..|`   :   `|              HP  : 100
                    |:'\ |   /'''::''|   .:.   |              ATK : 30
                     \ /\;-,/\   ::  |..:::::..|
                      \ <` >  >._::_.| ':::::' |
                       `""`  /   ^^  |   ':'   |
                             |       \    :    /
                             |        \   :   /
                             |___/\___|`-.:.-`
                              \_ || _/    `
                              <_ >< _>
                              |  ||  |
                              |  ||  | 
                             _\.:||:./_
                            /____/\____\
                   
)" << endl;
            cout<< "0) Back" << endl;
            do {
                cout << "Enter 0 to back" << endl;
                cin >> back;
                if (back == 0)
                {
                    break;
                }
                else {
                    system("cls");
                    cout << "Wrong choice , Enter again" << endl;
                    continue;
                }
            } while (1);
            if (back == 0)
            {
                continue;
            }
        }
        else if (choice == '3' || choice == 'R' || choice == 'r')
        {
            cout << R"( 
                                 .,
                         .    ____/__,
                       .' \  / \==\```
                      /    \ 77 \ |
                     /_.----\\__,-----.                HP  : 100
                 <--(\_|_____<__|_____/                ATK : 40
                     \  ````/|   ``/```
                      `.   / |    I|
                        `./  |____I|
                             !!!!!!!
                             | | I |
                             | | I |
                             \ \ I |
                             | | I |
                             | | I |
                             | | I |
                            _|_|_I_|
                           /__/____|  
             

)" << endl;
           
               cout << "0) Back" << endl;
            do {
                cout << "Enter 0 to back" << endl;
                cin >> back;
                if (back == 0)
                {
                    break;
                }
                else {
                    system("cls");
                    cout << "Wrong choice , Enter again" << endl;
                    continue;
                }
            } while (1);
            if (back == 0)
            {
                continue;
            }
        }
        else if (choice == '0')
        {
            break;
        }
        else
        {
            cout << "Wrong choice , Enter again.";
            continue;
        }
    } while (1);
}
void enemies_information()
{
    int back;
    do {
        system("cls");
        cout << "\n\n\n\n\n\n\n\n";
        cout << "\t\t\tCreatures :\n";
        cout << "\t\t\t---> T) Tasmanian Devil " << endl;
        cout << "\t\t\t---> S) Superman " << endl;
        cout << "\t\t\t---> D) Dragothorn" << endl;
        cout << "\t\t\t---> 0) Back" << endl;
        char choice;
        cout << "\t\t\tEnter choice (t,d,s or 0)" << endl;
        cin >> choice;
        system("cls");
        if (choice == '1' || choice == 't'||choice == 'T')
        {
            cout << R"( 
                                                  ^             
                                                 / \           ^
                           _,-~~~--~~~--._      (   \         / \
                       _,-'               `.__  (    \_.---._/   )
                     ,'                       `-(_` -'       `-. )      HP : 100
                    /       "--..                \.'           `/       ATK : 25
                   ,             `-.              :  _  .-.  _  : 
                  /                 ;             : (0).oYo.(0) ;
                /                    `             \.-'V'"'V'-./
               /                     '              \\^     ^//
      /\      /                      '     :    : .-'\\^   ^//
     ;  \    ;   /                  ,'  _.-`.    `. : \\^_^//
     ;   \   ;  ;`.               ,'~~-'     `.    `.`.`-.-'
      \   |_/   ;  `.        /-'/___.---.      `-.   `.`---.
       \       /     |      /____.---.)))         `-. `---.\
        \_____/      (____________))))\\\            `-.\\\\
                                    \\\\
)" << endl;
            cout << "0) Back" << endl;
          do 
          {
                cout << "Enter 0 to back" << endl;
                cin >> back;
                if (back == 0)
                {
                    break;
                }
                else 
                {
                    system("cls");
                    cout << "Wrong choice , Enter again." << endl;
                    continue;
                }
          } while (1);

            if (back == 0)
            {
                continue;
            }
        }
        else if (choice == '2' || choice == 'S' || choice == 's')
        {
            cout << R"(  
                          .=.,
                         ;c =\
                       __|  _/
                     .'-'-._/-'-._
                    /..   ____    \
                   /' _  [<_->] )  \             HP : 100
                  (  / \--\_>/-/'._ )            ATK : 35
                   \-;_/\__;__/ _/ _/
                    '._}|==o==\{_\/
                     /  /-._.--\  \_
                    // /   /|   \ \ \
                   / | |   | \;  |  \ \
                  / /  | :/   \: \   \_\
                 /  |  /.'|   /: |    \ \
                 |  |  |--| . |--|     \_\
                 / _/   \ | : | /___--._) \
                |_(---'-| >-'-| |       '-'
                       /_/     \_\
                   
)" << endl;
            cout << "0) Back" << endl;
            do {
                cout << "Enter 0 to back" << endl;
                cin >> back;
                if (back == 0)
                {
                    break;
                }
                else {
                    system("cls");
                    cout << "Wrong choice , Enter again." << endl;
                    continue;
                }
            } while (1);
            if (back == 0)
            {
                continue;
            }
        }
        else if (choice == '3' || choice == 'D' || choice == 'd')
        {
            cout << "\n\n\n";
            cout << R"( 
     (  )   /\   _                 (     
      \ |  (  \ ( \.(               )                      _____
    \  \ \  `  `   ) \             (  ___                 / _   \
   (_`    \+   . x  ( .\            \/   \____-----------/ (o)   \_            HP : 100
  - .-               \+  ;          (  O                           \____       ATK : 45
                            )        \_____________  `              \  /
  (__                +- .( -'.- <. - _  VVVVVVV VV V\                 \/
  (_____            ._._: <_ - <- _  (--  _AAAAAAA__A_/                  |
    .    /./.+-  . .- /  +--  - .     \______________//_              \_______
    (__ ' /x  / x _/ (                                  \___'          \     /
   , x / ( '  . / .  /                                      |           \   /
      /  /  _/ /    +                                      /              \/
     '  (__/                                             /                  \
)" << endl;
            cout << "0) Back" << endl;
            do {
                cout << "Enter 0 to back" << endl;
                cin >> back;
                if (back == 0)
                {
                    break;
                }
                else {
                    system("cls");
                    cout << "Wrong choice , Enter again." << endl;
                    continue;
                }
            } while (1);
            if (back == 0)
            {
                continue;
            }
        }
        else if (choice == '0')
        {
            break;
        }
        else
        {
            cout << "Wrong choice , Enter again.";
            continue;
        }
    } while (1);
}
void exit()
{
    system("cls");
    cout << "\n\n\n\n\n\n\n\n";
    cout << R"( 
                                      _______  _____ _____ _____ ____  
                                      | ____\ \/ /_ _|_   _| ____|  _ \ 
                                      |  _|  \  / | |  | | |  _| | | | |
                                      | |___ /  \ | |  | | | |___| |_| |
                                      |_____/_/\_\___| |_| |_____|____/  )" << endl;
    cout << "\n\n\n\n\n\n\n\n";
    cout << "\t\t\t\t\t\t\t\t\t---> Game Producer <---" << endl;
    cout << "\t\t\t\t\t\t\t\t\t     Ibtisam Abid - 035      " << endl;
    cout << "\t\t\t\t\t\t\t\t\t     Eshal Atif   - 023      " << endl;
    cout << "\t\t\t\t\t\t\t\t\t     Aizaz Ahmed  - 106    " << endl;

}

void embark1()
{
   
    int choiceUp;
    char choice1ofcreature;
    User player;
   
        do {
            User player = createUser();
            displayUser(player);
            if (player.exp == 100)
            {
                player.level++;
                player.exp = 0;
            }
            if (player.exp == -100)
            {
                player.level--;
                player.exp = 0;
            }
            do
            {
                displayquest1();
                displayquest2();
                cout << "\t\t\t\t3) Characters Information" << endl;
                cout << "\t\t\t\t4) Create chracter again" << endl;
                cout << "\t\t\t\t5) Enemies Information" << endl;
                cout << "\t\t\t\t99)Exit" << endl;
                cout << "Select your choice : ";
                cin >> choiceUp;
                if (choiceUp != 1 && choiceUp != 2 && choiceUp != 4 && choiceUp != 3&&choiceUp!=99 && choiceUp != 5 )
                {
                    system("cls");
                    cout << "\nWrong choice , Enter Again.";
                    continue;
                }
                else if (choiceUp == 4)
                {
                    break;
                }
                else if (choiceUp == 99)
                {
                    exit();
                    break;
                }
                else if (choiceUp == 3)
                {
                    chracterinformation();
                    continue;
                }
                else if (choiceUp == 5)
                {
                    enemies_information();
                    continue;
                }
              
                switch (choiceUp)
                {
                case 1:
                {
                    do
                    {
                        system("cls");
                     
                        cout << "\n\n\n\n\n\n\n\n";
                        cout << "\t\t\t---> T) Tasmanian Devil \t\tDifficulty level 1" << endl;
                        cout << "\t\t\t---> S) Superman \t\t\tDifficulty level 2" << endl;
                        cout << "\t\t\t---> D) Dragothorn\t\t\tDifficulty level 3" << endl;
                        cout << "\t\t\t---> 0) Back" << endl;
                        cout << "\t\t\t\tSelect   't' for Tasmanian Devil " << endl;
                        cout << "\t\t\t\t\t 's' for Superman" << endl;
                        cout << "\t\t\t\t\t 'd' for Dragothorn" << endl;
                        cout << "\t\t\t\t\t '0' to back" << endl;
                        cin >> choice1ofcreature;
                        cout << "-----------------------------------------------------------" << endl;
                        system("cls");
                        if (choice1ofcreature == 't' || choice1ofcreature == 'T' || choice1ofcreature == '1')
                        {
                            cout << R"(
                                                                    ^             
                                                                   / \           ^
                                             _,-~~~--~~~--._      (   \         / \
                                         _,-'               `.__  (    \_.---._/   )
                                       ,'                       `-(_` -'       `-. )   
                                      /       "--..                \.'           `/  
                                     ,             `-.              :  _  .-.  _  : 
                                    /                 ;             : (0).oYo.(0) ;
                                  /                    `             \.-'V'"'V'-./
                                 /                     '              \\^     ^//
                        /\      /                      '     :    : .-'\\^   ^//
                       ;  \    ;   /                  ,'  _.-`.    `. : \\^_^//
                       ;   \   ;  ;`.               ,'~~-'     `.    `.`.`-.-'
                        \   |_/   ;  `.        /-'/___.---.      `-.   `.`---.
                         \       /     |      /____.---.)))         `-. `---.\
                          \_____/      (____________))))\\\            `-.\\\\
                                                      \\\\
)" << endl;

                            displayCreatureInfo(choice1ofcreature);

                            int userHealth = player.health;
                            int creatureHealth = 100;
                            fight_selection(choice1ofcreature, userHealth, creatureHealth, player);
                           

                        }

                        else if (choice1ofcreature == 's' || choice1ofcreature == 'S' || choice1ofcreature == '2')
                        {
                            cout << R"(
                                                   .=.,
                                                  ;c =\
                                                __|  _/
                                              .'-'-._/-'-._
                                             /..   ____    \
                                            /' _  [<_->] )  \
                                           (  / \--\_>/-/'._ )
                                            \-;_/\__;__/ _/ _/
                                             '._}|==o==\{_\/
                                              /  /-._.--\  \_
                                             // /   /|   \ \ \
                                            / | |   | \;  |  \ \
                                           / /  | :/   \: \   \_\
                                          /  |  /.'|   /: |    \ \
                                          |  |  |--| . |--|     \_\
                                          / _/   \ | : | /___--._) \
                                         |_(---'-| >-'-| |       '-'
                                                /_/     \_\

        )" << endl;

                            displayCreatureInfo(choice1ofcreature);
                            int userHealth = player.health;
                            int creatureHealth = 100;

                            fight_selection(choice1ofcreature, userHealth, creatureHealth, player);
                        }

                        else if (choice1ofcreature == 'd' || choice1ofcreature == 'D' || choice1ofcreature == '3')
                        {
                            cout << R"(

                         (  )   /\   _                 (     
                          \ |  (  \ ( \.(               )                      _____
                        \  \ \  `  `   ) \             (  ___                 / _   \
                       (_`    \+   . x  ( .\            \/   \____-----------/ (o)   \_
                      - .-               \+  ;          (  O                           \____
                                                )        \_____________  `              \  /
                      (__                +- .( -'.- <. - _  VVVVVVV VV V\                 \/
                      (_____            ._._: <_ - <- _  (--  _AAAAAAA__A_/                  |
                        .    /./.+-  . .- /  +--  - .     \______________//_              \_______
                        (__ ' /x  / x _/ (                                  \___'          \     /
                       , x / ( '  . / .  /                                      |           \   /
                          /  /  _/ /    +                                      /              \/
                         '  (__/                                             /                  \
                        
        )" << endl;
                            displayCreatureInfo(choice1ofcreature);
                            int userHealth = player.health;
                            int creatureHealth = 100;

                            fight_selection(choice1ofcreature, userHealth, creatureHealth, player);
                        }
                        else if (choice1ofcreature == '0')
                        {
                            break;
                        }
                        else
                        {
                            cout << "\n\nWrong choice , Enter again.";
                            continue;
                        }   
                    } while (true);
                    if (choice1ofcreature == '0')
                    {
                        continue;
                    }
                    break;
                }
                case 2:
                {
                    system("cls");
                    cout << "\n";
                    cout << R"(
                       ____  ____  ___ _   _  ____ _____ ____ ____        _   vvvvvvvvv   _
                      |  _ \|  _ \|_ _| \ | |/ ___| ____/ ___/ ___|      ( `-._\...../_.-' )
                      | |_) | |_) || ||  \| | |   |  _| \___ \___ \       \   ((('_')))   /
                      |  __/|  _ < | || |\  | |___| |___ ___) |__) |       )   ))) (((   (
                      |_|___|_| \_\___|_| \_|\____|_____|____/____/       (   ((( v )))   )
                          | ____| |      / \  |  _ \    / \                )`--' )X( `-._(    
                          |  _| | |     / _ \ | |_) |  / _ \              /   _./   \._   \  
                          | |___| |___ / ___ \|  _ <  / ___ \            /  .' /     \ `.  \   
                          |_____|_____/_/   \_\_| \_\/_/   \_\          (__/  /       \  \__)    
                                                                             /         \
                                                                            /           \
                                                                           WwWwWwWwWwWwWwW 
                                                                            
)" << endl;
                  
                    cout << "Game Description: To save the princess, You have to play a dice game with the creature.If you save or lose the princess," << endl
                        << "You will gain or lose the golds respectively." << endl;
                    cout << "\t\t\t\t---> 1)  Start \n";
                    cout << "\t\t\t\t---> 0)  Back \n";
                    cout << "\t\t\t\t---> 99) Exit\n";
                  
                    cout << "Enter your choice(1 , 0 or 99)\n";
                    cin >> choiceUp;
                    system("cls");
                    char choice;
                    if (choiceUp == 1)
                    {
                        do {
                            srand(time(0));
                            cout << "\n\n\n\n\n\n\n";
                            cout << R"(
                                                     (( _______
                                           _______     /\O    O\
                                          /O     /\   /  \      \
                                         /   O  /O \ / O  \O____O\ ))
                                      ((/_____O/    \\    /O     /
                                        \O    O\    / \  /   O  /
                                         \O    O\ O/   \/_____O/
                                          \O____O\/ )) mrf      )))" << endl;
                            cout << "\n\n\t\t\t\t  Enter any key to roll the dice" << endl;
                            system("pause");
                            system("cls");
                            int playerr = rand() % 7;
                            int computer = rand() % 7;
                            cout << "\n\n\n\n\n\n\n\n\n";
                            cout << "\t\t\t\t---> " << player.name << " : " << playerr << endl;
                            cout << "\t\t\t\t---> Creature : " << computer << endl;
                            if (computer > playerr)
                            {
                                gold -= 10;
                                cout << "\t\t\t\*-----------------------------------------------------------*" << endl;
                                cout << "\t\t\t\|                                                           |" << endl;
                                cout << "\t\t\t\|         You lost the princess and 10 Golds.               |" << endl;
                                if (gold > 100)
                                {
                                    cout << "\t\t\t|                 You have " << gold << " Golds.                       |" << endl;
                                }
                                else if (gold < 100)
                                {
                                    cout << "\t\t\t|                 You have " << gold << " Golds.                        |" << endl;
                                }
                                cout << "\t\t\t\|                                                           |" << endl;
                                cout << "\t\t\t\*-----------------------------------------------------------*" << endl;

                            }
                            else if (playerr == computer)
                            {
                                cout << "\t\t\t*-----------------------------------------------------------*" << endl;
                                cout << "\t\t\t|                                                           |" << endl;
                                cout << "\t\t\t|                        Do Again                           |" << endl;
                                cout << "\t\t\t|                                                           |" << endl;
                                cout << "\t\t\t*-----------------------------------------------------------*" << endl;

                            }
                            else
                            {
                                gold += 20;
                                cout << "\t\t\t*-----------------------------------------------------------*" << endl;
                                cout << "\t\t\t|                                                           |" << endl;
                                cout << "\t\t\t|         You saved the princess and got 20 Golds.          |" << endl;
                                if (gold >= 100)
                                {
                                    cout << "\t\t\t|                 You have " << gold << " Golds.                       |" << endl;
                                }
                                else if (gold < 100)
                                {
                                    cout << "\t\t\t|                 You have " << gold << " Golds.                        |" << endl;
                                }
                                cout << "\t\t\t|                                                           |" << endl;
                                cout << "\t\t\t*-----------------------------------------------------------*" << endl;


                            }
                            cout << "Do you want to roll again? (y/n)" << endl;
                            cin >> choice;
                            system("cls");
                            if (choice == 'n')
                            {
                                break;
                            }
                        } while (1);
                        if (choice == 'n')
                        {
                            continue;
                        }
                        break;
                    }
                    else if (choiceUp == 99)
                    {
                        exit();
                        break;
                    }  
                    else if (choiceUp==0)
                    {
                        continue;
                    }
                    else if (choice1ofcreature == '0')
                    {
                        continue;
                    }
                    else if (choiceUp == 3)
                    {
                        continue;
                    }
                }
                }
                break;

            } while (1);

            if (choiceUp == 4)
            {
                system("cls");
                continue;
            }
            else if (choiceUp == 99)
            {
                break;
            }
          
        } while (1);
    
    
}
    void HEHE()
    {
        cout << "\n\n\n\n";
        cout << R"(
                    _____       _         ___                  _     _____                    
                   | ____|_ __ (_) ___   / _ \ _   _  ___  ___| |_  |  ___|__  _ __ __ _  ___ 
                   |  _| | '_ \| |/ __| | | | | | | |/ _ \/ __| __| | |_ / _ \| '__/ _` |/ _ \
                   | |___| |_) | | (__  | |_| | |_| |  __/\__ \ |_  |  _| (_) | | | (_| |  __/
                   |_____| .__/|_|\___|  \__\_\\__,_|\___||___/\__| |_|  \___/|_|  \__, |\___|
                         |_|                                                       |___/      
)" << endl;
        cout << "Game Information : Welcome to the mythical land of Eldoria, where brave adventurers embark on quests to become legendary" << endl
            << "heroes.In this console - based RPG, players create a character,explore the world, engage in battles, and complete quests" << endl
            << "The game features dynamic storytelling,character progression, and a variety of quests to keep players immersed in the" << endl
            << "fantasy realm." << endl << endl;

        int choice;
        do
        {
            cout << "\t\t\t\t\t     ---> 1) Start Game" << endl;
            cout << "\t\t\t\t\t     ---> 0) Exit" << endl;
            cout << "\t\t\t\t\t          Enter choice" << endl;
            cout << "\t\t\t\t\t               ";
            cin >> choice;
            if (choice == 1)
            {
                system("cls");
                embark1();
                break;
            }
            else if (choice == 0)
            {
                exit();
                break;
            }
            else
            {
                system("cls");
                cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
                cout << "Wrong choice.Enter again" << endl;
                continue;
            }
        } while (1);


    }
int main()
{
    HEHE();
    system("pause");
    return 0;
}