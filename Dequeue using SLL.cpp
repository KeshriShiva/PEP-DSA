#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct Dequeue {
    Node* front;
    Node* rear;

    Dequeue() {
        front = rear = NULL;
    }

    void insertFront(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = front;
        front = newNode;
        if (rear == NULL) {
            rear = newNode;
        }
    }

    void insertRear(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;
        if (rear == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void deleteFront() {
        if (front == NULL) {
            cout << "Dequeue is empty!" << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == NULL) {
            rear = NULL;
        }
        delete temp;
    }

    void deleteRear() {
        if (rear == NULL) {
            cout << "Dequeue is empty!" << endl;
            return;
        }
        if (front == rear) {
            delete front;
            front = rear = NULL;
        } else {
            Node* temp = front;
            while (temp->next != rear) {
                temp = temp->next;
            }
            delete rear;
            rear = temp;
            rear->next = NULL;
        }
    }

    void display() {
        if (front == NULL) {
            cout << "Dequeue is empty!" << endl;
            return;
        }
        Node* temp = front;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Dequeue dq;

    dq.insertFront(10);
    dq.insertRear(20);
    dq.insertFront(5);
    dq.insertRear(25);

    cout << "Dequeue elements: ";
    dq.display();

    dq.deleteFront();
    cout << "After deleting from front: ";
    dq.display();

    dq.deleteRear();
    cout << "After deleting from rear: ";
    dq.display();

    return 0;
}

