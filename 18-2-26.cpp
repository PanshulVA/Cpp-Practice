//Q1
#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    string name;
    int rollNumber;
    float marks;

public:
    void inputDetails() {
        cout << "Enter Name: ";
        getline(cin >> ws, name);

        cout << "Enter Roll Number: ";
        cin >> rollNumber;

        cout << "Enter Marks: ";
        cin >> marks;
    }

    void displayDetails() const {
        cout << "Roll Number: " << rollNumber
             << " | Name: " << name
             << " | Marks: " << marks << endl;
    }
};

int main() {
    const int NUM_STUDENTS = 3;
    Student students[NUM_STUDENTS];

    cout << "=== Enter Student Information ===" << endl;

    for (int i = 0; i < NUM_STUDENTS; i++) {
        cout << "\nStudent " << (i + 1) << ":" << endl;
        students[i].inputDetails();
    }

    cout << "\n\n=== Student Database ===" << endl;

    for (const auto & student : students) {
        student.displayDetails();
    }

    return 0;
}


//Q2
#include <iostream>
#include <iomanip>
#include <string>
#include <locale>

using namespace std;

class Employee {
private:
    string name;
    long double salary;

public:
    Employee(const string& empName, long double empSalary) : name(empName) {
        setSalary(empSalary);
    }

    string getName() const {
        return name;
    }

    void setName(const string& empName) {
        name = empName;
    }

    void setSalary(long double empSalary) {
        if (empSalary >= 0) {
            salary = empSalary;
        } else {
            cout << "Error: Salary cannot be negative! Defaulting to 0.\n";
            salary = 0.0;
        }
    }

    long double getSalary() const {
        return salary;
    }

    void display() const {
        cout << "\n--- Employee Details ---\n";
        cout << "Name: " << name << endl;

        locale oldLocale = cout.getloc();
        cout.imbue(locale(""));

        cout << fixed << setprecision(2);
        cout << "Salary: $" << salary << endl;

        cout.imbue(oldLocale);
    }
};

int main() {
    string name;
    long double salary;

    cout << "Enter Employee Name: ";
    getline(cin >> ws, name);

    cout << "Enter Salary: ";
    cin >> salary;

    Employee emp1(name, salary);
    emp1.display();

    cout << "\nAttempting to set a negative salary for " << emp1.getName() << "...\n";
    emp1.setSalary(-5000);
    emp1.display();

    return 0;
}

//Q3
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class BankAccount {
private:
    string accountNumber;
    double balance;

public:
    BankAccount(const string& accNo, double bal) : accountNumber(accNo), balance(bal) {
        cout << "Account Created Successfully!\n";
    }

    ~BankAccount() {
        cout << "Account Closed! Account Number: " << accountNumber << endl;
    }

    void display() const {
        cout << "Account Number: " << accountNumber
             << ", Balance: " << fixed << setprecision(0) << balance << endl;
    }
};

void createAccounts() {
    string accNo;
    double bal;

    cout << "\nEnter Account Number: ";
    cin >> accNo;
    cout << "Enter Balance: ";
    cin >> bal;
    BankAccount acc1(accNo, bal);

    cout << "\nEnter Account Number: ";
    cin >> accNo;
    cout << "Enter Balance: ";
    cin >> bal;
    BankAccount acc2(accNo, bal);

    cout << "\nInside createAccounts() function\n";
    acc1.display();
    acc2.display();

    cout << "Exiting createAccounts() function...\n";
}

int main() {
    createAccounts();
    cout << "Back in main()\n";
    return 0;
}

//Q4
#include <iostream>

using namespace std;

class Calculator {
public:
    int add(int a, int b) const {
        return a + b;
    }

    double add(double a, double b) const {
        return a + b;
    }

    int add(int a, int b, int c) const {
        return a + b + c;
    }
};

int main() {
    Calculator calc;

    int int1, int2, int3;
    double d1, d2;

    cout << "Enter two integers: ";
    cin >> int1 >> int2;
    cout << "Result (int + int): " << calc.add(int1, int2) << "\n";

    cout << "\nEnter two decimal numbers: ";
    cin >> d1 >> d2;
    cout << "Result (double + double): " << calc.add(d1, d2) << "\n";

    cout << "\nEnter three integers: ";
    cin >> int1 >> int2 >> int3;
    cout << "Result (int + int + int): " << calc.add(int1, int2, int3) << "\n";

    return 0;
}

