#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
    node(int d) {
        data = d;
        next = NULL;
    }
};

struct MyStack {
    node* head;
    int sz;

    MyStack() {
        head = NULL;
        sz = 0;
    }

    ~MyStack() {
        while (head != NULL) {
            pop();
        }
    }

    void push(int x) {
        node* temp = new node(x);
        temp->next = head;
        head = temp;
        sz++;
    }

    void pop() {
        if (head == NULL) {
            cout << "Stack is empty! Cannot pop.\n";
            return;
        }
        node* temp = head;
        head = head->next;
        delete temp;
        sz--;
    }

    int top() {
        if (head == NULL) {
            cout << "Stack is empty! No top element.\n";
            return -1;
        }
        return head->data;
    }

    bool isEmpty() {
        return head == NULL;
    }

    int size() {
        return sz;
    }

    void display() {
        node* curr = head;
        while (curr != NULL) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

int main() {
    MyStack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    cout << "Top element: " << s.top() << endl;
    s.pop();
    s.display();
    cout << "Stack size: " << s.size() << endl;
    return 0;
}
