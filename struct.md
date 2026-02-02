# C++ Structures & Pointers Notes

## Table of Contents

- [Structure Basics & Nesting](#1-structure-basics-and-nesting)
- [Advanced Pointer Arithmetic](#2-advanced-pointer-arithmetic-with-structures)
- [Self-Referential Structures & Arrays](#3-self-referential-structures--arrays)
- [Call by Value vs. Reference](#4-call-by-value-vs-call-by-reference)
- [Complex Pointer Arithmetic (GATE Problem)](#5-complex-pointer-arithmetic-gate-problem)
- [Arrays of Pointers](#6-arrays-of-pointers)

---

## 1. Structure Basics and Nesting

### Definition and Size

**Concept:** A structure creates a user-defined data type. In C++, struct members are public by default.

#### Basic Structure Example

```cpp
#include <iostream>
using namespace std;

struct Node {
    int a;    // 2 bytes (assuming 16-bit arch from notes)
    float b;  // 4 bytes
    char c;   // 1 byte
}; 
// Total Size: 7 bytes 
// Note: Modern compilers may add padding (alignment), making this 8 or 12 bytes.
```

#### Nested Structure Example

```cpp
struct Node1 {
    float d;      // 4 bytes
    Node e;       // 7 bytes (Nested struct)
};
// Total Size: 11 bytes
```

### Initialization and Access

```cpp
int main() {
    // Initializing nested structure: {d, {a, b, c}}
    Node1 f = {10.25f, {5, 20.45f, 's'}};
    
    // Accessing members
    // f.d -> 10.25
    // f.e.a -> 5
    
    cout << f.e.a << endl; // Output: 5
    return 0;
}
```

---

## 2. Advanced Pointer Arithmetic with Structures

**Scenario:** Accessing nested string pointers and manipulating their addresses.

```cpp
#include <iostream>
using namespace std;

struct A {
    char ch[7];
    const char* str; // Using const char* for string literals in C++
};

struct B {
    const char* c;
    A ssl;
};

int main() {
    // Initialization
    B s2 = {"Raipur", {"Kanpur", "Jaipur"}};

    // Memory Visualization:
    // s2.c points to "Raipur"
    // s2.ssl.ch contains "Kanpur"
    // s2.ssl.str points to "Jaipur"

    // 1. Basic Access
    cout << s2.c << " " << s2.ssl.str << endl;
    // Output: Raipur Jaipur

    // 2. Pre-incrementing pointers
    // ++s2.c: Moves pointer from "Raipur" to "aipur" (points to 'a')
    // ++s2.ssl.str: Moves pointer from "Jaipur" to "aipur" (points to 'a')
    cout << ++s2.c << " " << ++s2.ssl.str << endl;
    // Output: aipur aipur
    
    return 0;
}
```

---

## 3. Self-Referential Structures & Arrays

**Concept:** Implementing a Linked List using an array of structures. This demonstrates how array indices can act as "pointers" when mapped to memory addresses.

### Structure Definition

```cpp
struct S1 {
    const char* z;
    int i;
    S1* p; // Pointer to same structure type
};
```

### Implementation

```cpp
#include <iostream>
using namespace std;

int main() {
    S1 a[3]; // Declaration
    
    // Manual Initialization to simulate the specific memory layout
    a[0] = {"Nagpur", 1, &a[1]}; // p points to next element
    a[1] = {"Raipur", 2, &a[2]};
    a[2] = {"Kanpur", 3, a};     // Cyclic: p points back to start

    // Loop & Increment Example
    for (int j = 0; j <= 2; j++) {
        // --a[j].i : Pre-decrement integer i
        // ++a[j].z : Pre-increment string pointer z (moves to next char)
        cout << --a[j].i << " " << ++a[j].z << endl;
    }
    
    /* Execution Trace:
    Iteration 0: i becomes 0. z becomes "agpur". -> Output: 0 agpur
    Iteration 1: i becomes 1. z becomes "aipur". -> Output: 1 aipur
    Iteration 2: i becomes 2. z becomes "anpur". -> Output: 2 anpur
    */
    
    return 0;
}
```

---

## 4. Call by Value vs. Call by Reference

Comparison of passing structures to functions.

```cpp
#include <iostream>
using namespace std;

struct T {
    const char* a;
    const char* b;
};

// Call by Value (Copy is created)
void f1(T s) { 
    s.a = "U";
    s.b = "V";
    cout << "Inside f1: " << s.a << " " << s.b << endl; // Output: U V
}

// Call by Pointer (Address passed)
void f2(T* p) { 
    p->a = "V";
    p->b = "W";
    cout << "Inside f2: " << p->a << " " << p->b << endl; // Output: V W
}

int main() {
    T s = {"A", "B"};
    
    f1(s); 
    cout << "After f1: " << s.a << " " << s.b << endl; // Output: A B (No change)
    
    f2(&s);
    cout << "After f2: " << s.a << " " << s.b << endl; // Output: V W (Changed)
    
    return 0;
}
```

---

## 5. Complex Pointer Arithmetic (GATE Problem)

A complex tracing problem involving pointer precedence and post/pre-increments.

```cpp
#include <iostream>
using namespace std;

struct Test {
    int i;
    const char* c;
};

int main() {
    Test st[] = {
        {5, "become"},    // st[0]
        {4, "better"},    // st[1]
        {6, "jungle"},    // st[2]
        {8, "ancestor"},  // st[3]
        {7, "brother"}    // st[4]
    };

    Test* p = st;
    p += 1; // p now points to st[1]
    
    // Step 1: ++(p++->c)
    // 1. p++ uses current p (st[1]), then increments p to st[2].
    // 2. ->c accesses "better".
    // 3. ++ increments "better" to "etter".
    cout << ++(p++->c) << endl; // Output: etter
    
    // Step 2: *++p->c
    // 1. p is at st[2].
    // 2. p->c gets "jungle".
    // 3. ++ increments pointer "jungle" to "ungle".
    // 4. * dereferences "ungle" to 'u'.
    cout << *++p->c << endl; // Output: u

    // Step 3: p[0].i
    // p is still at st[2]. Accesses st[2].i
    cout << p[0].i << endl; // Output: 6
    
    // Step 4: p->c
    // Points to "ungle" (modified in Step 2)
    cout << p->c << endl; // Output: ungle
    
    return 0;
}
```

---

## 6. Arrays of Pointers

Understanding the size of pointer arrays vs arrays of values.

```cpp
#include <iostream>
using namespace std;

int main() {
    // Array of character pointers
    const char* str[] = {"Frogs", "Do", "Not", "Die", "Croak"};
    
    // Printing sizes
    // sizeof(str) = 5 elements * pointer_size
    // sizeof(str[0]) = pointer_size
    
    // Note: 
    // On 16-bit (Notes logic): Output 10 2
    // On 32-bit: Output 20 4
    // On 64-bit: Output 40 8
    
    cout << sizeof(str) << " " << sizeof(str[0]) << endl;
    
    return 0;
}
```

---

## Key Takeaways

- **Structure Size:** Remember that modern compilers add padding for memory alignment
- **Pointer Arithmetic:** Pre/post increment operators work differently with pointers
- **Pass by Reference:** Use pointers to modify original structure values
- **Memory Layout:** Understanding how structures are stored in memory is crucial for pointer manipulation

## Notes

These examples are based on lecture notes and preserve the original memory logic. Actual sizes may vary depending on your compiler and architecture (16-bit, 32-bit, or 64-bit).

---

## Contributing

Feel free to submit issues or pull requests if you find any errors or have suggestions for improvements.

## License

This project is open source and available for educational purposes.