//Q5
#include <iostream>
#include <string>
#include <limits>

using namespace std;

struct Subject {
    string name;
    int marks;
};

class Student {
private:
    int roll;
    string name;
    Subject* subjects;
    int n;

public:
    Student(int numSubjects, string* subNames) : n(numSubjects) {
        subjects = new Subject[n];
        for (int i = 0; i < n; i++) {
            subjects[i].name = subNames[i];
        }
    }

    ~Student() {
        delete[] subjects;
    }

    void input() {
        cout << "\nEnter Roll Number: ";
        while (!(cin >> roll)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Enter Roll Number: ";
        }

        cout << "Enter Name: ";
        getline(cin >> ws, name);

        for (int i = 0; i < n; i++) {
            cout << "Enter Marks for " << subjects[i].name << " (0-100): ";
            while (!(cin >> subjects[i].marks) || subjects[i].marks < 0 || subjects[i].marks > 100) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Enter Marks for " << subjects[i].name << " (0-100): ";
            }
        }
    }

    int total() const {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += subjects[i].marks;
        }
        return sum;
    }

    char grade() const {
        double avg = (double)total() / n;

        if (avg >= 90) return 'A';
        else if (avg >= 75) return 'B';
        else if (avg >= 60) return 'C';
        else if (avg >= 40) return 'D';
        else return 'F';
    }

    void display() const {
        cout << "\nRoll No: " << roll;
        cout << "\nName: " << name;

        for (int i = 0; i < n; i++) {
            cout << "\nSubject: " << subjects[i].name
                 << " | Marks: " << subjects[i].marks;
        }

        cout << "\nTotal Marks: " << total();
        cout << "\nGrade: " << grade() << "\n";
    }
};

int main() {
    int N, numSubjects;

    cout << "Enter number of students: ";
    while (!(cin >> N) || N <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Enter a valid number of students: ";
    }

    cout << "Enter number of subjects per student: ";
    while (!(cin >> numSubjects) || numSubjects <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Enter a valid number of subjects: ";
    }

    string* globalSubjects = new string[numSubjects];
    cout << "\n--- Define Subjects ---\n";
    for (int i = 0; i < numSubjects; i++) {
        cout << "Enter name for Subject " << i + 1 << ": ";
        getline(cin >> ws, globalSubjects[i]);
    }

    Student** students = new Student*[N];

    for (int i = 0; i < N; i++) {
        students[i] = new Student(numSubjects, globalSubjects);
        students[i]->input();
    }

    cout << "\n===== Student Details =====\n";
    for (int i = 0; i < N; i++) {
        students[i]->display();
    }

    int topperIndex = 0;
    int highestTotal = students[0]->total();

    for (int i = 1; i < N; i++) {
        if (students[i]->total() > highestTotal) {
            highestTotal = students[i]->total();
            topperIndex = i;
        }
    }

    cout << "\n===== Topper =====\n";
    students[topperIndex]->display();

    for (int i = 0; i < N; i++) {
        delete students[i];
    }
    delete[] students;
    delete[] globalSubjects;

    return 0;
}


//Q6
#include <iostream>
#include <limits>
#include <string>

using namespace std;

struct Node {
    int id;
    string name;
    int severity;
    Node* next;
};

class PatientQueue {
private:
    Node* front;

public:
    PatientQueue() {
        front = nullptr;
    }

