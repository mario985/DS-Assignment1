#include "SortingSystem.h"
template<typename T>
SortingSystem<T>::SortingSystem(int n) {
    Size = n;
    data = new T[n];
    for (int i = 0 ; i<Size;i++) {
        cout<<"Enter data ["<<i+1<<"] : ";
        cin>>data[i];
    }
}
template<typename T>
SortingSystem<T>::~SortingSystem() {
    delete [] data;
}
template<typename T>
void SortingSystem<T>::showMenu() {
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
                //  insertionSort();
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
}

template class SortingSystem<int>;
template class SortingSystem<float>;
template class SortingSystem<double>;
template class SortingSystem<string>;




