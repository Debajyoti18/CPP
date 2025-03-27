#include <iostream>
#include <cstring>

class MyClass {
private:
    int* data;
    int size;

public:
    // Default Constructor
    MyClass() {
        std::cout << "Default Constructor called" << std::endl;
        data = new int[5];  // Allocate default memory
        size = 5;
        for (int i = 0; i < size; ++i) {
            data[i] = 0;  // Initialize with zeros
        }
    }

    // Parameterized Constructor
    MyClass(int inputSize) {
        std::cout << "Parameterized Constructor called" << std::endl;
        size = inputSize;
        data = new int[size];
        for (int i = 0; i < size; ++i) {
            data[i] = i * 10;  // Initialize with some values
        }
    }

    // Copy Constructor
    MyClass(const MyClass& other) { //const is used to exact copy or deep copy of the object -no modification allowed
        std::cout << "Copy Constructor called" << std::endl;
        size = other.size;
        data = new int[size];
        
        // Deep copy of data
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    // Destructor
    ~MyClass() {
        std::cout << "Destructor called" << std::endl;
        delete[] data;  // Free dynamically allocated memory
    }

    // Method to print data
    void printData() {
        std::cout << "Data: ";
        for (int i = 0; i < size; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    // Default Constructor
    std::cout << "Creating object with default constructor:" << std::endl;
    MyClass obj1;
    obj1.printData();

    // Parameterized Constructor
    std::cout << "\nCreating object with parameterized constructor:" << std::endl;
    MyClass obj2(3);
    obj2.printData();

    // Copy Constructor
    std::cout << "\nCreating object using copy constructor:" << std::endl;
    MyClass obj3 = obj2;  // Copy constructor called
    obj3.printData();

    return 0;
}