    ~PatientQueue() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }

    void enqueue(int id, string name, int severity) {
        Node* newNode = new Node;
        newNode->id = id;
        newNode->name = name;
        newNode->severity = severity;
        newNode->next = nullptr;

        if (front == nullptr || severity > front->severity) {
            newNode->next = front;
            front = newNode;
        }
        else {
            Node* temp = front;

            while (temp->next != nullptr && temp->next->severity >= severity) {
                temp = temp->next;
            }

            newNode->next = temp->next;
            temp->next = newNode;
        }

        cout << "Patient Enqueued Successfully!\n";
    }

    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is Empty!\n";
            return;
        }

        Node* temp = front;

        cout << "\nDequeued Patient:\n";
        cout << "ID: " << temp->id
             << "\nName: " << temp->name
             << "\nSeverity: " << temp->severity << endl;

        front = front->next;
        delete temp;
    }

    void display() const {
        if (front == nullptr) {
            cout << "Queue is Empty!\n";
            return;
        }

        Node* temp = front;

        cout << "\nCurrent Patient Queue:\n";
        while (temp != nullptr) {
            cout << "ID: " << temp->id
                 << " | Name: " << temp->name
                 << " | Severity: " << temp->severity << endl;
            temp = temp->next;
        }
    }
};

int main() {
    PatientQueue pq;
    int choice;

    do {
        cout << "\n====== Patient Priority Queue ======\n";
        cout << "1. Enqueue Patient\n";
        cout << "2. Dequeue Patient\n";
        cout << "3. Display Queue\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Try again.\n";
            continue;
        }

        if (choice == 1) {
            int id, severity;
            string name;

            cout << "Enter Patient ID: ";
            while (!(cin >> id)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input! Enter a numerical ID: ";
            }

            cout << "Enter Name: ";
            getline(cin >> ws, name);

            cout << "Enter Severity (Numerical: Higher = More Critical): ";
            while (!(cin >> severity)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input! Enter a numerical Severity: ";
            }

            pq.enqueue(id, name, severity);
        }
        else if (choice == 2) {
            pq.dequeue();
        }
        else if (choice == 3) {
            pq.display();
        }
        else if (choice == 4) {
            cout << "Exiting Program...\n";
        }
        else {
            cout << "Invalid Choice!\n";
        }

    } while (choice != 4);

    return 0;
}


//Q7
#include <iostream>
#include <string>
#include <limits>

using namespace std;

struct BookNode {
    int id;
    string title;
    string author;
    bool issued;
    BookNode* next;

    BookNode(int i, string t, string a) : id(i), title(t), author(a), issued(false), next(nullptr) {}
};

class Library {
private:
    BookNode* head;

public:
    Library() : head(nullptr) {}

    ~Library() {
        BookNode* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }

    void addBook() {
        int id;
        string title, author;

        cout << "Enter Book ID: ";
        while (!(cin >> id)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Enter a numeric Book ID: ";
        }

        cout << "Enter Title: ";
        getline(cin >> ws, title);

        cout << "Enter Author: ";
        getline(cin >> ws, author);

        BookNode* newBook = new BookNode(id, title, author);

        if (head == nullptr) {
            head = newBook;
        } else {
            BookNode* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newBook;
        }

        cout << "Book added successfully!\n";
    }

    void issueBook() {
        int id;
        cout << "Enter Book ID to issue: ";
        while (!(cin >> id)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Enter a numeric Book ID: ";
        }

        BookNode* temp = head;
        while (temp != nullptr) {
            if (temp->id == id) {
                if (!temp->issued) {
                    temp->issued = true;
                    cout << "Book issued successfully!\n";
                } else {
                    cout << "Book is already issued!\n";
                }
                return;
            }
            temp = temp->next;
        }
        cout << "Book not found!\n";
    }

    void returnBook() {
        int id;
        cout << "Enter Book ID to return: ";
        while (!(cin >> id)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Enter a numeric Book ID: ";
        }

        BookNode* temp = head;
        while (temp != nullptr) {
            if (temp->id == id) {
                if (temp->issued) {
                    temp->issued = false;
                    cout << "Book returned successfully!\n";
                } else {
                    cout << "Book was not issued!\n";
                }
                return;
            }
            temp = temp->next;
        }
        cout << "Book not found!\n";
    }

