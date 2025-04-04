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
        
    protected:
        string ownerName;
        string registrationNumber;
    };
    
    // Concrete implementation
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
    };
    // Bus implementation derived from the Vehicle abstract class
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


    int main() {
        // Create a bus object
        Bus schoolBus(45, false);
        
        // Set owner information (from the base class)
        schoolBus.setOwner("Springfield School District");
        
        // Use bus-specific methods
        schoolBus.start();
        schoolBus.openDoors();
        schoolBus.loadPassengers(40);
        schoolBus.closeDoors();
        
        cout << "Fuel efficiency: " << schoolBus.getFuelEfficiency() << " mpg" << endl;
        
        schoolBus.stop();
        
        return 0;
    }