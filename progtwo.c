#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
//This is an exercise to recreate every data structure I possibly can
//from EECS 268 at KU into C for future C development
//This will contain implementations of:
//Node, Stack, Queue, LinkedList, BinaryTree, Heap
//Why not make this in C++ because of real classes??
//This is an exercise and I wanna challenge myself


//NODE
typedef struct Node {
struct Node *next;
int entry;
} Node;

//STACK
typedef struct Stack{
	Node *head;
	int length;
} Stack;

typedef struct Queue{
    Node *head;
    Node *tail;
    int length;
} Queue;
//stack push- pushes a new value to the top
//of the given stack
bool stack_is_empty(Stack *mystack){
    if (mystack->head == NULL){
        return true;
    }
    return false;
}
void stack_init(Stack *mystack){
    //clears the memory out on the head. not needed
    //but needed because otherwise the first value is garbage
    mystack->head = NULL;
    mystack->length = 0;
}
void stack_push(Stack *mystack, Node *nodeToPush) {
    //first get the head and set it to the previous head
    Node *previousHead = mystack->head;
    mystack->head = nodeToPush;
    nodeToPush->next = previousHead;
    mystack->length++;
}
int stack_peek(Stack *mystack) {
    //returns the top value
    printf("slength : %d\n", mystack->length);
    if (mystack->length != 0){
        //this if check avoids a segmentation fault
        return mystack->head->entry;
    }
    else{
        printf("stack unbounded");
        exit(1);
    }
}

Node stack_pop(Stack *mystack){
    //deletes the stuff from the stack!!
    // checks if the stack is empty
    if (mystack->length == 0){
        printf("Stack unbounded");
        exit(1);
    }

    mystack->length--;
    Node *previousHeadNode = mystack->head;
    mystack->head = mystack->head->next;
    return *previousHeadNode;
}

void queue_enqueue(){

}


int main(){
    Stack babysFirstStack;
    Node firstNode;
    Node secondNode;
    firstNode.entry = 1;
    secondNode.entry = 3;
    stack_init(&babysFirstStack);
    stack_push(&babysFirstStack,&firstNode);
    stack_push(&babysFirstStack, &secondNode);
    printf("%d\n", stack_peek(&babysFirstStack));
    stack_pop(&babysFirstStack);
    printf("%d\n", stack_peek(&babysFirstStack));
    printf("%d\n", stack_peek(&babysFirstStack));
	return 0;
}
