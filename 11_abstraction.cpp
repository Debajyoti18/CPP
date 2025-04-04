/*Abstraction is a fundamental concept in object-oriented programming that focuses on showing only essential features while
 hiding implementation details.In C++, abstraction helps manage complexity by allowing you to create simplified interfaces.
Key Concepts of Abstraction in C++
An abstract class in C++ is a class that can't be instantiated directly and is designed to serve as a base class for other classes. 
It's created by including at least one pure virtual function.
**** In C++, an interface is typically implemented as a class containing only pure virtual functions:*/
#include <iostream>
#include <vector>

using namespace std;
// Abstract class representing a Vehicle
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// Abstract class representing a Vehicle
class Vehicle {
public:
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual double getFuelEfficiency() = 0;
    virtual ~Vehicle() {}
    
    // Common functionality
    void setOwner(string name) {
        ownerName = name;
    }
    
    // New method that combines all abstracted methods
    string operateVehicle() {
        // Store information in a string instead of direct cout
        stringstream result;
        
        // Call start (polymorphic call)
        start();
        result << "Vehicle started. ";
        
        // Get and include fuel efficiency information
        double efficiency = getFuelEfficiency();
        result << "Operating at " << efficiency << " mpg. ";
        
        // Call stop (polymorphic call)
        stop();
        result << "Vehicle stopped.";
        
        // Return the combined result
        return result.str();
    }
    
protected:
    string ownerName;
    string registrationNumber;
};

// Car implementation
class Car : public Vehicle {
private:
    double fuelLevel;
    string model;
    
public:
    Car(string mdl) : model(mdl), fuelLevel(100.0) {}
    
    void start() override {
        cout << "Car engine started" << endl;
    }
    
    void stop() override {
        cout << "Car engine stopped" << endl;
    }
    
    double getFuelEfficiency() override {
        return 25.5; // miles per gallon
    }
    
    // Car-specific methods
    void honk() {
        cout << "Beep beep!" << endl;
    }
    
    string getModel() {
        return model;
    }
};

// Bus implementation
class Bus : public Vehicle {
private:
    int passengerCapacity;
    bool isPublicTransport;
    double fuelLevel;
    
public:
    // Constructor
    Bus(int capacity, bool publicTransport) 
        : passengerCapacity(capacity), 
          isPublicTransport(publicTransport),
          fuelLevel(200.0) {}
    
    // Implementation of pure virtual functions from Vehicle
    void start() override {
        cout << "Bus engine started with a loud rumble" << endl;
    }
    
    void stop() override {
        cout << "Bus engine stopped after air brakes engaged" << endl;
    }
    
    double getFuelEfficiency() override {
        return 7.5; // miles per gallon (buses typically have lower MPG)
    }
    
    // Bus-specific methods
    void openDoors() {
        cout << "Bus doors are now open" << endl;
    }
    
    void closeDoors() {
        cout << "Bus doors are now closed" << endl;
    }
    
    int getPassengerCapacity() {
        return passengerCapacity;
    }
    
    bool loadPassengers(int count) {
        if (count <= passengerCapacity) {
            cout << count << " passengers boarded the bus" << endl;
            return true;
        } else {
            cout << "Cannot board " << count << " passengers. Capacity is " << passengerCapacity << endl;
            return false;
        }
    }
};

// Example usage
int main() {
    Car myCar("Toyota Camry");
    Bus schoolBus(45, false);
    
    myCar.setOwner("John Smith");
    schoolBus.setOwner("Springfield School District");
    
    // Using specific methods
    cout << "Car operations:" << endl;
    myCar.start();
    myCar.honk();
    cout << "Fuel efficiency: " << myCar.getFuelEfficiency() << " mpg" << endl;
    myCar.stop();
    cout << endl;
    
    cout << "Bus operations:" << endl;
    schoolBus.start();
    schoolBus.openDoors();
    schoolBus.loadPassengers(40);
    schoolBus.closeDoors();
    cout << "Fuel efficiency: " << schoolBus.getFuelEfficiency() << " mpg" << endl;
    schoolBus.stop();
    cout << endl;
    
    // Using the combined method through polymorphism
    cout << "Using operateVehicle() method:" << endl;
    Vehicle* vehicles[2] = {&myCar, &schoolBus};
    
    for (int i = 0; i < 2; i++) {
        cout << "Vehicle " << i+1 << " operation: " << vehicles[i]->operateVehicle() << endl;
    }
    
    return 0;
}