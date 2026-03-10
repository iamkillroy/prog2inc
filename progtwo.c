#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <stdbool.h>


//TYPEDEFS
typedef struct Node {
    struct Node *next;
    uint32_t entry;
} Node;

typedef struct Stack {
    Node * head;
    uint16_t len;
} Stack;

typedef struct Queue {
    Node * head;
    Node * tail;
    uint16_t len;
} Queue;


void handleNullPtr(void * ptr);

Node * node_init(uint32_t);

Stack* stack_init();
void stack_push(Stack *, uint32_t);
void stack_pop(Stack *);
bool stack_is_empty(Stack *);
uint32_t stack_peek(Stack * );

Queue* queue_init();
void queue_enqueue(Queue *, uint32_t);
void queue_dequeue(Queue *);
uint32_t queue_peek(Queue *);



void handleNullPtr (void * ptr){
    if (ptr == NULL){printf("Malloc returned null pointer reference");exit(ENOMEM);}
}
/*#######
 # NODE #
 ########
 */


Node* node_init(uint32_t entry){
    /* Function inits a node and returns a pointer to the node */
    //make the node and sets the entry to the entry
    //and the Node's next to NULL

    // here we type case the return of malloc as a Node * (pointer)
    // and allocate the size of
    Node * myNode = (Node *) malloc(sizeof(Node));
    myNode->entry = entry;
    myNode->next = NULL;
    return myNode;
}


Stack* stack_init(){
    /* Makes a stack object and clear garbage */
    //allocate a stack on the heap with size of structStack
    Stack * myStack = (Stack * ) malloc(sizeof(Stack));
    handleNullPtr(myStack);
    myStack->head = NULL;
    myStack->len = 0; //set length to zero
    return myStack;
}

void stack_push(Stack * myStack, uint32_t value){
    /*Pushes a value onto the stack */
    //lets make a node in the heap
    Node * nodeToPush = malloc(sizeof(Node));
    handleNullPtr(nodeToPush);
    nodeToPush->entry = value;
    //now let's push it!!!!
    //let's do a quick check to see if the stack is empty
    if (myStack->len == 0){
        nodeToPush->next = myStack->head;
        myStack->head = nodeToPush;
        myStack->len++;
        return;
    }
    nodeToPush->next = myStack->head;
    myStack->head = nodeToPush;
    myStack->len++;

}

void stack_pop(Stack * myStack){
    //handles deletion of value from stack
    if (myStack->len == 0){
        return;
    }
    Node *nextValue = myStack->head->next;
    free(myStack->head);
    myStack->head = nextValue;
    myStack->len--;
    return;

}
uint32_t stack_peek(Stack * myStack){
    if (myStack->len == 0){
        printf("Cannot peek empty stack");
        exit(1);
    }
    return myStack->head->entry;
}
bool stack_is_empty(Stack * mystack) {
    if (mystack->len == 0){return true;}return false;
}

Queue * queue_init(){
    Queue * myQueue = (Queue * ) malloc(sizeof(Queue));
    myQueue->head = NULL;
    myQueue->tail = NULL;
    myQueue->len = 0;
    return myQueue;
}

void queue_enqueue(Queue* myqueue, uint32_t value) {
    ///adds a value to the back of the queue
    // make a new node with that value
    Node * newTailNode = malloc(sizeof(Node));
    newTailNode->entry = value;
    // then let's set that equal to the tail
    //first though if the len of queue == 0 then
    // we would be doing null pointer stuff so
    // let's check first bestie
    if (myqueue->len == 0){
        //set both the head and tail to the
        // first value, this will get replaced the second
        // time that we enque so that head = first enqued and
        // tail = latest enqued
        myqueue->head = newTailNode;
        myqueue->tail = newTailNode;
        myqueue->len++;
        return;
    }
    //okay now there should be at least some pointer here
    myqueue->tail->next = newTailNode;
    myqueue->tail = newTailNode;
    myqueue->len++;
    return;
}
void queue_dequeue(Queue * myqueue){
    //removes the value stored in the queue
    // and then evaluate the data
    if (myqueue->len == 0){
        return;
    }
    Node * prevHead = myqueue->head;
    myqueue->head = myqueue->head->next;
    free(prevHead);
    return;
}
uint32_t queue_peek(Queue * myqueue){
    if (myqueue->len == 0){
        printf("Cannot peek empty queue");
        exit(1);
    }
    return myqueue->head->entry;
}


int main(){
    Queue * mq = queue_init();
    queue_enqueue(mq, 32);
    printf("%d\n", queue_peek(mq));
    queue_enqueue(mq, 2345) ;
    queue_enqueue(mq, 19);
    printf("%d\n", queue_peek(mq));
    queue_dequeue(mq);
    printf("%d\n", queue_peek(mq));
    return 0;
}
