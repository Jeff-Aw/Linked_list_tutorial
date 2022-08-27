#include <iostream>

class Node{
	public:
		int Value;
		Node* Next;
};

void printList(Node* n){
	while(n != NULL){
		std::cout<< n->Value << std::endl;
		n = n-> Next;
	}
}
// get pointer to a pointer because to reference the address of head in the Node class pointer
void insertAtTheFront(Node**head, int newValue){
	// 1. Prepare a new Node
	Node* newNode = new Node();
	newNode->Value = newValue;
	// 2. Put it in front of the current head
	newNode->Next = *head;
	// 3. Move head to the point of the new Node
	*head = newNode;
}

void insertAtTheEnd(Node**head, int newValue){
	// 1. Prepare a new Node
	Node* newNode = new Node();
	newNode->Value = newValue;
	newNode->Next = NULL;
	// 2. Check if list is empty, new Node will be head Node
	if(*head == NULL){
		*head == newNode;
		return;
	}
	// 3. Find the last Node

	Node* last = *head;
	while(last->Next != NULL){
		last = last->Next;
	}
	// 4. Insert new Node at the end
	last->Next = newNode;
}

void insertAfter(Node* previous, int newValue){
	// 1. Check if previous node is NULL
	if(previous == NULL){
		std::cout<<"\nprevious node cannot be NULL"<< std::endl;
		return;
	}
	// 2. Prepare a newNode
	Node* newNode = new Node();
	newNode->Value = newValue;
	// 3. Insert newNode after previous Node
	newNode->Next = previous->Next;
	previous->Next = newNode;
}
int main(){

	Node* head = new Node();
	Node* second = new Node();
	Node* third = new Node();
	
	head->Value = 1;
	head->Next = second;
	second->Value = 2;
	second->Next = third;
	third->Value = 3;
	third->Next = NULL;
	
	insertAtTheFront(&head, -1);
	insertAtTheFront(&head, -2);
	
	insertAtTheEnd(&head, 4);
	insertAtTheEnd(&head, 5);
	
	insertAfter(head, 69);
	insertAfter(second, 96);
	printList(head);
} 
