#include<iostream>
#include<cstdlib>
using namespace std;

struct node {
    int data;
    struct node* next;
    struct node* prev;
};

struct node* createNode(int value) {
    struct node* node1 = (struct node*)malloc(sizeof(struct node));
    node1->data = value;
    node1->prev = NULL;
    node1->next = NULL;
    return node1;
}

void forwardTraversal(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void backwardTraversal(struct node* tail) {
    struct node* temp = tail;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

struct node* insertAtBeginning(struct node* head, int value) {
    struct node* newNode = createNode(value);
    if (head == NULL) {
        return newNode;
    }
    newNode->next = head;
    head->prev = newNode;
    return newNode;
}

struct node* insertAtEnd(struct node* head, int value) {
    struct node* newNode = createNode(value);
    if (head == NULL) {
        return newNode;
    }
    struct node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

struct node* deleteAtBeginning(struct node* head) {
    if (head == NULL) {
        return NULL;
    }
    struct node* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(temp);
    return head;
}

struct node* deleteAtEnd(struct node* head) {
    if (head == NULL) {
        return NULL;
    }
    struct node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        head = NULL;
    }
    free(temp);
    return head;
}

struct node* insertAtPosition(struct node* head, int value, int position) {
    if (position == 1) {
        return insertAtBeginning(head, value);
    }
    struct node* newNode = createNode(value);
    struct node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        return head;
    }
    newNode->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

struct node* deleteAtPosition(struct node* head, int position) {
    if (position == 1) {
        return deleteAtBeginning(head);
    }
    struct node* temp = head;
    for (int i = 1; i < position && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        return head;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    free(temp);
    return head;
}

struct node* getTail(struct node* head) {
    struct node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    return temp;
}

int main() {
    struct node* head = createNode(10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);

    cout << "List before insertions and deletions (Forward): ";
    forwardTraversal(head);

    struct node* tail = getTail(head);
    cout << "List before insertions and deletions (Backward): ";
    backwardTraversal(tail);

    head = insertAtBeginning(head, 5);
    head = insertAtEnd(head, 40);
    head = insertAtPosition(head, 25, 4);

    cout << "List after insertions (Forward): ";
    forwardTraversal(head);

    tail = getTail(head);
    cout << "List after insertions (Backward): ";
    backwardTraversal(tail);

    head = deleteAtBeginning(head);
    head = deleteAtEnd(head);
    head = deleteAtPosition(head, 3);

    cout << "List after deletions (Forward): ";
    forwardTraversal(head);

    tail = getTail(head);
    cout << "List after deletions (Backward): ";
    backwardTraversal(tail);

    return 0;
}

