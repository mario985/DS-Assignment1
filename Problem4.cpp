#include <iostream>
#include <stack>
#include <map>
#include <queue>
#include <string>
#include <array>
#include <vector>
using namespace std;
template <typename T>
class SortingSystem {
private:
    T*data;
    int Size;
public:
    SortingSystem(int n) {
        Size = n;
        data = new T[n];
        for (int i = 0 ; i<Size;i++) {
            cout<<"Enter data ["<<i+1<<"] : ";
            cin>>data[i];
        }

    }
    ~SortingSystem() {
        delete[] data;
    }
    void insertionSort(); // (1) Insertion Sort
    void selectionSort(); // (2) Selection Sort
    void bubbleSort(); // (3) Bubble Sort
    void shellSort(); // (4) Shell Sort
    void mergeSort(int left, int right); // (5) Merge Sort
    void merge(int left, int mid, int right); // Merge Sort Helper
    void quickSort(int left, int right); // (6) Quick Sort
    int partition(int low, int high); // Quick Sort Helper
    void countSort(); // (7) Count Sort (Only for int)
    void radixSort(); // (8) Radix Sort (Only for int)
    void bucketSort(); // (9) Bucket Sort
    void displayData(); // Print the current state of the array
    void measureSortTime(void (*sortFunc)()); // Measure sorting time
    void showMenu() {
        while (true) {
            cout << "Choose a sorting algorithm:\n";
            cout << "1 - Insertion Sort\n";
            cout << "2 - Selection Sort\n";
            cout << "3 - Bubble Sort\n";
            cout << "4 - Shell Sort\n";
            cout << "5 - Merge Sort\n";
            cout << "6 - Quick Sort\n";
            cout << "7 - Count Sort (Only for int)\n";
            cout << "8 - Radix Sort (Only for int)\n";
            cout << "9 - Bucket Sort\n";
            cout << "Choice: ";
            int sortingChoice;
            cin >> sortingChoice;
            switch (sortingChoice) {
                case 1:
                    //insertionSort();
                        break;
                case 2:
                    //selectionSort();
                        break;
                case 3:
                    //bubbleSort();
                        break;
                case 4:
                    //shellSort();
                        break;
                case 5:
                    //mergeSort(0, size - 1);
                        break;
                case 6:
                    //quickSort(0, size - 1);
                        break;
                case 7:
                    //countSort();
                        break;
                case 8:
                    //radixSort();
                        break;
                case 9:
                    //bucketSort();
                        break;
                default:
                    cout << "Invalid choice! Please enter a number between 1 and 9.\n";
            }
            if (sortingChoice>=1 and sortingChoice<=9) {
                break;
            }
        }
    } // Display menu for user interaction
};
int main(void) {
    cout<<"Welcome to our Sorting System"<<endl;
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
            default:
                cout << "Invalid choice! Please enter a number between 1 and 4.\n";
        }
        if (choice>=1 and choice <=4) {
            cout << "\nEEEEE  X   X  III  TTTTT   TTTTT  III  N   N   GGG  "<<endl;
            cout << "E      X   X   I     T       T     I   NN  N  G     "<<endl;
            cout << "EEE     X X    I     T       T     I   N N N  G  GG "<<endl;
            cout << "E        X     I     T       T     I   N  NN  G   G "<<endl;
            cout << "EEEEE   X  X  III    T       T    III  N   N   GGG  "<<endl;
            break;
        }
    }
        }
