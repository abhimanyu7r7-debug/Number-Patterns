
#include <iostream>
using namespace std;

// Function 1: Calculate total marks
int calculateTotal(int marks[], int size) {
    int total = 0;

    for (int i = 0; i < size; i++) {
        total += marks[i];
    }

    return total;
}

// Function 2: Calculate average
float calculateAverage(int total, int size) {
    return (float)total / size;
}

// Function 3: Find highest marks
int findHighest(int marks[], int size) {
    int highest = marks[0];

    for (int i = 1; i < size; i++) {
        if (marks[i] > highest) {
            highest = marks[i];
        }
    }

    return highest;
}

// Function 4: Find lowest marks
int findLowest(int marks[], int size) {
    int lowest = marks[0];

    for (int i = 1; i < size; i++) {
        if (marks[i] < lowest) {
            lowest = marks[i];
        }
    }

    return lowest;
}

// Function 5: Calculate grade
char calculateGrade(float average) {
    if (average >= 90)
        return 'A';
    else if (average >= 80)
        return 'B';
    else if (average >= 70)
        return 'C';
    else if (average >= 60)
        return 'D';
    else
        return 'F';
}

int main() {
    const int SIZE = 5;
    int marks[SIZE];

    cout << "===== MARKS MANAGER =====\n";

    // Input and validation
    for (int i = 0; i < SIZE; i++) {
        while (true) {
            cout << "Enter marks for Subject "
                 << i + 1 << " (0-100): ";

            if (!(cin >> marks[i])) {
                cout << "Invalid input! Enter a number.\n";
                cin.clear();
                cin.ignore(10000, '\n');
                continue;
            }

            if (marks[i] < 0 || marks[i] > 100) {
                cout << "Marks must be between 0 and 100!\n";
                continue;
            }

            break;
        }
    }

    // Calculations
    int total = calculateTotal(marks, SIZE);
    float average = calculateAverage(total, SIZE);
    int highest = findHighest(marks, SIZE);
    int lowest = findLowest(marks, SIZE);
    char grade = calculateGrade(average);

    // Display result
    cout << "\n===== FINAL RESULT =====\n";

    cout << "Total Marks: " << total << "/500\n";
    cout << "Average: " << average << "\n";
    cout << "Highest Marks: " << highest << "\n";
    cout << "Lowest Marks: " << lowest << "\n";
    cout << "Grade: " << grade << "\n";

    return 0;
}
