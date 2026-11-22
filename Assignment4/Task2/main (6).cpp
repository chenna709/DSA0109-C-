#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int id;
    string phone;
public:
    Person(string n, int i, string p) : name(std::move(n)), id(i), phone(std::move(p)) {}
    virtual ~Person() = default;
    void printPerson() const { cout << name << " ID=" << id << " Phone=" << phone; }
};

class Student : virtual public Person {
protected:
    string programme;
    double cgpa;
public:
    Student(string n, int i, string p, string prog, double g)
        : Person(std::move(n), i, std::move(p)), programme(std::move(prog)), cgpa(g) {}
    void printStudent() const {
        printPerson(); cout << " Programme=" << programme << " CGPA=" << cgpa;
    }
};

class Staff : virtual public Person {
protected:
    string department;
    double salary;
public:
    Staff(string n, int i, string p, string dept, double sal)
        : Person(std::move(n), i, std::move(p)),
          department(std::move(dept)), salary(sal) {}
    void printStaff() const {
        printPerson(); cout << " Department=" << department << " Salary=" << salary;
    }
};

class TeachingAssistant : public Student, public Staff {
public:
    TeachingAssistant(string n, int i, string p, string prog, double g,
                      string dept, double sal)
        : Person(n, i, p),
          Student(n, i, p, prog, g), Staff(n, i, p, dept, sal) {}
    void print() const {
        printPerson();
        cout << " Programme=" << programme << " CGPA=" << cgpa
             << " Department=" << department << " Salary=" << salary << '\n';
    }
};

class ResearchScholar : public Student {
    double fellowship;
public:
    ResearchScholar(string n, int i, string p, string prog, double g, double f)
        : Person(std::move(n), i, std::move(p)),
          Student(name, id, phone, std::move(prog), g), fellowship(f) {}
    void print() const {
        printStudent(); cout << " Fellowship=" << fellowship << '\n';
    }
};

int main() {
    TeachingAssistant ta("Kavya", 201, "9000000001", "CSE", 9.1, "Computing", 25000);
    cout << "Teaching assistant: "; ta.print();

    ResearchScholar scholar("Ravi", 202, "9000000002", "Data Science", 9.4, 18000);
    cout << "Research scholar: "; scholar.print();

    cout << "sizeof(Person)=" << sizeof(Person)
         << " sizeof(TeachingAssistant)=" << sizeof(TeachingAssistant) << '\n';
}
