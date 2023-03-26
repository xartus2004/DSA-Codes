#include <iostream>
using namespace std;
//LINKED LIST
/*This is a NON-CONTIGUOUS data structure which makes deletion and insertion efficient

    |10| -> |20|-> |20|-> |20|-> |20|-> NULL
    head    nodes
Each node is stored at different locations and they contain the address of their child node
*/
 
 //SINGLY LINKED LIST

 struct Node
 {
    int data;
    Node* next;
    Node(int x)
    {
        data=x;
        next=NULL;
    }
 };

 //Traversal

 void printList(Node* head)   //This head is different from the head given as argument
 {
    Node* curr = head;
    while(curr!=NULL)
    {
        cout<<(curr->data)<<" ";
        curr=curr->next;
    }
 }

 //Recursive Traversal

 int* rprintlst(Node* head)
 {
    if(head==NULL)
        return;                     //Return NULL
    cout<<head->data<<" ";
    rprintlst(head->next);
 }

 //Insertion at beginning

 Node* insbegin(Node* head , int x)
 {
    Node* temp=new Node(x);
    temp->next=head;
    return temp;
 }

 //Insertion at end

Node* insend(Node* head,int x)
{
   Node* temp=new Node(x);
   if(head==NULL)
      return temp;
   Node* curr=head;
   while(curr->next!=NULL)
      curr=curr->next;
   curr->next=temp;
   return head;
}

//Deletion of First Node

void delstart(Node* head)
{
   if(head==NULL)
      return;
   Node* temp=head;
   head=head->next;
   delete temp;
   return;
}

//Deletion at the End

void delend(Node* head)
{
   if(head==NULL)
      return;
   Node* curr=head;
   while(curr->next->next!=NULL)
      curr=curr->next;
   delete curr->next;
   curr->next=NULL;
   return;
}
//Here we take two instance because to set the address of next pointer of the second last node as null we need to set the address of last node as null in the second last node
//The second last node contains the address of the last element not the last element itself

//Insertion

Node* insert(Node* head,int x,int pos)
{
   Node* temp=new Node(x);
   if(pos==1)
   {
      temp->next=head;
      return temp;
   }
   Node* curr=head;
   for(int i=0 ; i<pos-2 && curr!=NULL ; i++)
   {
      curr=curr->next;
   }
   if(curr==NULL)    //This checks if the position we are trying to add element even exits!!!
      return head;
   temp->next=curr->next;
   curr->next=temp;
   return head;
}

//Searching

   //Iterative

int ISearch(Node* head,int x)
{
   Node* curr=head;
   int pos=1;
   while(curr!=NULL)
   {
      if(curr->data==x)
         return pos;
      else
      {
         pos++;
         curr=curr->next;
      }
   }
   return -1;
}

   //Recursive

int search(Node* head,int x)
{
   if(head==NULL)
      return -1;
   if(head->data==x)
      return 1;
   else
   {
      int res=search(head->next,x);
      if(res==-1) return -1;
      else return res+1;
   }
}

 int main()
 {
    // Node* head=new Node(10);
    // Node* temp1=new Node(20);
    // Node* temp2=new Node(30);
    // head->next=temp1;
    // temp1->next=temp2;

    //Cleaner Method
     
    Node* head=new Node(10);
    head->next=new Node(20);
    head->next->next=new Node(30);
    head->next->next->next=new Node(40);
    printList(head);

    //Insertion

    head=insbegin(head,30);
    head=insbegin(head,20);
    head=insbegin(head,10);

    //It is stores in reverse 
    //e.g. The above lines create the linked list   10 -> 20 -> 30


 }
 