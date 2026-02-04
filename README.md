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
### C++ Structures and Pointer-Based Questions

**1. Structure: Student**
* Create a structure `Student` with:
    * Roll number
    * Name
    * Marks
* Input details of **5 students**.
* Display students who scored **more than 75 marks**.

**2. Structure: Employee**
* Define a structure `Employee` with:
    * Employee ID
    * Name
    * Basic salary
* Calculate and display **gross salary**:
    * HRA = 20% of basic salary
    * DA = 10% of basic salary

**3. Pointer and Array Output Questions**
* **Task:** Predict the output and explain why.

    **Case 1**
    ```cpp
    int arr[] = {10, 20, 30, 40};
    int *p = arr;

    cout << *p << endl;
    cout << *(p + 1) << endl;
    cout << *(p + 3) << endl;
    ```

    **Case 2**
    ```cpp
    int arr[] = {5, 10, 15, 20};
    int *p = arr + 2;

    cout << *p << endl;
    cout << *(p - 1) << endl;
    ```

    **Case 3**
    ```cpp
    int arr[5] = {1, 2, 3, 4, 5};

    for(int i = 0; i < 5; i++)
        cout << *(arr + i) << " ";
    ```

    **Case 4**
    ```cpp
    int arr[] = {2, 4, 6, 8};
    int *p = arr;

    p++;
    cout << *p << endl;
    ```

    **Case 5**
    ```cpp
    int arr[] = {7, 14, 21};

    cout << arr[1] << endl;
    cout << 1[arr] << endl;
    ```

    **Case 6**
    ```cpp
    int arr[] = {10, 20, 30};
    int *p = arr;

    cout << *p + 1 << endl;
    cout << *(p + 1) << endl;
    ```

    **Case 7**
    ```cpp
    int arr[] = {3, 6, 9, 12};
    int *p = arr;

    while(p <= &arr[3]) {
        cout << *p << " ";
        p++;
    }
    ```

    **Case 8**
    ```cpp
    int arr[] = {1, 2, 3};
    int *p = arr;

    for(int i = 0; i < 3; i++)
        cout << *(p++) << " ";
    ```

    **Case 9**
    ```cpp
    int arr[] = {10, 20, 30};
    int *p = arr;

    cout << p << endl;
    cout << p + 1 << endl;
    ```

    **Case 10**
    ```cpp
    char arr[] = {'A', 'B', 'C'};
    char *p = arr;

    cout << p << endl;
    cout << p + 1 << endl;
    ```

    **Case 11**
    ```cpp
    struct Data {
        int x;
        int y;
    };

    Data arr[] = {{1,2}, {3,4}, {5,6}};
    Data *p = arr;

    cout << p->x << endl;
    cout << (p + 1)->y << endl;
    ```

    **Case 12**
    ```cpp
    struct Item {
        int price;
    };

    Item arr[] = {100, 200, 300};
    Item *p = arr;

    cout << p[2].price << endl;
    cout << (*(p + 1)).price << endl;
    ```
