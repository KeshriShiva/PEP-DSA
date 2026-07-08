    #include <iostream>
    using namespace std;
    
    struct StackNode {
        int data;
        StackNode *next;
    };
    
    struct Stack{
        StackNode* top;
    };
    
    
    StackNode* createNode(int d){
        StackNode* node = new StackNode();
        node->data=d;
        node->next=NULL;
        return node;       
    }
    
    
    Stack* createStack(){
        Stack* stack = new Stack();
        stack->top=NULL;
        return stack;
    }
    
    bool isEmpty(Stack* stack){
        return  stack->top==NULL;
    }
    void push(int value,Stack* stack){
        StackNode* node = createNode(value);
        node->next=stack->top;
        stack->top=node;
        cout << "Value pushed in the stack is " << value << "\n";
    }
    
    int pop(Stack* stack){
        if(isEmpty(stack)) return -1;
        StackNode* popped=stack->top;
        stack->top=stack->top->next;
        int val = popped->data;
        delete popped;
        return val;
    }
    int peek(Stack* stack){
        return stack->top->data;
        
    }
    void printStack(Stack* stack){
        StackNode* temp=stack->top;
        cout << "Data in the stack is : ";
        while(temp!=NULL){
            cout << temp->data << " ";
            temp=temp->next;
        }
    }
    
    int main(){
        Stack* stack = createStack();
        push(5,stack);
        push(4,stack);
        push(3,stack);
        push(2,stack);
        push(1,stack);
        printStack(stack);
        cout << "\nTop element in stack is " << peek(stack) << endl;
        cout << "Value popped from stack is " << pop(stack) << endl;
        cout << "Top element in stack is " << peek(stack) << endl;
        printStack(stack);
        
        
    }
