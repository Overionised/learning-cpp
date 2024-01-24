#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int cycle;
int usr[3][3] = {
    {111111, 211111, 311111},  // usr
    {1111, 2111, 3111},         // pin
    {200, 300, 400}             // cash
};

bool login(string askfor) {
    int input;
    bool validCredentials = false;
    int tries = 3;

    while (tries > 0) {
        cout << "Please enter " << askfor << ": ";
        cin >> input;

        if (askfor == "PIN") {
            for (int i = 0; i < 3; i++) {
                if (usr[1][i] == input) {  // Fix index for PIN
                    validCredentials = true;
                    break;
                }
            }
        } else {
            for (int i = 0; i < 3; i++) {
                if (usr[0][i] == input) {  // Fix index for username
                    validCredentials = true;
                    break;
                }
            }
        }

        if (validCredentials) {
            break;
        }

        cout << "Invalid input. Tries left: " << tries - 1 << endl;
        tries--;
    }

    return validCredentials;
}

bool amiin(bool validCredentials) {
    if (validCredentials) {
        if (cycle == 1) {
            cout << "Access granted." << endl;
            return true;
        } else if (cycle == 0) {
            cout << "Username verified. Enter PIN next." << endl;
            validCredentials = login("PIN");
            if (validCredentials) {
                cout << "Access granted." << endl;
                return true;
            } else {
                cout << "Access denied." << endl;
                return false;
            }
        }
    } else {
        cout << "Access denied." << endl;
        return false;
    }
}

void changePIN() {
    int newPIN, confirmPIN;
    cout << "Enter your new PIN: ";
    cin >> newPIN;

    cout << "Confirm your new PIN: ";
    cin >> confirmPIN;

    if (newPIN == confirmPIN) {
        usr[1][cycle] = newPIN;
        cout << "PIN changed successfully." << endl;
    } else {
        cout << "PINs do not match. PIN remains unchanged." << endl;
    }
}

void withdrawMoney(int amount) {
    if (usr[2][cycle] - amount < 0) {
        cout << "Insufficient funds. Cannot withdraw $" << amount << endl;
    } else {
        usr[2][cycle] -= amount;
        cout << "$" << amount << " withdrawn successfully." << endl;
    }
}

void userAction() {
    cout << "Choose an action:" << endl;
    cout << "1. Check account balance" << endl;
    cout << "2. Change PIN" << endl;
    cout << "3. Withdraw money" << endl;

    int choice;
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "Your account balance is: $" << usr[2][cycle] << endl;
            break;
        case 2:
            changePIN();  // Call the function to change the PIN
            break;
        case 3:
            int withdrawAmount;
            cout << "Enter the amount to withdraw: ";
            cin >> withdrawAmount;
            withdrawMoney(withdrawAmount);  // Call the function to withdraw money
            break;
        default:
            cout << "Invalid choice." << endl;
    }
}

int main() {
    bool validCredentials;
    bool ender;

    for (cycle = 0; cycle < 2; cycle++) {
        validCredentials = login("username");
        ender = amiin(validCredentials);

        if (ender) {
            userAction();  // Call the userAction function after successful login
        }
    }
    cout << "Goodbye now, hope you had fun" << endl;
    return 0;
}
