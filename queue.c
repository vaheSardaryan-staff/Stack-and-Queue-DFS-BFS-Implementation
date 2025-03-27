#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct Queue {
    int arr[MAX_SIZE];
    int front;
    int rear;
} Queue;

void init(Queue *qu) {
    qu->front = -1;
    qu->rear = -1;
}

bool isEmpty(Queue *qu) {
    return qu->front == -1;
}

bool isFull(Queue *qu) {
    return qu->rear == MAX_SIZE - 1;
}

void enqueue(Queue *qu, int value) {
    if (isFull(qu)) {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty(qu)) {
        qu->front = 0;
    }
    qu->arr[++qu->rear] = value;
}

void dequeue(Queue *qu) {
    if (isEmpty(qu)) {
        printf("Queue is empty\n");
        return;
    }
    qu->front++;
    if (qu->front > qu->rear) {
        init(qu);
    }
}

int front(Queue *qu) {
    if (isEmpty(qu)) {
        printf("Queue is empty\n");
        return -1;
    }
    return qu->arr[qu->front];
}

void printQueue(Queue *qu) {
    if (isEmpty(qu)) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = qu->front; i <= qu->rear; i++) {
        printf("%d ", qu->arr[i]);
    }
    printf("\n");
}

int main() {
    Queue qu;
    init(&qu);
    
    enqueue(&qu, 10);
    enqueue(&qu, 20);
    enqueue(&qu, 30);
    printQueue(&qu);
    
    dequeue(&qu);
    printQueue(&qu);
    
    printf("Front: %d\n", front(&qu));
    
    return 0;
}
