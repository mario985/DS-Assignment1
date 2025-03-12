#include "SortingSystem.h"
#include<chrono>
#include <iomanip>
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
void SortingSystem<T>::measureSortTime(void (SortingSystem::*sortFunc)()) {
    auto start_time = std::chrono::high_resolution_clock::now();
    (this->*sortFunc)();
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    cout << fixed << setprecision(6);
    cout  << "Sorting Time: " << duration.count() /1000000.0 << " seconds\n";
}

template<typename T>
void SortingSystem<T>::displayData(){
    cout << "[";
    for(int i =0 ;  i < Size ; i++){
        cout << data[i];
        if(i < Size - 1) cout << ", ";
    }
    cout << "]"<< endl;
}
template<typename T>
void SortingSystem<T>:: selectionSort(){
    cout << "Sorting using Selection Sort..." << endl;
    cout << "Initial Data: ";
    displayData();
    for(int i = 0 ; i < Size-1 ; i++){
        int least = i;
        for(int j = i + 1 ; j < Size ; j++){
            if(data[j] < data[least]){
                least = j;
            }
        }
        if(least != i) {
            swap(data[i], data[least]);
        }
        cout << "Iteration " << i + 1 << ": ";
        displayData();
    }
    cout << endl;
    cout << "Sorted Data : " << endl;
    displayData();
}
template<typename T>
void SortingSystem<T>:: shellSort() {
    cout << "Sorting using Shell Sort..." << endl;
    cout << "Initial Data: ";
    displayData();
    int pass = 1;
    // Outer loop for the gap reduction to half at each iteration
    for (int gap = Size / 2; gap > 0; gap /= 2) {
        cout << "At pass " << pass << " (The gap = " << gap << ')' << endl;
        for (int i = gap; i < Size; ++i) {
            // Store the original value
            T temp = data[i];
            int j;
            // A loop that compares 2 numbers of different indices and checks their arrangement
            for (j = i; j >= gap && temp < data[j - gap]; j -= gap) {
                // If they need to be swapped
                // Put the greater value in the needed position
                data[j] = data[j - gap];
            }
            // After decrementing the index i to be equal the position needed for the smaller value
            // Was stored in temp, will add it
            data[j] = temp;
            displayData();
        }
        cout << "Data at the end of pass " << pass << ": ";
        displayData();
        cout << "-------------------------------------------" << endl;
        ++pass;
    }
    cout << endl;
    cout << "Sorted Data : " << endl;
    displayData();
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
                measureSortTime(&SortingSystem::selectionSort);
                    break;
            case 3:
                //bubbleSort();
                    break;
            case 4:
                measureSortTime(&SortingSystem::shellSort);
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




