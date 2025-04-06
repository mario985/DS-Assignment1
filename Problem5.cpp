#include <iostream>
#include <fstream>
#include <limits>
#include <sstream>
using namespace std;

template <typename T>
class StatisticalCalculation {
private:
    T* data;
    int size;
public:
    StatisticalCalculation(int size =0);
    ~StatisticalCalculation();

    void sort();
    double findMedian();
    T findMin();
    T findMax();
    T findMean();
    T findSummation();

    void displayArray();
    void inputData();
    void ReadFile(const string& filename);
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
void StatisticalCalculation<T>::ReadFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
        return;
    }
    string line;
    int test = 1;
    // reads one line at a time
    while(getline(file,line)){
        // split the line into values
        stringstream ss(line);
        T* temp = new T[1000];
        int count = 0 ;
        T value;
        // read the values from the current line into temp
        while(ss >> value){
            temp[count++] = value;
        }
        if (count == 0) {
            delete[] temp;
            continue;
        }

        delete[] data;
        size = count;
        data = new T[size];
        for (int i = 0; i < size; ++i) {
            data[i] = temp[i];
        }
        delete[] temp;

        cout << "\n----- Test Case #" << test++ << " -----\n";
        cout << "Original Data: ";
        displayArray();

        sort();
        cout << "Sorted Data: ";
        displayArray();

        cout << "Median: " << findMedian() << endl;
        cout << "Minimum: " << findMin() << endl;
        cout << "Maximum: " << findMax() << endl;
        cout << "Mean: " << findMean() << endl;
        cout << "Summation: " << findSummation() << endl;
    }
    file.close();
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
// here we find minimum element from data
template<typename T>
T StatisticalCalculation<T>::findMin() {
    displayArray();
    T min = data[0];
    for(int i = 0; i < size; i++) {
        if(data[i] < min) {
            min = data[i];
        }
    }
    return min;
}
// here we find maximum element from data
template<typename T>
T StatisticalCalculation<T>::findMax() {
    displayArray();
    T max = data[0];
    for(int i = 0; i < size; i++) {
        if(data[i] > max) {
            max = data[i];
        }
    }
    return max;
}
// mean is sum of data values over the size
template<typename T>
T StatisticalCalculation<T>::findMean() {
    displayArray();
    double sum = 0;
    for(int i = 0; i < size; i++) {
        sum += data[i];
    }
    return sum / size;
}

template<typename T>
T StatisticalCalculation<T>::findSummation() {
    displayArray();
    T sum = 0;
    for(int i = 0; i < size; i++) {
        sum += data[i];
    }
    return sum;
}
// here we got element at 50% , it has different cases when length of data even or odd
template<typename T>
double StatisticalCalculation<T>::findMedian() {
    sort();
    displayArray();
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

    char inputChoice;
    cout << "Do you want to input data manually (M) or from a file (F)? " << endl;
    cin >> inputChoice;

    if (tolower(inputChoice) == 'f') {

        StatisticalCalculation<double> stat;
        stat.ReadFile("Testcases/testcases_problem5.txt");
    }
    else {
        // Manual processing
        while (true) {
            string dataType;
            while (true) {
                cout << "\nSelect the data type:\n";
                cout << "1 - Integer\n";
                cout << "2 - Float\n";
                cout << "3 - Double\n";
                cout << "Enter choice (1-3): ";
                int type;
                cin >> type;

                if (cin.fail() || type < 1 || type > 3) {
                    cout << "Invalid input! Please enter 1, 2, or 3.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                else {
                    if (type == 1) dataType = "integer";
                    else if (type == 2) dataType = "float";
                    else if (type == 3) dataType = "double";
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
                }
                else {
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

            cout << "\nDo you want to enter a new dataset? (y/n): ";
            char Choice;
            cin >> Choice;
            if (tolower(Choice) == 'n') {
                cout << "Exiting the program...\n";
                break;
            }
        }
    }
    return 0;
}