#include <iostream>
#include <string>
using namespace std;

class Address {
    string city;
    int pin;
public:
    Address(string c, int p) : city(std::move(c)), pin(p) {
        cout << "Address constructed ";
    }
    ~Address() { cout << "Address destroyed "; }
    string str() const { return city + "-" + to_string(pin); }
};

class Course {
    string title;
public:
    explicit Course(string t) : title(std::move(t)) {
        cout << "Course constructed ";
    }
    ~Course() { cout << "Course destroyed "; }
};

class Person {
protected:
    string name;
    int age;
    Address home;
public:
    Person(const string& n, int a, const string& city, int pin)
        : name(n), age(a), home(city, pin) {
        cout << "Person constructed ";
    }
    virtual ~Person() { cout << "Person destroyed "; }
};

class Student : public Person {
    long long regNo;
    Course course;
public:
    Student(const string& n, int a, long long reg, const string& city,
            int pin, const string& courseName)
        : Person(n, a, city, pin), regNo(reg), course(courseName) {
        cout << "Student constructed ";
    }
    ~Student() override { cout << "Student destroyed "; }
    void print() const {
        cout << "\n" << regNo << " " << name << " (" << age << ") "
             << home.str() << '\n';
    }
};

class Staff : public Person {
    string department;
public:
    Staff(const string& n, int a, const string& city, int pin, string dept)
        : Person(n, a, city, pin), department(std::move(dept)) {
        cout << "Staff constructed ";
    }
    ~Staff() override { cout << "Staff destroyed "; }
};

int main() {
    cout << "Student lifetime: ";
    {
        Student s("Kavya", 19, 192311001, "Salem", 636001, "C++ OOP");
        s.print();
    }
    cout << "\nStaff lifetime: ";
    {
        Staff st("Meera", 40, "Chennai", 600001, "CSE");
    }
    cout << "\nCar-like base/member order is demonstrated by Student above.\n";
}
