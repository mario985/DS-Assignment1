#include <iostream>
#include <string>
#include <array>
#include <cmath>
#include <algorithm>
#include <chrono>
#include <iomanip>
#include <fstream>
#include <type_traits>
using namespace std;
bool isAutomaticMode;
int sortingChoice;
template <typename T>
class SortingSystem {
private:
    T* data;
    int Size;
    void apply_ms();
    void apply_qs();
    void insertionSortForBucket(T* bucket, int size, int bucketNumber);


public:

    SortingSystem(int n);
    SortingSystem(const string&filename);
    ~SortingSystem();
    void insertionSort();
    void selectionSort();
    void bubbleSort();
    void shellSort();
    void mergeSort(int left, int right);
    void merge(int left, int mid, int right);
    void quickSort(int start, int end);
    int partition(int start, int end);
    template <typename U = T, typename enable_if<is_integral<U>::value, bool>::type = true>
    void countSort();
    template <typename U = T, typename enable_if<is_integral<U>::value, bool>::type = true>
    void radixSort();
    void bucketSort();
    void displayData();
    void measureSortTime(void (SortingSystem::*sortFunc)());
    void showMenu();
};

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
                        SortingSystem<string> sorter("Testcases/testcases_problem4.txt");
                        break;
                    }
                    case 2: {
                        SortingSystem<int> sorter("Testcases/testcases_problem4.txt");
                        break;
                    }
                    case 3: {
                        SortingSystem<double> sorter("Testcases/testcases_problem4.txt");
                        break;
                    }
                    case 4: {
                        SortingSystem<float> sorter("Testcases/testcases_problem4.txt");
                        break;
                    }
                    case 5: {
                        SortingSystem<char> sorter("Testcases/testcases_problem4.txt");
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
template<typename T>
SortingSystem<T>::SortingSystem(int n) {
    isAutomaticMode = false;
    Size = n;
    data = new T[n];
    for (int i = 0 ; i<Size;i++) {
        cout<<"Enter data ["<<i+1<<"] : ";
        cin >> data[i];
    }
}
template <typename T>
SortingSystem<T>::SortingSystem(const string &filename) {
    isAutomaticMode = true;
    ifstream file(filename);

    if (!file) {
        cerr << "Error: Unable to open file: " << filename << endl;
        return;
    }

    string type;
    int size;
    data = nullptr;

    while (file >> type >> size) {

        if ((is_same<T, int>::value && type == "int") ||
            (is_same<T, float>::value && type == "float") ||
            (is_same<T, double>::value && type == "double") ||
            (is_same<T, string>::value && type == "string") ||
            (is_same<T, char>::value && type == "char")) {
            if(data){
                delete[] data;
            }
            data = new T[size];
            this->Size = size;
            for (int i = 0; i < size; i++) {
                file >> data[i];

            }
            break;
        }
        file.clear();
        file.ignore(1000, '\n');
        file.ignore(1000, '\n');
    }
    T*dataCopy = new T[size];
    for(int i = 0 ;i<size;i++){
        dataCopy[i]=data[i];
    }
    for(int i = 1;i<=9;i++){
        sortingChoice = i;
        SortingSystem::showMenu();
        if(i!=9)cout<<"================================================================="<<endl;
        for(int i = 0 ;i<size;i++){
            data[i]=dataCopy[i];
        }
    }
    delete [] dataCopy;
    file.close();
}
template<typename T>
void SortingSystem<T>::measureSortTime(void (SortingSystem::*sortFunc)()) {
    auto start_time = chrono::high_resolution_clock::now();
    (this->*sortFunc)();
    auto end_time = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
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
void SortingSystem<T>:: bubbleSort(){
    cout << "Sorting using Bubble Sort..." << endl;
    cout << "Initial Data: ";
    displayData();
    bool swapsDone;

    for(int i = 0 ; i < Size-1 ;i++){
        swapsDone = false;

        // Comparing each element with the adjacent one from right to left
        for (int j = Size-1; j >i; j--){
            if(data[j] < data[j-1]){
                swapsDone = true;
                swap(data[j], data[j-1]);
            }
        }
        cout << "Iteration " << i + 1 << ": ";
        displayData();

        // Stop when no more swaps have done
        if (swapsDone == false){
            break;
        }
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
void SortingSystem<T>::insertionSort(){
    T tmp;
    cout << "Sorting using insertion Sort..." << endl;
    cout << "Initial Data: ";
    displayData();
    for(int i = 1; i < Size; i++){
        tmp = data[i];
        int j = i;
        while(j > 0 && tmp < data[j-1]){
            // comparing each element with all the previous ones
            data[j] = data[j-1];
            j--;
            // shift all elements until they are arranged in the correct order
        }
        data[j] = tmp;

        cout << "Iteration " << i << ": ";
        displayData();

    }
    cout << endl;
    cout << "Sorted Data : " << endl;
    displayData();
}

int h = 0;
template<typename T>
void SortingSystem<T>::merge(int left, int mid, int right) {

    int l = mid - left + 1;
    int r = right - mid;

    T* leftArray = new T[l];
    T* rightArray = new T[r];

    for (int i = 0; i < l; i++) {
        leftArray[i] = data[left + i];
    }
    for (int j = 0; j < r; j++) {
        rightArray[j] = data[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    int iteration = 1;
    h++;
    cout <<"\n" << h << "_ Merging Subarrays : " << endl;

    displayData();

    while (i < l && j < r) {
        if (leftArray[i] <= rightArray[j]) {
            data[k] = leftArray[i];
            i++;
        }
        else {
            data[k] = rightArray[j];
            j++;
        }
        k++;
        cout << "Iteration " << iteration++ << ": ";
        displayData();
    }

    while (i < l) {
        data[k] = leftArray[i];
        i++;
        k++;
        cout << "Iteration " << iteration++ << ": ";
        displayData();
    }

    while (j < r) {
        data[k] = rightArray[j];
        j++;
        k++;
        cout << "Iteration " << iteration++ << ": ";
        displayData();
    }
    delete[] leftArray;
    delete[] rightArray;

}

template<typename T>
void SortingSystem<T>::mergeSort(int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(left, mid);
        mergeSort(mid + 1, right);
        merge(left, mid, right);
    }
}

template<typename T>
void SortingSystem<T>::apply_ms() {
    cout << "Sorting using Merge Sort..." << endl;
    cout << "Initial Data: ";
    displayData();
    mergeSort(0, Size - 1);
    cout << endl << " final Sorted Data : " << endl;
    displayData();
}

template<typename T>
// The partition function of quick sort
int SortingSystem<T>::partition(int start, int end){
    // Choose the pivot as the first element
    T pivot = data[start];
    cout << "\nThe pivot is: " << pivot << endl;
    int i = start;
    for (int j = start + 1; j <= end; ++j) {
        // If current element is smaller than pivot
        if(data[j] < pivot){
            i++;
            swap(data[i], data[j]);
        }
        cout << "Iteration " << j << ": ";
        displayData();
    }
    // Add the pivot in its correct position
    // What's before is less than the pivot
    // What's after is greater than the pivot
    swap(data[i], data[start]);
    cout << "After placing the pivot in its position: ";
    displayData();
    cout << "---------------------------------";
    // return the index of the pivot
    return i;
}
template<typename T>
// The recursive function
void SortingSystem<T>::quickSort(int start, int end){
    // Base case: If start >= end, no need to sort
    if(start < end){
        int pivot_ind = partition(start, end);
        quickSort(start, pivot_ind - 1 );
        quickSort(pivot_ind + 1, end);
    }
}
template<typename T>
// Function to use the quick sort since measureSortTime requires a function without parameters
void SortingSystem<T>::apply_qs(){
    cout << "Sorting using Quick Sort..." << endl;
    cout << "Initial Data: ";
    displayData();

    quickSort(0, Size - 1);

    cout << endl << "Sorted Data : " << endl;
    displayData();
}
template <typename T>
template <typename U, typename enable_if<is_integral<U>::value, bool>::type>
void SortingSystem<T>::countSort() {
    cout << "Sorting using count Sort..." << endl;
    cout << "Initial Data: ";

    int maxNumber = 0;

    for (int i = 0; i < Size; i++) {
        if (data[i] > maxNumber) maxNumber = data[i];
    }
    cout << "Step 1: Find Max -> " << maxNumber << endl << endl;
    int* countSorted = new int[maxNumber]();
    vector<int> CountSorted(maxNumber + 1, 0);
    for (int i = 0; i < Size; i++) {
        CountSorted[data[i]]++;
    }

    cout << "Step 2: Count Occurrences" << endl;
    cout << "Index:  ";
    for (int i = 0; i <= maxNumber; i++) {
        if (CountSorted[i] > 0) cout << setw(3) << i << " ";
    }
    cout << endl << "Count:  ";
    for (int i = 0; i <= maxNumber; i++) {
        if (CountSorted[i] > 0) cout << setw(3) << CountSorted[i] << " ";
    }
    cout << endl << endl;

    for (int i = 1; i <= maxNumber; i++) {
        CountSorted[i] += CountSorted[i - 1];
    }

    cout << "Step 3: Cumulative Sum" << endl;
    cout << "Index:  ";
    for (int i = 0; i <= maxNumber; i++) {
        if (CountSorted[i] > 0) cout << setw(3) << i << " ";
    }
    cout << endl << "Count:  ";
    for (int i = 0; i <= maxNumber; i++) {
        if (CountSorted[i] > 0) cout << setw(3) << CountSorted[i] << " ";
    }
    cout << endl << endl;

    int* sortedData = new int[Size]();

    cout << "Step 4: Placing Elements in Sorted Order" << endl;
    for (int i = Size - 1; i >= 0; i--) {
        sortedData[CountSorted[data[i]] - 1] = data[i];
        CountSorted[data[i]]--;

        cout << "Placed " << data[i] << " -> ";
        for (int j = 0; j < Size; j++) {
            if (sortedData[j] == 0) cout << "_ ";
            else cout << sortedData[j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < Size; i++) {
        data[i] = sortedData[i];
    }
    cout << "Final Sorted Array: " << endl;
    displayData();
    delete[] sortedData;
    delete [] countSorted;
}

template<typename T>
template <typename U, typename enable_if<is_integral<U>::value, bool>::type>
void SortingSystem<T>::radixSort() {
    cout << "Sorting using Radix Sort..." << endl;
    cout << "Initial Data: ";
    displayData();

    int maxNumber = 0;

    // Calculating the maximum number
    for (int i = 0; i < Size; i++) {
        if (data[i] > maxNumber) maxNumber = data[i];
    }
    cout << "Find Maximum Value -> " << maxNumber << endl << endl;

    for (int i = 1; maxNumber / i > 0; i *= 10) {
        cout << "---->   Sorting by digit place: " << i << endl;

        // Initialize the array with zeros (0-9)
        int countOccurrences[10] = {0};
        int* result= new int[Size]();

        // Count the occurrences of each digit
        for (int j = 0; j < Size; j++) {
            int digit = (data[j] / i) % 10;
            countOccurrences[digit]++;
        }

        cout << "Step 1: Counting digits at place " << i << endl;
        cout << "Digit:   ";
        for (int j = 0; j < 10; j++) {
            cout << setw(3) << j << " ";
        }
        cout << endl << "Count:   ";
        for (int j = 0; j < 10; j++) {
            cout << setw(3) << countOccurrences[j] << " ";
        }
        cout << endl << endl;

        // Calculating cumulative sum from the frequency array
        for (int j = 1; j < 10; j++) {
            countOccurrences[j] += countOccurrences[j - 1];
        }

        cout << "Step 2: Cumulative Sum of Counts" << endl;
        cout << "Digit:   ";
        for (int j = 0; j < 10; j++) cout << setw(3) << j << " ";
        cout << endl << "Sum:     ";
        for (int j = 0; j < 10; j++) cout << setw(3) << countOccurrences[j] << " ";

        // Add each element in its correct place from LSD to MSB
        for (int j = Size - 1; j >= 0; j--) {
            int digit = (data[j] / i) % 10;
            result[countOccurrences[digit] - 1] = data[j];
            countOccurrences[digit]--;
        }

        cout << endl << "Step 3: Placing Elements in Sorted Order" << endl;
        for (int j = 0; j < Size; j++) {
            if (result[j] == 0) cout << "_ ";
            else cout << result[j] << " ";
        }
        cout << endl;

        // Copy sorted data back to original array
        for (int j = 0; j < Size; j++) {
            data[j] = result[j];
        }

        cout << "Step 4: Array after sorting by place " << i << ": ";
        displayData();
        cout << endl << endl;

        delete[] result;
    }

    cout << "Final Sorted Array: ";
    displayData();
}
template <typename T>
void SortingSystem<T>::insertionSortForBucket(T* bucket, int size, int bucketNumber) {
    cout << "Sorting bucket " << bucketNumber << " using Insertion Sort..." << endl;
    for (int i = 1; i < size; i++) {
        T tmp = bucket[i];
        int j = i;
        while (j > 0 && tmp < bucket[j - 1]) {
            bucket[j] = bucket[j - 1];
            j--;
        }
        bucket[j] = tmp;

        cout << "Bucket " << bucketNumber << " after iteration " << i << ": ";
        for (int k = 0; k < size; k++) {
            cout << bucket[k] << " ";
        }
        cout << endl;
    }
}
template <typename T>
void SortingSystem<T>::bucketSort(){
    cout << "Sorting using Bucket Sort..." << endl;
    cout << "Initial Data: ";
    displayData();

    int bucketCount = sqrt(Size);
    // pointer of pointers , storing addresses of multiple arrays
    T** buckets = new T*[bucketCount];
    // integer array to store size of each bucket.
    int* bucketSizes = new int[bucketCount]();
    for(int i = 0 ; i < bucketCount ; i++){
        buckets[i] = new T[Size];
    }

    cout << "Distributing elements into buckets" << endl;
    // is_arithmetic to be able to work with (integer , double , float , etc...)
    if constexpr (is_arithmetic<T> :: value) {
        T min = data[0];
        T max = data[0];
        for (int i = 1; i < Size; i++) {
            if (data[i] < min) min = data[i];
            if (data[i] > max) max = data[i];
        }
        T range = max - min + 1;
        for (int i = 0; i < Size; i++) {
            int bucketIndex = ((data[i] - min)* bucketCount )/ range;
            if(bucketIndex >= bucketCount) bucketIndex = bucketCount - 1;
            buckets[bucketIndex][bucketSizes[bucketIndex]++] = data[i];
            cout << "Placed " << data[i] << " into bucket " << bucketIndex << endl;
        }
    }
    else{
        char minChar = data[0][0];
        char maxChar = data[0][0];
        for(int i = 1 ; i < Size ; i++){
            char first = data[i][0];
            if(first < minChar) minChar = first;
            if(first > maxChar) maxChar = first;
        }

        char Range = maxChar - minChar + 1;
        for(int i = 0 ; i < Size; i++ ){
            char first = data[i][0];
            int bucketIndex = ((first - minChar)* bucketCount) / Range;
            if(bucketIndex >= bucketCount) bucketIndex = bucketCount - 1;
            buckets[bucketIndex][bucketSizes[bucketIndex]++] = data[i];
            cout << "Placed " << data[i] << " into bucket " << bucketIndex << endl;
        }
    }
    for (int i = 0; i < bucketCount; i++) {
        insertionSortForBucket(buckets[i], bucketSizes[i],i);
    }
    cout << "\nMerging buckets back into array" << endl;
    int index = 0;
    for(int i = 0; i < bucketCount ; i++){
        for(int j = 0; j < bucketSizes[i]; j++){
            data[index++] = buckets[i][j];
        }
    }
    cout << "\nSorted Data: ";
    displayData();
    for(int i = 0; i < bucketCount; i++){
        delete[] buckets[i];
    }
    delete[] buckets;
    delete[] bucketSizes;
}



template<typename T>
SortingSystem<T>::~SortingSystem() {
    if(data){
        delete [] data;
    }
}
template<typename T>
void SortingSystem<T>::showMenu() {
    while (true) {
        if(isAutomaticMode==false){
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
            cin >> sortingChoice;
        }
        switch (sortingChoice) {
            case 1:
                measureSortTime(&SortingSystem::insertionSort);
                break;
            case 2:
                measureSortTime(&SortingSystem::selectionSort);
                break;
            case 3:
                measureSortTime(&SortingSystem::bubbleSort);
                break;
            case 4:
                measureSortTime(&SortingSystem::shellSort);
                break;
            case 5:
                measureSortTime(&SortingSystem::apply_ms);
                break;
            case 6:
                measureSortTime(&SortingSystem::apply_qs);
                break;
            case 7:
                if constexpr(is_integral<T>::value) {
                    measureSortTime(&SortingSystem::countSort);
                }
                else{
                    cout<<"CountSort only works for Integer numbers"<<endl;
                    sortingChoice = -1;
                }
                break;
            case 8:
                if constexpr(is_integral<T>::value) {
                    measureSortTime(&SortingSystem::radixSort);
                }
                else{
                    cout<<"CountSort only works for Integer numbers"<<endl;
                    sortingChoice = -1;
                }
                break;
            case 9:
                measureSortTime(&SortingSystem::bucketSort);
                break;
            default:
                cout << "Invalid choice! Please enter a number between 1 and 9.\n";
        }
        if ((sortingChoice>=1 and sortingChoice<=9) ||isAutomaticMode==true) {
            break;
        }
    }
}
template class SortingSystem<int>;
template class SortingSystem<float>;
template class SortingSystem<double>;
template class SortingSystem<string>;
template class SortingSystem<char>;


