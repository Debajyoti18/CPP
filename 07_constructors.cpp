#include <iostream>
#include <cstring>
using namespace std;
class MyClass {
private:
    int* data;
    int size;

public:
    // Default Constructor
    MyClass() {
       cout << "Default Constructor called" <<endl;
        data = new int[5];  // Allocate default memory
        size = 5;
        for (int i = 0; i < size; ++i) {
            data[i] = 0;  // Initialize with zeros
        }
    }

    // Parameterized Constructor
    MyClass(int inputSize) {
       cout << "Parameterized Constructor called" <<endl;
        size = inputSize;
        data = new int[size];
        for (int i = 0; i < size; ++i) {
            data[i] = i * 10;  // Initialize with some values
        }
    }

    // Copy Constructor
    MyClass(const MyClass& other) { //const is used to exact copy or deep copy of the object -no modification allowed
       cout << "Copy Constructor called" <<endl;
        size = other.size;
        data = new int[size];
        
        // Deep copy of data
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    // Destructor
    ~MyClass() {
       cout << "Destructor called" <<endl;
        delete[] data;  // Free dynamically allocated memory
    }

    // Method to print data
    void printData() {
       cout << "Data: ";
        for (int i = 0; i < size; ++i) {
           cout << data[i] << " ";
        }
       cout <<endl;
    }
};

int main() {
    // Default Constructor
   cout << "Creating object with default constructor:" <<endl;
    MyClass obj1;
    obj1.printData();

    // Parameterized Constructor
   cout << "\nCreating object with parameterized constructor:" <<endl;
    MyClass obj2(3);
    obj2.printData();

    // Copy Constructor
   cout << "\nCreating object using copy constructor:" <<endl;
    MyClass obj3 = obj2;  // Copy constructor called
    obj3.printData();

    return 0;
}

//>>>>>>>>>> conatructor Delegation >>>>>>>>>>>
/*
Constructor delegation in C++ allows one constructor to call another constructor of the same class, helping to avoid code
 duplication. This feature was introduced in C++11 and is a useful tool for implementing class hierarchies and managing 
 constructor overloads.

 Execution Order:
The delegated constructor is executed first
Then the delegating constructor's body is executed


Rules and Limitations:
A constructor cannot both delegate and initialize other class members in its initializer list
Circular delegation is not allowed (will cause a compilation error)
The delegation must appear in the initializer list, not in the constructor body


Benefits:
Reduces code duplication
Centralizes initialization logic
Makes code maintenance easier
Supports the DRY (Don't Repeat Yourself) principle
Constructor delegation is particularly useful in classes with multiple constructors that share common initialization logic.
*/


class Car {
private:
   string make;
   string model;
    int year;

public:
    // Primary constructor
    Car(string make,string model, int year) 
        : make(make), model(model), year(year) {
       cout << "Full constructor called" <<endl;
    }
    
    // Delegating constructor (no year specified)
    Car(string make,string model) : Car(make, model, 2025) { // Delegates to primary constructor
       cout << "Year defaulted to 2025" <<endl;
    }
    
    // Delegating constructor (only make specified)
    Car(string make) 
        : Car(make, "Unknown") { // Delegates to second constructor
       cout << "Model defaulted to Unknown" <<endl;
    }
    
    void display() {
       cout << year << " " << make << " " << model <<endl;
    }
};

int main() {
    Car car1("Toyota", "Corolla", 2023);
    car1.display();  // Output: 2023 Toyota Corolla
    
    Car car2("Honda", "Civic");
    car2.display();  // Output: 2025 Honda Civic
    
    Car car3("Tesla");
    car3.display();  // Output: 2025 Tesla Unknown
    
    return 0;
}