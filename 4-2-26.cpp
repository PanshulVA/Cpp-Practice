//Q1
#include <iostream>
#include <string>
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

        cin.ignore();

        cout << "Name: ";
        getline(cin, s[i].name);

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
// Enter details of student 1
// Roll number: 25570041
// Name: Nishant
// Marks: 98

// Enter details of student 2
// Roll number: 25570063
// Name: Jairaj
// Marks: 69

// Enter details of student 3
// Roll number: 25570071
// Name: Pranshu
// Marks: 67

// Enter details of student 4
// Roll number: 25570063
// Name: Yasg
// Marks: 89

// Enter details of student 5
// Roll number: 2570072
// Name: Panshul
// Marks: 100

//Output
// Students scoring more than 75 marks:

// Roll No: 25570041
// Name: Nishant
// Marks: 98

// Roll No: 25570063
// Name: Yasg
// Marks: 89

// Roll No: 2570072
// Name: Panshul
// Marks: 100

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

    cin.ignore();  // clear newline left by cin

    cout << "Enter Name: ";
    getline(cin, e.name);

    cout << "Enter Basic Salary: ";
    cin >> e.basicSalary;

    // Salary calculations
    hra = 0.20 * e.basicSalary;
    da  = 0.10 * e.basicSalary;
    grossSalary = e.basicSalary + hra + da;

    // Formatting output to 2 decimal places
    cout << fixed << setprecision(2);

    cout << "\nEmployee Details";
    cout << "\nID: " << e.empId;
    cout << "\nName: " << e.name;
    cout << "\nBasic Salary: " << e.basicSalary;
    cout << "\nGross Salary: " << grossSalary << endl;

    return 0;
}

// Input
// Enter Employee ID: 235692365
// Enter Name: Panshul the Legend
// Enter Basic Salary: 100000000

// Output
// Employee Details
// ID: 235692365
// Name: Panshul the Legend
// Basic Salary: 100000000.00
// Gross Salary: 130000000.00
