#include <iostream>
using namespace std;
struct node
{
    int data;
    node* next;
    node(int d)
    {
        data=d;
        next=NULL;
    }
};
struct MyStack
{
    node* head;
    int sz=0;
    MyStack()
    {
        head=NULL;
        sz=0;
    }
    void push(int x)
    {
        node* temp=new node(x);
        temp->next=head;
        head=temp;
        sz++;
    }
    
}