// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 6
// =============================================================================
//
// TASK: Multiplication Table Generator
//
// Write a C++ program that generates multiplication tables using loops
// and functions.
//
// -----------------------------------------------------------------------------
// PART A — Single Table
// -----------------------------------------------------------------------------
// - Ask the user to enter a number.
// - Print the multiplication table for that number from 1 to 12.
//
// Expected output (if user enters 5):
//
//   Multiplication Table for 5:
//   5  x  1  =  5
//   5  x  2  =  10
//   5  x  3  =  15
//   ...
//   5  x  12 =  60
//
// -----------------------------------------------------------------------------
// PART B — Bonus: Tables from 1 to N
// -----------------------------------------------------------------------------
// - Ask the user to enter a number N.
// - Print the full multiplication table for every number from 1 to N.
// - Add a separator line (e.g. "---") between each table.
//
// Expected output (if user enters 3):
//
//   Multiplication Table for 1:
//   1  x  1  =  1
//   ...
//   1  x  12 =  12
//   ---------------------------
//   Multiplication Table for 2:
//   2  x  1  =  2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - N must be a positive integer. If the user enters an invalid value,
//   print an error message and stop.
// - Each part must be in its own function (see scaffold below).
// - Complete Part A before attempting Part B.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;


void print_single_table(int n) {
    cout << "\nMultiplication Table for " << n << ":\n";
    for (int i = 1; i <= 12; ++i) {
        cout << n << "  x  " << i;
        if (i < 10) cout << " "; 
        cout << " =  " << (n * i) << "\n";
    }
}

void part_a() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (num <= 0) {
        cout << "Error: Number must be a positive integer.\n";
        return;
    }

    print_single_table(num);
}

void part_b() {
    int n;
    cout << "Enter N to print tables from 1 to N: ";
    cin >> n;

    if (n <= 0) {
        cout << "Error: N must be a positive integer.\n";
        return;
    }

    for (int i = 1; i <= n; ++i) {
        print_single_table(i);
        if (i < n) {
            cout << "---------------------------\n";
        }
    }
}

int main() {
    int choice;
    cout << "Multiplication Table Generator\n";
    cout << "1. Part A (Single Table)\n";
    cout << "2. Part B (Tables 1 to N)\n";
    cout << "Select an option (1 or 2): ";
    cin >> choice;

    if (choice == 1) {
        part_a();
    } else if (choice == 2) {
        part_b();
    } else {
        cout << "Error: Invalid choice.\n";
    }

    return 0;
}