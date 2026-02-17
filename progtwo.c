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
//we're using fixed sized stacks here chat
Node* Stack_peek_front(Stack *  user_stack){
	return user_stack->head;
}



int main(){
	Node firstNode;
	Node secondNode;
	firstNode.next = &secondNode;
	printf("%d", firstNode.next);
	return 0;
}

