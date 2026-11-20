#include <cstring>
#include <iostream>
#include <stdexcept>
using namespace std;

class Text {
    char* data;
public:
    explicit Text(const char* s = "") {
        if (!s) s = "";
        data = new char[strlen(s) + 1];
        strcpy(data, s);
    }
    Text(const Text& other) : Text(other.data) {}

    Text& operator=(const Text& other) {
        if (this == &other) return *this;
        char* fresh = new char[strlen(other.data) + 1];
        strcpy(fresh, other.data);
        delete[] data;
        data = fresh;
        return *this;
    }

    Text& operator+=(const Text& other) {
        const size_t left = strlen(data), right = strlen(other.data);
        char* fresh = new char[left + right + 1];
        strcpy(fresh, data);
        strcat(fresh, other.data);
        delete[] data;
        data = fresh;
        return *this;
    }

    friend Text operator+(const Text& a, const Text& b) {
        Text result(a);
        result += b;
        return result;
    }
    bool operator==(const Text& other) const { return strcmp(data, other.data) == 0; }
    bool operator!=(const Text& other) const { return !(*this == other); }
    friend ostream& operator<<(ostream& out, const Text& t) { return out << t.data; }
    ~Text() { delete[] data; }
};

int main() {
    Text a("Hello"), b(" "), c("World");
    Text message = a + b + c;
    cout << message << '\n';
    cout << boolalpha << (message == Text("Hello World")) << ' '
         << (message != Text("Hello")) << '\n';

    Text empty;
    empty = empty; // self-assignment
    cout << "Empty: [" << empty << "]\n";

    Text longMessage("A long SMS message can contain more than a short greeting.");
    Text copy = longMessage;
    cout << "Copy: " << copy << '\n';
}
