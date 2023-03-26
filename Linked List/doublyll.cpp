#include <iostream>
using namespace std;
//List is linked to both previous and after elements
/*
Advantages
1.Can be traversed in both directions
2.A given delete a node in O(1) time with given reference/pointer to it
3.Insert/Delete before a given node
4.Insertion and deletion from both end in O(1) time by maintaining tail

Disadvantages
1.Extra space for prev
2.Code becomes more complex

*/
struct Node
{
    int data;
    Node* prev;
    Node* next;
    Node(int x)
    {
        data=x;
        prev=NULL;
        next=NULL;
    }
};

//Insertion at Beginning
Node* insbegin(Node* head,int x)
{
    Node* temp=new Node(x);
    temp->next=head;
    if(head!=NULL)
        head->prev=temp;
    return temp;
}

//Reversing a DLL
// Node* reverse(Node* head)
// {
//     if(head==NULL !! (head->next)==NULL)
//         return head;
//     Node *temp=NULL;
//     Node *curr=head;
//     while(curr!=NULL)
//     {
//         temp=curr->prev;
//         curr->prev=curr->next;
//         curr->next=temp;
//         curr=curr->prev;

//     }
// }
Node* reverse(Node*head)
{
    Node*temp=NULL;
    Node*curr=head;
    while(curr!=NULL)
    {
        temp=curr->prev;
        curr->prev=curr->next;
        curr->next=temp;
    }
    if(temp!=NULL)          //This condition is put for dll which have 0 or 1 element
        head=temp->prev;
    return head;
}

void printlist(Node *head){
    Node *curr=head;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr=curr->next;
    }cout<<endl;
}

//Deleting head of a doubly linked list

Node* delbegin(Node*head)
{
    Node *temp=head;
    (head->next)->prev=NULL;
    delete temp;
    return head->next;
}

//Deleting from end
void delend(Node*head)
{
    Node *curr=head;
    while(curr->next!=NULL)
    {
        curr=curr->next;
    }
    (curr->prev)->next=NULL;
}

//Insert at End

void insend(Node* head,int x)
{
    Node* temp=new Node(x);
    Node* curr=head;
    while(curr->next!=NULL)
    {
        curr=curr->next;
    }
    curr->next=temp;
    temp->prev=curr;
}

int main()
{
    Node* head=new Node(10);
    Node* temp1=new Node(20);
    Node* temp2=new Node(30);
    // Node* reverse(Node* head)
// {
//     if(head==NULL !! (head->next)==NULL)
//         return head;
//     Node *temp=NULL;
//     Node *curr=head;
//     while(curr!=NULL)
//     {
//         temp=curr->prev;
//         curr->prev=curr->next;
//         curr->next=temp;
//         curr=curr->prev;

//     }
// }
    head->prev=NULL;
    head->next=temp1;
    temp1->prev=head;
    temp1->next=temp2;
    temp2->prev=temp1;
    printlist(head);
    // head=delbegin(head);
    // delend(head);
    insend(head,40);
    printlist(head);
}