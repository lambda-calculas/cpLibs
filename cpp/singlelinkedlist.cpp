#include <bits/stdc++.h>
using namespace std;

#define pb push_back

class Node {
public:
	int value; //the value of this node
	Node *next;//pointer to the next element
};

void printLinkedList(Node* node) {
	while (node != NULL) {
		cout << node->value << "\n";
		node = node->next;
	}
	cout << endl;
}

void appendElement(Node* node, int data) {
	Node *temp = node;
	while (temp != NULL) {
		temp = temp->next;
	}
	//now at the end of the linked list
	temp->value = data; //append at the last
	temp->next = NULL; //next pointer is NULL
	//print a message that this node was addded to the linked list
	cout << "Node value  : " << data << "added to the linked list!!" << "\n";
}

void push(Node **head_ref, int data) {
	//insert a node at the beginning
	Node *temp = new Node();
	temp->value = data ;
	temp->next = *head_ref;
	*head_ref = temp ;

}

void deleteNode(Node *head , Node *n) {
	//when node to be deleted is head node
	if (head == n) {
		if (head->next == NULL) {
			cout << "Only one node to delete ; the list can't be empty" << endl;
			return ;
		}
		else {
			//1. copying the data of the next node to head
			head->value = head->next->value;
			//2. store address of next node
			n = head->next;
			//3 . REmove the link of next node
			head->next  = head->next->next;
			//4 .FInally free the memory
			free(n);
			return ;
		}

	}
	//when not first node ,then normal deletion
	//find the previous node
	Node *prev = head;
	while (prev->next != NULL && prev->next != n ) {
		prev = prev->next;
	}
	//check if the node really exists in Linked list 
	if(prev->next==NULL){
		cout << "Given node is node present in linked list\n ";
		return ;
	}
	//remove node from linked list 
	prev->next= prev->next->next;
	//free memory 
	free(n);
	return ;
}

int main() {
	Node* head =NULL; 

	cout <<"Enter the size of the linked list : "<<"\n";
	int n ;
	cin >>n ;

	vector<int> arr;
	while(n--){
		int a ;
		cin >> a ;
		arr.pb(a);
	}
	for(size_t i=0;i<arr.size();i++){
		push(&head,arr[i]);
	}

	cout << "The given linked list : ";
	printLinkedList(head);

	//let the node to be deleted by the 2nd one 
	cout << "Deleting 2nd node "<<'\n';
	deleteNode(head,head->next->next);

	cout <<"Modified linked list :";
	printLinkedList(head);

	//let us delelte first node 
	cout << "Deleting first node ";
	deleteNode(head,head);
	cout <<"Modified linked list ";
	printLinkedList(head);
	return 0;
}