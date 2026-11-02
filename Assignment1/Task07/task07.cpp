
#include <iostream>
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

bool canTravel(long long balance, long long f)
{
    return f >= 0 && balance - f >= MIN_BALANCE_PAISE;
}

bool deduct(long long& balance, long long f)
{
    if (canTravel(balance, f))
    {
        balance -= f;
        return true;
    }

    return false;
}

int main()
{
    long long balance = 10000;

    int zones[] = {1, 3, 2};
    bool peakHours[] = {false, true, false};

    for (int i = 0; i < 3; i++)
    {
        long long f = fare(zones[i], peakHours[i]);

        if (f < 0)
        {
            cout << "Invalid zone\n";
            continue;
        }

        if (deduct(balance, f))
        {
            cout << "Fare Rs " << f / 100 << '.';
            if (f % 100 < 10)
                cout << '0';
            cout << f % 100;
        }
        else
        {
            cout << "Denied (low balance)";
        }

        cout << " balance Rs " << balance / 100 << '\n';
    }

    return 0;
}
