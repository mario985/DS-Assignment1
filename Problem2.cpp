#include <iostream>
#include <limits>
#include <fstream>
using namespace std;

void validateInteger(int& num);
void display(const int* polynomial, int size);
void calculate_sum(const int* poly1, const int* poly2, int size1, int size2);
void calculate_diff(const int* poly1, const int* poly2, int size1, int size2);

// Function to read file
void readFile(string fileName) {
    cout << "Reading \"" << fileName << "\" file" << endl << endl;

    ifstream file(fileName);
    if (!file) {
        cerr << "Error opening file!\n";
        return;
    }

    int poly1degree, poly2degree;

    while (!file.eof()){
        // Read first polynomial degree and coefficients
        file >> poly1degree;
        int* firstPoly = new int[poly1degree + 2];

        for (int i = 0; i < poly1degree + 2; i++) {
            file >> firstPoly[i];
        }

        // Read second polynomial degree and coefficients
        file >> poly2degree;
        int* secondPoly = new int[poly2degree + 2];

        for (int i = 0; i < poly2degree + 2; i++) {
            file >> secondPoly[i];
        }

        // Display polynomials
        cout << "First polynomial: ";
        display(firstPoly, poly1degree + 2);

        cout << "Second polynomial: ";
        display(secondPoly, poly2degree + 2);

        calculate_sum(firstPoly, secondPoly, poly1degree + 2, poly2degree + 2);
        calculate_diff(secondPoly, firstPoly, poly2degree + 2, poly1degree + 2);

        cout << "------------------------------------------------------------------------\n";
        delete[] firstPoly;
        delete[] secondPoly;

    }
    file.close();
}

// Function to validate integer input
void validateInteger(int& num) {
    while (!(cin >> num)) {
        cerr << "Input must be an integer!";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void display(const int* polynomial, int size) {
    // Flag for only adding the + if the term is not the first one
    bool first = true;

    for (int i = size - 1; i > 1; i--) {
        // Skip the term if the coefficient equals 0
        if (polynomial[i] == 0) {
            continue;
        }
        // Adding the operation depending on the coefficient
        if (!first && polynomial[i] > 0 )
            cout << " + ";
        else if (polynomial[i] < 0)
            cout << " - ";
        // If the coefficient is one, skip
        if(abs(polynomial[i]) != 1){
            cout << abs(polynomial[i]);
        }
        cout << "x";
        if (i != 2) {
            cout << "^" << (i - 1);
        }
        first = false;
    }

    if (polynomial[1] != 0) {
        if (!first && polynomial[1] > 0)
            cout << " + ";
        else if (polynomial[1] < 0)
            cout << " - ";

        cout << abs(polynomial[1]);
    }

    cout << " = " << polynomial[0] << endl;
}

void calculate_sum(const int* poly1, const int* poly2, int size1, int size2) {
    int min_size = (size1 < size2) ? size1 : size2;
    int max_size = (size1 > size2) ? size1 : size2;

    // Determine which polynomial is larger
    const int* largerPoly = (size1 > size2) ? poly1 : poly2;
    const int* smallerPoly = (size1 > size2) ? poly2 : poly1;

    // Allocate memory for result and copy the larger polynomial into it
    int* result = new int[max_size];
    for (int i = 0; i < max_size; i++) {
        result[i] = largerPoly[i];
    }

    // Add elements of the smaller polynomial
    for (int i = 0; i < min_size; i++) {
        result[i] += smallerPoly[i];
    }

    cout << "Sum of polynomials: ";
    display(result, max_size);

    delete[] result;
}

void calculate_diff(const int* poly1, const int* poly2, int size1, int size2){
    int max_size = (size1 > size2) ? size1 : size2;

    // Allocate memory for result and copy the first polynomial into it
    int* result = new int[max_size]();
    for (int i = 0; i < size1; i++) {
        result[i] = poly1[i];
    }

    // Subtract elements of the second polynomial
    for (int i = 0; i < size2; i++) {
        result[i] -= poly2[i];
    }

    cout << "Difference of polynomials: ";
    display(result, max_size);

    delete[] result;
}

int main() {
    char choice;
    cout << "Choose:\n1) Enter values\n2) Use predefined test cases\n";
    cin >> choice;

    switch (choice) {
        case '1': {
            int poly1degree, poly2degree;

            // Reading first polynomial
            cout << "Order of first polynomial: ";
            validateInteger(poly1degree);

            // Dynamic memory allocation for first polynomial
            int* firstPoly = new int[poly1degree + 2];
            cout << "Enter polynomial: " << endl;
            for (int i = 0; i < poly1degree + 2; i++) {
                validateInteger(firstPoly[i]);
            }

            // Reading second polynomial
            cout << "Order of second polynomial: ";
            validateInteger(poly2degree);

            int* secondPoly = new int[poly2degree + 2];
            cout << "Enter polynomial: " << endl;
            for (int i = 0; i < poly2degree + 2; i++) {
                validateInteger(secondPoly[i]);
            }

            // Display polynomials
            cout << "First polynomial: ";
            display(firstPoly, poly1degree + 2);
            cout << "Second polynomial: ";
            display(secondPoly, poly2degree + 2);
            calculate_sum(firstPoly, secondPoly, poly1degree + 2, poly2degree + 2);
            calculate_diff(secondPoly, firstPoly, poly2degree + 2, poly1degree + 2);

            // Free allocated memory
            delete[] firstPoly;
            delete[] secondPoly;
            cout << "GOODBYE!";

            break;
        }
        case '2':
            readFile("Testcases/testcases_problem2.txt");
            cout << "GOODBYE!"<<endl;
            break;
        default:
            cerr << "Invalid choice! Please enter a valid one\n";
            cin >> choice;
            break;
    }

    return 0;
}
