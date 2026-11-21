#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

class Cart {
    string items[10];
    double prices[10];
    int n = 0;
    double discount = 0;
public:
    Cart& add(const string& item, double price) {
        if (n < 10) {
            items[n] = item;
            prices[n] = price;
            ++n;
        }
        return *this;
    }
    Cart& setDiscount(double discount) {
        this->discount = discount;
        return *this;
    }
    double total() const {
        double sum = 0;
        for (int i = 0; i < n; ++i) sum += prices[i];
        return sum * (100 - discount) / 100;
    }
    int size() const { return n; }
};

int main() {
    Cart direct;
    direct.add("Rice", 60).add("Dal", 120);

    Cart* pointer = &direct;
    pointer->add("Oil", 180);

    Cart& reference = direct;
    reference.setDiscount(10);

    Cart* heapCart = new Cart;
    heapCart->add("Milk", 40);
    cout << "Heap cart total: " << heapCart->total() << '\n';
    delete heapCart;

    Cart first, second, third;
    first.add("A", 50);
    second.add("B", 220);
    third.add("C", 140);
    Cart* active[] = {&first, &second, &third};

    int best = 0;
    for (int i = 1; i < 3; ++i)
        if (active[i]->total() > active[best]->total()) best = i;

    cout << fixed << setprecision(2) << "Chained cart total: "
         << pointer->total() << '\n';
    cout << "Highest cart total: " << active[best]->total()
         << " at index " << best << '\n';
}
