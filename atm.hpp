#include <iostream>
#include <string>
#include <fstream>
#include "storage.hpp"

using namespace std;
namespace fs = std::filesystem;

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
    changePin()
    {
        // calling createPin would help very much

        if (loginstate == "not logged in")
        {
            printf("Please log in before you try to change your PIN.");
        }
        if (!fs::exists("rgMetadata/.Pin"))
        {
            printf("you didn't set a PIN yet, please go set it.");
        }

        fstream pinfile;
        pinfile.open("rgMetadata/.Pin", ios::out);
        pinfile >> pin;
        pinfile.close();

        for (size_t i = 0; i < 3; i++)
        {
            printf("enter your current PIN: ");
            cin >> pinInput;

            if (pinInput == pin)
            {
                clear();
                printf("Success! Now you can change your pin.\n");
                createPin(false);
            } 
            else 
            {
                if (i == 3)
                {
                    printf("You tried too many times, please try again later.\n");
                }
                clear();
                printf("Pin is wrong, please try again.\n");
                
            } // if statement      
        } // for loop
    } // function

    void 
    hello()
    {
        cout << "WELCOME TO THE ATM" << endl;
        clear();
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

        fstream pinVerification;
        pinVerification.open("rgMetadata/.Pin", ios::out);
        pinVerification >> pin;
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

            if (i == 3)
            {
                printf("you entered the wrong PIN too many times, please try again later.\n");
                return;
            } 

        } // for loop

    } // function

    void
    withdraw(int outamt)
    {
        if (outamt != NULL) {
            wallet.deposit(outamt);
        }
        else if (loginstate == "not logged in")
        {
            printf("You will need to log in first.");
            return;
        }
        
        cout << "How much money do you want to withdraw?";
        cin >> outmoneyc;

        wallet.withdraw(outmoneyc);
    }

    void
    deposit(int inamt)
    {
        if (inamt != NULL) {
            wallet.deposit(inamt);
        }
        else if (loginstate == "not logged in")
        {
            printf("You will need to log in first.");
            return;
        }
        
        cout << "How much money do you want to deposit?";
        cin >> inmoneyc;

        wallet.deposit(inmoneyc);
    }

    void
    createPin(bool create)
    {
        if (create == true)
        {
            if (!fs::exists("rgMetadata/.Pin"))
            {
                printf("you have already created the PIN, you just need to log in.\n");
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
                if (i == 3)
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

void
atmmenu()
{ while (true) {

    clear();
    atm.hello();
    cout << endl;
    printf("+---------------------------------------+"); cout << endl;

    if (loginstate == "logged in!")
  { printf("+ 1. Log in to the ATM [%s]     +\n", loginstate.c_str()); cout << endl; } else {
    printf("+ 1. Log in to the ATM [%s]  +\n", loginstate.c_str()); }

    printf("+ 2. Create an ATM PIN                  +"); cout << endl;
    printf("+ 3. Withdraw some money                +"); cout << endl;
    printf("+ 4. Deposit some money                 +"); cout << endl;
    printf("+ 5. Change your ATM PIN                +"); cout << endl;
    printf("+---------------------------------------+"); cout << endl;
    cout << "Enter your choice: "; cin >> choicebf;

    if (choicebf == "1")
    {
        atm.login();
    }
    else if (choicebf == "2")
    {
        atm.createPin(true);
    }
    else if (choicebf == "3")
    {
        printf("how much money to withdraw?");
        cin >> outmoneyc;
        atm.withdraw(outmoneyc);
    }
    else if (choicebf == "4")
    {
        printf("how much money to deposit?");
        cin >> inmoneyc;
        atm.deposit(inmoneyc);
    }
    else if (choicebf == "5")
    {
        // code
    }
}}
