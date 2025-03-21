#include "SortingSystem.h"

using namespace std;

int main() {
    cout << "Welcome to our Sorting System" << endl;

    while (true) {
        int choice, size, sortingMethod;

        while (true) {
            cout << "Choose input method:\n";
            cout << "1. Use predefined test cases\n";
            cout << "2. Enter numbers manually\n";
            cout << "Choice: ";
            cin >> sortingMethod;

            if (sortingMethod == 1 || sortingMethod == 2) {
                break;
            }
            cout << "Please enter a valid choice (1 or 2)." << endl;
        }

        if (sortingMethod == 1) {
            while (true) {
                cout << "Choose the type of data to test:\n";
                cout << "1 - String\n";
                cout << "2 - Integer\n";
                cout << "3 - Double\n";
                cout << "4 - Float\n";
                cout << "5 - Char\n";
                cout << "Choice: ";
                cin >> choice;

                if (choice < 1 || choice > 5) {
                    cout << "Invalid choice! Please enter a number between 1 and 5.\n";
                    continue; 
                }

                    switch (choice) {
                        case 1: {
                            SortingSystem<string> sorter("testcases.txt");
                            break;
                        }
                        case 2: {
                            SortingSystem<int> sorter("testcases.txt");
                            break;
                        }
                        case 3: {
                            SortingSystem<double> sorter("testcases.txt");
                            break;
                        }
                        case 4: {
                            SortingSystem<float> sorter("testcases.txt");
                            break;
                        }
                        case 5: {
                            SortingSystem<char> sorter("testcases.txt");
                            break;
                        }
                    }
                    break;
                }
            }
        
        else if (sortingMethod == 2) {
            while (true) {
                cout << "Enter the number of elements: ";
                cin >> size;

                if (size > 0) {
                    break;
                }
                cout << "Please enter a valid positive number." << endl;
            }

            while (true) {
                cout << "Enter the type of data that you want to sort:\n";
                cout << "1 - String\n";
                cout << "2 - Integer\n";
                cout << "3 - Double\n";
                cout << "4 - Float\n";
                cout << "5 - Char\n";
                cout << "Choice: ";
                cin >> choice;

                switch (choice) {
                    case 1: {
                        SortingSystem<string> sorter(size);
                        sorter.showMenu();
                        break;
                    }
                    case 2: {
                        SortingSystem<int> sorter(size);
                        sorter.showMenu();
                        break;
                    }
                    case 3: {
                        SortingSystem<double> sorter(size);
                        sorter.showMenu();
                        break;
                    }
                    case 4: {
                        SortingSystem<float> sorter(size);
                        sorter.showMenu();
                        break;
                    }
                    case 5: {
                        SortingSystem<char> sorter(size);
                        sorter.showMenu();
                        break;
                    }
                    default:
                        cout << "Invalid choice! Please enter a number between 1 and 5.\n";
                        continue;
                }
                break; 
            }
        }

        cout << "Do you want to sort another dataset? (y/n): ";
        char c;
        cin >> c;

        if (tolower(c) == 'n') {
            cout << "\nEEEEE  X   X  III  TTTTT   TTTTT  III  N   N   GGG  " << endl;
            cout << "E      X   X   I     T       T     I   NN  N  G     " << endl;
            cout << "EEE     X X    I     T       T     I   N N N  G  GG " << endl;
            cout << "E        X     I     T       T     I   N  NN  G   G " << endl;
            cout << "EEEEE   X  X  III    T       T    III  N   N   GGG  " << endl;
            break; 
        }
    }

    return 0;
}
