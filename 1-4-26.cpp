//Q1
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <limits> // For clearing the input buffer

using namespace std;

// Base Class: Student
class Student {
protected:
    int roll_number;
    string name;
    vector<float> marks;

public:
    // Constructor
    Student(int r, string n, vector<float> m) : roll_number(r), name(n), marks(m) {}

    // Virtual Destructor
    virtual ~Student() {}

    // Calculates the average of the marks
    float calculateAverage() const {
        if (marks.empty()) return 0.0f;
        float sum = accumulate(marks.begin(), marks.end(), 0.0f);
        return sum / marks.size();
    }

    // Virtual display function for polymorphism
    virtual void displayStudent() const {
        cout << "Roll No: " << roll_number
             << " | Name: " << name
             << " | Average Grade: " << calculateAverage();
    }
};

// Subclass 1: Undergraduate
class UndergraduateStudent : public Student {
private:
    string major;

public:
    UndergraduateStudent(int r, string n, vector<float> m, string maj)
        : Student(r, n, m), major(maj) {}

    void displayStudent() const override {
        cout << "[Undergrad] ";
        Student::displayStudent();
        cout << " | Major: " << major << endl;
    }
};

// Subclass 2: Graduate
class GraduateStudent : public Student {
private:
    string thesis_topic;

public:
    GraduateStudent(int r, string n, vector<float> m, string thesis)
        : Student(r, n, m), thesis_topic(thesis) {}

    void displayStudent() const override {
        cout << "[Grad] ";
        Student::displayStudent();
        cout << " | Thesis: " << thesis_topic << endl;
    }
};

// Helper function to clear input buffer
void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// MAIN FUNCTION - User Interactive Menu
int main() {
    vector<Student*> directory; // Stores pointers to handle polymorphism
    int choice;

    cout << "--- Welcome to the Student Record System ---" << endl;

    while (true) {
        cout << "\nMenu Options:" << endl;
        cout << "1. Add Undergraduate Student" << endl;
        cout << "2. Add Graduate Student" << endl;
        cout << "3. Display All Records" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        if (choice == 4) {
            cout << "Exiting system. Goodbye!" << endl;
            break;
        }

        if (choice == 1 || choice == 2) {
            int roll;
            string name;
            int numSubjects;
            vector<float> marks;

            // Get basic student info
            cout << "Enter Roll Number: ";
            cin >> roll;
            clearInputBuffer(); // Clear newline character left by cin >>

            cout << "Enter Full Name: ";
            getline(cin, name);

            cout << "Enter the number of subjects: ";
            cin >> numSubjects;

            cout << "Enter marks for " << numSubjects << " subjects:" << endl;
            for (int i = 0; i < numSubjects; ++i) {
                float mark;
                cout << "Subject " << (i + 1) << ": ";
                cin >> mark;
                marks.push_back(mark);
            }
            clearInputBuffer();

            // Handle specific details based on student type
            if (choice == 1) {
                string major;
                cout << "Enter Undergraduate Major: ";
                getline(cin, major);

                // Create object and add to directory
                directory.push_back(new UndergraduateStudent(roll, name, marks, major));
                cout << "Undergraduate student added successfully!" << endl;

            } else if (choice == 2) {
                string thesis;
                cout << "Enter Graduate Thesis Topic: ";
                getline(cin, thesis);

                // Create object and add to directory
                directory.push_back(new GraduateStudent(roll, name, marks, thesis));
                cout << "Graduate student added successfully!" << endl;
            }
        }
        else if (choice == 3) {
            if (directory.empty()) {
                cout << "No student records found. Please add a student first." << endl;
            } else {
                cout << "\n--- All Student Records ---" << endl;
                for (const auto* student : directory) {
                    student->displayStudent(); // Polymorphism in action
                }
            }
        }
        else {
            cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
            clearInputBuffer();
        }
    }

    // Cleanup: Prevent memory leaks by deleting dynamically allocated objects
    for (auto* student : directory) {
        delete student;
    }
    directory.clear();

    return 0;
}


// Q2
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include <limits>
#include <stdexcept>

using namespace std;

// --- Class Design ---
class Employee {
private:
    int employee_id;
    string name;
    double base_salary;
    double net_salary;

public:
    // Constructor
    Employee(int id, string n, double salary)
        : employee_id(id), name(n), base_salary(salary), net_salary(0.0) {}

    // Business Logic: Calculate salary with bonuses and deductions
    void calculateSalary() {
        // Example logic: 12% bonus, 5% tax deduction
        double bonus = base_salary * 0.12;
        double tax = base_salary * 0.05;
        net_salary = base_salary + bonus - tax;
    }

    // Getters
    int getId() const { return employee_id; }
    string getName() const { return name; }
    double getBaseSalary() const { return base_salary; }
    double getNetSalary() const { return net_salary; }
};

