#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
//This is an exercise to recreate every data structure I possibly can
//from EECS 268 at KU into C for future C development
//This will contain implementations of:
//Node, Stack, Queue, LinkedList, BinaryTree, Heap
//Why not make this in C++ because of real classes??
//This is an exercise and I wanna challenge myself
// is this code bad right now? yes
// but i hope for it to be eductational

//NODE
typedef struct Node {
struct Node *next; //defining a reference of a struct as the struct itself? take that python!
int entry;//or an int like object
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

void stack_pop(Stack *mystack){
    //deletes the stuff from the stack!!
    // checks if the stack is empty
    if (mystack->length == 0){
        printf("Stack unbounded");
        exit(1);
    }
    //deincrement me!!!
    mystack->length--;
    //save previousHeadNode
    Node *previousHeadNode = mystack->head;
    //now let's set mystack to the next part
    mystack->head = mystack->head->next;
}
void queue_init(Queue *myqueue){
    //initialises values instead of having garbage
    myqueue->head = NULL;
    myqueue->tail = NULL;
    myqueue->length = 0;
}
void queue_enqueue(Queue *myqueue, Node *newTail){
    //to avoid a segfault, we need to check if the
    // tail is already null and set both the head and tail to
    // reference the same node pointer
    myqueue->length++; //increment the length by 1
    //what weird syntax
    if (myqueue->tail == NULL){
        myqueue->head = newTail;
        myqueue->tail = newTail;
        return;
    }
    //basically we're going to set the tail to a
    // new element and have the previous point to the tail
    Node *previousTail = myqueue->tail;
    //why use the heap? when you can just use the stack???
    myqueue->tail = newTail;
    previousTail->next = previousTail;
}

int queue_peek(Queue *myqueue){
    if (myqueue->length != 0){
        return myqueue->head->entry;
    }
    else {
        printf("Cannot peek, unknown value");
        exit(1);
    }
}

void queue_dequeue(Queue *myqueue){
    if (myqueue->length == 0){printf("Queue is empty, cannot dequeue");exit(1);}
    myqueue->length--;//deincrement the length
    myqueue->head = myqueue->head->next;
    printf("myqueueheadnext is ");
}

bool queue_is_empty(Queue *myqueue){
    //switch statement for speed and quick checking
    switch (myqueue->length){
       case 0:
            return true;
        default:
            return false;
   }

}
int queue_sizeof(Queue *myqueue){
    return myqueue->length;
}


int main(){
    Queue q;
    queue_init(&q);
    Node newNode;
    newNode.entry = 2;
    Node secondNode;
    secondNode.entry = 4;
    queue_enqueue(&q, &newNode);
    printf("%d\n", queue_peek(&q));
    queue_enqueue(&q, &secondNode);
    printf("%d\n", queue_peek(&q));
    queue_dequeue(&q);
    printf("%d", queue_peek(&q));
	return 0;
}
