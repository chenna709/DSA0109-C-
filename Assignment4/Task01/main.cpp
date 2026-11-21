#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

class Staff {
    string name;
    int id;
protected:
    Staff(string n, int i) : name(std::move(n)), id(i) {}
public:
    virtual ~Staff() = default;
    const string& getName() const { return name; }
    int getId() const { return id; }
    virtual double pay() const = 0;
    virtual string role() const = 0;
};

class Professor : public Staff {
    double basic, research;
public:
    Professor(string n, int i, double b, double r)
        : Staff(std::move(n), i), basic(b), research(r) {}
    double pay() const override { return basic + basic * 0.42 + research; }
    string role() const override { return "Professor"; }
};

class LabAssistant : public Staff {
    double basic;
public:
    LabAssistant(string n, int i, double b)
        : Staff(std::move(n), i), basic(b) {}
    double pay() const override { return basic + basic * 0.42; }
    string role() const override { return "Lab Assistant"; }
};

class GuestFaculty : public Staff {
    double hours, rate;
public:
    GuestFaculty(string n, int i, double h, double r)
        : Staff(std::move(n), i), hours(h), rate(r) {}
    double pay() const override { return hours * rate; }
    string role() const override { return "Guest Faculty"; }
};

int main() {
    vector<unique_ptr<Staff>> payroll;
    payroll.push_back(make_unique<Professor>("Anita", 101, 50000, 8000));
    payroll.push_back(make_unique<LabAssistant>("Bala", 102, 30000));
    payroll.push_back(make_unique<GuestFaculty>("Charan", 103, 40, 900));

    cout << "Payroll summary\n";
    for (const auto& person : payroll)
        cout << person->role() << " | " << person->getName()
             << " | ID " << person->getId() << " | Pay Rs "
             << person->pay() << '\n';
}
