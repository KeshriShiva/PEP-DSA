#include<iostream>
using namespace std;

int sumOfNumbers(int n) {
    if (n == 0) 
        return 0;
    else 
        return n + sumOfNumbers(n - 1);
}

int main() {
    int n=4;
//    cin>>n;
    int sum = sumOfNumbers(n);
    
    cout << "Sum of numbers from 1 to " << n << " is: " << sum << endl;
    
    return 0;
}

