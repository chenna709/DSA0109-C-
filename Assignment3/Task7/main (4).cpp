#include <cmath>
#include <iomanip>
#include <iostream>
#include <stdexcept>
using namespace std;

class Complex {
    double re, im;
public:
    Complex() : re(0), im(0) {}
    Complex(double real) : re(real), im(0) {}
    Complex(double real, double imaginary) : re(real), im(imaginary) {}

    double real() const { return re; }
    double imag() const { return im; }
    double magnitude() const { return hypot(re, im); }

    Complex operator+(const Complex& z) const {
        return Complex(re + z.re, im + z.im);
    }
    Complex operator-(const Complex& z) const {
        return Complex(re - z.re, im - z.im);
    }
    Complex operator*(const Complex& z) const {
        return Complex(re*z.re - im*z.im, re*z.im + im*z.re);
    }
    Complex operator/(const Complex& z) const {
        const double denominator = z.re*z.re + z.im*z.im;
        if (denominator == 0.0) throw domain_error("division by zero impedance");
        return Complex((re*z.re + im*z.im)/denominator,
                       (im*z.re - re*z.im)/denominator);
    }
    bool operator==(const Complex& z) const {
        const double eps = 1e-9;
        return abs(re-z.re) < eps && abs(im-z.im) < eps;
    }
    friend ostream& operator<<(ostream& out, const Complex& z) {
        out << fixed << setprecision(3) << z.re
            << (z.im < 0 ? " - j" : " + j") << abs(z.im);
        return out;
    }
};

int main() {
    const double pi = acos(-1.0);
    const double frequency = 50.0;
    const double omega = 2.0 * pi * frequency;
    const double R = 10.0;
    const double L = 0.1;
    const double C = 100e-6;

    Complex resistor(R, 0);
    Complex inductor(0, omega * L);
    Complex capacitor(0, -1.0 / (omega * C));

    Complex series = resistor + inductor + capacitor;
    cout << "Series impedance: " << series
         << ", magnitude = " << series.magnitude() << " ohm\n";

    // Parallel combination: (Z1 * Z2) / (Z1 + Z2)
    Complex z1(100, 0), z2(0, 100);
    Complex parallel = (z1 * z2) / (z1 + z2);
    cout << "Parallel impedance: " << parallel
         << ", magnitude = " << parallel.magnitude() << " ohm\n";

    try {
        Complex invalid = z1 / Complex(0, 0);
        cout << invalid << '\n';
    } catch (const domain_error& e) {
        cout << "Safe division: " << e.what() << '\n';
    }
}
