#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
};
struct node* createNode(int value){
	struct node* node1=(struct node*)malloc(sizeof(struct node));
	node1->data=value;
	node1->next=NULL;
	return node1;
}
int main(){
	struct node* head=createNode(10);
	printf("%d\t",head->data);
	printf("%d",head->next);
	
	
	return 0;
}
