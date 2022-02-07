#include <iostream>
#include <string>

using namespace std;

// its OO so i will take advantage of it

class Player { public:
    int HP;
    string name;
    int moneyInPocket;
    
    void
    says(string message)
    {
        printf("%s", message.c_str());
    }
};

int randomBuffer;
string inputBuffer;

int 
random(int max)
{
    srand((unsigned) time(0));
    max = 1 + (rand() % max);
    return max;
}

bool
game(string playername)
{
    Player player;
    player.name = playername;

    randomBuffer = random(10);
    if (randomBuffer < 3)
    {
        printf("You get lucky, and get to start off with 10 dollars.");
        player.moneyInPocket = 10;
    } // the player will or will not get money in player.moneyInPocket
    
    printf("You end up somewhere in a castle, and there are 2 doors in front of you, which path to pick? [left / right]");
    cin >> inputBuffer;

    if (inputBuffer == "left")
    {
        printf("you choose the left path");
    }
    else if (inputBuffer == "right")
    {
        printf("you choose the right path");
    }
    

    return true;
}