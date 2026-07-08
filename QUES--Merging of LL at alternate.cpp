#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void append(Node**head_ref, int new_data) {
    Node* new_node = new Node();
    Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
}

void mergeAtAlternate(Node* head1, Node** head2_ref) {
    Node* head2 = *head2_ref;
    Node* curr1 = head1, *next1;
    Node* curr2 = head2, *next2;

    while (curr1 != NULL && curr2 != NULL) {
        next1 = curr1->next;
        next2 = curr2->next;

        curr1->next = curr2;
        curr2->next = next1;

        curr1 = next1;
        curr2 = next2;
    }

    *head2_ref = curr2;
}

void printList(Node* node) {
    while (node !=NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    Node* head1 = NULL;
    append(&head1, 1);
    append(&head1, 2);
    append(&head1, 3);

    Node* head2 = NULL;
    append(&head2, 4);
    append(&head2, 5);
    append(&head2, 6);
    append(&head2, 7);
    append(&head2, 8);

    cout << "List 1 before merge: ";
    printList(head1);

    cout << "List 2 before merge: ";
    printList(head2);

    mergeAtAlternate(head1, &head2);

    cout << "List 1 after merge: ";
    printList(head1);

    cout << "Remaining nodes in List 2 (if any): ";
    printList(head2);

    return 0;
}

