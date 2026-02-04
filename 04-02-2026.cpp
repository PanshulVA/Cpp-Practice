//Q1

#include <iostream>
using namespace std;

struct Student {
    int roll;
    string name;
    float marks;
};

int main() {
    Student s[5];
    for (int i = 0; i < 5; i++) {
        cout << "\nEnter details of student " << i + 1 << endl;

        cout << "Roll number: ";
        cin >> s[i].roll;

        cout << "Name: ";
        cin >> s[i].name;

        cout << "Marks: ";
        cin >> s[i].marks;
    }
    cout << "\nStudents scoring more than 75 marks:\n";

    for (int i = 0; i < 5; i++) {
        if (s[i].marks > 75) {
            cout << "\nRoll No: " << s[i].roll;
            cout << "\nName: " << s[i].name;
            cout << "\nMarks: " << s[i].marks << endl;
        }
    }

    return 0;
}

//Input
//Enter details of student 1
//Roll number: 25570041
//Name: Nishant 
//Marks: 98

//Enter details of student 2
//Roll number: 25570063
//Name: Jairaj
//Marks: 69

//Enter details of student 3
//Roll number: 25570072
//Name: Panshul
//Marks: 100

//Enter details of student 4
//Roll number: 2570071
//Name: Pranshu
//Marks: 67

//Enter details of student 5
//Roll number: 25570061
//Name: Yash
//Marks: 89

//Output
//Students scoring more than 75 marks:

//Roll No: 25570041
//Name: Nishant
//Marks: 98

//Roll No: 25570072
//Name: Panshul
//Marks: 100

//Roll No: 25570061
//Name: Yash
//Roll No: 25570041
//Name: Nishant
//Marks: 98

//Roll No: 25570072
//Name: Panshul
//Marks: 100

//Roll No: 25570061
//Name: Yash
//Marks: 89
  
//Q2
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Employee {
    int empId;
    string name;
    double basicSalary;
};

int main() {
    Employee e;
    double hra, da, grossSalary;

    cout << "Enter Employee ID: ";
    cin >> e.empId;

    cin.ignore();  // clear newline

    cout << "Enter Name: ";
    getline(cin, e.name);

    cout << "Enter Basic Salary: ";
    cin >> e.basicSalary;

    hra = 0.20 * e.basicSalary;
    da  = 0.10 * e.basicSalary;
    grossSalary = e.basicSalary + hra + da;

    cout << fixed << setprecision(2);

    cout << "\nEmployee Details";
    cout << "\nID: " << e.empId;
    cout << "\nName: " << e.name;
    cout << "\nBasic Salary: " << e.basicSalary;
    cout << "\nGross Salary: " << grossSalary << endl;

    return 0;
}

//Input:
//Enter Employee ID: 235692365
//Enter Name: Panshul the Legend
//Enter Basic Salary: 100000000

//Output:
//Employee Details
//ID: 235692365
//Name: Panshul the Legend
//Basic Salary: 100000000.00
//Gross Salary: 130000000.00




// Q3: Pointer and Array Output Questions

#include <iostream>
using namespace std;

struct Data {
    int x;
    int y;
};

struct Item {
    int price;
};

int main() {

    // Case 1
    int arr1[] = {10, 20, 30, 40};
    int *p1 = arr1;
    cout << *p1 << endl;
    cout << *(p1 + 1) << endl;
    cout << *(p1 + 3) << endl;

    cout << endl;

    // Case 2
    int arr2[] = {5, 10, 15, 20};
    int *p2 = arr2 + 2;
    cout << *p2 << endl;
    cout << *(p2 - 1) << endl;

    cout << endl;

    // Case 3
    int arr3[5] = {1, 2, 3, 4, 5};
    for(int i = 0; i < 5; i++)
        cout << *(arr3 + i) << " ";
    cout << endl << endl;

    // Case 4
    int arr4[] = {2, 4, 6, 8};
    int *p4 = arr4;
    p4++;
    cout << *p4 << endl;

    cout << endl;

    // Case 5
    int arr5[] = {7, 14, 21};
    cout << arr5[1] << endl;
    cout << 1[arr5] << endl;

    cout << endl;

    // Case 6
    int arr6[] = {10, 20, 30};
    int *p6 = arr6;
    cout << *p6 + 1 << endl;
    cout << *(p6 + 1) << endl;

    cout << endl;

    // Case 7
    int arr7[] = {3, 6, 9, 12};
    int *p7 = arr7;
    while(p7 <= &arr7[3]) {
        cout << *p7 << " ";
        p7++;
    }
    cout << endl << endl;

    // Case 8
    int arr8[] = {1, 2, 3};
    int *p8 = arr8;
    for(int i = 0; i < 3; i++)
        cout << *(p8++) << " ";
    cout << endl << endl;

    // Case 9
    int arr9[] = {10, 20, 30};
    int *p9 = arr9;
    cout << p9 << endl;
    cout << p9 + 1 << endl;

    cout << endl;

    // Case 10
    char arr10[] = {'A', 'B', 'C'};
    char *p10 = arr10;
    cout << p10 << endl;
    cout << p10 + 1 << endl;

    cout << endl;

    // Case 11
    Data arr11[] = {{1,2}, {3,4}, {5,6}};
    Data *p11 = arr11;
    cout << p11->x << endl;
    cout << (p11 + 1)->y << endl;

    cout << endl;

    // Case 12
    Item arr12[] = {100, 200, 300};
    Item *p12 = arr12;
    cout << p12[2].price << endl;
    cout << (*(p12 + 1)).price << endl;

    return 0;
}

/*
==================== OUTPUT ====================

Case 1 Output:
10
20
40

Case 2 Output:
15
10

Case 3 Output:
1 2 3 4 5

Case 4 Output:
4

Case 5 Output:
14
14

Case 6 Output:
11
20

Case 7 Output:
3 6 9 12

Case 8 Output:
1 2 3

Case 9 Output:
<Address of arr9[0]>
<Address of arr9[1]>

Case 10 Output:
ABC
BC

Case 11 Output:
1
4

Case 12 Output:
300
200

===============================================
*/
