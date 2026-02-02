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
