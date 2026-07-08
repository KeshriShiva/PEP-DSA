#include<bits/stdc++.h>

using namespace std;

struct node
{
	int data;
	struct node* next;
	
};

struct node* createNode(int value)
{
	struct node *node1=(struct node*)malloc(sizeof(struct node));
	node1->data=value;
	node1->next=NULL;
	return node1;
};

void printList(struct node* header) {
    struct node* current = header->next;
    while (current != NULL) {
        cout << current->data << " "; 
        current = current->next;      
    }
    cout << endl;
}

struct node* insertAtEnd(struct node* header, int value) {
    struct node* node1 = createNode(value);
    if (header->next == NULL) {
        header->next = node1;
    } else {
        struct node* current = header->next;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = node1;
    }
    
    header->data += 1;
    return header;
}

void insertAtPosition(struct node* header, int value, int position) {
    if (position < 1 || position > header->data + 1) {
        cout << "Invalid position!" << endl;
        return;
    }

    struct node* node1 = createNode(value);
    struct node* current = header;
    
    for (int i = 0; i < position - 1; ++i) {
        current = current->next;
    }

    node1->next = current->next;
    current->next = node1;
    header->data += 1;
}


struct node* insertAtBeg(struct node* header,int value)
{
	struct node* node1 =createNode(value);
	node1->next=header->next;
	header->next=node1;
	header->data+=1;
	return header;	
 };
 
void deleteAtPosition(struct node* header, int position) {
    if (position < 1 || position > header->data) {
        cout << "Invalid position!" << endl;
        return;
    }

    struct node* current = header;
    
    for (int i = 0; i < position - 1; ++i) {
        current = current->next;
    }

    struct node* temp = current->next;
    current->next = temp->next;
    free(temp); 
    header->data -= 1;
}

void deleteAtEnd(struct node* header) {
    if (header->next == NULL) {
        cout << "List is empty, nothing to delete!" << endl;
        return;
    }

    struct node* current = header->next;
    struct node* prev = header;

    if (current->next == NULL) {
        free(current);  
        header->next = NULL;
    } else {
        while (current->next != NULL) {
            prev = current;
            current = current->next;
        }

        prev->next = NULL; 
        free(current);  
    }

    header->data -= 1; 
}

 
 void deleteAtBeg(struct node* header) {
    if (header->next == NULL) {
        cout << "List is empty, nothing to delete!" << endl;
        return;
    }

    struct node* temp = header->next; 
    header->next = temp->next;       
    free(temp);                       
    header->data -= 1;              
}

void printNodeCount(struct node* header) {
    cout << "Number of nodes: " << header->data << endl;

}

int main()
{
	struct node* header=(struct node*)malloc(sizeof(struct node));
	header->data=0;
	header->next=NULL;
	header=insertAtBeg(header,10);
	header=insertAtBeg(header,20);
	header=insertAtBeg(header,30);
	header=insertAtBeg(header,40);
	header=insertAtBeg(header,50);
	header = insertAtEnd(header,60);
    header = insertAtEnd(header,70);
	cout << "Linked list after insertions: ";
    printList(header);
    insertAtPosition(header, 25, 3);
    insertAtPosition(header, 15, 1);
    insertAtPosition(header, 90, 10);
    cout<<"Linked list after insertions at specific positions: ";
    printList(header);
    printNodeCount(header);
    deleteAtBeg(header);
    deleteAtBeg(header);
    cout<<"Linked list after deletions at beginning: ";
    printList(header);
    deleteAtPosition(header, 3);
    deleteAtPosition(header, 1); 
    deleteAtPosition(header, 7); 
    cout << "Linked list after deletions at specific positions: ";
    printList(header);
    deleteAtEnd(header);
    deleteAtEnd(header);
    cout << "Linked list after deletions at end: ";
    printList(header);
    printNodeCount(header);
    return 0;
}
