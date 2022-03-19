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
void Sorting(){
    struct Node* temp;
    temp=head;
    while(temp!=NULL){
     if(temp->data==0){
     c1++;
     }
     else if(temp->data==1){
     c2++;
     }
     else if(temp->data==2){
     c3++;
     }
     temp=temp->next;
    }
    for(int i =0;i<c3;i++){
        push(&Head,2);
    }
    for(int i =0;i<c2;i++){
        push(&Head,1);
    }
    for(int i =0;i<c1;i++){
        push(&Head,0);
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
   
   Sorting();
   Print(Head);
   return 0;
}