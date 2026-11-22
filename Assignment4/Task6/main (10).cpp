#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

class Vehicle {
    string registration;
    double dailyRate;
    bool rented = false;
public:
    Vehicle(string reg, double rate) : registration(std::move(reg)), dailyRate(rate) {}
    virtual ~Vehicle() = default;
    const string& regNo() const { return registration; }
    double dailyRateValue() const { return dailyRate; }
    bool isRented() const { return rented; }
    bool rent() {
        if (rented) return false;
        rented = true; return true;
    }
    bool giveBack() {
        if (!rented) return false;
        rented = false; return true;
    }
    virtual double charge(int days, double usage) const = 0;
    virtual string type() const = 0;
    virtual void details() const {
        cout << type() << " [" << registration << "] daily rate Rs "
             << dailyRate << (rented ? " (rented)" : " (available)");
    }
};

class Bicycle : public Vehicle {
public:
    Bicycle(string reg, double rate) : Vehicle(std::move(reg), rate) {}
    double charge(int days, double) const override { return dailyRateValue() * days; }
    string type() const override { return "Bicycle"; }
};

class MotorVehicle : public Vehicle {
    double fuelOrCharge;
    string serviceDue;
protected:
    MotorVehicle(string reg, double rate, double level, string due)
        : Vehicle(std::move(reg), rate), fuelOrCharge(level), serviceDue(std::move(due)) {}
public:
    double level() const { return fuelOrCharge; }
    const string& serviceDate() const { return serviceDue; }
};

class TwoWheeler : public MotorVehicle {
public:
    TwoWheeler(string reg, double rate, double fuel, string due)
        : MotorVehicle(std::move(reg), rate, fuel, std::move(due)) {}
    double charge(int days, double litres) const override {
        return dailyRateValue() * days + litres * 105.0;
    }
    string type() const override { return "Two-wheeler"; }
};

class Car : public MotorVehicle {
    int seats;
public:
    Car(string reg, double rate, double fuel, string due, int capacity)
        : MotorVehicle(std::move(reg), rate, fuel, std::move(due)), seats(capacity) {}
    double charge(int days, double litres) const override {
        return dailyRateValue() * days + litres * 105.0;
    }
    string type() const override { return "Car"; }
    void details() const override {
        Vehicle::details(); cout << " seats=" << seats;
    }
};

class ElectricCar : public MotorVehicle {
    double batteryKWh;
public:
    ElectricCar(string reg, double rate, double chargeLevel, string due, double battery)
        : MotorVehicle(std::move(reg), rate, chargeLevel, std::move(due)),
          batteryKWh(battery) {}
    double charge(int days, double kWh) const override {
        return dailyRateValue() * days + kWh * 8.0;
    }
    string type() const override { return "Electric car"; }
    void details() const override {
        Vehicle::details(); cout << " battery=" << batteryKWh << " kWh";
    }
};

// New vehicle type: existing Vehicle and fleet-processing code is unchanged.
class ElectricBus : public MotorVehicle {
    int seats;
public:
    ElectricBus(string reg, double rate, double level, string due, int capacity)
        : MotorVehicle(std::move(reg), rate, level, std::move(due)), seats(capacity) {}
    double charge(int days, double kWh) const override {
        return dailyRateValue() * days + kWh * 8.0;
    }
    string type() const override { return "Electric bus"; }
    void details() const override {
        Vehicle::details(); cout << " seats=" << seats;
    }
};

class RentalFleet {
    vector<unique_ptr<Vehicle>> vehicles;
public:
    void add(unique_ptr<Vehicle> v) { vehicles.push_back(std::move(v)); }
    void list() const {
        for (const auto& v : vehicles) { v->details(); cout << '\n'; }
    }
    Vehicle* find(const string& reg) const {
        for (const auto& v : vehicles) if (v->regNo() == reg) return v.get();
        return nullptr;
    }
};

int main() {
    RentalFleet fleet;
    fleet.add(make_unique<Bicycle>("BI-101", 100));
    fleet.add(make_unique<TwoWheeler>("TW-202", 250, 70, "2027-01-15"));
    fleet.add(make_unique<Car>("CA-303", 1200, 40, "2027-02-01", 5));
    fleet.add(make_unique<ElectricCar>("EV-404", 1500, 85, "2027-02-10", 60));
    fleet.add(make_unique<ElectricBus>("EB-505", 4000, 90, "2027-03-01", 30));

    cout << "Fleet:\n";
    fleet.list();

    Vehicle* car = fleet.find("CA-303");
    if (car && car->rent()) {
        cout << "Rented " << car->regNo() << ", charge for 2 days + 5 litres: Rs "
             << car->charge(2, 5) << '\n';
        car->giveBack();
        cout << "Returned " << car->regNo() << " with late fee Rs 200; total Rs "
             << car->charge(2, 5) + 200 << '\n';
    }
    Vehicle* ev = fleet.find("EV-404");
    if (ev) cout << "Electric usage charge: Rs " << ev->charge(3, 20) << '\n';
}
