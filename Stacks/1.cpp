#include <iostream>
using namespace std;

struct MyStack{
    int *arr;
    int cap;
    int top;
    MyStack(int c)
    {
        cap=c;
        arr=new int[cap];
        top=-1;
    }
    void push(int x)
    {
        top++;
        arr[top]=x;
    }
    int pop()
    {
        int rep=arr[top];
        top--;
        return rep;
    }
    int peek()
    {
        return arr[top];
    }
    int size()
    {
        return top+1;
    }
    int isEmpty()
    {
        return top==-1;
    }
};
