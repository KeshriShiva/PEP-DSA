#include<bits/stdc++.h>
using namespace std;

#define MAX 100

struct Stack {
    int top;
    int arr[MAX];
};

void initStack(struct Stack* stack) {
    stack->top = -1;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

int isFull(struct Stack* stack) {
    return stack->top == MAX - 1;
}

void push(struct Stack* stack, int value) {
    if (isFull(stack)) {
        cout << "Cannot insert an element as stack is full" << endl;
        return;
    }
    cout << "Element inserted in the stack: " << value << endl;
    stack->arr[++stack->top] = value;
}

int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        cout << "Cannot display the top as stack is empty" << endl;
        return -1;
    }
    return stack->arr[stack->top];
}

void displayStack(struct Stack* stack) {
    if (isEmpty(stack)) {
        cout << "Stack is empty, nothing to display." << endl;
        return;
    }
    cout << "Stack elements: ";
    for (int i = stack->top; i >= 0; i--) {
        cout << stack->arr[i] << " ";
    }
    cout << endl;
}

int main() {
    struct Stack stack;
    initStack(&stack);
    
    int n;
    cout << "Enter the number of elements to push: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int value;
        cout << "Enter element " << i + 1 << ": ";
        cin >> value;
        push(&stack, value);
    }

    cout << "Top element: " << peek(&stack) << endl;
    displayStack(&stack);

    return 0;
}

