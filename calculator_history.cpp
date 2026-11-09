
#include <iostream>
#include <cmath>
#include <string>
#include <limits>
using namespace std;

const int MAX_HISTORY = 10;

double history[MAX_HISTORY];
string expressions[MAX_HISTORY];
int historyCount = 0;

void addHistory(string expression, double result) {
    if (historyCount < MAX_HISTORY) {
        expressions[historyCount] = expression;
        history[historyCount] = result;
        historyCount++;
    } else {
        for (int i = 0; i < MAX_HISTORY - 1; i++) {
            expressions[i] = expressions[i + 1];
            history[i] = history[i + 1];
        }
        expressions[MAX_HISTORY - 1] = expression;
        history[MAX_HISTORY - 1] = result;
    }
}

void showHistory() {
    if (historyCount == 0) {
        cout << "No calculation history yet.\n";
        return;
    }

    cout << "\n--- Last 10 Calculations ---\n";
    for (int i = 0; i < historyCount; i++) {
        cout << i + 1 << ". " << expressions[i]
             << " = " << history[i] << "\n";
    }
}

double calculate(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '%': return fmod(a, b);
        case '^': return pow(a, b);
        default: return 0;
    }
}

int main() {
    double a, b, result;
    char op;
    int choice;

    cout << "===== CALCULATOR WITH HISTORY =====\n";

    while (true) {
        cout << "\n1. Calculate\n";
        cout << "2. Show History\n";
        cout << "3. Quit\n";
        cout << "Enter choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input! Enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (choice == 3) {
            cout << "Calculator closed.\n";
            break;
        }

        if (choice == 2) {
            showHistory();
            continue;
        }

        if (choice != 1) {
            cout << "Invalid choice!\n";
            continue;
        }

        cout << "Enter first number: ";
        if (!(cin >> a)) {
            cout << "Invalid number!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        cout << "Enter operator (+ - * / % ^): ";
        if (!(cin >> op)) {
            cout << "Invalid operator input!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        cout << "Enter second number: ";
        if (!(cin >> b)) {
            cout << "Invalid number!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (op != '+' && op != '-' && op != '*' &&
            op != '/' && op != '%' && op != '^') {
            cout << "Unsupported operator!\n";
            continue;
        }

        if ((op == '/' || op == '%') && b == 0) {
            cout << "Error: Division by zero!\n";
            continue;
        }

        result = calculate(a, b, op);

        cout << "Result = " << result << "\n";

        string expression = to_string(a) + " " + op
                          + " " + to_string(b);

        addHistory(expression, result);
    }

    return 0;
}
