/*In C++, a friend function is a special function that has access to private and protected members of a class, 
even though it is not a member of that class.*/
#include <iostream>
#include <vector>

using namespace std;

class myfriend {
    private:
        int privateData;
        
    //constructor
    public:
    myfriend(int data) : privateData(data) {}
        
        // Declaring a friend function
        friend void displayPrivateData(const myfriend& obj);
    };
    
    // Definition of the friend function
    void displayPrivateData(const myfriend& obj) {
        // Can access private members directly
        cout << "Private data: " << obj.privateData << endl;
    }
    /*
    Key Features of Friend Functions
    1.Access privileges: Friend functions can access private and protected members of the class that declares them as friends.
    2.Not member functions: They are not member functions of the class and don't have a this pointer.
    3.Declaration location: Friend functions must be declared inside the class definition, but they are defined outside the class.
    3.Not inherited: Friendship is not inherited or transitive. If class A is a friend of class B, it doesn't mean subclasses of A are friends of B.
    Common Use Cases
    1.Operator overloading (especially binary operators)
    2.Functions that need to work with multiple classes
    3.When you need to separate functionality from class implementation
    
    */
   class Complex {
    private:
        double real, imag;
        
    public:
        Complex(double r = 0, double i = 0) : real(r), imag(i) {}
        
        // Declare the friend function
        friend Complex operator+(const Complex& c1, const Complex& c2);
        
        void display() {
            cout << real << " + " << imag << "i" << endl;
        }
    };
    
    // Define the friend function
    Complex operator+(const Complex& c1, const Complex& c2) {
        return Complex(c1.real + c2.real, c1.imag + c2.imag);
    }




    //>>>>>>>>>>>>>>>> AS CLASS >>>>>>>>>>>>>>>>>>>>>>>>>>>
   

class ClassB; // Forward declaration

class ClassA {
private:
    int privateData;
    
public:
    ClassA(int data) : privateData(data) {}
    
    // Declaring ClassB as a friend class
    friend class ClassB;
    
    void display() {
        std::cout << "ClassA private data: " << privateData << std::endl;
    }
};

// ClassB can access private members of ClassA
class ClassB {
public:
    void accessClassA(const ClassA& a) {
        // Can directly access private members of ClassA
        std::cout << "ClassB accessing ClassA's private data: " << a.privateData << std::endl;
    }
    
    void modifyClassA(ClassA& a) {
        a.privateData = 100; // Can modify private data
        std::cout << "ClassB modified ClassA's private data" << std::endl;
    }
};

int main() {
    ClassA objA(42);
    objA.display();
    
    ClassB objB;
    objB.accessClassA(objA);
    objB.modifyClassA(objA);
    
    objA.display(); // Will show the modified value
    
    return 0;
}
