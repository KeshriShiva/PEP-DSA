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
    	cout<<"cannot insert a element as stack is full"<<endl;
        return;
    }
    cout<<"element is inserted in the stack"<<" "<<value<<endl;
    stack->arr[++stack->top] = value;
}
int pop(struct Stack* stack){
	if(isEmpty(stack)){
		cout<<"cannot delete any element as stack is empty"<<endl;
		return -1;
	}
	return stack->arr[stack->top--];
}
int peek(struct Stack* stack)
{
	if(isEmpty(stack)){
		cout<<"cannot display the top as stack is empty"<<endl;
		return -1;
	}
	return stack->arr[stack->top];
}


int main() {
    struct Stack stack;
    initStack(&stack);
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
	cout<<"element deleted is"<<" "<<pop(&stack)<<endl;
    cout<<"top element is"<<" "<<peek(&stack)<<endl;
    
	return 0;
}

