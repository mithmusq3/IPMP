#include<bits/stdc++.h>
using namespace std;
int c1=0,c2=0,c3=0;
struct Node
{
 int data;
 struct Node* next;
 Node(int data){
     this->data=data;
     next=NULL;
 }
}*head = NULL,*Head = NULL;

void push(struct Node** top,int data){
   
    Node* newnode = new Node(data);
    newnode->next = *top;
    *top = newnode;

}
void Sorting(struct Node** head){

    struct Node* curr;
    struct Node* prev;
    struct Node* end;
    struct Node* new_end=NULL;
    curr=*head;
    while(curr!=NULL){
     end=curr;
     new_end=curr->next;
     curr=curr->next;
    }

    prev=NULL;
    curr=*head;
    while(curr!=end){

     if((curr->data)%2==0){
         prev=curr;
         curr=curr->next;
     }
     else if((curr->data)%2==1){
          prev->next=curr->next;
          curr->next=new_end;
          end->next=curr;
          new_end=curr;
          curr=prev->next;
     }
     //Look at odd numbers order carefully 
    }

}
void Print(struct Node* top){
 struct Node * temp;
 temp = top;
 while(temp!=NULL){
     cout<<temp->data<<" -> ";
     temp=temp->next;
 }
 cout<<" NULL \n";
}
int main(){
   int n,data;
   cout<<"Enter the number of data u r gonna entry: ";
   cin>>n;
   cout<<"\nEnter the data: \n";

   for(int i=0;i<n;i++){
   cin>>data;
   push(&head,data);
   }
   cout<<"\n";
   Print(head);
   cout<<" \tSorting \n";
   
   Sorting(&head);
   Print(head);
   return 0;
}