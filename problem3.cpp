#include "linkedlist.h"
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
                    return 1;
                }
            
                string line;
                int testCaseNumber = 1;
            
                while (getline(file, line)) {
                    if (line.empty()) continue; 
            
                    SortedLinkedList fileList;
                    istringstream ss(line);
                    int value;

                    while (ss >> value) {
                        fileList.insert(value);
                    }
            
                    cout << "Test Case " << testCaseNumber++ << ":\n";
                    cout << "Initial List: " << fileList << endl;
            
                    while (getline(file, line) && !line.empty()) {
                        istringstream commandStream(line);
                        string command;
                        commandStream >> command;
            
                        if (command == "insert") {
                            int val;
                            if (commandStream >> val) {
                                fileList.insert(val);
                                cout << "Inserted " << val << "\n";
                                cout<<fileList<<endl;
                            }
                        } else if (command == "remove") {
                            int index;
                            if (commandStream >> index) {
                                fileList.remove(index);
                                cout << "Removed at index " << index << "\n";
                                cout<<fileList<<endl;
                            }
                        } else if (command == "print") {
                            cout << "List: " << fileList << endl;
                        } else if (command == "access") {
                            int index;
                            if (commandStream >> index) {
                                try {
                                    fileList[index];
                                    cout << "Element at index " << index << " : " << fileList[index] << "\n";
                                } catch (const out_of_range& e) {
                                    cerr << e.what() << "\n";
                                }
                            }
                        }
                    }
                    cout << "Final List: " << fileList << "\n\n";
                }
            
                file.close();
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

