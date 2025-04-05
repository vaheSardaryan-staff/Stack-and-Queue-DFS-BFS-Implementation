#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

// dfs - stack-based depth-first search
// bfs - queue-based breadth-first search

typedef struct TreeNode {
    int data;
    struct TreeNode *firstChild; 
    struct TreeNode *nextSiblings;
} TreeNode;

TreeNode*  createNode(int data) {
    TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));

    node->data = data;
    node->firstChild = NULL;
    node->nextSiblings = NULL;

    return node;
}

void addChild(TreeNode *parent, TreeNode *child){
    if(parent->firstChild == NULL){
        parent->firstChild = child;
    }
    else{
        TreeNode *c = parent->firstChild;
        while(c->nextSiblings != NULL){
            c = c->nextSiblings;
        }
        c->nextSiblings = child;
    }
}

typedef struct Queue {
    TreeNode *arr[MAX_SIZE];
    int front;
    int rear;
} Queue;


void init(Queue *qu) {
    qu->front = -1;
    qu->rear = -1;
}

bool isEmpty(Queue *qu) {
    if (qu->front == -1 || qu->front > qu->rear) {
        return true;
    }
    return false;
}

bool isFull(Queue *qu) {
    return qu->rear == MAX_SIZE - 1;
}

void enqueue(Queue *qu, TreeNode *node) {
    if (isFull(qu)) {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty(qu)) {
        qu->front = 0;
    }
    qu->arr[++qu->rear] = node;
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

TreeNode* front(Queue *qu) {
    if (isEmpty(qu)) {
        printf("Queue is empty\n");
        return NULL;
    }
    return qu->arr[qu->front];
}

void bfs(TreeNode *head){
    if (head == NULL) {
        return;
    }
    Queue q;
    init(&q);
    enqueue(&q, head);
    
    while(!isEmpty(&q)){
        TreeNode *t = front(&q);
        printf("%d ", t->data);
        dequeue(&q);

        TreeNode *c = t -> firstChild;;
        while (c){
            enqueue(&q, c);
            c = c->nextSiblings;
        }
    }
}

int main(){
    
    TreeNode *n1 = createNode(1);
    TreeNode *n2 = createNode(2);
    TreeNode *n3 = createNode(3);
    TreeNode *n4 = createNode(4);
    TreeNode *n5 = createNode(5);
    TreeNode *n6 = createNode(6);

    addChild(n1, n2); // n1 is the parent of n2
    addChild(n1, n3);
    addChild(n1, n4);

    addChild(n2, n5);
    addChild(n3, n6);

    bfs(n1);

    return 0;
}