// Helper function to clear input buffer
void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// --- Main Function ---
int main() {
    vector<Employee> employees;
    string inputFileName = "employees_input.txt";
    string outputFileName = "employees_updated.txt";
    int choice;

    cout << "--- Interactive Employee Salary Management System ---" << endl;

    while (true) {
        cout << "\nMenu Options:" << endl;
        cout << "1. Add New Employee Manually" << endl;
        cout << "2. Save Current Records to File (" << inputFileName << ")" << endl;
        cout << "3. Load Records from File (" << inputFileName << ")" << endl;
        cout << "4. Calculate Salaries & Save to Updated File (" << outputFileName << ")" << endl;
        cout << "5. Display Records on Screen" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice (1-6): ";

        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number." << endl;
            clearInputBuffer();
            continue;
        }

        if (choice == 6) {
            cout << "Exiting system. Goodbye!" << endl;
            break;
        }

        switch (choice) {
            case 1: { // Add Employee
                int id;
                string name;
                double salary;

                cout << "\n-- Enter Employee Details --" << endl;
                cout << "Enter Employee ID: ";
                cin >> id;
                clearInputBuffer();

                cout << "Enter Full Name: ";
                getline(cin, name);

                cout << "Enter Base Salary: ";
                cin >> salary;
                clearInputBuffer();

                employees.push_back(Employee(id, name, salary));
                cout << "Success: " << name << " added to current session memory." << endl;
                break;
            }

            case 2: { // Save to File
                try {
                    ofstream outFile(inputFileName);
                    if (!outFile.is_open()) {
                        throw runtime_error("Error: Could not open " + inputFileName + " for writing.");
                    }
                    for (const auto& emp : employees) {
                        outFile << emp.getId() << ","
                                << emp.getName() << ","
                                << fixed << setprecision(2) << emp.getBaseSalary() << "\n";
                    }
                    outFile.close();
                    cout << "Success: " << employees.size() << " records saved to " << inputFileName << endl;
                } catch (const exception& e) {
                    cerr << e.what() << endl;
                }
                break;
            }

            case 3: { // Load from File
                try {
                    ifstream inFile(inputFileName);
                    if (!inFile.is_open()) {
                        throw runtime_error("Error: Could not find or open " + inputFileName + ". Try saving records first.");
                    }

                    employees.clear(); // Clear current session memory before loading
                    string line;

                    while (getline(inFile, line)) {
                        if (line.empty()) continue;

                        stringstream ss(line);
                        string id_str, name, salary_str;

                        getline(ss, id_str, ',');
                        getline(ss, name, ',');
                        getline(ss, salary_str, ',');

                        employees.push_back(Employee(stoi(id_str), name, stod(salary_str)));
                    }
                    inFile.close();
                    cout << "Success: " << employees.size() << " records loaded from " << inputFileName << endl;

                } catch (const exception& e) {
                    cerr << e.what() << endl;
                }
                break;
            }

            case 4: { // Calculate and Save Updated Data
                if (employees.empty()) {
                    cout << "Error: No records in memory. Add manually or load from file first." << endl;
                    break;
                }

                try {
                    ofstream outFile(outputFileName);
                    if (!outFile.is_open()) {
                        throw runtime_error("Error: Could not open " + outputFileName + " for writing.");
                    }

                    outFile << "ID,Name,Base_Salary,Net_Salary\n"; // Add CSV Headers

                    for (auto& emp : employees) {
                        emp.calculateSalary(); // Apply business logic

                        outFile << emp.getId() << ","
                                << emp.getName() << ","
                                << fixed << setprecision(2) << emp.getBaseSalary() << ","
                                << emp.getNetSalary() << "\n";
                    }
                    outFile.close();
                    cout << "Success: Salaries calculated and saved to " << outputFileName << endl;
                } catch (const exception& e) {
                    cerr << e.what() << endl;
                }
                break;
            }

            case 5: { // Display Records
                if (employees.empty()) {
                    cout << "No records to display. Please add employees or load a file." << endl;
                    break;
                }

                cout << "\n--- Current Employee Roster ---" << endl;
                cout << left << setw(5) << "ID" << setw(18) << "Name"
                     << setw(15) << "Base Salary" << setw(15) << "Net Salary" << endl;
                cout << "------------------------------------------------------" << endl;

                for (const auto& emp : employees) {
                    cout << left << setw(5) << emp.getId()
                         << setw(18) << emp.getName()
                         << "$" << setw(14) << fixed << setprecision(2) << emp.getBaseSalary()
                         << "$" << setw(14) << emp.getNetSalary() << endl;
                }
                break;
            }

            default:
                cout << "Invalid choice. Please enter a number between 1 and 6." << endl;
                clearInputBuffer();
                break;
        }
    }

    return 0;
}

