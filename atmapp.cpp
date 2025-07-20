#include <iostream>
#include <fstream>
using namespace std;

int getBalance() {
    ifstream inFile("balance.txt");
    int balance = 0;

    if (!inFile) {
        // File doesn't exist, set default balance
        ofstream outFile("balance.txt");
        balance = 10000;
        outFile << balance;
        outFile.close();
    } else {
        inFile >> balance;
    }

    inFile.close();
    return balance;
}

void updateBalance(int balance) {
    ofstream outFile("balance.txt");
    outFile << balance;
    outFile.close();
}

int main() {
    const int pin = 1234;
    int enteredPin, balance, choice, amount;

    cout << "Welcome to ATM Machine\n";
    cout << "Please enter your PIN: ";
    cin >> enteredPin;

    if (enteredPin != pin) {
        cout << "Invalid PIN. Access Denied!\n";
        return 0;
    }

    balance = getBalance();

    do {
        cout << "\n==== ATM MENU ====\n";
        cout << "1. Check Balance\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Your current balance is Rs." << balance << "\n";
                break;
            case 2:
                cout << "Enter deposit amount: Rs.";
                cin >> amount;
                if (amount > 0) {
                    balance += amount;
                    updateBalance(balance);
                    cout << "Rs." << amount << " deposited successfully.\n";
                } else {
                    cout << "Invalid amount!\n";
                }
                break;
            case 3:
                cout << "Enter withdrawal amount: Rs.";
                cin >> amount;
                if (amount > balance) {
                    cout << "Insufficient funds!\n";
                } else {
                    balance -= amount;
                    updateBalance(balance);
                    cout << "Rs." << amount << " withdrawn successfully.\n";
                }
                break;
            case 4:
                cout << "Thank you for using our ATM. Goodbye!\n";
                break;
            default:
                cout << "Invalid option. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
