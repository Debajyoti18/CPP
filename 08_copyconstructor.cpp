#include <iostream>
#include <vector>
#include <string>

class Resource {
private:
    std::string* data;

public:
    // Default Constructor
    Resource() : data(new std::string("Default")) {
        std::cout << "Default Constructor" << std::endl;
    }

    // Parameterized Constructor
    Resource(const std::string& input) : data(new std::string(input)) {
        std::cout << "Parameterized Constructor" << std::endl;
    }

    // Copy Constructor (Deep Copy)
    Resource(const Resource& other) {
        std::cout << "Copy Constructor Called" << std::endl;
        // Deep copy of dynamically allocated string
        data = new std::string(*other.data);
    }

    // Destructor
    ~Resource() {
        std::cout << "Destructor. Deleting: " << *data << std::endl;
        delete data;
    }

    // Method to modify and display data
    void modifyData(const std::string& newData) {
        *data = newData;
    }

    std::string getData() const {
        return *data;
    }
};

// Function that receives object by value (triggers copy constructor)
void processResource(Resource res) {
    std::cout << "Processing resource with data: " << res.getData() << std::endl;
}

// Function that returns a Resource object
Resource createResource() {
    Resource temp("Created in function");
    return temp;
}

int main() {
    // Scenario 1: Explicit Copy Construction
    std::cout << "--- Scenario 1: Explicit Copy ---" << std::endl;
    Resource original("Original Data");
    Resource copy = original;  // Copy constructor called
    std::cout << "Original: " << original.getData() 
              << ", Copy: " << copy.getData() << std::endl;

    // Scenario 2: Passing by Value
    std::cout << "\n--- Scenario 2: Passing by Value ---" << std::endl;
    Resource passResource("Pass Resource");
    processResource(passResource);  // Copy constructor called when passing

    // Scenario 3: Return by Value
    std::cout << "\n--- Scenario 3: Return by Value ---" << std::endl;
    Resource returnedResource = createResource();  // Copy constructor called
    std::cout << "Returned Resource Data: " 
              << returnedResource.getData() << std::endl;

    // Scenario 4: Container Storage
    std::cout << "\n--- Scenario 4: Vector Storage ---" << std::endl;
    std::vector<Resource> resourceVector;
    resourceVector.push_back(Resource("First"));  // Copy constructor called
    resourceVector.push_back(Resource("Second")); // Another copy constructor call

    return 0;
}
/*Copy Constructor Use Cases:

Explicit Object Copying

When you create a new object as an exact copy of an existing object
Ensures a deep copy of dynamically allocated resources
Prevents multiple objects from sharing the same memory


Passing Objects by Value

When a function receives an object as a parameter
The copy constructor is called to create a local copy of the object
Prevents modifications to the original object


Returning Objects from Functions

When a function returns an object by value
The copy constructor creates a copy of the local object
Allows returning temporary objects
