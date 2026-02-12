#include <iostream>
#include <string>

using namespace std;

 // Structure
struct Account {
    string ownerName;
    int accountNumber;
    double balance;
};

 // Functions (Pass by Reference)
void deposit(Account &acc) {
    double amount;
    cout << "Enter amount to deposit: ";
    cin >> amount;
    acc.balance += amount;
    cout << "Deposit successful! New balance: $" << acc.balance << endl;
}

// Functions (Pass by Pointer)
void showAccountDetails(Account* accPtr) {
    cout << "\n--- Account Details ---" << endl;
    cout << "Owner: " << accPtr->ownerName << endl;
    cout << "Acc #: " << accPtr->accountNumber << endl;
    cout << "Balance: $" << accPtr->balance << endl;
}

int main() {
    // Arrays (Storing 5 accounts)
    Account bank[5] = {
        {"Mary", 101, 1000.07},
        {"Bob", 102, 1340.50},
        {"Colton", 103, 128.37},
        {"Kary", 104, 375.25},
        {"Brian", 105, 465.48}
    };

    int choice = 0;
    int userIdx = -1; 


    // Printout/Display (Cout) & User Input (Cin)
    cout << "Welcome to the Bank!" << endl;
    cout << "Enter your Account Index (0, 1, 2, 3, or 4): ";
    cin >> userIdx;

   // If/Else Logic
    if (userIdx < 0 || userIdx > 4) {
        cout << "Invalid account selected. Exiting." << endl;
        return 0;
    }

   // Pointers (Pointing to the selected account)
    Account* currentAccount = &bank[userIdx];

    // Loops (Do-While for the menu)
    do {
        cout << "\n1. Check Balance\n2. Deposit\n3. Show All Balances\n4. Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            showAccountDetails(currentAccount);
        } else if (choice == 2) {
            deposit(*currentAccount); // Dereferencing the pointer
        }

    } while (choice != 3);

    // For Loop (Final printout of all accounts)
    cout << "\nFinal Bank State:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << bank[i].ownerName << ": $" << bank[i].balance << endl;
    }

    return 0;
}