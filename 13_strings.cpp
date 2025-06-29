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
    bool validate(char str[]){
        for(int i = 0; str[i] != '\0'; i++) {
            if(!(str[i]>=65 && str[i]<=122) && !(str[i]>=65 && str[i]<=90 )&& !(str[i]>=48 && str[i]<=57)){
                return true;
            }
            
            }
            return false;
    }
    void reverse(char str[]){
        int i=str[0],j=findLength(str)-1;char temp;
        while(i<=j){
            temp = str[i];
            str[i]=str[j];
            str[j]=temp;
            i++;
            j--;
        }

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
        cout << "3: Validate String\n" << endl;
        cout << "4: Reversing String\n";


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
        case 3:
            if(validate(str)){
                cout << "Your String is Valid "<< endl;
            }
            cout << "Your String is not Valid "<< endl;
            break;
        case 4:
            reverse(str);
            cout << "Reversed String is: " << str << endl;
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
