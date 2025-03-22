#ifndef SORTING_SYSTEM_H
#define SORTING_SYSTEM_H
#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include<chrono>
#include <iomanip>
#include <concepts>
#include <fstream>
#include <type_traits>
using namespace std;
template <typename T>
class SortingSystem {
private:
    T* data;
    int Size;

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
    void apply_ms();
    void quickSort(int start, int end);
    void apply_qs();
    int partition(int start, int end);
    template <typename U = T, typename enable_if<is_integral<U>::value, bool>::type = true>
    void countSort();
    template <typename U = T, typename enable_if<is_integral<U>::value, bool>::type = true>
    void radixSort();
    void bucketSort();
    void insertionSortForBucket(T* bucket, int size, int bucketNumber);
    void displayData();
    void measureSortTime(void (SortingSystem::*sortFunc)());
    void showMenu();
};
#endif
