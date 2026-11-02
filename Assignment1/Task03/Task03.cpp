
#include <iostream>
using namespace std;

int main() {
    int balance = 500;
    int fare = 20;
    int remainingBalance;

    remainingBalance = balance - fare;

    cout << "Metro Smart Card" << endl;
    cout << "Initial Balance: Rs. " << balance << endl;
    cout << "Journey Fare: Rs. " << fare << endl;
    cout << "Remaining Balance: Rs. " << remainingBalance << endl;

    cout << "Size of int: " << sizeof(int) << " bytes" << endl;
    cout << "Size of char: " << sizeof(char) << " byte" << endl;
    cout << "Size of double: " << sizeof(double) << " bytes" << endl;

    return 0;
}
