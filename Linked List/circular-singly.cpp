#include<iostream>
using namespace std;
//Advantages of Circular Singly Linked list
/*
1.We can traverse the whole list from any node
2.Implementaion of algorithms like round robin
3.We can inset at the beginning or end just by maintaining one tail reference
*/
//Disadvantages of Circular Singly Linked list
//1.Implementation of functions becomes complex

//---------------------------------------------//
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
//---------------------------------------------//

//Print
void printLst(Node*head)
{
    Node *curr=head;
    do{
        cout<<curr->data<<"\t";
        curr=curr->next;
    }while(curr!=head);
}

//----------------------------------------------//
Node *insBegin(Node * head,int x)
{
    Node *temp=new Node(x);
    Node *curr=head;
    while(curr->next!=head)
        curr=curr->next;
    curr->next=temp;
    temp->next=head;
    return temp;
}

Node *insEnd(Node * head,int x)
{
    Node *temp=new Node(x);
    Node *curr=head;
    while(curr->next!=head)
        curr=curr->next;
    curr->next=temp;
    temp->next=head;
    return head;
}

Node *DelHead(Node *head)
{
    if(head==NULL) return NULL;
    if(head->next==head)
    {
        delete head;
        return NULL;
    }
    Node* curr=head;
    while(curr->next!=head)
    {
        curr=curr->next;
    }
    curr->next=head->next;
    delete head;
    return head->next;
}


int main()
{
    Node* head=new Node(10);
    Node* temp1=new Node(20);
    Node* temp2=new Node(30);
    head->next=temp1;
    temp1->next=temp2;
    temp2->next=head;
    printLst(head);
    head=DelHead(head);
    printLst(head);
    return 0;
}