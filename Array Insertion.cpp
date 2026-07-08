#include <iostream>
using namespace std;
void insert(int arr[], int& size, int element, int pos, int capacity) {
    if (size >= capacity) return;
    for (int i = size++; i > pos; i--) arr[i] = arr[i - 1];
    arr[pos] = element;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int main() {
    int arr[10] = {1, 2, 4, 5}, size = 4;
    insert(arr, size, 3, 2, 10);
    printArray(arr, size);
    return 0;
}

