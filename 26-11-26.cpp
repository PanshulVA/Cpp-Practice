// //Q1
// #include <iostream>
// using namespace std;
// int globalVar=10;
// int main(){
//     int localVar = 20;
//     int *heapVar= new int(30);
//     cout <<"Global var address: " << globalVar<< " (Data segment)\n";
//     cout <<"Local var address: " << localVar<< " (Stack)\n";
//     cout <<"Heap var address: " << heapVar<< " (Heap)\n";
//     delete heapVar;
//     return 0;
// }
// // Output
// // Global var address: 10 (Data segment)
// // Local var address: 20 (Stack)
// // Heap var address: 0x30ce1320 (Heap)

// // Q2
// #include <iostream>
// using namespace std;

// int square(int x) {
//     return x*x;
// }

// int main() {
//     cout <<square(5) << endl;
//     int(*fp)(int)=square;
//     cout<<fp(5)<<endl;
//     return 0;
// }

// // Output
// // 25
// // 25

// //Q3


// #include <iostream>
// using namespace std;

// int main() {
//     int x= 10;
//     int *p=&x;
//     cout << "Value of x: " << x << endl;
//     cout << "Address of x: " << &x << endl;
//     cout << "Value stored in pointer: " << p << endl;
//     return 0;
// }
// // Output
// // Value of x: 10
// // Address of x: 0x7ffe2e39c3a4
// // Value stored in pointer: 0x7ffe2e39c3a4

// // Q4

// #include <iostream>
// using namespace std;

// int main() {
//     int a = 5;
//     int *p = &a;
//     int b;

//     b = *p;

//     cout << b << endl;
//     return 0;
// }

// // Output
// // 5

// // Q5 (a)
// #include <iostream>
// using namespace std;

// int main() {
//     int x = 5;
//     int *p = &x;
//     *p = 10;
//     cout << x << endl;
//     return 0;
// }

// //Output 10
// // Q5 (b)
// #include <iostream>
// using namespace std;

// int main() {
//     int a = 1, b = 2;
//     int *p = &a;
//     p = &b;
//     *p = 5;
//     cout << a << " " << b;
//     return 0;
// }
// //Output 1 5
// // Q5 (c)
// #include <iostream>
// using namespace std;

// int main() {
//     int x = 10;
//     int *p = &x;
//     int **pp = &p;
//     **pp = 20;
//     cout << x;
//     return 0;
// }
// //Ouput 20

// // Q5 (d)
// #include <iostream>
// using namespace std;

// int main() {
//     int a[5] = {2,4,6,8,10};
//     int *p = a;
//     cout << *p++ << " ";
//     cout << *p;
//     return 0;
// }
// //Ouput 2 4

// //Q6
// #include <iostream>
// using namespace std;

// void swap(int *a, int *b){
//     int temp = *a;
//     *a=*b;
//     *b=temp;
// }

// int main() {
//     int x = 5, y = 10;
//     swap(&x, &y);
//     cout << x << " " << y;
//     return 0;
// }
// //Ouput
// //10 5

// //Q7
// #include <iostream>
// using namespace std;

// int main() {
//     int *p = new int(10);   // create

//     *p = 20;               // modify
//     cout << *p << endl;

//     delete p;              // delete
//     return 0;
// }

// //Ouput
// // 20

// //Q8
// #include <iostream>
// using namespace std;

// int main() {
//     int a[] = {1,2,3,4,5};
//     int *p = a;

//     cout << *p++ << " ";    // 1
//     cout << (*p)++ << " ";  // 2
//     cout << ++*p << " ";    // 4
//     cout << *p << "\n";     // 4

//     for(int i=0;i<5;i++) cout << a[i] << " ";

//     return 0;
// }

// //Ouput
// // 1 2 4 4
// //1 4 3 4 5

// //Q9
// #include <iostream>
// using namespace std;

// int main() {
//     int x=10;
//     int *p=&x;
//     cout << (*p)++ << " " << x << "\n";
//     cout << ++(*p) << " " << x << "\n";
//     cout << *p++ << " " << x << "\n";
//     return 0;
// }

// //Ouput
// // 10 11
// // 12 12
// // 12 12


//Q10
#include <iostream>
using namespace std;

int main() {
    int a[] = {10,20,30,40,50};
    int *p = a + 1;
    cout << *(p+2) << " " << *(p-1);
    return 0;
}

//Ouput
//40 10
