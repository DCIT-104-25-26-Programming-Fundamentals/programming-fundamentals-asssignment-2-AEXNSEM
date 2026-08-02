// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 9
// =============================================================================
//
// TASK: Console-Based Simple Calculator
//
// Build a calculator program that runs in the console and performs basic
// arithmetic operations based on the user's input.
//
// -----------------------------------------------------------------------------
// OPERATIONS YOUR CALCULATOR MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Addition          ( + )    e.g.  10 + 3  =  13
//   2. Subtraction       ( - )    e.g.  10 - 3  =  7
//   3. Multiplication    ( * )    e.g.  10 * 3  =  30
//   4. Division          ( / )    e.g.  10 / 3  =  3.33
//   5. Modulus           ( % )    e.g.  10 % 3  =  1  (remainder)
//   6. Exponentiation    ( ^ )    e.g.  2 ^ 8   =  256
//   7. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        SIMPLE CALCULATOR
//   ============================
//   1. Addition
//   2. Subtraction
//   3. Multiplication
//   4. Division
//   5. Modulus
//   6. Exponentiation
//   7. Quit
//   Select an operation (1-7):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Select an operation (1-7): 4
//   Enter first number : 10
//   Enter second number: 3
//   Result: 10 / 3 = 3.33
//
//   Select an operation (1-7): 4
//   Enter first number : 5
//   Enter second number: 0
//   Error: Cannot divide by zero.
//
//   Select an operation (1-7): 7
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Each arithmetic operation MUST be written as its own function.
// - Use a loop so the calculator keeps running until the user selects Quit.
// - Division by zero must be caught and handled with a clear error message
//   (do NOT let the program crash).
// - Use fixed and setprecision(2) to display results to 2 decimal places.
// - Handle invalid menu choices gracefully.
// - For exponentiation use a loop or the pow() function from <cmath>.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double addNumbers(double a, double b) {
    return a + b;
}

double subtractNumbers(double a, double b) {
    return a - b;
}

double multiplyNumbers(double a, double b) {
    return a * b;
}

bool divideNumbers(double a, double b, double& result) {
    if (b == 0) {
        return false; 
    }
    result = a / b;
    return true;
}

bool modulusNumbers(int a, int b, int& result) {
    if (b == 0) {
        return false; 
    }
    result = a % b;
    return true;
}

double powerNumbers(double base, double exponent) {
    return pow(base, exponent);
}


double getNumberInput(const string& prompt) {
    double val;
    cout << prompt;
    while (!(cin >> val)) {
        cout << "Invalid input. Please enter a valid number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return val;
}

int main() {
    int choice = 0;

    do {
        cout << "\n============================\n";
        cout << "      SIMPLE CALCULATOR     \n";
        cout << "============================\n";
        cout << "1. Addition\n";
        cout << "2. Subtraction\n";
        cout << "3. Multiplication\n";
        cout << "4. Division\n";
        cout << "5. Modulus\n";
        cout << "6. Exponentiation\n";
        cout << "7. Quit\n";
        cout << "Select an operation (1-7): ";

        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number between 1 and 7.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (choice == 7) {
            cout << "Goodbye!\n";
            break;
        }

        if (choice < 1 || choice > 7) {
            cout << "Invalid choice. Please select an option from 1 to 7.\n";
            continue;
        }

        
        cout << fixed << setprecision(2);

        if (choice == 5) { 
            int num1 = static_cast<int>(getNumberInput("Enter first number : "));
            int num2 = static_cast<int>(getNumberInput("Enter second number: "));
            int modResult;

            if (modulusNumbers(num1, num2, modResult)) {
                cout << "Result: " << num1 << " % " << num2 << " = " << modResult << "\n";
            } else {
                cout << "Error: Cannot perform modulus by zero.\n";
            }
        } 
        else {
            double num1 = getNumberInput("Enter first number : ");
            double num2 = getNumberInput("Enter second number: ");

            switch (choice) {
                case 1:
                    cout << "Result: " << num1 << " + " << num2 << " = " << addNumbers(num1, num2) << "\n";
                    break;
                case 2:
                    cout << "Result: " << num1 << " - " << num2 << " = " << subtractNumbers(num1, num2) << "\n";
                    break;
                case 3:
                    cout << "Result: " << num1 << " * " << num2 << " = " << multiplyNumbers(num1, num2) << "\n";
                    break;
                case 4: {
                    double divResult;
                    if (divideNumbers(num1, num2, divResult)) {
                        cout << "Result: " << num1 << " / " << num2 << " = " << divResult << "\n";
                    } else {
                        cout << "Error: Cannot divide by zero.\n";
                    }
                    break;
                }
                case 6:
                    cout << "Result: " << num1 << " ^ " << num2 << " = " << powerNumbers(num1, num2) << "\n";
                    break;
            }
        }

    } while (choice != 7);

    return 0;
        
}