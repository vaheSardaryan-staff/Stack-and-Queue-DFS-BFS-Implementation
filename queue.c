#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct Stack{
    int arr[MAX_SIZE];
    int top_index;
}Stack;

bool isEmpty(Stack *st){
    if (st->top_index == -1){
        return true;
    }
    return false;
}

bool isFull(Stack *st){
    if(st->top_index == MAX_SIZE - 1){
        return true;     
    }
    return false;
}

void init(Stack *st){
    st->top_index = -1;
}

void push(Stack *st, int value){
    if (isFull(st)){
        printf("Stack is full\n");
        return;
    }
    st->arr[++st->top_index] = value;
}

void pop(Stack *st){
    if (isEmpty(st)){
        printf("Stack is empty\n");
        return;
    }
    st->top_index--; 
}

int top(Stack *st){
    if (isEmpty(st)){
        printf("Siktir");
        return -1;
    }   
    return st->arr[st->top_index];
}

void print(Stack *st){
    if (isEmpty(st)){
        printf("Stack is empty.");
        return;
    }
    for (int i = 0; i <= st->top_index; i++){
        printf("%d ", st->arr[i]);
    }
}

int main(){
    Stack st;
    init(&st);

    print(&st);
    print(&st);

    return 0;
}
