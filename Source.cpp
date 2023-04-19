#include <iostream>
#include <vector>
#include "LinkedList.h"
using namespace std;

void insertAfter(vector <int>& ,int, int);
void printvec(vector <int>);

int main() {

	vector<int> myvec;
	int n,x;
	cout << "enter the number of integers you want to have: ";
	cin >> n;

	for (int i = 0; i < n; i++) {
		cout << "enter the element number " << i+1<<": ";
		cin >> x;
		myvec.push_back(x);
		cout << endl;
	}

	printvec(myvec);
	insertAfter(myvec, 3, 5);
	printvec(myvec);

	//the linked list part
	LinkedList mylist;
	
	mylist.insert(5);
	mylist.insert(6);
	mylist.insert(7);
	mylist.insert(5);
	
	cout << "the automatically inserted list is ";
	mylist.printList();

	mylist.removeNode(7);

	cout << "the list after removing 7 looks like this: ";
	mylist.printList();

	cout << "the sum of 5+6+5 is :";
	cout<<mylist.sumOfNodes();
	cout << endl;

	LinkedList veclist;
	veclist.vectoLL(myvec);
	cout << " the list that you put in your vector is: ";
	veclist.printList();

	return 0;
}

void insertAfter(vector <int>& myvec, int firstValue, int secondValue) {
	
	//using linear search 
	for (auto it = myvec.begin(); it != myvec.end(); ++it) {
		if (*it == firstValue) {
			it = myvec.insert(it + 1, secondValue);
		}
	}
}


void printvec(vector <int> v) {
	for (int x : v) {
		std::cout << x << " ";
	}
	cout << endl;
}