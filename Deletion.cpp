#include <iostream>
using namespace std;

int main() {
	int *nullptr;
    int *arr = new int[5];
    for (int i = 0; i < 5; ++i) {
        arr[i] = arr[i+ 1];
    }
    for (int i = 0; i < 5; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    delete[] arr;
    arr= nullptr;

    return 0;
}

