#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class Account {
public:
    double rate() const { return 3.5; }                 // non-virtual
    virtual double vrate() const { return 3.5; }       // dynamic dispatch
    virtual ~Account() { cout << "Account destroyed\n"; }
};

class SeniorAccount : public Account {
    double* history;
public:
    SeniorAccount() : history(new double[100]{}) {}
    double rate() const { return 4.0; }                 // hides base function
    double vrate() const override { return 4.0; }
    ~SeniorAccount() override {
        delete[] history;
        cout << "SeniorAccount destroyed\n";
    }
};

class PremiumAccount : public Account {
public:
    double vrate() const override { return 4.5; }
};

int main() {
    vector<unique_ptr<Account>> accounts;
    accounts.push_back(make_unique<Account>());
    accounts.push_back(make_unique<SeniorAccount>());
    accounts.push_back(make_unique<PremiumAccount>());

    for (const auto& a : accounts)
        cout << "Virtual rate: " << a->vrate() << '\n';

    Account* p = new SeniorAccount;
    cout << "Base pointer: non-virtual=" << p->rate()
         << " virtual=" << p->vrate() << '\n';
    delete p; // virtual destructor releases SeniorAccount's owned memory

    Account sliced = SeniorAccount();
    cout << "Sliced copy virtual rate: " << sliced.vrate() << '\n';
}