    void searchBook() const {
        string title;
        cout << "Enter Title to search: ";
        getline(cin >> ws, title);

        const BookNode* temp = head;
        while (temp != nullptr) {
            if (temp->title == title) {
                cout << "\n--- Book Found ---\n";
                cout << "ID: " << temp->id << endl;
                cout << "Author: " << temp->author << endl;
                cout << "Status: " << (temp->issued ? "Issued" : "Available") << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Book not found!\n";
    }

    void displayAll() const {
        if (head == nullptr) {
            cout << "Library is empty!\n";
            return;
        }

        const BookNode* temp = head;
        while (temp != nullptr) {
            cout << "\nID: " << temp->id << endl;
            cout << "Title: " << temp->title << endl;
            cout << "Author: " << temp->author << endl;
            cout << "Status: " << (temp->issued ? "Issued" : "Available") << endl;
            cout << "------------------------";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Library lib;
    int choice;

    do {
        cout << "\n===== LIBRARY MENU =====\n";
        cout << "1. Add Book\n";
        cout << "2. Issue Book\n";
        cout << "3. Return Book\n";
        cout << "4. Search Book\n";
        cout << "5. Display All\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Try again.\n";
            continue;
        }

        switch (choice) {
            case 1: lib.addBook(); break;
            case 2: lib.issueBook(); break;
            case 3: lib.returnBook(); break;
            case 4: lib.searchBook(); break;
            case 5: lib.displayAll(); break;
            case 6: cout << "Exiting Library System...\n"; break;
            default: cout << "Invalid choice! Please select 1-6.\n";
        }
    } while (choice != 6);

    return 0;
}


//Q8
#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

// ================= TRANSACTION STRUCT =================
struct Transaction {
    string type;
    double amount;
    string date;
    Transaction* next;

    Transaction(const string& t, double a, const string& d)
        : type(t), amount(a), date(d), next(nullptr) {}
};

// ================= BANK ACCOUNT CLASS =================
class BankAccount {
private:
    int accountNo;
    string holderName;
    double balance;
    Transaction* historyHead;

public:
    // Constructor using initializer list
    BankAccount(int accNo, const string& name, double initialBalance)
        : accountNo(accNo), holderName(name), balance(initialBalance), historyHead(nullptr) {}

    // Destructor
    ~BankAccount() {
        Transaction* temp;
        while (historyHead != nullptr) {
            temp = historyHead;
            historyHead = historyHead->next;
            delete temp;
        }
    }

    int getAccountNo() const {
        return accountNo;
    }

    // ================= DEPOSIT =================
    void deposit(double amount, const string& date) {
        if (amount <= 0) {
            cout << "Invalid deposit amount!\n";
            return;
        }

        balance += amount;
        Transaction* newTrans = new Transaction("Deposit", amount, date);

        if (historyHead == nullptr) {
            historyHead = newTrans;
        } else {
            Transaction* temp = historyHead;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = newTrans;
        }

        cout << "Deposit successful!\n";
    }

    // ================= WITHDRAW =================
    void withdraw(double amount, const string& date) {
        if (amount <= 0) {
            cout << "Invalid withdrawal amount!\n";
            return;
        }

        if (amount > balance) {
            cout << "Insufficient balance!\n";
            return;
        }

        balance -= amount;
        Transaction* newTrans = new Transaction("Withdraw", amount, date);

        if (historyHead == nullptr) {
            historyHead = newTrans;
        } else {
            Transaction* temp = historyHead;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = newTrans;
        }

        cout << "Withdrawal successful!\n";
    }

    // ================= SHOW BALANCE =================
    void showBalance() const {
        cout << fixed << setprecision(2);
        cout << "Current Balance: $" << balance << endl;
    }

    // ================= SHOW HISTORY =================
    void showHistory() const {
        if (historyHead == nullptr) {
            cout << "No transactions yet.\n";
            return;
        }

        const Transaction* temp = historyHead;

        cout << fixed << setprecision(2);
        cout << "\n--- Transaction History ---\n";

        while (temp != nullptr) {
            cout << left << setw(10) << temp->type
                 << " | Amount: $" << setw(8) << temp->amount
                 << " | Date: " << temp->date << endl;
            temp = temp->next;
        }
        cout << "---------------------------\n";
    }
};

// ================= MAIN =================
int main() {
    BankAccount* accounts[100];
    int accountCount = 0;
    int choice;

    cout << fixed << setprecision(2);

    do {
        cout << "\n===== BANK MENU =====\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Show Balance\n";
        cout << "5. Show Transaction History\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";

        // Validate menu choice input
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number between 1 and 6.\n";
            continue;
        }

        if (choice == 1) {
            if (accountCount >= 100) {
                cout << "Bank is at full capacity! Cannot create more accounts.\n";
                continue;
            }

            int accNo;
            string name;
            double initial;

            cout << "Enter Account Number: ";
            while (!(cin >> accNo)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input! Enter a numerical Account Number: ";
            }

            cout << "Enter Holder Name: ";
            getline(cin >> ws, name);

            cout << "Enter Initial Balance: ";
            while (!(cin >> initial) || initial < 0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input! Enter a valid positive Balance: ";
            }

            accounts[accountCount++] = new BankAccount(accNo, name, initial);
            cout << "Account created successfully!\n";
        }
        else if (choice >= 2 && choice <= 5) {
            int accNo;
            cout << "Enter Account Number: ";
            while (!(cin >> accNo)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input! Enter a numerical Account Number: ";
            }

            BankAccount* found = nullptr;

            for (int i = 0; i < accountCount; i++) {
                if (accounts[i]->getAccountNo() == accNo) {
                    found = accounts[i];
                    break;
                }
            }

            if (found == nullptr) {
                cout << "Account not found!\n";
                continue;
            }

            if (choice == 2 || choice == 3) {
                double amount;
                string date;

                cout << "Enter Amount: ";
                while (!(cin >> amount) || amount <= 0) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input! Enter a valid positive amount: ";
                }

                cout << "Enter Date (e.g., YYYY-MM-DD): ";
                getline(cin >> ws, date);

                if (choice == 2) {
                    found->deposit(amount, date);
                } else {
                    found->withdraw(amount, date);
                }
            }
            else if (choice == 4) {
                found->showBalance();
            }
            else if (choice == 5) {
                found->showHistory();
            }
        }
        else if (choice != 6) {
            cout << "Invalid choice! Please select an option from 1 to 6.\n";
        }

    } while (choice != 6);

    // Free memory
    for (int i = 0; i < accountCount; i++) {
        delete accounts[i];
    }

    cout << "Exiting system. Memory successfully freed.\n";
    return 0;
}


Q9
#include <iostream>
#include <string>
#include <limits>

using namespace std;

// ================= COURSE STRUCT =================
struct Course {
    string courseCode;
    string courseName;
    int credits;
};

// ================= STUDENT CLASS =================
class Student {
private:
    int roll;
    string name;

