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
    double findMedian();
    T findMin();
    T findMax();
    T findMean();
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
T StatisticalCalculation<T>::findMean() {
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
double StatisticalCalculation<T>::findMedian() {
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
        string dataType;
        while (true) {
            cout << "Select the data type:\n";
            cout << "1 - Integer\n";
            cout << "2 - Float\n";
            cout << "3 - Double\n";
            cout << "Enter choice (1-3): ";
            int typeChoice;
            cin >> typeChoice;

            if (cin.fail() || typeChoice < 1 || typeChoice > 3) {
                cout << "Invalid input! Please enter 1, 2, or 3.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                if (typeChoice == 1) dataType = "integer";
                else if (typeChoice == 2) dataType = "float";
                else if (typeChoice == 3) dataType = "double";
                break;
            }
        }

        int size;
        while (true) {
            cout << "Enter the number of elements: ";
            cin >> size;

            if (cin.fail() || size < 1) {
                cout << "Please enter a valid positive number.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                break;
            }
        }

        if (dataType == "integer") {
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
        }
        else if (dataType == "double") {
            StatisticalCalculation<double> stat(size);
            stat.inputData();
            stat.sort();
            while (true) {
                stat.statisticsMenu();
                cout << "Do you want to perform another calculation on this dataset? (y/n): ";
                char c;
                cin >> c;
                if (tolower(c) == 'n') break;
            }
        }
        else if (dataType == "float") {
            StatisticalCalculation<float> stat(size);
            stat.inputData();
            stat.sort();
            while (true) {
                stat.statisticsMenu();
                cout << "Do you want to perform another calculation on this dataset? (y/n): ";
                char c;
                cin >> c;
                if (tolower(c) == 'n') break;
            }
        }

        cout << "Do you want to enter a new dataset? (y/n): ";
        char choice;
        cin >> choice;
        if (tolower(choice) == 'n') {
            cout << "Exiting the program...\n";
            break;
        }
    }

    return 0;
}
