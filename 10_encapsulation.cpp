/*Encapsulation refers to the bundling of data (attributes) and methods (functions) that operate on that data within a
 single unit (class), while restricting direct access to some of the object's components.
 
 Access Specifiers: C++ provides three access specifiers:
        1.private: Members can only be accessed within the class
        2.protected: Members can be accessed within the class and by derived classes
        3.public: Members can be accessed from anywhere.
        Data Hiding: Private members are hidden from external code, preventing unauthorized access.
        Getter/Setter Methods: Controlled access to private data through public methods.
 
 */
#include <iostream>
#include <vector>

using namespace std;
class BankAccount {
    private:
        // Private data members
        double balance;
        string accountNumber;
        
    public:
        // Constructor
        BankAccount(string accNum, double initialBalance) {
            accountNumber = accNum;
            balance = initialBalance;
        }
        
        // Getter methods
        double getBalance() {
            return balance;
        }
        
        string getAccountNumber() {
            return accountNumber;
        }
        
        // Setter method with validation
        void deposit(double amount) {
            if (amount > 0) {
                balance += amount;
            }
        }
        
        bool withdraw(double amount) {
            if (amount > 0 && amount <= balance) {
                balance -= amount;
                return true;
            }
            return false;
        }
    };