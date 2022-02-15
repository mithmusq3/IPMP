#include <bits/stdc++.h>
using namespace std;

class Node
{
	public:
	int data;
	Node* next;
};

void printReverse(Node* head)
{
	if (head == NULL)
	return;

	printReverse(head->next);

	cout << head->data << " ";
}

void push(Node** head_ref, char new_data)
{
	Node* new_node = new Node();

	new_node->data = new_data;

	new_node->next = (*head_ref);

	(*head_ref) = new_node;
}

int main()
{
	Node* head = NULL;
	push(&head, 22);
	push(&head, 33);
	push(&head, 55);
	push(&head, 66);
	
	printReverse(head);
	return 0;
}