// Q3
#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

// --- ANSI Color Codes for UI ---
const string RESET = "\033[0m";
const string BOLD = "\033[1m";
const string RED = "\033[31m";    // For Player X
const string BLUE = "\033[34m";   // For Player O
const string GREEN = "\033[32m";  // For Success Messages
const string YELLOW = "\033[33m"; // For Board Borders
const string CYAN = "\033[36m";   // For Info Text
const string DIM = "\033[2m";     // For the 1-9 Grid numbers

// --- Helper Function ---
void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// --- Base Class ---
class TicTacToe {
protected:
    char board[3][3];
    char current_turn;
    char winner;
    int move_count;
    int input_mode; // 1 for Numpad (1-9), 2 for Matrix (Row Col)

    void clearScreen() const {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
    }

    void updateWinnerStatus() {
        for (int i = 0; i < 3; i++) {
            if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) winner = board[i][0];
            if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) winner = board[0][i];
        }
        if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) winner = board[0][0];
        if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) winner = board[0][2];

        if (winner == ' ' && move_count == 9) winner = 'D'; // Draw
    }

    string formatCell(int r, int c) const {
        if (board[r][c] == 'X') return BOLD + RED + "X" + RESET;
        if (board[r][c] == 'O') return BOLD + BLUE + "O" + RESET;

        // If the cell is empty and we are in Numpad mode, show the number 1-9
        if (input_mode == 1) {
            return DIM + to_string(r * 3 + c + 1) + RESET;
        }
        return " ";
    }

public:
    TicTacToe() { resetGame(); }
    virtual ~TicTacToe() {}

    void resetGame() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = ' ';
            }
        }
        current_turn = 'X';
        winner = ' ';
        move_count = 0;
        input_mode = 1;
    }

    void askInputMode() {
        clearScreen();
        cout << BOLD << GREEN << "--- Game Settings ---" << RESET << "\n\n";
        cout << "How would you like to input your moves?\n";
        cout << CYAN << "1. Numpad Style (1-9) - Easy & Beginner Friendly\n" << RESET;
        cout << YELLOW << "2. Matrix Style (Row & Col) - Advanced\n" << RESET;
        cout << "Enter your choice (1 or 2): ";

        while (!(cin >> input_mode) || (input_mode != 1 && input_mode != 2)) {
            clearInputBuffer();
            cout << RED << "Invalid choice. Please enter 1 or 2: " << RESET;
        }
    }

    void printBoard() const {
        clearScreen();
        cout << BOLD << GREEN << "\n   === TIC-TAC-TOE ===" << RESET << "\n\n";

        if (input_mode == 2) {
            cout << "      0   1   2\n"; // Column coordinates for Matrix Mode
        } else {
            cout << "\n"; // Padding for Numpad mode
        }

        for (int i = 0; i < 3; i++) {
            if (input_mode == 2) cout << "    " << i << " "; // Row coordinates
            else cout << "      "; // Padding

            cout << formatCell(i, 0) << YELLOW << " | " << RESET
                 << formatCell(i, 1) << YELLOW << " | " << RESET
                 << formatCell(i, 2) << " \n";

            if (i < 2) {
                if (input_mode == 2) cout << "      ";
                else cout << "      ";
                cout << YELLOW << " ---|---|---\n" << RESET;
            }
        }
        cout << "\n";
    }

    bool makeMove(int row, int col) {
        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ' || winner != ' ') {
            return false;
        }
        board[row][col] = current_turn;
        move_count++;
        updateWinnerStatus();

        if (winner == ' ') {
            current_turn = (current_turn == 'X') ? 'O' : 'X';
        }
        return true;
    }

    bool isGameOver() const { return winner != ' '; }

    // Helper to get human input cleanly without duplicating code
    void getHumanMove(int &row, int &col) {
        bool valid_input = false;
        while (!valid_input) {
            if (input_mode == 1) {
                cout << "Enter a box number (1-9): ";
                int num;
                if (cin >> num && num >= 1 && num <= 9) {
                    row = (num - 1) / 3;
                    col = (num - 1) % 3;
                    valid_input = true;
                } else {
                    cout << RED << "Invalid! Enter a number from 1 to 9.\n" << RESET;
                    clearInputBuffer();
                }
            } else {
                cout << "Enter row and column (e.g., '1 1'): ";
                if (cin >> row >> col) {
                    valid_input = true;
                } else {
                    cout << RED << "Invalid! Enter two numbers.\n" << RESET;
                    clearInputBuffer();
                }
            }
        }
    }

    virtual void playGame() {
        askInputMode();
        int row, col;

        while (!isGameOver()) {
            printBoard();
            cout << "Player " << ((current_turn == 'X') ? (BOLD + RED + "X") : (BOLD + BLUE + "O")) << RESET << "'s turn.\n";

            getHumanMove(row, col);

            if (!makeMove(row, col)) {
                cout << RED << "Invalid move! Space taken or out of bounds." << RESET << "\nPress Enter to try again...";
                clearInputBuffer();
                cin.get();
            }
        }

        printBoard();
        if (winner == 'D') cout << BOLD << YELLOW << "Game Over: It's a Draw!\n" << RESET;
        else cout << BOLD << GREEN << "Game Over: Player " << winner << " wins!\n" << RESET;
    }
};

