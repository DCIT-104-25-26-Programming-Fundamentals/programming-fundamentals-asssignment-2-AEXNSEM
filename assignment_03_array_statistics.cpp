// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 3
// =============================================================================
//
// TASK: Array Statistics Calculator
//
// Write a C++ program that reads a collection of numbers from the user
// and computes key statistical values using separate functions.
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLE
// -----------------------------------------------------------------------------
//
//   How many numbers? 5
//   Enter number 1: 4
//   Enter number 2: 7
//   Enter number 3: 2
//   Enter number 4: 9
//   Enter number 5: 1
//
//   Results:
//   Sum:     23
//   Average: 4.6
//   Maximum: 9
//   Minimum: 1
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement each calculation in its own function (see scaffold).
// - You may NOT use any standard library functions like accumulate(), max(),
//   or min(). Implement the logic yourself using loops.
// - N must be a positive integer. If the user enters 0 or a negative number,
//   print an error message and stop.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iostream>
#include <vector>
using namespace std;

// Function to compute sum using a loop
double compute_sum(const vector<double>& numbers) {
    double total = 0.0;
    for (size_t i = 0; i < numbers.size(); ++i) {
        total += numbers[i];
    }
    return total;
}

// Function to compute average
double compute_average(const vector<double>& numbers) {
    if (numbers.empty()) return 0.0;
    return compute_sum(numbers) / numbers.size();
}

// Function to find maximum using a loop
double compute_max(const vector<double>& numbers) {
    double max_val = numbers[0];
    for (size_t i = 1; i < numbers.size(); ++i) {
        if (numbers[i] > max_val) {
            max_val = numbers[i];
        }
    }
    return max_val;
}

// Function to find minimum using a loop
double compute_min(const vector<double>& numbers) {
    double min_val = numbers[0];
    for (size_t i = 1; i < numbers.size(); ++i) {
        if (numbers[i] < min_val) {
            min_val = numbers[i];
        }
    }
    return min_val;
}

int main() {
    int count;
    cout << "How many numbers? ";
    cin >> count;

    // Validate positive integer requirement
    if (count <= 0) {
        cout << "Error: Number of elements must be positive." << endl;
        return 1;
    }

    vector<double> numbers(count);
    for (int i = 0; i < count; ++i) {
        cout << "Enter number " << (i + 1) << ": ";
        cin >> numbers[i];
    }

    // Compute statistics using dedicated functions
    double sum = compute_sum(numbers);
    double avg = compute_average(numbers);
    double max_val = compute_max(numbers);
    double min_val = compute_min(numbers);

    // Display results matching expected output
    cout << "\nResults:\n";
    cout << "Sum:     " << sum << "\n";
    cout << "Average: " << avg << "\n";
    cout << "Maximum: " << max_val << "\n";
    cout << "Minimum: " << min_val << "\n";

    return 0;
}