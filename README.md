# C++ Practice
These are all the questions throught the semester our teacher will give according to the dates and questions.

## 21st of January in 2026
### C++ Pointer and Memory Management Exercises

**1. Global, Local, and Dynamic Variables**
* **Task:**
    * Declare a global variable.
    * Declare a local variable inside main().
    * Dynamically allocate an integer using `new`.
    * Print the addresses of all three variables and identify the memory region each belongs to (stack, heap, or data segment).

**2. Function square(int) Usage**
* **Task:**
    * Write a function `square(int)` that returns the square of a number.
    * Call it normally.
    * Call it using a function pointer.

**3. Variable and Pointer Information**
* **Task:** Write a program to print:
    * The value of a variable.
    * The address of the variable.
    * The value stored in a pointer pointing to that variable.

**4. Copy Value Using Pointer Dereferencing**
* **Task:**
    * Declare a pointer that stores the address of a variable.
    * Copy the value of that variable into a third variable using pointer dereferencing.

**5. Pointer Operation Outputs**
* **Task:** Predict the output of the following pointer operations:

    *Case A:*
    ```cpp
    int x = 5;
    int *p = &x;
    *p = 10;
    cout << x;
    ```

    *Case B:*
    ```cpp
    int a = 1, b = 2;
    int *p = &a;
    p = &b;
    *p = 5;
    cout << a << " " << b;
    ```

    *Case C:*
    ```cpp
    int x = 10;
    int *p = &x;
    int **pp = &p;
    **pp = 20;
    cout << x;
    ```

    *Case D:*
    ```cpp
    int a[5] = {2,4,6,8,10};
    int *p = a;
    cout << *p++ << " ";
    cout << *p;
    ```

**6. Swap Two Numbers Using Pointers**
* **Task:** Write a function to swap two numbers using pointers.

**7. Dynamic Integer Management**
* **Task:**
    * Create an integer dynamically using `new`.
    * Modify its value through a pointer.
    * Properly delete the allocated memory.

**8. Pointer Increments and Arithmetic**
* **Task:** Predict the output of pointer increment and dereference operations:
    ```cpp
    int a[] = {1,2,3,4,5};
    int *p = a;
    cout << *p++ << " ";
    cout << (*p)++ << " ";
    cout << ++*p << " ";
    cout << *p << "\n";
    for(int i=0; i<5; i++) cout << a[i] << " ";
    ```

**9. Pointer Value and Post/Pre Increment**
* **Task:** Analyze the output for pointer increment and value modification:
    ```cpp
    int x = 10;
    int *p = &x;
    cout << (*p)++ << " " << x << "\n";
    cout << ++(*p) << " " << x << "\n";
    cout << *p++ << " " << x << "\n";
    ```

**10. Pointer Arithmetic**
* **Task:** Use pointer arithmetic to access elements of an array:
    ```cpp
    int a[] = {10,20,30,40,50};
    int *p = a + 1;
    cout << *(p+2) << " " << *(p-1);
    ```

## 28th of January in 2026
### C++ Array Manipulation Exercises

**1. Array Input and Display**
* **Task:** Write a C++ program to read and display elements of an array.

**2. Sum of Array Elements**
* **Task:** Write a C++ program to find the sum of all elements in an array.

**3. Copying Arrays**
* **Task:** Write a C++ program to copy one array into another.

**4. Accessing Elements by Index**
* **Task:** Write a C++ program to print array elements at even index positions.

**5. 2D Array (Matrix) Input and Display**
* **Task:** Write a C++ program to read and display a 2D array (matrix).

**6. Row-wise Matrix Traversal**
* **Task:** Write a C++ program to print all elements of a matrix in row-wise order.

**7. Column-wise Matrix Traversal**
* **Task:** Write a C++ program to print all elements of a matrix in column-wise order.

## 4th of February in 2026
### C++ Structure Exercises

**1. Student Structure and Filtering**
* **Task:** Create a structure `Student` with:
    * roll number
    * name
    * marks
    * Input details of 5 students and display students who scored more than 75 marks.

**2. Employee Structure and Salary Calculation**
* **Task:** Define a structure `Employee` containing:
    * employee ID
    * name
    * basic salary
    * Calculate and display gross salary (basic + 20% HRA + 10% DA).

## 11th of February in 2026
### C++ Dynamic Memory and Pointer Exercises

**1. Dynamic Array Allocation**
* **Task:** Write a C++ program that dynamically allocates memory for an array of integers using `new` based on the size input by the user. The program should:
    * Allow the user to enter the size of the array.
    * Allow the user to enter the values for the array.
    * Print the array.
    * Free the dynamically allocated memory using `delete[]`.

**2. Swap Two Numbers Using Pointers**
* **Task:** Write a C++ program that swaps two numbers using pointers. The program should:
    * Declare two integer variables.
    * Use a pointer to swap their values.
    * Print the swapped values.

**3. Dynamic Array of Strings**
* **Task:** Write a C++ program that dynamically allocates memory for an array of strings (an array of pointers). The program should:
    * Allow the user to input multiple strings.
    * Print all the strings using the array of pointers.
    * Free the allocated memory for each string and the array of pointers using `delete[]`.

**4. Circular Buffer Implementation**
* **Task:** Write a C++ program that implements a circular buffer using a dynamically allocated array. The program should:
    * Dynamically allocate memory for the buffer.
    * Allow the user to add and remove elements.
    * Handle overflow and underflow conditions.
    * Properly deallocate the memory used by the buffer.

**5. Pointer to a Constant Variable**
* **Task:** Write a C++ program that demonstrates the use of a pointer to a constant variable. The program should:
    * Declare a constant variable and a pointer to it.
    * Show how you can read the value pointed to by the pointer, but not modify it.

**6. Returning a Reference**
* **Task:** Write a C++ program where a function returns a reference to a local variable.
    * Identify potential problems and how to avoid them.
    * Implement a version where the function returns a reference to a static or globally declared variable.

## 13th of February in 2026
### C++ Graph Algorithm Exercises

**1. Dijkstra's Algorithm for Shortest Path**
* **Task:** Write a C++ program to implement Dijkstra's Algorithm to find the shortest paths from a source vertex to all other vertices. The program should:
    * Represent a weighted graph using an adjacency list.
    * Use a priority queue (min-heap) to efficiently select the next vertex with the minimum distance.
    * Initialize the source vertex with a distance of 0 and all other vertices with infinity.
    * Calculate and display the final shortest distances for all vertices.

<details>
<summary><b>Information</b></summary>
The above question(13th of Feb) is of dijkstra's algorithm given to us in Discrete Mathematics class.
</details>
