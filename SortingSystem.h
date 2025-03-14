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
using namespace std;
template <typename T>
class SortingSystem {
private:
     T* data;
     T* tmp;
     int Size;
     vector<int>dataInt;

public:

    SortingSystem(int n);
    ~SortingSystem();
    void insertionSort();
    void selectionSort();
    void bubbleSort();
    void shellSort();
    //void mergeSort(int left, int right);
    //void merge(int left, int mid, int right);
    //void quickSort(int left, int right);
    //int partition(int low, int high);
    template <typename U = T, typename std::enable_if<std::is_integral<U>::value, bool>::type = true>
    void countSort();
    //void radixSort();
    //void bucketSort();
    void displayData();
    void measureSortTime(void (SortingSystem::*sortFunc)());
    void showMenu();
};
#endif