    Course* registeredCourses;   // dynamic array
    int courseCount;
    int capacity;

public:
    // Constructor using initializer list
    Student(int r, const string& n) : roll(r), name(n), courseCount(0), capacity(5) {
        registeredCourses = new Course[capacity];
    }

    // Destructor
    ~Student() {
        delete[] registeredCourses;
    }

    int getRoll() const {
        return roll;
    }

    string getName() const {
        return name;
    }

    // ================= REGISTER COURSE =================
    void registerCourse(const string& code, const string& cname, int credits) {
        // Resize dynamic array if needed
        if (courseCount == capacity) {
            capacity *= 2;
            Course* temp = new Course[capacity];

            for (int i = 0; i < courseCount; i++) {
                temp[i] = registeredCourses[i];
            }

            delete[] registeredCourses;
            registeredCourses = temp;
        }

        registeredCourses[courseCount].courseCode = code;
        registeredCourses[courseCount].courseName = cname;
        registeredCourses[courseCount].credits = credits;

        courseCount++;

        cout << "Course registered successfully!\n";
    }

    // ================= DROP COURSE =================
    void dropCourse(const string& code) {
        for (int i = 0; i < courseCount; i++) {
            if (registeredCourses[i].courseCode == code) {
                // Shift left to fill the gap
                for (int j = i; j < courseCount - 1; j++) {
                    registeredCourses[j] = registeredCourses[j + 1];
                }

                courseCount--;
                cout << "Course dropped successfully!\n";
                return;
            }
        }
        cout << "Course not found!\n";
    }

