#include "linkedlist.h"
using namespace std;

void displayMenu() {
    cout << "\n===== Linked List Menu =====\n";
    cout << "1. Read from file\n";
    cout << "2. Insert element\n";
    cout << "3. Remove element by index\n";
    cout << "4. Access element using operator[]\n";
    cout << "5. Print linked list\n";
    cout << "6. Exit\n";
    cout << "===========================\n";
    cout << "Enter your choice: ";
}

int main(void) {
    SortedLinkedList list;
    int choice;
    while (choice != 6){
        displayMenu();
        cin >> choice;
        switch (choice) {
            case 1: { 
                ifstream file("testcases_problem3.txt");
                if (!file) {
                    cerr << "Error: Could not open file.\n";
                    break;
                }

                int value;
                while (file >> value) {
                    list.insert(value);
                }
                file.close();
                cout << "Data loaded successfully!\n";
                cout<<list;
                break;
            }
            case 2: {
                int value;
                cout << "Enter value to insert: ";
                cin >> value;
                list.insert(value);
                cout << "Inserted " << value << " into the list.\n";
                break;
            }
            case 3: {  
                int index;
                cout << "Enter index to remove: ";
                cin >> index;
                list.remove(index);
                cout << "Removed element at index " << index << ".\n";
                break;
            }
            case 4: { 
                int index;
                cout << "Enter index to access: ";
                cin >> index;
                try {
                    list[index];
                    cout << "Element at index " << index << ": " << list[index] << endl;
                } catch (const out_of_range& e) {
                    cerr << "Error: " << e.what() << endl;
                }
                break;
            }
            case 5: { 
                cout << "Linked List: " << list << endl;
                break;
            }
            case 6:
            cout << "\nEEEEE  X   X  III  TTTTT   TTTTT  III  N   N   GGG  " << endl;
            cout << "E      X   X   I     T       T     I   NN  N  G     " << endl;
            cout << "EEE     X X    I     T       T     I   N N N  G  GG " << endl;
            cout << "E        X     I     T       T     I   N  NN  G   G " << endl;
            cout << "EEEEE   X  X  III    T       T    III  N   N   GGG  " << endl;
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }

    }
}
/*
predefined testcases
10 5 30 20 50 40 25
77 12 99 65 23 87 11
-5 0 -10 20 -15 25 -1
300 150 450 100 200 350 250
8 19 2 45 33 27 11
42 99 7 77 55 21 90
1 -1 2 -2 3 -3 4
*/

