
#include <iostream>
#include <iomanip>
#include <limits>
#include <string>

using namespace std;

const long long MIN_BALANCE_PAISE = 5000;

long long fare(int zone, bool peak)
{
    long long base = 0;

    switch (zone)
    {
        case 1:
            base = 1000;
            break;
        case 2:
            base = 2000;
            break;
        case 3:
            base = 3000;
            break;
        default:
            return -1;
    }

    if (peak)
        base += base * 20 / 100;

    return base;
}

int main()
{
    int zone;
    int peakInput;
    long long balance;

    cout << "CITY METRO SMART-CARD SYSTEM\n";
    cout << "Zones: 1-Inner, 2-Middle, 3-Outer\n";

    // Read and validate zone
    while (true)
    {
        cout << "Enter zone number: ";

        if (cin >> zone)
        {
            if (zone >= 1 && zone <= 3)
                break;

            cout << "Invalid zone. Enter 1, 2, or 3.\n";
        }
        else
        {
            cout << "Invalid input. Enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    // Read and validate peak status
    while (true)
    {
        cout << "Peak hour? (1=Yes, 0=No): ";

        if (cin >> peakInput)
        {
            if (peakInput == 0 || peakInput == 1)
                break;

            cout << "Enter only 1 or 0.\n";
        }
        else
        {
            cout << "Invalid input. Enter 1 or 0.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    // Read and validate balance
    while (true)
    {
        cout << "Enter card balance in rupees: ";

        if (cin >> balance)
        {
            if (balance >= 0 && balance <= 1000000000LL)
                break;

            cout << "Enter a valid non-negative balance.\n";
        }
        else
        {
            cout << "Invalid input. Enter a whole number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    long long balancePaise = balance * 100;
    long long f = fare(zone, peakInput == 1);

    cout << "\n========== JOURNEY REPORT ==========\n";
    cout << "Zone: ";

    switch (zone)
    {
        case 1: cout << "Inner"; break;
        case 2: cout << "Middle"; break;
        case 3: cout << "Outer"; break;
    }

    cout << "\nPeak hour: " << (peakInput ? "Yes" : "No");

    cout << fixed << setprecision(2);
    cout << "\nInitial balance: Rs " << balancePaise / 100.0;

    if (balancePaise - f >= MIN_BALANCE_PAISE)
    {
        balancePaise -= f;

        cout << "\nFare charged: Rs " << f / 100.0;
        cout << "\nJourney status: APPROVED";
    }
    else
    {
        cout << "\nFare charged: Rs " << 0.0;
        cout << "\nJourney status: DENIED (low balance)";
    }

    cout << "\nRemaining balance: Rs "
         << balancePaise / 100.0 << '\n';

    cout << "====================================\n";

    return 0;
}
