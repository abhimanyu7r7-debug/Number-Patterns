
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int number, height;

    // Multiplication table
    cout << "Enter a number for multiplication table: ";
    cin >> number;

    cout << "\nMultiplication Table\n";
    cout << "-------------------\n";

    for (int i = 1; i <= 10; i++) {
        cout << setw(3) << number
             << " x " << setw(2) << i
             << " = " << setw(4) << number * i << endl;
    }

    // Star pyramid
    cout << "\nEnter pyramid height: ";
    cin >> height;

    if (height <= 0) {
        cout << "Height must be a positive number.\n";
        return 0;
    }

    cout << "\nStar Pyramid\n";

    for (int i = 1; i <= height; i++) {
        // Print spaces
        for (int j = 1; j <= height - i; j++) {
            cout << " ";
        }

        // Print stars
        for (int k = 1; k <= 2 * i - 1; k++) {
            cout << "*";
        }

        cout << endl;
    }

    return 0;
}
