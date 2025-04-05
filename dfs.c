#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct TreeNode {
    int data;
    struct TreeNode *firstChild;
    struct TreeNode *nextSiblings;
} TreeNode;

TreeNode* createNode(int data) {
    TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;
    node->firstChild = NULL;
    node->nextSiblings = NULL;
    return node;
}

void addChild(TreeNode *parent, TreeNode *child) {
    if (parent->firstChild == NULL) {
        parent->firstChild = child;
    } else {
        TreeNode *c = parent->firstChild;
        while (c->nextSiblings != NULL) {
            c = c->nextSiblings;
        }
        c->nextSiblings = child;
    }
}

typedef struct Stack {
    TreeNode* arr[MAX_SIZE];
    int top_index;
} Stack;

void init(Stack *st) {
    st->top_index = -1;
}

bool isEmpty(Stack *st) {
    return st->top_index == -1;
}

bool isFull(Stack *st) {
    return st->top_index == MAX_SIZE - 1;
}

void push(Stack *st, TreeNode *value) {
    if (isFull(st)) {
        printf("Stack is full\n");
        return;
    }
    st->arr[++st->top_index] = value;
}

void pop(Stack *st) {
    if (isEmpty(st)) {
        printf("Stack is empty\n");
        return;
    }
    st->top_index--;
}

TreeNode* top(Stack *st) {
    if (isEmpty(st)) {
        printf("Stack is empty\n");
        return NULL;
    }
    return st->arr[st->top_index];
}

void dfs(TreeNode *head){
    if (head == NULL) {
        return;
    }
    Stack s;
    init(&s);
    push(&s, head);
    
    while(!isEmpty(&s)){
        TreeNode *t = top(&s);
        printf("%d ", t->data);
        pop(&s);

        TreeNode* children[MAX_SIZE];
        int count = 0;

        TreeNode *c = t->firstChild;
        while (c){
            children[count++] = c;
            c = c->nextSiblings;
        }

        for (int i = count - 1; i >= 0; i--){
            push(&s, children[i]);
        }
    }
}

int main() {
    TreeNode *n1 = createNode(1);
    TreeNode *n2 = createNode(2);
    TreeNode *n3 = createNode(3);
    TreeNode *n4 = createNode(4);
    TreeNode *n5 = createNode(5);
    TreeNode *n6 = createNode(6);

    addChild(n1, n2);
    addChild(n1, n3);
    addChild(n1, n4);

    addChild(n2, n5);
    addChild(n3, n6);

    dfs(n1);

    return 0;
}