// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_SIZE = 10;

void readMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, const string& label = "") {
    if (!label.empty()) {
        cout << "Enter elements for Matrix " << label << " (" << rows << "x" << cols << "):\n";
    } else {
        cout << "Enter elements (" << rows << "x" << cols << "):\n";
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void displayMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << setw(6) << matrix[i][j];
        }
        cout << "\n";
    }
}

void transposeMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[j][i] = matrix[i][j];
        }
    }
}

void partA() {
    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    if (rows <= 0 || rows > MAX_SIZE || cols <= 0 || cols > MAX_SIZE) {
        cout << "Error: Dimensions must be between 1 and " << MAX_SIZE << ".\n";
        return;
    }

    int matrix[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];

    readMatrix(matrix, rows, cols);

    cout << "\nOriginal Matrix:\n";
    displayMatrix(matrix, rows, cols);

    transposeMatrix(matrix, result, rows, cols);

    cout << "\nTransposed Matrix:\n";
    displayMatrix(result, cols, rows);
}


void addMatrices(const int a[MAX_SIZE][MAX_SIZE], const int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void partB() {
    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    if (rows <= 0 || rows > MAX_SIZE || cols <= 0 || cols > MAX_SIZE) {
        cout << "Error: Dimensions must be between 1 and " << MAX_SIZE << ".\n";
        return;
    }

    int a[MAX_SIZE][MAX_SIZE];
    int b[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];

    readMatrix(a, rows, cols, "A");
    readMatrix(b, rows, cols, "B");

    addMatrices(a, b, result, rows, cols);

    cout << "\nSum of Matrices (A + B):\n";
    displayMatrix(result, rows, cols);
}

void multiplyMatrices(const int a[MAX_SIZE][MAX_SIZE], const int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rowsA, int colsA, int colsB) {
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; ++k) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void partC() {
    int rowsA, colsA, colsB;
    cout << "Enter rows of Matrix A: ";
    cin >> rowsA;
    cout << "Enter columns of Matrix A: ";
    cin >> colsA;

    if (rowsA <= 0 || rowsA > MAX_SIZE || colsA <= 0 || colsA > MAX_SIZE) {
        cout << "Error: Dimensions must be between 1 and " << MAX_SIZE << ".\n";
        return;
    }

    int a[MAX_SIZE][MAX_SIZE];
    readMatrix(a, rowsA, colsA, "A");

    int rowsB = colsA;
    cout << "Matrix B must have " << rowsB << " rows.\n";
    cout << "Enter columns of Matrix B: ";
    cin >> colsB;

    if (colsB <= 0 || colsB > MAX_SIZE) {
        cout << "Error: Columns must be between 1 and " << MAX_SIZE << ".\n";
        return;
    }

    int b[MAX_SIZE][MAX_SIZE];
    readMatrix(b, rowsB, colsB, "B");

    int result[MAX_SIZE][MAX_SIZE];
    multiplyMatrices(a, b, result, rowsA, colsA, colsB);

    cout << "\nProduct Matrix (A x B):\n";
    displayMatrix(result, rowsA, colsB);
}

int main() {
    int choice;
    cout << "============================\n";
    cout << "     MATRIX OPERATIONS      \n";
    cout << "============================\n";
    cout << "1. Transpose a Matrix\n";
    cout << "2. Add Two Matrices\n";
    cout << "3. Multiply Two Matrices\n";
    cout << "Select an operation (1-3): ";
    cin >> choice;

    switch (choice) {
        case 1:
            partA();
            break;
        case 2:
            partB();
            break;
        case 3:
            partC();
            break;
        default:
            cout << "Error: Invalid choice.\n";
            break;
    }

    return 0;
}