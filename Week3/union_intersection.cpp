#include <iostream>
using namespace std;
bool isPresent(struct Node* head, int data);
void insert(struct Node** head_ref, int new_data);
struct Node {
   int data;
   struct Node *next;
};
struct Node* head = NULL;
struct Node* head3 = NULL;

void insert(struct Node** head2, int new_data) {
   struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
   new_node->data = new_data;
   new_node->next = *head2;
   *head2 = new_node;
}
void display(struct Node* head2) {
   struct Node* ptr;
   ptr = head2;
   while (ptr != NULL) {
      cout<< ptr->data <<" ";
      ptr = ptr->next;
   }
}

struct Node* getUnion(
    struct Node* head1,
    struct Node* head2)
{
    struct Node* result = NULL;
    struct Node *t1 = head1, *t2 = head2;
 
    while (t1 != NULL) {
        insert(&result, t1->data);
        t1 = t1->next;
    }
 
    while (t2 != NULL) {
        if (!isPresent(result, t2->data))
            insert(&result, t2->data);
        t2 = t2->next;
    }
    return result;
}

struct Node* getIntersection(struct Node* head1,
                            struct Node* head2)
{
    struct Node* result = NULL;
    struct Node* t1 = head1;
 
    while (t1 != NULL) {
        if (isPresent(head2, t1->data))
            insert(&result, t1->data);
        t1 = t1->next;
    }
    return result;
}
 

 
void printList(struct Node* node)
{
    while (node != NULL) {
        cout << " " << node->data;
        node = node->next;
    }
}
 
bool isPresent(struct Node* head, int data)
{
    struct Node* t = head;
    while (t != NULL) {
        if (t->data == data)
            return 1;
        t = t->next;
    }
    return 0;
}
 
int main() {
   insert(&head,3);
   insert(&head,1);
   insert(&head,7);
   insert(&head,2);
   insert(&head,9);
   cout<<"The linked list is: ";
   display(head);
   cout<<endl;
   cout<<"The linked list is: ";
   insert(&head3,5);
   insert(&head3,7);
   insert(&head3,8);
   insert(&head3,0);
   insert(&head3,9);
   display(head3);

    struct Node* intersecn = NULL;
    struct Node* unin = NULL;

    intersecn = getIntersection(head, head3);
    unin = getUnion(head, head3);
    cout<<endl;
    cout<<"The linked list intersection: ";
    display(intersecn);
    cout<<endl;
    cout<<"The linked list union: ";
    display(unin);


   return 0;
}
