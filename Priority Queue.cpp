#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define MAX 100

struct PriorityQueue {
    int arr[MAX];
    int priority[MAX];
    int size;
};

void initQueue(struct PriorityQueue* pq) {
    pq->size = 0;
}

int isEmpty(struct PriorityQueue* pq) {
    return pq->size == 0;
}

int isFull(struct PriorityQueue* pq) {
    return pq->size == MAX;
}

void enqueue(struct PriorityQueue* pq, int value, int priority_value) {
    if (isFull(pq)) {
        printf("Priority Queue is full\n");
        return;
    }
    pq->arr[pq->size] = value;
    pq->priority[pq->size] = priority_value;
    pq->size++;
}

int getHighestPriorityIndex(struct PriorityQueue* pq) {
    int maxPriority = INT_MIN;
    int index = -1;
    for (int i = 0; i < pq->size; i++) {
        if (pq->priority[i] > maxPriority) {
            maxPriority = pq->priority[i];
            index = i;
        }
    }
    return index;
}

int dequeue(struct PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Priority Queue is empty\n");
        return -1;
    }
    int index = getHighestPriorityIndex(pq);
    int value = pq->arr[index];
    
    for (int i = index; i < pq->size - 1; i++) {
        pq->arr[i] = pq->arr[i + 1];
        pq->priority[i] = pq->priority[i + 1];
    }
    
    pq->size--;
    return value;
}

void display(struct PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Priority Queue is empty\n");
        return;
    }
    
    printf("Queue elements are: \n");
    for (int i = 0; i < pq->size; i++) {
        printf("Value: %d, Priority: %d\n", pq->arr[i], pq->priority[i]);
    }
}

int main() {
    struct PriorityQueue pq;
    initQueue(&pq);
    
    enqueue(&pq, 10, 3);
    enqueue(&pq, 20, 4);
    enqueue(&pq, 30, 2);
    enqueue(&pq, 40, 5);
    
    display(&pq);
    
    printf("\nDequeued element: %d\n", dequeue(&pq));
    display(&pq);
    
    return 0;
}

