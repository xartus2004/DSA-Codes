//Implementation of queue using stack
#include <iostream>
#include <stack>

struct queue
{
    std::stack<int> s1, s2;

    void Enqueue(int x)
    {
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(x);

        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int Dequeue()
    {
        if(s1.empty())
        {
            std::cout<<"Queue is empty";
            return 0;
        }

        int temp=s1.top();
        s1.pop();
        return temp;
    }
};

int main()
{
    queue q;
    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    std::cout<<q.Dequeue();
    std::cout<<q.Dequeue();
    std::cout<<q.Dequeue();
}