    // ================= SHOW COURSES =================
    void showCourses() const {
        if (courseCount == 0) {
            cout << "No courses registered.\n";
            return;
        }

        cout << "\nCourses for " << name << ":\n";
        for (int i = 0; i < courseCount; i++) {
            cout << registeredCourses[i].courseCode
                 << " | " << registeredCourses[i].courseName
                 << " | Credits: " << registeredCourses[i].credits
                 << endl;
        }
    }

    // ================= TOTAL CREDITS =================
    int totalCredits() const {
        int total = 0;
        for (int i = 0; i < courseCount; i++) {
            total += registeredCourses[i].credits;
        }
        return total;
    }

    // ================= CHECK COURSE =================
    bool isRegisteredIn(const string& code) const {
        for (int i = 0; i < courseCount; i++) {
            if (registeredCourses[i].courseCode == code) {
                return true;
            }
        }
        return false;
    }
};

// ================= MAIN PROGRAM =================
int main() {
    Student* students[100];
    int studentCount = 0;
    int choice;

    do {
        cout << "\n===== STUDENT MENU =====\n";
        cout << "1. Add Student\n";
        cout << "2. Register Course\n";
        cout << "3. Drop Course\n";
        cout << "4. Show Student Courses\n";
        cout << "5. Show Total Credits\n";
        cout << "6. Show Students in a Course\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";

        // Input validation for menu choice
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number between 1 and 7.\n";
            continue;
        }

        if (choice == 1) {
            if (studentCount >= 100) {
                cout << "System is at full capacity! Cannot add more students.\n";
                continue;
            }

            int roll;
            string name;

            cout << "Enter Roll: ";
            while (!(cin >> roll)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input! Enter a numerical Roll Number: ";
            }

            cout << "Enter Name: ";
            getline(cin >> ws, name);

            students[studentCount++] = new Student(roll, name);
            cout << "Student added successfully!\n";
        }

        else if (choice >= 2 && choice <= 5) {
            int roll;
            cout << "Enter Roll: ";
            while (!(cin >> roll)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input! Enter a numerical Roll Number: ";
            }

            Student* found = nullptr;

            for (int i = 0; i < studentCount; i++) {
                if (students[i]->getRoll() == roll) {
                    found = students[i];
                    break;
                }
            }

            if (found == nullptr) {
                cout << "Student not found!\n";
                continue;
            }

            if (choice == 2) {
                string code, cname;
                int credits;

                cout << "Enter Course Code: ";
                getline(cin >> ws, code);

                cout << "Enter Course Name: ";
                getline(cin >> ws, cname);

                cout << "Enter Credits: ";
                while (!(cin >> credits) || credits < 0) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input! Enter a positive number for credits: ";
                }

                found->registerCourse(code, cname, credits);
            }
            else if (choice == 3) {
                string code;
                cout << "Enter Course Code to drop: ";
                getline(cin >> ws, code);

                found->dropCourse(code);
            }
            else if (choice == 4) {
                found->showCourses();
            }
            else if (choice == 5) {
                cout << "Total Credits: " << found->totalCredits() << endl;
            }
        }

        else if (choice == 6) {
            string code;
            cout << "Enter Course Code: ";
            getline(cin >> ws, code);

            cout << "\nStudents registered in " << code << ":\n";

            bool any = false;
            for (int i = 0; i < studentCount; i++) {
                if (students[i]->isRegisteredIn(code)) {
                    cout << students[i]->getRoll() << " - " << students[i]->getName() << endl;
                    any = true;
                }
            }

            if (!any) {
                cout << "No students registered in this course.\n";
            }
        }
        else if (choice != 7) {
            cout << "Invalid choice! Please select an option from 1 to 7.\n";
        }

    } while (choice != 7);

    // Free memory
    for (int i = 0; i < studentCount; i++) {
        delete students[i];
    }

    cout << "Exiting system. Memory successfully freed...\n";
    return 0;
}


//Q10
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

// --- Data Structure ---
struct DirNode {
    string name;
    bool isFile;
    DirNode* child;
    DirNode* sibling;

