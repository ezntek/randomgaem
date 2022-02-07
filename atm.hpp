#include <iostream>
#include <string>
#include <fstream>
#include "storage.hpp"

using namespace std;

Wallet wallet;

float storeRet;
int pin;
int pinInput;
string loginstate = "not logged in";
float inmoneyc;
float outmoneyc;
string choicebf;

class ATM { public:

    void 
    hello()
    {
        cout << "WELCOME TO THE ATM" << endl;
        system("clear");
    } 

    void
    checkBal()
    {
        storeRet = wallet.checkbal();
        printf("Your balance is: %0.2f\n", storeRet);
    }

    void
    login()
    {
        if (!fs::exists("rgMetadata/.Pin"))
        {
            printf("You didnt set a pin yet... Go set one?");
        }

        ofstream pinVerification;
        pinVerification.open("rgMetadata/.Pin");
        pin << pinVerification;
        pinVerification.close();

        for (size_t i = 0; i < 3; i++)
        {

            cout << "Enter your pin here: "; 
            cin >> pinInput;

            if (pinInput == pin)
            {
                printf("login success!\n");
                loginstate = "logged in!";
            }
            else if (pinInput != pin)
            {
                printf("you didn't enter your PIN correctly, please try again.\n");
            }

            if (i = 3)
            {
                printf("you entered the wrong PIN too many times, please try again later.\n");
                return;
            } 

        } // for loop

    } // function

    void
    withdraw()
    {
        if (loginstate == "not logged in")
        {
            printf("You will need to log in first.");
            return;
        }
        
        cout << "How much money do you want to withdraw?";
        cin >> choicebf;

        wallet.withdraw(choicebf);
    }

    void
    deposit()
    {
        if (loginstate == "not logged in")
        {
            printf("You will need to log in first.");
            return;
        }
        
        cout << "How much money do you want to deposit?";
        cin >> choicebf;

        wallet.deposit(choicebf);
    }

    void
    createPin(bool create)
    {
        if (create == true)
        {
            if (!fs::exists("rgMetadata/.Pin"))
            {
                printf("you have already created the PIN, you just need to log in.\n")
            }
        }
        
        ofstream pinstream;
        int pincode;
        int verifycode;
        pinstream.open("rgMetadata/.Pin");

        for (size_t i = 0; i < 3; i++)
        {
            printf("Enter a PIN to set. ");
            cin >> pincode;

            printf("Re-enter that PIN code to verify. ");
            cin >> verifycode;

            if (pincode != verifycode)
            {
                if (i = 3)
                {
                    printf("You tried too many times but the PINs never matched. please try again from the menu.\n");
                    return;
                }
                printf("The PIN codes do not match. Please try again.\n");
            }
            else if (pincode == verifycode)
            {
                pinstream << verifycode;
                pincode = 0;
                pinstream.close();

                printf("the PIN creation was successful, Log in from the menu.\n");

                return;
            } // if
        } // 3x for loop
    } // function

}; // class

ATM atm;

bool boolret;

bool
atmmenu()
{
    // code here
    system("clear");
    while (true)
    {

        int atmchoice;
        ATM atm;
        cout << endl;
        atm.checkbalance(); cout << endl;
        atm.hello(); cout << endl;
        printf("what would you like to do in the ATM??"); cout << endl; cout << endl;
        printf("1. Log into the ATM [%s]", loginstate.c_str()); cout << endl;
        printf("2. Set a PIN Code"); cout << endl;
        printf("3. Change your PIN Code"); cout << endl;
        printf("4. Deposit pcMoney/pcDollars"); cout << endl;
        printf("5. Withdraw pcMoney/pcDollars"); cout << endl;
        printf("6. Exit to main screen"); cout << endl;
        cout << "enter your choice here [Number ID]: ";
        cin >> atmchoice;

        if (atmchoice == 1) 
        {
            boolret = atm.login();
            if (boolret != true)
            {
                printf("Some error occured. Please report this issue.");
                return false;
            }

        } else if (atmchoice == 2) 
        {
            boolret = atm.createPcPin(true);
            if (boolret != true)
            {
                printf("Some error occured. Please report this issue.");
                return false;
            }

        } else if (atmchoice == 4)
        {
            atm.deposit();

        } else if (atmchoice == 5)
        {
            atm.withdraw();

        } else if (atmchoice == 6)
        {
            return true;

        } else if (atmchoice == 3)
        {
            boolret = atm.changePcPin();
            if (boolret != true)
            {
                printf("Some error occured. Please report this issue.");
                return false;
            }
            
        }
        
    }
 
    return true;
}

