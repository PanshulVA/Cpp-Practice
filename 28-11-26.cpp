//Q1
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "The elements of the array are:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
// Output
// Enter the number of elements: 4
// Enter 4 elements:
// 28 16 44 3
// The elements of the array are:
// 28 16 44 3

//Q2
#include <iostream>
using namespace std;

int main() {
    int n, sum = 0;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    cout << "Sum of all elements in the array = " << sum << endl;
    return 0;
}
// Output
// Enter the number of elements: 4
// Enter 4 elements:
// 28 16 44 3
// The elements of the array are:
// 28 16 44 3

//Q3
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr1[n], arr2[n];
    cout << "Enter elements of the first array:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }
    // Copying elements from arr1 to arr2
    for (int i = 0; i < n; i++) {
        arr2[i] = arr1[i];
    }
    cout << "Elements of the second array are:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr2[i] << " ";
    }

    return 0;
}
// Output
// Enter the number of elements: 4
// Enter 4 elements:
// 28 16 44 3
// The elements of the array are:
// 28 16 44 3

//Q4
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Elements at even index positions are:" << endl;
    for (int i = 0; i < n; i += 2) {
        cout << arr[i] << " ";
    }
    return 0;
}
// Output
// Enter the number of elements: 10
// Enter 10 elements:
// 28 44 3 16 81 17 95 46 007 51
// Elements at even index positions are:
// 28 3 81 95 7

//Q5
#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;
    int matrix[rows][cols];
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
    cout << "The matrix is:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
// Output
// Enter number of rows and columns: 2 2
// Enter the elements of the matrix:
// 28 57 40 22
// The matrix is:
// 28 57
// 40 22

//Q6
#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;
    int matrix[rows][cols];
    cout << "Enter the elements of the matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
    cout << "Matrix elements in row-wise order:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
    }
    return 0;
}
// Output
// Enter number of rows and columns: 2 3
// Enter the elements of the matrix:
// 28 5 7
// 57 40 22
// Matrix elements in row-wise order:
// 28 5 7 57 40 22

//Q7
#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;
    int matrix[rows][cols];
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
    cout << "Matrix elements in column-wise order are:" << endl;
    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows; i++) {
            cout << matrix[i][j] << " ";
        }
    }
    return 0;
}
// Output
// Enter number of rows and columns: 2 2
// Enter the elements of the matrix:
// 28 57
// 40 22
// Matrix elements in column-wise order are:
// 28 40 57 22
