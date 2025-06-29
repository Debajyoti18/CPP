#include <iostream>
using namespace std;
    int findLength(char str[]){
        int i ;
            for(i = 0; str[i] != '\0'; i++) {
            }
            return i;
    }
    void ToggleCase(char str[]){
        for (int i = 0; str[i] != '\0'; i++) {
                if (str[i] >= 'a' && str[i] <= 'z') {
                    str[i] -= 32;  // Convert to uppercase
                } else if (str[i] >= 'A' && str[i] <= 'Z') {
                    str[i] += 32;  // Convert to lowercase
                }
            }
    }
    void findVowelsandConsonants(char str[]){
        int vowels = 0, consonants = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        char ch = tolower(str[i]);  
        if (isalpha(ch)) {  
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                vowels++;
            else
                consonants++;
        }
    }

    cout << "Vowels: " << vowels << endl;
    cout << "Consonants: " << consonants << endl;
    }
    
int main() {
    int choice;
    char str[100]; // Increased size for safety

    do {
        cout << "-------------------------------------------------------------------" << endl; 
        cout << "----------------------- MENU DRIVEN PROGRAM -----------------------" << endl;
        cout << "Enter Your String: ";
        cin.getline(str,100);

        cout << "\nMenu:\n";
        cout << "0: Find Length of Your String\n";
        cout << "1: Toggle Case of Your String\n";
        cout << "2: Find Number of Vowels and Consonants of Your String\n";


        cout << "8: Exit\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice) {
        case 0: {
            cout << "Length of your string is: " << findLength(str) << endl;
            break;
        }

        case 1: {
            ToggleCase(str);
            cout << "Toggled String is: " << str << endl;
            break;
        }
        case 2:
            findVowelsandConsonants(str);
            break;

        case 8:
            cout << "Exiting Program." << endl;
            break;

        default:
            cout << "Invalid Choice. Please try again." << endl;
        }

    } while (choice != 8);

    return 0;
}
