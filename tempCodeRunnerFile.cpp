#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int size;

    cout << "Enter the number of strings: ";
    cin >> size;
    cin.ignore();

    if (size <= 0) {
        cout << "Invalid size. Must be greater than 0." << endl;
        return 1;
    }

    char** arr = new char*[size];

    for (int i = 0; i < size; i++) {
        char temp[100];

        cout << "Enter string " << i + 1 << ": ";
        cin.getline(temp, 100);

        arr[i] = new char[strlen(temp) + 1];

        strcpy(arr[i], temp);
    }

    cout << "\nYou entered:\n";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << endl;
    }

    for (int i = 0; i < size; i++) {
        delete[] arr[i];
    }

    delete[] arr;

    return 0;
}