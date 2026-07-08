#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* createNode(int value) {
    struct node* node1 = (struct node*)malloc(sizeof(struct node));
    node1->data = value;
    node1->next = NULL;
    return node1;
}

void printList(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int cnt(struct node* head) {
    int count = 0;
    struct node* temp = head;
    while (temp != NULL) {
        temp = temp->next;
        count++;
    }
    return count;
}

struct node* insertAtEnd(struct node* head, int value) {
    struct node* node1 = createNode(value);
    if (head == NULL) {
        return node1;
    }
    struct node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = node1;
    return head;
}

struct node* insertAtBeg(struct node* head, int value) {
    struct node* node1 = createNode(value);
    node1->next = head;
    return node1;
}

struct node* insertAtPos(struct node* head, int value, int position) {
    if (position == 1) {
        head = insertAtBeg(head, value);
        return head;
    }
    
    int count = cnt(head);
    if (position == count + 1) {
        head = insertAtEnd(head, value);
        return head;
    }

    struct node* node1 = createNode(value);
    struct node* current = head;
    for (int i = 1; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }

    if (current != NULL) {
        node1->next = current->next;
        current->next = node1;
    }
    
    return head;
}

	struct node* second_last = head;
	while(second_last->next->next!=NULL){
	second_last = second_last->next;
}

struct node* deleteAtBeg(struct node* head) {
    if (head == NULL) {
        return NULL;
    }
    struct node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

int main() {
    struct node* head = createNode(10);
    head = insertAtBeg(head, 12);
    head = insertAtEnd(head, 20);
    printList(head);
    printf("Count: %d\n", cnt(head));

    head = insertAtPos(head, 15, 3);
    printList(head);

    head = deleteAtBeg(head);
    printList(head);

    return 0;
    
}
