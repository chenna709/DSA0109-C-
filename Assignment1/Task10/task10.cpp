
#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

int main()
{
    const int FARE_PAISE = 3601; // Rs 36.01
    const double FARE_RUPEES = 36.01;

    const int journeyCounts[] = {20000, 500000, 3000000};

    cout << fixed << setprecision(6);
    cout << "FARE TOTAL COMPARISON\n\n";

    for (int n : journeyCounts)
    {
        double doubleTotal = 0.0;
        long long paiseTotal = 0;

        for (int i = 0; i < n; i++)
        {
            doubleTotal += FARE_RUPEES;
            paiseTotal += FARE_PAISE;
        }

        double paiseTotalInRupees = paiseTotal / 100.0;
        double difference = doubleTotal - paiseTotalInRupees;

        cout << "Journeys: " << n << '\n';

        cout << "Double total: Rs "
             << setprecision(6) << doubleTotal << '\n';

        cout << "Integer-paise total: Rs "
             << setprecision(2) << paiseTotalInRupees << '\n';

        cout << "Difference: Rs "
             << setprecision(6) << difference << '\n';

        cout << "Integer-paise total: "
             << paiseTotal << " paise\n";

        if (paiseTotal > numeric_limits<int>::max())
        {
            cout << "int total in paise: OVERFLOW RISK\n";
        }
        else
        {
            cout << "int total in paise: Within range\n";
        }

        cout << "-----------------------------\n";
    }

    cout << "\nType size comparison:\n";
    cout << "int: " << sizeof(int) << " bytes\n";
    cout << "long long: " << sizeof(long long) << " bytes\n";
    cout << "double: " << sizeof(double) << " bytes\n";

    cout << "\nMaximum int: "
         << numeric_limits<int>::max() << '\n';

    return 0;
}
