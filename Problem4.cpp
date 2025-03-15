#include "SortingSystem.h"
int main(void) {
    cout<<"Welcome to our Sorting System"<<endl;
    while (true) {
        int choice, size;
        while (true) {
            cout << "Enter the number of elements: ";
            cin >> size;
            if (size<1) {
                cout<<"Please enter a valid positive number"<<endl;
            }
            else break;
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
                    SortingSystem<char>sorter(size);
                    sorter.showMenu();
                    break;
                }
                default:
                    cout << "Invalid choice! Please enter a number between 1 and 4.\n";
            }
            if (choice>=1 and choice <=4) {

                break;
            }
        }
        cout<<"Do you want to sort another dataset? (y/n): ";
        char c;
        cin>>c;
         if (tolower(c)=='n') {
          cout << "\nEEEEE  X   X  III  TTTTT   TTTTT  III  N   N   GGG  "<<endl;
            cout << "E      X   X   I     T       T     I   NN  N  G     "<<endl;
            cout << "EEE     X X    I     T       T     I   N N N  G  GG "<<endl;
            cout << "E        X     I     T       T     I   N  NN  G   G "<<endl;
            cout << "EEEEE   X  X  III    T       T    III  N   N   GGG  "<<endl;
            break;

        }

    }
}
