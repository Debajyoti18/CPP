#include <iostream>
#include <cctype>
using namespace std;

int findLength(char str[]) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {}
    return i;
}

void ToggleCase(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32;
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 32;
        }
    }
}

void findVowelsandConsonants(char str[]) {
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

bool validate(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!(isalnum(str[i]))) {
            return false;
        }
    }
    return true;
}

void reverse(char str[]) {
    int i = 0, j = findLength(str) - 1;
    char temp;
    while (i <= j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

void Compare(char str[], char st[]) {
    int i = 0;
    bool areEqual = true;
    while (str[i] != '\0' && st[i] != '\0') {
        if (str[i] != st[i]) {
            areEqual = false;
            break;
        }
        i++;
    }
    if (str[i] != '\0' || st[i] != '\0') {
        areEqual = false;
    }
    if (areEqual)
        cout << "Strings are equal." << endl;
    else
        cout << "Strings are not equal." << endl;
}

void Palindrome(char str[]) {
    int i = 0, j = findLength(str) - 1;
    bool isPalin = true;
    while (i < j) {
        if (str[i] != str[j]) {
            isPalin = false;
            break;
        }
        i++;
        j--;
    }
    if (isPalin)
        cout << "The string is a Palindrome." << endl;
    else
        cout << "The string is not a Palindrome." << endl;
} 
    int findDuplicates(char str[]) {
     int hash[26] = {0};
     int i = 0, duplicates = 0;

    while (str[i] != '\0') {
        char ch = tolower(str[i]);
        if (ch >= 'a' && ch <= 'z') {
            hash[ch - 'a']++;
        }
        i++;
    }

    for (int j = 0; j < 26; j++) {
        if (hash[j] > 1) {
            duplicates++;
            cout << "Character '" << char(j + 'a') << "' appears " << hash[j] << " times." << endl;
        }
    }

    return duplicates;
}


int main() {
    int choice;
    char str[100];

    do {
        cout << "-------------------------------------------------------------------" << endl;
        cout << "----------------------- MENU DRIVEN PROGRAM -----------------------" << endl;
        cout << "Enter Your String: ";
        cin.ignore();
        cin.getline(str, 100);

        cout << "\nMenu:\n";
        cout << "0: Find Length of Your String\n";
        cout << "1: Toggle Case of Your String\n";
        cout << "2: Find Number of Vowels and Consonants of Your String\n";
        cout << "3: Validate String\n";
        cout << "4: Reversing String\n";
        cout << "5: Comparing String\n";
        cout << "6: Check Palindrome\n";
        cout << "7: Check Number of Duplicate Alphabets in Your String\n";
        cout << "8: Exit\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice) {
            case 0:
                cout << "Length of your string is: " << findLength(str) << endl;
                break;

            case 1:
                ToggleCase(str);
                cout << "Toggled String is: " << str << endl;
                break;

            case 2:
                findVowelsandConsonants(str);
                break;

            case 3:
                if (validate(str)) {
                    cout << "Your String is Valid" << endl;
                } else {
                    cout << "Your String is not Valid" << endl;
                }
                break;

            case 4:
                reverse(str);
                cout << "Reversed String is: " << str << endl;
                break;

            case 5: {
                char st[100];
                cout << "Enter the string you want to compare: ";
                cin.ignore();
                cin.getline(st, 100);
                Compare(str, st);
                break;
            }

            case 6:
                Palindrome(str);
                break;
            case 7:
                findDuplicates(str);
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
