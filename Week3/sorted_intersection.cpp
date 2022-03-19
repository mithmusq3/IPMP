#include<bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node* next;
};

void push(Node** head_ref, int new_data);

Node* sortedIntersect(Node* a, Node* b)
{
	Node dummy;
	Node* tail = &dummy;
	dummy.next = NULL;

	while (a != NULL && b != NULL) {
		if (a->data == b->data) {
			push((&tail->next), a->data);
			tail = tail->next;
			a = a->next;
			b = b->next;
		}
		else if (a->data < b->data)
			a = a->next;
		else
			b = b->next;
	}
	return (dummy.next);
}

void push(Node** head_ref, int new_data)
{
	Node* new_node = (Node*)malloc(
		sizeof(Node));

	new_node->data = new_data;

	new_node->next = (*head_ref);

	(*head_ref) = new_node;
}

void printList(Node* node)
{
	while (node != NULL) {
		cout << node->data <<" ";
		node = node->next;
	}
}

int main()
{
	Node* a = NULL;
	Node* b = NULL;
	Node* intersect = NULL;

	push(&a, 6);
	push(&a, 5);
	push(&a, 4);
	push(&a, 3);
	push(&a, 2);
	push(&a, 1);

	push(&b, 8);
	push(&b, 6);
	push(&b, 4);
	push(&b, 2);

	intersect = sortedIntersect(a, b);

	cout<<"Linked list containing common items of a & b \n";
	printList(intersect);
}
































// #include<iostream>
// using namespace std;
// struct LList{
//     int data;
//     struct LList *next;
// }*head1=NULL,*head3=NULL;
// LList *head2= NULL; 


// int main()
// {
// LList *l3;
// l3=new LList();
// l3=head3;
// char ch = 'y';
// int c1=0,c2=0,c3=0;
// for(int i =6; i>0;i--){
// LList* new_node = (LList*)malloc(sizeof(LList));
//  new_node-> data = i;
//  new_node->next = head1;
//  head1 = new_node;
//  c1++;
// }

// LList* l1;
// l1 = head1; 
// for(int i =6; i>0;i--,l1=l1->next){
// printf(" %d ",l1->data);
// }
// LList* new_node = (LList*)malloc(sizeof(LList));
//  new_node-> data = 8;
//  new_node->next = head2;
//  head2 = new_node;
//  LList* new_node2 = (LList*)malloc(sizeof(LList));
//  new_node2-> data = 6;
//  new_node2->next = head2;
//  head2 = new_node2;
//  LList* new_node3 = (LList*)malloc(sizeof(LList));
//  new_node3-> data = 4;
//  new_node3->next = head2;
//  head2 = new_node3;
//  LList* new_node4 = (LList*)malloc(sizeof(LList));
//  new_node4-> data = 2;
//  new_node4->next = head2;
//  head2 = new_node4;
//  c2=4;
// LList* l2;
// l2 = head2; 
// printf(" \n ");
//  for(int i =4; i>0;i--,l2=l2->next){
// printf(" %d ",l2->data);
// }
// l1 = head1; 
// l2 = head2; 
// printf(" \n ");

// //
// while(l1!=NULL||l2!=NULL)
//  { 
// printf(" bunda ");

//   if(l1->data == l2-> data){
//       printf(" bunda comein ");
//       LList* new_node = (LList*)malloc(sizeof(LList));
//         new_node-> data = l1->data;
//         new_node->next = NULL;
//       if(l3==NULL){
//        new_node->data=l1->data;
//        head3=new_node;
//        c3++;
//       printf(" bunda head ");
//       }
//       else{
        
//         l3->next=new_node;
//         l3=new_node;
//         c3++;
//       printf(" bunda tail ");

//       }
//   }
//   else if(l1->data < l2-> data){
//      l1=l1->next;
//   }
//   else{
//       l2=l2->next;
//   }
 

// }
//  printf(" \n ");
// printf(" %d ",c3);
//  for(int i =c3; i>0;i--){
// printf(" %d ",head3->data);
// head3=head3->next;
//  }
// return 0;
// }