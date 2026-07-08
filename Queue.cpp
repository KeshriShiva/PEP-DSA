// You are using GCC
#include<stdio.h>
#include<stdlib.h>
#define MAX 100

struct Queue
{
    int front;
    int rear;
    int arr[MAX];
};

void initQueue(struct Queue* queue){
    queue->front=-1;
    queue->rear=-1;
}

int isFull(struct Queue* queue){
    return queue->rear==MAX-1;
}

int isEmpty(struct Queue* queue){
    return queue->front==-1 || queue->front>queue->rear;
}

void Enqueue(struct Queue* queue,int value){
    if(isFull(queue)){
        printf("Queue overflow");
        return;
    }
    if(queue->front==-1) queue->front=0;
    printf("%d enqueued to queue\n",value);
    queue->arr[++queue->rear]=value;
}
void Dequeue(struct Queue* queue){
    if(isEmpty(queue)){
        printf("Queue is Empty");
        return;
    }
    if(queue->front>queue->rear){
        queue->front=queue->rear=-1;
    }
    printf("Dequeued value is: %d\n", queue->arr[queue->front++]);
    
}
void display(struct Queue* queue){
    if(isEmpty(queue)){
        printf("Queue is Empty");
        return;
    }
    printf("Queue elements: ");
    for(int i=queue->front;i<=queue->rear;i++){
        printf("%d ",queue->arr[i]);
    }
    printf("\n");
}
void frontElement(struct Queue* queue){
    if(isEmpty(queue)){
        printf("Queue is Empty");
        return;
    }
    printf("Element at the front is %d\n",queue->arr[queue->front]);
}
int main(){
    struct Queue queue;
    initQueue(&queue);
    Enqueue(&queue,10);
    Enqueue(&queue,20);
    Enqueue(&queue,30);
    Enqueue(&queue,40);
    display(&queue);
    frontElement(&queue);
    Dequeue(&queue);
    frontElement(&queue);
    display(&queue);
    Dequeue(&queue);
    Dequeue(&queue);
    Dequeue(&queue);
}
