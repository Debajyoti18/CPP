#include<iostream> //header files and libraries
#include<bits/stdc++.h> // contains all the libraries
//c++ is statically typed
using namespace std;
/*This defines a scope for the identifiers that are used in a program. For using the identifiers defined in the namespace scope
 we must include the using directive.This will bring all the identifiers defined in std to the current global scope. */


 namespace myspaced {
    void display(){
        cout<< "hello this is my region";
    }
 }

int main(){
    myspaced:: display;
    // std::cout << "Hello I'm Dj !" << "\n";
    // std::cout << "Hello I'm Dj !" << std::endl;
    //"/n" and endl are commonly used for the next line 
    cout << "Hello I'm Dj !" << "\n";
    cout << "Hello I'm Dj !" << endl;//The operator << is called the insertion or put to operator. It inserts
    //(or sends) the contents of the variable on its right to the object on its left

    //input 
    int x,y;
    cin >> x >> y;// The operator >> is known as extraction or get from operator. It extracts (or takes) the value from
     //the keyboard and assigns it to the variable on its right .: cin can read only one word and therefore we cannot
    //use names with blank spaces
    cout << "Value of the x is " << x << " Y is :" << y;


    return 0;//The default return type for all functions in C++ is int. So its return to the os. if no return then shows warnings.
}
/*>>>>> Theory Concepts >>>>>>>>>*/
