#pragma once
#include <iostream>
#include <vector>
class LinkedList
{
private: 
	struct node {
		int value;
		int occ;
		node* next;

		//using a struct constructor to make it easier to add nodes when adding elements to the LL
		node(int value, int occurance) : value(value), occ(occurance), next(nullptr){}
	};
	//initiaize the head of list
	node* head;
	int size=0;

public:
	LinkedList();
	void insert(int);
	void removeNode(int);
	void printList();
	void vectoLL(const std::vector<int>&);
	int sumOfNodes();
};

