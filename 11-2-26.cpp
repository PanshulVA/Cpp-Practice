// // Q1

// #include <iostream>
// using namespace std;

// int main() {
//     int size;

//     cout << "Enter the size of the array: ";
//     cin >> size;

//     if (size <= 0) {
//         cout << "Invalid size. Size must be greater than 0." << endl;
//         return 1;
//     }

//     int* arr = new int[size];


//     cout << "Enter " << size << " integers:" << endl;
//     for (int i = 0; i < size; i++) {
//         cin >> arr[i];
//     }

//     cout << "The array elements are:" << endl;
//     for (int i = 0; i < size; i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;

//     delete[] arr;

//     arr = nullptr;

//     return 0;
// }

// // Input
// // Enter the size of the array: 4
// // Enter 4 integers:
// // 28 57 22 40

// // Output
// // The array elements are:
// // 28 57 22 40

// // Q2
// // #include <iostream>
// // using namespace std;

// int main() {
//     // Declare two integer variables
//     int a, b;

//     // Take input from user
//     cout << "Enter first number: ";
//     cin >> a;
//     cout << "Enter second number: ";
//     cin >> b;

//     // Declare pointers and assign addresses
//     int* ptr1 = &a;
//     int* ptr2 = &b;

//     // Swap values using pointers
//     int temp = *ptr1;
//     *ptr1 = *ptr2;
//     *ptr2 = temp;

//     // Print swapped values
//     cout << "After swapping:" << endl;
//     cout << "First number: " << a << endl;
//     cout << "Second number: " << b << endl;

//     return 0;
// }

// // Input
// // Enter first number: 28
// // Enter second number: 57

// // Output
// // After swapping:
// // First number: 57
// // Second number: 28

// //Q3
// #include <iostream>
// #include <cstring>
// using namespace std;

// int main() {
//     int size;

//     cout << "Enter the number of strings: ";
//     cin >> size;
//     cin.ignore();

//     if (size <= 0) {
//         cout << "Invalid size. Must be greater than 0." << endl;
//         return 1;
//     }

//     char** arr = new char*[size];

//     for (int i = 0; i < size; i++) {
//         char temp[100];

//         cout << "Enter string " << i + 1 << ": ";
//         cin.getline(temp, 100);

//         arr[i] = new char[strlen(temp) + 1];

//         strcpy(arr[i], temp);
//     }

//     cout << "\nYou entered:\n";
//     for (int i = 0; i < size; i++) {
//         cout << arr[i] << endl;
//     }

//     for (int i = 0; i < size; i++) {
//         delete[] arr[i];
//     }

//     delete[] arr;

//     return 0;
// }

// // Input

// // Enter the number of strings: 5
// // Enter string 1: 2374
// // Enter string 2: 31451325
// // Enter string 3: 25124
// // Enter string 4: 4534
// // Enter string 5: 345

// // Output

// // You entered:
// // 2374
// // 31451325
// // 25124
// // 4534
// // 345

// //Q4
// #include <iostream>
// using namespace std;

// class CircularBuffer {
// private:
//     int* buffer;
//     int size;
//     int front;
//     int rear;
//     int count;

// public:
//     CircularBuffer(int s) {
//         size = s;
//         buffer = new int[size];
//         front = 0;
//         rear = -1;
//         count = 0;
//     }

//     void enqueue(int value) {
//         if (count == size) {
//             cout << "Buffer Overflow! Cannot add more elements.\n";
//             return;
//         }

//         rear = (rear + 1) % size;
//         buffer[rear] = value;
//         count++;

//         cout << value << " added to buffer.\n";
//     }

//     void dequeue() {
//         if (count == 0) {
//             cout << "Buffer Underflow! No elements to remove.\n";
//             return;
//         }

//         cout << buffer[front] << " removed from buffer.\n";
//         front = (front + 1) % size;
//         count--;
//     }

//     void display() {
//         if (count == 0) {
//             cout << "Buffer is empty.\n";
//             return;
//         }

//         cout << "Buffer elements: ";
//         for (int i = 0; i < count; i++) {
//             cout << buffer[(front + i) % size] << " ";
//         }
//         cout << endl;
//     }

//     ~CircularBuffer() {
//         delete[] buffer;
//         cout << "Memory deallocated successfully.\n";
//     }
// };

// int main() {
//     int size;

//     cout << "Enter buffer size: ";
//     cin >> size;

//     if (size <= 0) {
//         cout << "Invalid size.\n";
//         return 1;
//     }

//     CircularBuffer cb(size);

//     int choice, value;

//     do {
//         cout << "\n--- Circular Buffer Menu ---\n";
//         cout << "1. Add Element\n";
//         cout << "2. Remove Element\n";
//         cout << "3. Display Buffer\n";
//         cout << "4. Exit\n";
//         cout << "Enter your choice: ";
//         cin >> choice;

//         switch (choice) {
//             case 1:
//                 cout << "Enter value: ";
//                 cin >> value;
//                 cb.enqueue(value);
//                 break;

//             case 2:
//                 cb.dequeue();
//                 break;

//             case 3:
//                 cb.display();
//                 break;

//             case 4:
//                 cout << "Exiting program...\n";
//                 break;

//             default:
//                 cout << "Invalid choice.\n";
//         }

//     } while (choice != 4);

//     return 0;
// }

// //Input and Output
// // Enter buffer size: 3

// // --- Circular Buffer Menu ---
// // 1. Add Element
// // 2. Remove Element
// // 3. Display Buffer
// // 4. Exit
// // Enter your choice: 1
// // Enter value: 10
// // 10 added to buffer.

// // Enter your choice: 1
// // Enter value: 20
// // 20 added to buffer.

// // Enter your choice: 1
// // Enter value: 30
// // 30 added to buffer.

// // Enter your choice: 1
// // Enter value: 40
// // Buffer Overflow! Cannot add more elements.

// // Enter your choice: 3
// // Buffer elements: 10 20 30

// // Enter your choice: 2
// // 10 removed from buffer.

// // Enter your choice: 3
// // Buffer elements: 20 30

// // Enter your choice: 4
// // Exiting program...
// // Memory deallocated successfully.

// //Q5
// #include <iostream>
// using namespace std;

// int main() {
//     const int number = 100;

//     const int* ptr = &number;

//     cout << "Value of number: " << number << endl;
//     cout << "Value using pointer: " << *ptr << endl;

//     cout << "Modification through pointer is not allowed." << endl;

//     return 0;
// }

// //Output
// // Value of number: 100
// // Value using pointer: 100
// // Modification through pointer is not allowed.

//Q6

// #include <iostream>

// int& getStaticReference() {
//     static int staticVar = 42;
//     std::cout << "Inside function: staticVar = " << staticVar << std::endl;
//     return staticVar;
// }

// int main() {
//     std::cout << "First call:" << std::endl;
//     int& ref = getStaticReference();
//     std::cout << "Back in main: ref = " << ref << std::endl;

//     ref = 100;  // Modifies the static variable
//     std::cout << "After modification: ref = " << ref << std::endl;

//     std::cout << "Second call (shows persistence):" << std::endl;
//     int& ref2 = getStaticReference();
//     std::cout << "ref2 = " << ref2 << std::endl;

//     return 0;
// }

// // Output
// // First call:
// // Inside function: staticVar = 42
// // Back in main: ref = 42
// // After modification: ref = 100
// // Second call (shows persistence):
// // Inside function: staticVar = 100
// // ref2 = 100
