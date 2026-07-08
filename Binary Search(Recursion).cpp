#include <iostream>
using namespace std;

int binarySearch(int arr[], int left, int right, int x) {
    if (left > right) {
        return -1;
    }
    int mid = left + (right - left) / 2;
    if (arr[mid] == x) {
        return mid;
    }
    if (arr[mid] > x) {
        return binarySearch(arr, left, mid - 1, x);
    }
    return binarySearch(arr, mid + 1, right, x);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x;
    cout << "Enter a number to search: ";
    cin >> x;
    int result = binarySearch(arr, 0, n - 1, x);
    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }
    return 0;
}

