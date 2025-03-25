#include <iostream>
using namespace std;

// Function declarations
void display(int);
void displayR(int&);

int main() {
    int x = 7;

    // Call by Value
    display(x);
    cout << "After call by value, x in main() is " << x << endl;

    // Call by Reference
    displayR(x);
    cout << "After call by reference, x in main() is " << x << endl;

    return 0;
}

// Function Definitions
void display(int x) {  // Call by Value
    x = x + 2;
    cout << "Call by value called! x is " << x << endl;
}

void displayR(int &x) {  // Call by Reference
    x = x + 2;
    cout << "Call by reference called! x is " << x << endl;
}
/*
Example 1: Simple Lambda Function
#include <iostream>
using namespace std;

int main() {
    auto add = [](int a, int b) {
        return a + b;
    };

    cout << "Sum: " << add(5, 3) << endl; // Output: Sum: 8
    return 0;
}
The lambda function [ ](int a, int b) { return a + b; } takes two integers and returns their sum.

auto add stores the lambda function.

Example 2: Capturing Variables
#include <iostream>
using namespace std;

int main() {
    int x = 10, y = 5;

    auto multiply = [x, y]() {
        return x * y;
    };

    cout << "Multiplication: " << multiply() << endl; // Output: 50
    return 0;
}
[x, y] captures the variables x and y by value.

The lambda has no parameters and returns x * y.

Example 3: Capturing by Reference
#include <iostream>
using namespace std;

int main() {
    int count = 0;

    auto increment = [&count]() {
        count++;
    };

    increment();
    increment();
    cout << "Count: " << count << endl; // Output: Count: 2
    return 0;
}
[&count] captures count by reference, allowing it to be modified inside the lambda.

Example 4: Using auto Parameters (C++14)
#include <iostream>
using namespace std;

int main() {
    auto square = [](auto x) {
        return x * x;
    };

    cout << "Square of 4: " << square(4) << endl;   // Output: 16
    cout << "Square of 5.5: " << square(5.5) << endl; // Output: 30.25
    return 0;
}
C++14 allows generic lambdas using auto as the parameter type.

Example 5: Lambda with std::function
#include <iostream>
#include <functional>
using namespace std;

int main() {
    function<int(int, int)> multiply = [](int a, int b) {
        return a * b;
    };

    cout << "Multiplication: " << multiply(4, 5) << endl; // Output: 20
    return 0;
}
std::function<int(int, int)> defines a function object that can hold a lambda.

Example 6: Returning a Lambda Function
#include <iostream>
using namespace std;

// Function returning a lambda
auto getLambda() {
    return [](int x) {
        return x * x;
    };
}

int main() {
    auto square = getLambda();
    cout << "Square: " << square(6) << endl; // Output: 36
    return 0;
}
A function returns a lambda, which is then used in main().
*/