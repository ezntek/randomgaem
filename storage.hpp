#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;
namespace fs = std::filesystem;

float buf;
float balance;

// return values shall be used

void
getData()
{
    ifstream wa;
    wa.open("rgMetadata/.Wallet");
    wa >> buf;
    wa.close();
}

class Wallet { public:

    void
    deposit(int depositAmount)
    {  
        ofstream wallet;
        wallet.open("rgMetadata/.Wallet");

        buf = getData();
        
        balance = buf + depositAmount;
        wallet << balance;

        return balance;
        wallet.close();
    }

    float
    withdraw(int withdrawAmount)
    {
        ofstream wallet;
        wallet.open("rgMetadata/.Wallet");

        buf = getData();

        if (withdrawAmount > buf)
        {
            printf("sorry, but you're too broke to withdraw that much...\n");
            return buf;
        }

        balance = buf - withdrawAmount;
        return balance;
        wallet.close();
    }

    float
    checkbal()
    {
        buf = getData();
        return buf;
    }
}