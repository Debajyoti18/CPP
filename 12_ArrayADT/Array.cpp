#include<iostream>
#include<stdlib.h>
using namespace std;

class Array {
private:
    int *A;
    int size;
    int length;
    void Swap(int *x, int *y);

public:
    Array() {
        size = 10;
        length = 0;
        A = new int[size];
    }
    
    Array(int sz) {
        size = sz;
        length = 0;
        A = new int[size];
    }
    
    ~Array() {
        delete[] A;
    }
    
    void Display();
    void Append(int x);
    void Insert(int index, int x);
    int LinearSearch(int x);
    int BinarySearch(int x);
    int Get(int index);
    void Set(int index, int x);
    int Max();
    int Min();
    void Reverse();
    bool isSorted();
    void LeftRotate(int k);
    void RightRotate(int k);
    void Merge(Array B);
    void Union(Array B);
    void Intersection(Array B);
    void Difference(Array B);
    
    int getLength() { return length; }
    int getSize() { return size; }
};

void Array::Swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void Array::Display() {
    cout << "Array elements: ";
    for (int i = 0; i < length; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

void Array::Append(int x) {
    if (length < size) {
        A[length++] = x;
        cout << "Element " << x << " appended successfully." << endl;
    } else {
        cout << "Array is full! Cannot append." << endl;
    }
}

void Array::Insert(int index, int x) {
    if (index >= 0 && index <= length && length < size) {
        for (int i = length; i > index; i--) {
            A[i] = A[i-1];
        }
        A[index] = x;
        length++;
        cout << "Element " << x << " inserted at index " << index << " successfully." << endl;
    } else {
        cout << "Invalid index or array is full!" << endl;
    }
}

int Array::LinearSearch(int x) {
    for (int i = 0; i < length; i++) {
        if (A[i] == x) {
            return i;
        }
    }
    return -1;
}

int Array::BinarySearch(int x) {
    int low = 0, high = length - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (A[mid] == x) {
            return mid;
        } else if (A[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int Array::Get(int index) {
    if (index >= 0 && index < length) {
        return A[index];
    }
    cout << "Invalid index!" << endl;
    return -1;
}

void Array::Set(int index, int x) {
    if (index >= 0 && index < length) {
        A[index] = x;
        cout << "Element at index " << index << " set to " << x << endl;
    } else {
        cout << "Invalid index!" << endl;
    }
}

int Array::Max() {
    if (length == 0) {
        cout << "Array is empty!" << endl;
        return -1;
    }
    int max = A[0];
    for (int i = 1; i < length; i++) {
        if (A[i] > max) {
            max = A[i];
        }
    }
    return max;
}

int Array::Min() {
    if (length == 0) {
        cout << "Array is empty!" << endl;
        return -1;
    }
    int min = A[0];
    for (int i = 1; i < length; i++) {
        if (A[i] < min) {
            min = A[i];
        }
    }
    return min;
}

void Array::Reverse() {
    for (int i = 0; i < length/2; i++) {
        Swap(&A[i], &A[length-1-i]);
    }
    cout << "Array reversed successfully." << endl;
}

bool Array::isSorted() {
    for (int i = 0; i < length-1; i++) {
        if (A[i] > A[i+1]) {
            return false;
        }
    }
    return true;
}

void Array::LeftRotate(int k) {
    if (length == 0) return;
    k = k % length;
    
    for (int i = 0; i < k; i++) {
        int temp = A[0];
        for (int j = 0; j < length-1; j++) {
            A[j] = A[j+1];
        }
        A[length-1] = temp;
    }
    cout << "Array left rotated by " << k << " positions." << endl;
}

void Array::RightRotate(int k) {
    if (length == 0) return;
    k = k % length;
    
    for (int i = 0; i < k; i++) {
        int temp = A[length-1];
        for (int j = length-1; j > 0; j--) {
            A[j] = A[j-1];
        }
        A[0] = temp;
    }
    cout << "Array right rotated by " << k << " positions." << endl;
}

void Array::Merge(Array B) {
    cout << "Merge function - To be implemented" << endl;
}

void Array::Union(Array B) {
    cout << "Union function - To be implemented" << endl;
}

void Array::Intersection(Array B) {
    cout << "Intersection function - To be implemented" << endl;
}

void Array::Difference(Array B) {
    cout << "Difference function - To be implemented" << endl;
}

// Menu function
void displayMenu() {
    cout << "\n========== ARRAY OPERATIONS MENU ==========" << endl;
    cout << "1.  Display Array" << endl;
    cout << "2.  Append Element" << endl;
    cout << "3.  Insert Element" << endl;
    cout << "4.  Linear Search" << endl;
    cout << "5.  Binary Search" << endl;
    cout << "6.  Get Element" << endl;
    cout << "7.  Set Element" << endl;
    cout << "8.  Find Maximum" << endl;
    cout << "9.  Find Minimum" << endl;
    cout << "10. Reverse Array" << endl;
    cout << "11. Check if Sorted" << endl;
    cout << "12. Left Rotate" << endl;
    cout << "13. Right Rotate" << endl;
    cout << "14. Merge Arrays" << endl;
    cout << "15. Union of Arrays" << endl;
    cout << "16. Intersection of Arrays" << endl;
    cout << "17. Difference of Arrays" << endl;
    cout << "18. Exit" << endl;
    cout << "==========================================" << endl;
    cout << "Enter your choice: ";
}

int main() {
    int size, choice, element, index, k;
    
    cout << "Enter the size of array: ";
    cin >> size;
    
    Array arr(size);
    
    while (true) {
        displayMenu();
        cin >> choice;
        
        switch (choice) {
            case 1:
                arr.Display();
                break;
                
            case 2:
                cout << "Enter element to append: ";
                cin >> element;
                arr.Append(element);
                break;
                
            case 3:
                cout << "Enter index and element to insert: ";
                cin >> index >> element;
                arr.Insert(index, element);
                break;
                
            case 4:
                cout << "Enter element to search: ";
                cin >> element;
                index = arr.LinearSearch(element);
                if (index != -1) {
                    cout << "Element found at index: " << index << endl;
                } else {
                    cout << "Element not found!" << endl;
                }
                break;
                
            case 5:
                cout << "Enter element to search (Binary Search): ";
                cin >> element;
                if (arr.isSorted()) {
                    index = arr.BinarySearch(element);
                    if (index != -1) {
                        cout << "Element found at index: " << index << endl;
                    } else {
                        cout << "Element not found!" << endl;
                    }
                } else {
                    cout << "Array must be sorted for binary search!" << endl;
                }
                break;
                
            case 6:
                cout << "Enter index to get element: ";
                cin >> index;
                element = arr.Get(index);
                if (element != -1) {
                    cout << "Element at index " << index << " is: " << element << endl;
                }
                break;
                
            case 7:
                cout << "Enter index and new value: ";
                cin >> index >> element;
                arr.Set(index, element);
                break;
                
            case 8:
                element = arr.Max();
                if (element != -1) {
                    cout << "Maximum element: " << element << endl;
                }
                break;
                
            case 9:
                element = arr.Min();
                if (element != -1) {
                    cout << "Minimum element: " << element << endl;
                }
                break;
                
            case 10:
                arr.Reverse();
                break;
                
            case 11:
                if (arr.isSorted()) {
                    cout << "Array is sorted." << endl;
                } else {
                    cout << "Array is not sorted." << endl;
                }
                break;
                
            case 12:
                cout << "Enter number of positions to left rotate: ";
                cin >> k;
                arr.LeftRotate(k);
                break;
                
            case 13:
                cout << "Enter number of positions to right rotate: ";
                cin >> k;
                arr.RightRotate(k);
                break;
                
            case 14:
                arr.Merge(Array());
                break;
                
            case 15:
                arr.Union(Array());
                break;
                
            case 16:
                arr.Intersection(Array());
                break;
                
            case 17:
                arr.Difference(Array());
                break;
                
            case 18:
                cout << "Exiting program. Goodbye!" << endl;
                return 0;
                
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
        
        cout << "\nPress Enter to continue...";
        cin.ignore();
        cin.get();
    }
    
    return 0;
}
