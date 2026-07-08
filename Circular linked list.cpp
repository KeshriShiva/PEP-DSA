#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};

class CircularLinkedList {
private:
    Node* last;

public:
    CircularLinkedList() {
        last = nullptr;
    }

    void addToEmpty(int data) {
        if (last != nullptr) {
            return;
        }
        Node* newNode = new Node();
        newNode->data = data;
        last = newNode;
        last->next = last; 
    }

    void addAtEnd(int data) {
        if (last == nullptr) {
            addToEmpty(data);
            return;
        }
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }

    void traverse() {
        if (last == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }
        Node* temp = last->next;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != last->next);
        cout << endl;
    }

    void deleteNode(int key) {
        if (last == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }
        Node* temp = last->next;
        Node* prev = nullptr;

        if (last == last->next && last->data == key) {
            delete last;
            last = nullptr;
            return;
        }

        if (temp->data == key) {
            prev = last;
            last->next = temp->next;
            delete temp;
            return;
        }

        do {
            prev = temp;
            temp = temp->next;
        } while (temp != last->next && temp->data != key);

        if (temp == last->next) {
            cout << "Node not found." << endl;
            return;
        }

        prev->next = temp->next;

        if (temp == last) {
            last = prev;
        }

        delete temp;
    }
};

int main() {
    CircularLinkedList cll;

    cll.addAtEnd(10);
    cll.addAtEnd(20);
    cll.addAtEnd(30);
    cll.addAtEnd(40);

    cout << "Circular Linked List: ";
    cll.traverse();

    cout << "Deleting 20..." << endl;
    cll.deleteNode(20);
    cout << "Updated List: ";
    cll.traverse();

    return 0;
}

