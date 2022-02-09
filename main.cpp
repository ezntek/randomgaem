#include <iostream>
#include <string>
#include "play.hpp"
#include "atm.hpp"

using namespace std;

/*

Notes:
 - Start porting the base game (+.)
 - Write a hud (++)
*/

string choice;
string name;

int
main(int      argc,
     char   **argv)
{ while (true) {

    system("clear");

    // randomgaem (its spelt wrong on purpose now shut up)
    printf("Welcome to randomGaem!");
    printf("(shut up it is gaem not game)"); cout << endl;

    printf("+---------------------------------+"); cout << endl;
    printf("+ Random Gaem by Ezintegg2398     +"); cout << endl;
    printf("+ Directed by jasonddebaba        +"); cout << endl;
    printf("+                                 +"); cout << endl;
    printf("+ Written in C++, Version rolling +"); cout << endl;
    printf("+                                 +"); cout << endl;
    printf("+ 1. Launch the ATM [incomplete]  +"); cout << endl;
    printf("+ 2. Launch the Game              +"); cout << endl;
    printf("+ 3. Exit                         +"); cout << endl;
    printf("+---------------------------------+"); cout << endl;

    cout << "what to do?: "; cin >> choice;

    if (choice == "1")
    {
        atmmenu();
    }
    else if (choice == "2")
    {
        printf("What is your name?: ");
        cin >> name;
        game(name);
    }
    else if (choice == "3")
    {
        return 0; // just exit
    }

    return 0;

}}
