#include <iostream>
#include <limits> 
using namespace std;

template <typename T>
class StatisticalCalculation {
private:
    T* data;
    int size;
public:
    StatisticalCalculation(int size);
    ~StatisticalCalculation();

    void sort();
    T findMedian();
    T findMin();
    T findMax();
    double findMean();
    T findSummation();

    void displayArray();
    void inputData();
    void statisticsMenu();
};

template <typename T>
StatisticalCalculation<T>::StatisticalCalculation(int n) {
    size = n;
    data = new T[size];
}

template <typename T>
StatisticalCalculation<T>::~StatisticalCalculation() {
    delete[] data;
}

template <typename T>
void StatisticalCalculation<T>::inputData() {
    for (int i = 0; i < size; i++) {
        while (true) {
            cout << "Enter element " << i + 1 << ": ";
            cin >> data[i];
            if (cin.fail()) {
                cout << "Invalid input! Please enter a valid number." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                break;
            }
        }
    }
}

template <typename T>
void StatisticalCalculation<T>::displayArray() {
    for (int i = 0; i < size; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}

template <typename T>
void StatisticalCalculation<T>::sort() {
    for(int i = 0; i < size - 1; i++) {
        int least = i;
        for(int j = i + 1; j < size; j++) {
            if(data[j] < data[least]) {
                least = j;
            }
        }
        if(least != i) {
            swap(data[i], data[least]);
        }
    }
}

template<typename T>
T StatisticalCalculation<T>::findMin() {
    T min = data[0];
    for(int i = 0; i < size; i++) {
        if(data[i] < min) {
            min = data[i];
        }
    }
    return min;
}

template<typename T>
T StatisticalCalculation<T>::findMax() {
    T max = data[0];
    for(int i = 0; i < size; i++) {
        if(data[i] > max) {
            max = data[i];
        }
    }
    return max;
}

template<typename T>
double StatisticalCalculation<T>::findMean() {
    double sum = 0;
    for(int i = 0; i < size; i++) {
        sum += data[i];
    }
    return sum / size;
}

template<typename T>
T StatisticalCalculation<T>::findSummation() {
    T sum = 0;
    for(int i = 0; i < size; i++) {
        sum += data[i];
    }
    return sum;
}

template<typename T>
T StatisticalCalculation<T>::findMedian() {
    sort();
    int n = size;
    if(n % 2 == 1) {
        return data[n / 2];
    } else {
        return (data[n / 2] + data[n / 2 - 1]) / 2.0;
    }
}

template<typename T>
void StatisticalCalculation<T>::statisticsMenu() {
    while (true) {
        cout << "\nSelect a statistical calculation:\n";
        cout << "1 - Find Median\n";
        cout << "2 - Find Minimum\n";
        cout << "3 - Find Maximum\n";
        cout << "4 - Find Mean\n";
        cout << "5 - Find Summation\n";
        cout << "Enter your choice (1-5): ";

        int choice;
        cin >> choice;

        if (cin.fail() || choice < 1 || choice > 5) {
            cout << "Invalid choice! Please enter a number between 1 and 5.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1:
                cout << "Median: " << findMedian() << endl;
                break;
            case 2:
                cout << "Minimum: " << findMin() << endl;
                break;
            case 3:
                cout << "Maximum: " << findMax() << endl;
                break;
            case 4:
                cout << "Mean: " << findMean() << endl;
                break;
            case 5:
                cout << "Summation: " << findSummation() << endl;
                break;
        }
        break;
    }
}

int main() {
    cout << "Welcome to the Statistical Analysis System\n";

    while (true) {
        int size;
        cout << "Enter the number of elements: ";
        cin >> size;

        while (cin.fail() || size < 1) {
            cout << "Please enter a valid positive number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter the number of elements: ";
            cin >> size;
        }

        StatisticalCalculation<int> stat(size);

        stat.inputData();
        stat.sort();

        while (true) {
            stat.statisticsMenu();
            cout << "Do you want to perform another calculation on this dataset? (y/n): ";
            char c;
            cin >> c;
            if (tolower(c) == 'n') break;
        }

        cout << "Do you want to enter a new dataset? (y/n): ";
        char choice;
        cin >> choice;
        if (tolower(choice) == 'n') {
            cout << "Exiting the program\n";
            break;
        }
    }

    return 0;
}