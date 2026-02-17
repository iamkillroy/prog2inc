#include <stdio.h>
#include <stdbool.h>

//This is an exercise to recreate every data structure I possibly can 
//from EECS 268 at KU into C for future C development
//This will contain implementations of: 
//Node, Stack, Queue, LinkedList, BinaryTree, Heap
//Why not make this in C++ because of real classes??
//This is an exercise and I wanna challenge myself


//NODE
typedef struct Node {
struct Node* next;
int entry;
} Node;

//STACK
typedef struct Stack{
	Node* head;
} Stack;

//STACK METHODS
//we're using dynamically allocated stacks
//i get why people built these now because malloc
//and free and memory safe c is so hard
//but linked objects get dynamically put in the stack

Node* Stack_peek_front(Stack *  user_stack){
	return user_stack->head;
}

void Stack_push(Stack * user_stack, int entryValue) {
	Node userNode;
	userNode.entry = entryValue;
	userNode.next = user_stack->head;
	user_stack->head = *userNode;
}



int main(){
	Node firstNode;
	Node secondNode;
	firstNode.next = &secondNode;
	printf("%d", firstNode.next);
	return 0;
}

