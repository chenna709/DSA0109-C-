#include <iomanip>
#include <iostream>
using namespace std;

class Money {
    long long paise;

public:
    Money(long long rupees = 0, int p = 0) : paise(rupees * 100 + p) {}

    Money operator+(const Money& other) const {
        return Money(0, static_cast<int>(paise + other.paise));
    }
    Money operator-(const Money& other) const {
        return Money(0, static_cast<int>(paise - other.paise));
    }
    Money& operator+=(const Money& other) {
        paise += other.paise;
        return *this;
    }
    bool operator==(const Money& other) const { return paise == other.paise; }
    bool operator<(const Money& other) const { return paise < other.paise; }

    friend ostream& operator<<(ostream& out, const Money& m) {
        const long long whole = m.paise / 100;
        long long fraction = m.paise % 100;
        if (fraction < 0) fraction = -fraction;
        const bool negative = m.paise < 0;
        out << (negative ? "-Rs " : "Rs ") << (whole < 0 ? -whole : whole)
            << '.' << setw(2) << setfill('0') << fraction << setfill(' ');
        return out;
    }
    friend istream& operator>>(istream& in, Money& m) {
        long long rupees;
        int p;
        if (in >> rupees >> p) m.paise = rupees * 100 + p;
        return in;
    }
};

int main() {
    Money a(120, 75), b(79, 25);
    Money c = a + b;
    cout << c << '\n' << boolalpha << (c == Money(200)) << '\n';

    Money x(0, 75), y(0, 50);
    cout << "Carry test: " << x + y << '\n';

    Money negative = Money(1, 0) - Money(2, 0);
    cout << "Negative test: " << negative << '\n';
    Money bill(10, 0);
    bill += Money(2, 50);
    cout << "Bill total: " << bill << '\n';
}
