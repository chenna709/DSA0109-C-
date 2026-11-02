
#include <iostream>
using namespace std;

class SmartCard {
public:
    int balance;

    void showBalance() {
        cout << "Balance: Rs. " << balance << endl;
    }
};

int main() {
    SmartCard card;

    card.balance = 500;

    cout << "Metro Smart Card" << endl;
    card.showBalance();

    card.balance = card.balance - 20;

    cout << "After journey:" << endl;
    card.showBalance();

    return 0;
}