    DirNode(string n, bool f)
        : name(n), isFile(f), child(nullptr), sibling(nullptr) {}
};

// --- Logic Class ---
class DirectoryTree {
private:
    DirNode* root;

    // Helper to split path string by '/'
    vector<string> splitPath(const string& path) const {
        vector<string> tokens;
        stringstream ss(path);
        string item;
        while (getline(ss, item, '/')) {
            if (!item.empty()) tokens.push_back(item);
        }
        return tokens;
    }

    // Helper to find a specific node based on path
    DirNode* findNode(const string& path) const {
        if (path == "/" || path == "") return root;

        vector<string> parts = splitPath(path);
        DirNode* curr = root->child; // Start searching inside root

        for (const string& part : parts) {
            DirNode* temp = curr;
            bool found = false;
            while (temp) {
                if (temp->name == part) {
                    curr = temp;
                    found = true;
                    break;
                }
                temp = temp->sibling;
            }
            if (!found) return nullptr;

            // If we aren't at the last part of the path, move into the child
            if (&part != &parts.back()) {
                curr = curr->child;
            }
        }
        return curr;
    }

    // Recursive helper for destructor
    void clear(DirNode* node) {
        if (!node) return;
        clear(node->child);
        clear(node->sibling);
        delete node;
    }

    void addNode(const string& path, bool isFile) {
        size_t lastSlash = path.find_last_of('/');
        string parentPath = (lastSlash == string::npos) ? "/" : path.substr(0, lastSlash);
        string name = (lastSlash == string::npos) ? path : path.substr(lastSlash + 1);

        DirNode* parent = findNode(parentPath);
        if (!parent || parent->isFile) {
            cout << "Error: Invalid path or parent is a file.\n";
            return;
        }

        DirNode* newNode = new DirNode(name, isFile);
        if (!parent->child) {
            parent->child = newNode;
        } else {
            DirNode* temp = parent->child;
            while (temp->sibling) temp = temp->sibling;
            temp->sibling = newNode;
        }
    }

public:
    DirectoryTree() {
        root = new DirNode("root", false);
    }

    ~DirectoryTree() {
        clear(root);
    }

    void createFolder(const string& path) { addNode(path, false); }
    void createFile(const string& path) { addNode(path, true); }

    void list(const string& path) const {
        DirNode* node = findNode(path);
        if (!node || node->isFile) {
            cout << "Directory not found: " << path << endl;
            return;
        }

        cout << "Contents of " << path << ":" << endl;
        DirNode* curr = node->child;
        if (!curr) cout << "  (empty)" << endl;
        while (curr) {
            cout << "  [" << (curr->isFile ? "File" : "Dir") << "] " << curr->name << endl;
            curr = curr->sibling;
        }
    }

    void deleteNode(const string& path) {
        if (path == "/" || path == "") return;

        size_t lastSlash = path.find_last_of('/');
        string parentPath = (lastSlash == 0 || lastSlash == string::npos) ? "/" : path.substr(0, lastSlash);
        string targetName = (lastSlash == string::npos) ? path : path.substr(lastSlash + 1);

        DirNode* parent = findNode(parentPath);
        if (!parent || !parent->child) return;

        DirNode* curr = parent->child;
        DirNode* prev = nullptr;

        while (curr) {
            if (curr->name == targetName) {
                // Remove from sibling chain
                if (prev) prev->sibling = curr->sibling;
                else parent->child = curr->sibling;

                // Important: Isolate from sibling before clearing subtree
                curr->sibling = nullptr;
                clear(curr);
                return;
            }
            prev = curr;
            curr = curr->sibling;
        }
    }
};

// --- Example Usage ---
int main() {
    DirectoryTree myDrive;

    myDrive.createFolder("/home");
    myDrive.createFolder("/home/user");
    myDrive.createFile("/home/user/notes.txt");
    myDrive.createFile("/home/user/todo.md");
    myDrive.createFolder("/system");

    myDrive.list("/home/user");

    cout << "\nDeleting notes.txt..." << endl;
    myDrive.deleteNode("/home/user/notes.txt");

    myDrive.list("/home/user");

    return 0;
}
