
#include <iostream>
using namespace std;

int main() {
    const int INNER_FARE = 10;
    const int MIDDLE_FARE = 20;
    const int OUTER_FARE = 30;

    enum Zone {
        INNER = 1,
        MIDDLE = 2,
        OUTER = 3
    };

    Zone passengerZone = MIDDLE;

    cout << "Metro Fare System" << endl;
    cout << "Inner Fare: Rs. " << INNER_FARE << endl;
    cout << "Middle Fare: Rs. " << MIDDLE_FARE << endl;
    cout << "Outer Fare: Rs. " << OUTER_FARE << endl;

    cout << "Selected Zone: ";

    if (passengerZone == INNER) {
        cout << "Inner" << endl;
    } else if (passengerZone == MIDDLE) {
        cout << "Middle" << endl;
    } else {
        cout << "Outer" << endl;
    }

    return 0;
}
