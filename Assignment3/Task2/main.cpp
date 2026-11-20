#include <chrono>
#include <iostream>
#include <string>
#include <utility>
using namespace std;

class Prescription {
    int n;
    string* medicines;

public:
    explicit Prescription(int count)
        : n(count < 0 ? 0 : count), medicines(n ? new string[n] : nullptr) {}

    // Deep-copy constructor.
    Prescription(const Prescription& other)
        : n(other.n), medicines(n ? new string[n] : nullptr) {
        for (int i = 0; i < n; ++i) medicines[i] = other.medicines[i];
        cout << "[copy constructor] copied " << n << " medicine(s)\n";
    }

    // Deep-copy assignment with self-assignment protection and strong safety.
    Prescription& operator=(const Prescription& other) {
        if (this == &other) return *this;
        string* fresh = other.n ? new string[other.n] : nullptr;
        try {
            for (int i = 0; i < other.n; ++i) fresh[i] = other.medicines[i];
        } catch (...) {
            delete[] fresh;
            throw;
        }
        delete[] medicines;
        medicines = fresh;
        n = other.n;
        return *this;
    }

    ~Prescription() { delete[] medicines; }

    void set(int i, const string& medicine) {
        if (i < 0 || i >= n) throw out_of_range("medicine index out of range");
        medicines[i] = medicine;
    }
    string get(int i) const {
        if (i < 0 || i >= n) throw out_of_range("medicine index out of range");
        return medicines[i];
    }
    int size() const { return n; }
};

void inspectByValue(Prescription p) { (void)p; }
void inspectByReference(const Prescription& p) { (void)p; }

int main() {
    Prescription p(2);
    p.set(0, "Paracetamol");
    p.set(1, "ORS");

    Prescription q = p;
    q.set(1, "Cetirizine");

    Prescription r(1);
    r = p;
    p.set(0, "Ibuprofen");
    r = r; // self-assignment test

    cout << p.get(0) << ' ' << p.get(1) << " | "
         << q.get(0) << ' ' << q.get(1) << " | "
         << r.get(0) << ' ' << r.get(1) << '\n';

    cout << "Passing by value:\n";
    inspectByValue(p);
    cout << "Passing by const reference:\n";
    inspectByReference(p);

    // Basic copy-time experiment (repeat runs and record actual measurements).
    for (int count : {10, 1000, 100000}) {
        Prescription source(count);
        const auto start = chrono::steady_clock::now();
        Prescription copy(source);
        const auto stop = chrono::steady_clock::now();
        const auto us = chrono::duration_cast<chrono::microseconds>(stop - start).count();
        cout << "Copied " << count << " entries in " << us << " us (single sample)\n";
    }
}
