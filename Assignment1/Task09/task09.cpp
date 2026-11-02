
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

enum class Zone { Inner = 1, Middle = 2, Outer = 3 };

const long long MIN_BALANCE = 5000;
const int SURCHARGE_PERCENT = 20;

// Convert input text to an integer safely
bool readInteger(string input, int& value)
{
    stringstream ss(input);
    char extra;

    if (!(ss >> value))
        return false;

    if (ss >> extra)
        return false;

    return true;
}

// Check valid zone
bool validZone(int zone)
{
    return zone >= 1 && zone <= 3;
}

// Check peak hours: 08:00-09:59 and 17:00-19:59
bool isPeak(int hour)
{
    return (hour >= 8 && hour < 10) ||
           (hour >= 17 && hour < 20);
}

// Calculate fare in paise
long long fare(int zone, int hour)
{
    if (!validZone(zone) || hour < 0 || hour > 23)
        return -1;

    long long base;

    switch (static_cast<Zone>(zone))
    {
        case Zone::Inner:
            base = 1000;
            break;

        case Zone::Middle:
            base = 2000;
            break;

        case Zone::Outer:
            base = 3000;
            break;

        default:
            return -1;
    }

    if (isPeak(hour))
        base += base * SURCHARGE_PERCENT / 100;

    return base;
}

// Check whether balance remains at least Rs 50
bool canTravel(long long balance, long long f)
{
    return f >= 0 && balance >= f &&
           balance - f >= MIN_BALANCE;
}

// Validate recharge amount
bool validRecharge(long long recharge)
{
    return recharge >= 0;
}

// Display money in rupees and paise
void printMoney(long long amount)
{
    cout << "Rs " << amount / 100 << '.'
         << setw(2) << setfill('0') << amount % 100
         << setfill(' ');
}

struct TestCase
{
    string name;
    int zone;
    int hour;
    long long balance;
    long long expectedFare;
    bool expectedTravel;
};

int main()
{
    vector<TestCase> tests = {
        {"Inner off-peak", 1, 12, 10000, 1000, true},
        {"Inner peak",     1, 8,  10000, 1200, true},
        {"Middle off-peak",2, 12, 10000, 2000, true},
        {"Middle peak",    2, 17, 10000, 2400, true},
        {"Outer off-peak", 3, 12, 10000, 3000, true},
        {"Outer peak",     3, 19, 10000, 3600, true},

        {"Boundary 08:00", 1, 8, 10000, 1200, true},
        {"Boundary 10:00", 1, 10, 10000, 1000, true},
        {"Boundary 17:00", 1, 17, 10000, 1200, true},
        {"Boundary 20:00", 1, 20, 10000, 1000, true},

        {"Exactly Rs 50 left", 1, 12, 6000, 1000, true},
        {"Unknown zone", 4, 12, 10000, -1, false}
    };

    int passed = 0;

    cout << "METRO FARE LOGIC - TEST REPORT\n\n";

    for (const TestCase& t : tests)
    {
        long long actualFare = fare(t.zone, t.hour);
        bool actualTravel = canTravel(t.balance, actualFare);

        bool ok = actualFare == t.expectedFare &&
                  actualTravel == t.expectedTravel;

        cout << left << setw(24) << t.name
             << (ok ? "PASS" : "FAIL") << '\n';

        if (!ok)
        {
            cout << "  Expected fare: ";
            if (t.expectedFare < 0)
                cout << "Invalid";
            else
                printMoney(t.expectedFare);

            cout << "\n  Actual fare: ";
            if (actualFare < 0)
                cout << "Invalid";
            else
                printMoney(actualFare);

            cout << '\n';
        }

        if (ok)
            passed++;
    }

    // Invalid input tests
    int hourValue = 0;
    bool hourValid = readInteger("abc", hourValue);
    cout << left << setw(24) << "Letters for hour"
         << (!hourValid ? "PASS" : "FAIL") << '\n';
    if (!hourValid)
        passed++;

    cout << left << setw(24) << "Negative recharge"
         << (!validRecharge(-100) ? "PASS" : "FAIL") << '\n';
    if (!validRecharge(-100))
        passed++;

    // Five journeys calculated by hand
    int zones[] = {1, 2, 3, 1, 2};
    int hours[] = {12, 8, 18, 20, 17};

    long long total = 0;

    cout << "\nFIVE-JOURNEY SUMMARY\n";

    for (int i = 0; i < 5; i++)
    {
        long long f = fare(zones[i], hours[i]);
        total += f;

        cout << "Journey " << i + 1 << ": ";
        printMoney(f);
        cout << '\n';
    }

    cout << "Total fare: ";
    printMoney(total);
    cout << "\n";

    cout << "\nTests passed: " << passed
         << " out of " << tests.size() + 2 << '\n';

    return 0;
}
