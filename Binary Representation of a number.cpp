#include <iostream>
using namespace std;

void printBinary(int n) {
    if (n > 1) {
        printBinary(n / 2);
    }
    cout << n % 2;
}

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;
    printBinary(number);
    cout << endl;
    return 0;
}

