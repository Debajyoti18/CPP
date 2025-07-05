#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

class Node {
    public:
    int data;
    Node *next;
    
    Node() {
        data = 0;
        next = nullptr;
    }
    Node(int value) {
        data = value;
        next = nullptr;
    }
    ~Node(){}

};
class LinkedList{
  private:
    Node *head;
  public:
     LinkedList(){
        head = nullptr;
     }
     ~LinkedList(){}
    void displayMenu();
    void createSampleList();
    void insertAtBeginning(int data);
    void insertAtEnd(int data);
    void insertAtPosition(int data, int position);
    void deleteAtBeginning();
    void deleteAtEnd();
    void deleteAtPosition(int position);
    void deleteByValue(int value);
    void displayList();
    bool searchElement(int value);
    int getLength();
    void reverseList();
    void printReverse();
    void removeDuplicatesFromSorted();

};

int main() {
    LinkedList list;
    int choice, data, position, value;
    
    cout << "=== C++ LINKED LIST OPERATIONS ===" << endl;
    cout << "Object-Oriented Menu-Driven Program" << endl << endl;
    
    while (true) {
        list.displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Creating sample list..." << endl;
                 list.createSampleList();
                break;
                
            case 2:
                cout << "Enter data to insert at beginning: ";
                cin >> data;
                 list.insertAtBeginning(data);
                cout << "Implementation needed for insertAtBeginning()" << endl;
                break;
                
            case 3:
                // Insert at End
                cout << "Enter data to insert at end: ";
                cin >> data;
                list.insertAtEnd(data);
                cout << "Implementation needed for insertAtEnd()" << endl;
                break;
                
            case 4:
                // Insert at Position
                cout << "Enter data: ";
                cin >> data;
                cout << "Enter position (0-based indexing): ";
                cin >> position;
               list.insertAtPosition(data, position);
                cout << "Implementation needed for insertAtPosition()" << endl;
                break;
                
            case 5:
                // Delete from Beginning
                // list.deleteAtBeginning();
                cout << "Implementation needed for deleteAtBeginning()" << endl;
                break;
                
            case 6:
                // Delete from End
                // list.deleteAtEnd();
                cout << "Implementation needed for deleteAtEnd()" << endl;
                break;
                
            case 7:
                // Delete from Position
                cout << "Enter position to delete (0-based): ";
                cin >> position;
                // list.deleteAtPosition(position);
                cout << "Implementation needed for deleteAtPosition()" << endl;
                break;
                
            case 8:
                // Delete by Value
                cout << "Enter value to delete: ";
                cin >> value;
                // list.deleteByValue(value);
                cout << "Implementation needed for deleteByValue()" << endl;
                break;
                
            case 9:
                // Display List
                cout << "Current List: ";
                list.displayList();
                break;
                
            case 10:
                // Search Element
                cout << "Enter element to search: ";
                cin >> value;
                // if (list.searchElement(value))
                //     cout << "Element " << value << " found in the list!" << endl;
                // else
                //     cout << "Element " << value << " not found in the list!" << endl;
                cout << "Implementation needed for searchElement()" << endl;
                break;
                
            case 11:
                // Get Length
                // cout << "Length of list: " << list.getLength() << endl;
                cout << "Implementation needed for getLength()" << endl;
                break;
                
            case 12:
                // Check if Empty
                // if (list.isEmpty())
                //     cout << "List is empty" << endl;
                // else
                //     cout << "List is not empty" << endl;
                cout << "Implementation needed for isEmpty()" << endl;
                break;
                
            case 13:
                // Reverse List
                cout << "Reversing the list..." << endl;
                // list.reverseList();
                cout << "Implementation needed for reverseList()" << endl;
                break;
                
            case 14:
                // Remove Duplicates (Sorted)
                cout << "Removing duplicates from sorted list..." << endl;
                // list.removeDuplicatesFromSorted();
                cout << "Implementation needed for removeDuplicatesFromSorted()" << endl;
                break;
                
            case 15:
                // Sort List
                cout << "Sorting the list..." << endl;
                // list.sortList();
                cout << "Implementation needed for sortList()" << endl;
                break;
                
            case 16:
                // Find Middle Element
                // Node* middle = list.findMiddle();
                // if (middle)
                //     cout << "Middle element: " << middle->data << endl;
                // else
                //     cout << "List is empty" << endl;
                cout << "Implementation needed for findMiddle()" << endl;
                break;
                
            case 17:
                // Print in Reverse
                cout << "List in reverse order: ";
                // list.printReverse();
                cout << "Implementation needed for printReverse()" << endl;
                break;
                
            case 18:
                // Clear List
                cout << "Clearing the entire list..." << endl;
                // list.clearList();
                cout << "Implementation needed for clearList()" << endl;
                break;
                
            case 19:
                // Display Menu
                list.displayMenu();
                break;
                
            case 0:
                // Exit
                cout << "Cleaning up and exiting..." << endl;
                cout << "Thank you for using the C++ Linked List Program!" << endl;
                return 0;
                
            default:
                cout << "Invalid choice! Please select a valid option (0-19)." << endl;
                break;
        }
        
        cout << "\nPress Enter to continue...";
        cin.ignore();

        cin.get();
    }
    
    return 0;
}
void LinkedList::displayMenu() {
    cout << "\n" << string(50, '=') << endl;
    cout << setw(35) << "C++ LINKED LIST OPERATIONS" << endl;
    cout << string(50, '=') << endl;
    cout << "1.  Create Sample List" << endl;
    cout << "2.  Insert at Beginning" << endl;
    cout << "3.  Insert at End" << endl;
    cout << "4.  Insert at Position" << endl;
    cout << "5.  Delete from Beginning" << endl;
    cout << "6.  Delete from End" << endl;
    cout << "7.  Delete from Position" << endl;
    cout << "8.  Delete by Value" << endl;
    cout << "9.  Display List" << endl;
    cout << "10. Search Element" << endl;
    cout << "11. Get Length" << endl;
    cout << "12. Check if Empty" << endl;
    cout << "13. Reverse List" << endl;
    cout << "14. Remove Duplicates (Sorted)" << endl;
    cout << "15. Sort List" << endl;
    cout << "16. Find Middle Element" << endl;
    cout << "17. Print in Reverse" << endl;
    cout << "18. Clear List" << endl;
    cout << "19. Display Menu" << endl;
    cout << "0.  Exit" << endl;
    cout << string(50, '=') << endl;
}
void LinkedList:: createSampleList() {
    int a[]={12,13,14,15,16,17,18};
    int size = sizeof(a)/sizeof(a[0]);
    for(int i=0;i<size;i++){
        Node* newnode=new Node(a[i]);
        if(head == nullptr){
            head=newnode;
        }else{
            Node* curr=head;
            while(curr->next != nullptr){
                curr =curr->next;

            }
            curr->next=newnode;
        }

    }


}
void LinkedList::displayList(){
    while (head!=nullptr)
    {
        cout << head->data << ",";
        head= head->next;

    }
    
}
void LinkedList:: insertAtBeginning(int x){
   Node* newnode=new Node(x);
    newnode->next = head;
    head=newnode; 
}
void LinkedList::insertAtEnd(int data){
    Node* newnode=new Node(data);
    Node* temp=head;
    if(head ==nullptr){
        head=newnode;
        return;
    }
    while(temp->next !=nullptr){
        temp = temp->next;
    }
    temp->next=newnode;
    newnode->=nullptr;
}
void LinkedList::insertAtPosition(int data,int pos){
    if(pos < 0 || pos > Length(head)){
        return ;
    }
    Node* t=new Node(data);
     t.next=nullptr;
    if(pos == 0){
        t.next = head;
        head=t;
    }else{
        Node* p=head;
        for(int i=0;i<pos-1;i++){p=p->next;}
        t->next = p->next;
        p->next=t;
    }
}