// --- Derived Class: "Hard" AI with Randomized Roles ---
class TicTacToeAI : public TicTacToe {
private:
    char human_piece;
    char ai_piece;

    int evaluateBoard() const {
        for (int i = 0; i < 3; i++) {
            if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
                if (board[i][0] == ai_piece) return +10;
                else return -10;
            }
            if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
                if (board[0][i] == ai_piece) return +10;
                else return -10;
            }
        }
        if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            if (board[0][0] == ai_piece) return +10;
            else return -10;
        }
        if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
            if (board[0][2] == ai_piece) return +10;
            else return -10;
        }
        return 0;
    }

    bool isMovesLeft() const {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (board[i][j] == ' ') return true;
        return false;
    }

    int minimax(int depth, bool isMax) {
        int score = evaluateBoard();

        if (score == 10) return score - depth;
        if (score == -10) return score + depth;
        if (!isMovesLeft()) return 0;

        if (isMax) {
            int best = -1000;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (board[i][j] == ' ') {
                        board[i][j] = ai_piece;
                        best = max(best, minimax(depth + 1, !isMax));
                        board[i][j] = ' ';
                    }
                }
            }
            return best;
        } else {
            int best = 1000;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (board[i][j] == ' ') {
                        board[i][j] = human_piece;
                        best = min(best, minimax(depth + 1, !isMax));
                        board[i][j] = ' ';
                    }
                }
            }
            return best;
        }
    }

    void findBestMove(int &bestRow, int &bestCol) {
        if (rand() % 100 < 20) {
            do {
                bestRow = rand() % 3;
                bestCol = rand() % 3;
            } while (board[bestRow][bestCol] != ' ');
            return;
        }

        int bestVal = -1000;
        bestRow = -1;
        bestCol = -1;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = ai_piece;
                    int moveVal = minimax(0, false);
                    board[i][j] = ' ';

                    if (moveVal > bestVal) {
                        bestRow = i;
                        bestCol = j;
                        bestVal = moveVal;
                    }
                }
            }
        }
    }

public:
    void playGame() override {
        askInputMode(); // Ask for input preference

        srand(time(0));
        human_piece = (rand() % 2 == 0) ? 'X' : 'O';
        ai_piece = (human_piece == 'X') ? 'O' : 'X';

        int row, col;
        while (!isGameOver()) {
            printBoard();

            string human_color = (human_piece == 'X') ? (BOLD + RED + "X") : (BOLD + BLUE + "O");
            string ai_color = (ai_piece == 'X') ? (BOLD + RED + "X") : (BOLD + BLUE + "O");

            cout << CYAN << "You are playing as: " << human_color << RESET << "\n";
            cout << CYAN << "Computer is playing as: " << ai_color << RESET << "\n\n";

            if (current_turn == human_piece) {
                cout << "Your turn!\n";
                getHumanMove(row, col);

                if (!makeMove(row, col)) {
                    cout << RED << "Invalid move! Space taken or out of bounds." << RESET << "\nPress Enter to try again...";
                    clearInputBuffer();
                    cin.get();
                }
            } else {
                cout << "Computer is thinking...\n";
                findBestMove(row, col);
                makeMove(row, col);
            }
        }

        printBoard();
        if (winner == 'D') cout << BOLD << YELLOW << "Game Over: It's a Draw!\n" << RESET;
        else if (winner == human_piece) cout << BOLD << GREEN << "You beat the AI! Amazing!\n" << RESET;
        else cout << BOLD << RED << "Game Over: Computer wins!\n" << RESET;
    }
};

int main() {
    int choice;
    TicTacToe* game = nullptr;

    while (true) {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

        cout << BOLD << GREEN << "--- Welcome to Tic-Tac-Toe ---" << RESET << endl;
        cout << "\n1. Play Player vs Player" << endl;
        cout << "2. Play Player vs Computer (Hard)" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            clearInputBuffer();
            continue;
        }

        if (choice == 3) break;

        if (choice == 1) game = new TicTacToe();
        else if (choice == 2) game = new TicTacToeAI();
        else continue;

        game->playGame();

        cout << "\nPress Enter to return to the main menu...";
        clearInputBuffer();
        cin.get();

        delete game;
        game = nullptr;
    }

    return 0;
}
