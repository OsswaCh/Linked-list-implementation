#include "LinkedList.h"

//by creating the list we define a new head to be a null pointer
LinkedList::LinkedList() {
	head = nullptr;
}

void LinkedList::insert(int x) {
	node* current = head; //this pointer is used to traverse the list
	node* aux = nullptr; //this pointer is used to keep track of other nodes

	
	// handling the case where the linked list is empty( add a new node to the front of the list,).
	//can't traverse the list to find the location where the new node should be inserted. Instead, we need to make the new node the head of the list.
	if (head == nullptr) {
		head = new node(x, 1);
		size++;
		return;
	}

	while (current != nullptr && current->value != x) {
		aux = current;
		current = current->next;
	}

	//if we found a node having the same value as the added node, we add to the occurance variable and not a new node
	if (current != nullptr) {
		current->occ++;
	}
	else {
		node* addnode = new node(x, 1);
		size++;
		//case of inserting in the head of the list 
		if (aux == nullptr) {
			head = addnode;
		}
		//generic case
		else {
			//update the the pointer of the previous node to the new node instead of nullptr
			aux->next = addnode;
		}
		//update the pointer of the new node
		addnode->next = current;
	}

	


}

void LinkedList::removeNode(int value) {
	
	// Check if the list is empty
	if (head == nullptr) {
		std::cout << "your list is empty";
		return;
	}
	
	//speacial case handeling: the head is the value
	if (head->value == value) {
		node* aux = head;
		head = head->next;
		delete aux;
		size--;
		return;
	}

	//normal case handeling
	node* aux = head;
	node* current = head ->next;
	//traverse the list and look for a similar value
	while (current != nullptr) {
		if (current->value == value) {
			//move the pointer of the to-be deleted node to the one next to it
			aux->next = current->next;
			delete current;
			size--;
			return;
		}
		//move the cuurent pointer to the node after it and the one after to the one following it
		aux = current;
		current = current->next;
	}

}

void LinkedList::printList() {
	
	node* current = head;

	//do a loop that keeps looping as long as the we didnt reach the end of the list (the null pointer)
	while (current != nullptr) {
		std::cout << current->value << " ";
		current = current->next;
	}
	std::cout << std::endl;

}


void LinkedList::vectoLL(const std::vector<int>& vec) {
	for (int element : vec) {
		insert(element);
	}
}

int LinkedList::sumOfNodes() {
	int sum = 0;
	node* current = head;
	//traverse the list by moving to the next node until we reach the null pointer (ned of list)
	while (current != nullptr) {
		sum += current->value;
		current = current->next;
	}

	return sum;
}