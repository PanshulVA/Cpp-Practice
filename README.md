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
  
  
## 18th of February in 2026

### C++ Object-Oriented Programming and Data Structures Exercises

**1. Basic Student Class**

* **Task:**

  * Create a `Student` class with attributes: name, roll number, and marks.

  * Add member functions to input and display student details.

  * Create at least 3 objects and display their data.

**2. BankAccount Constructor and Destructor**

* **Task:**

  * Create a `BankAccount` class.

  * Initialize account number and balance using a constructor.

  * Display a message when the destructor is called.

  * Create objects inside a function to observe destructor behavior.

**3. Employee Class Encapsulation**

* **Task:**

  * Create an `Employee` class.

  * Make salary private.

  * Provide getter and setter functions.

  * Add validation: salary cannot be negative.

**4. Calculator Function Overloading**

* **Task:**

  * Create a class `Calculator`.

  * Overload a function `add()` for:

    * `int`

    * `double`

    * three parameters

**5. Student Class with Dynamic Memory Allocation**

* **Task:**

  * Create a struct `Subject { string name; int marks; }`.

  * Create a class `Student` with:

    * `private:` int roll; string name; `Subject* subjects`; int n;

  * Create a constructor that allocates dynamic memory for `n` subjects.

  * Add member functions: `input()`, `display()`, `total()`, `grade()`.

  * Store `N` students using a pointer to an object array, find the topper, and free all memory properly.

**6. Patient Priority Queue**

* **Task:**

  * Create a struct `Node` containing:

    * Patient data (id, name, severity)

    * `Node* next`

  * Create a class `PatientQueue` implementing:

    * enqueue (based on severity priority)

    * dequeue

    * display

  * Use dynamic memory (`new`/`delete`) and demonstrate queue operations.

**7. Linked List Library System**

* **Task:**

  * Create a struct `BookNode`:

    * `int id; string title; string author; bool issued; BookNode* next;`

  * Create a class `Library` with:

    * `BookNode* head`

    * Functions: `addBook()`, `issueBook(id)`, `returnBook(id)`, `searchBook(title)`, `displayAll()`

  * Use pointers to traverse the linked list and manage memory safely.

**8. Bank Account with Transaction History**

* **Task:**

  * Create a struct `Transaction`:

    * `string type; double amount; string date; Transaction* next;`

  * Create a class `BankAccount`:

    * `private:` accountNo, holderName, balance, `Transaction* historyHead`

    * Functions: `deposit()`, `withdraw()`, `showHistory()`, `showBalance()`

  * Store multiple accounts using a `BankAccount*` array pointer and search account by number.

**9. Course Registration System**

* **Task:**

  * Create a struct `Course`:

    * courseCode, courseName, credits

  * Create a class `Student`:

    * roll, name

    * `Course* registeredCourses` (dynamic)

    * Functions: `registerCourses()`, `dropCourse(code)`, `showCourses()`, `totalCredits()`

  * Store multiple students using pointers and print a list of students registered in a given course.

**10. Directory Tree Structure**

* **Task:**

  * Create a struct `DirNode`:

    * `string name; bool isFile; DirNode* child; DirNode* sibling;`

  * Create a class `DirectoryTree`:

    * Functions: `createFolder(path)`, `createFile(path)`, `list(path)`, `deleteNode(path)`

  * Implement using pointers (tree navigation) and free memory in the destructor.
  
    
    
## 1st of April in 2026

### C++ Advanced Object-Oriented Use Cases

**1. Student Record System with Classes and Objects**

* **Scenario:** You need to develop a student record management system for a college. The system should allow the addition of student records, modification, and display of records, as well as calculations like average grades.
* **Tasks:**
  * **Class Design:** Create a `Student` class with data members like `roll_number`, `name`, and `marks`.
  * Implement a constructor to initialize student records when an object is created and a destructor to clean up resources if needed.
  * Include methods like `addStudent()`, `modifyStudent()`, `displayStudent()`, and `calculateAverage()`.
  * Use overloaded constructors to initialize students with different data (e.g., full info vs just roll number).
* **Approach:**
  * **Class and objects:** Use a class to represent the student, encapsulating the details of each student.
  * **Inheritance:** You could extend this to have subclasses like `GraduateStudent` or `UndergraduateStudent`, which inherit from `Student` and add more specialized data.
  * **Polymorphism:** Use method overloading for various operations like `addStudent()` (with different types of arguments).

**2. Employee Salary Management System Using File Handling**

* **Scenario:** You need to build an employee salary management system that reads employee records from a file, calculates their salary, and writes the updated data back to the file.
* **Tasks:**
  * Create an `Employee` class with attributes like `employee_id`, `name`, and `salary`.
  * Implement a method `calculateSalary()` which calculates salary based on some business logic (e.g., bonuses, deductions).
  * Use file handling to:
    * Read employee data from a text file (`ifstream`).
    * Write updated employee data back to the file (`ofstream`).
  * Implement a `main` function that loads employee records from the file, calculates their salary, and saves the updated records back to the file.
* **Approach:**
  * **File Handling:** Use `ifstream` to read the employee data and `ofstream` to write the data back after processing.
  * **Object-Oriented Design:** Use a class to represent employees and encapsulate their data.
  * **Exception Handling:** Implement error checking to ensure the file exists and is accessible.

**3. Tic-Tac-Toe Game with Classes and Object-Oriented Design**

* **Scenario:** Develop a Tic-Tac-Toe game using object-oriented design principles. The game should allow two players to take turns, check for a winner, and reset the game.
* **Tasks:**
  * Create a `Game` class with a board (a 3x3 matrix), turn (to keep track of whose turn it is), and winner (to determine the winner).
  * Implement methods for:
    * `resetGame()`: Resets the board.
    * `makeMove()`: Places a mark on the board.
    * `checkWinner()`: Checks if there is a winner.
    * `printBoard()`: Displays the current state of the board.
  * Implement game logic to alternate between players and check if a player wins or if it’s a draw.
* **Approach:**
  * **Classes/Objects:** Use a class to encapsulate game-related data and methods.
  * **Encapsulation:** Keep game data (board, winner, turn) private inside the class.
  * **Polymorphism:** You could also extend this with different game modes (e.g., player vs AI).
