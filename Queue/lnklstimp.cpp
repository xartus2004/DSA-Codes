#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) {
        data = d;
        next = NULL;
    }
};

struct MyQueue {
    Node* start;
    Node* end;
    int sz;

    MyQueue() {
        start = NULL;
        end = NULL;
        sz = 0;
    }

    ~MyQueue() {
        while (start != NULL) {
            pop();
        }
    }

    void push(int n) {
        Node* temp = new Node(n);
        if (start == NULL) {
            start = end = temp;
        } else {
            end->next = temp;
            end = temp;
        }
        sz++;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Queue is empty! Cannot pop.\n";
            return;
        }
        Node* temp = start;
        start = start->next;
        if (start == NULL) {
            end = NULL;
        }
        delete temp;
        sz--;
    }

    int front() {
        if (isEmpty()) {
            cout << "Queue is empty! No front element.\n";
            return -1;
        }
        return start->data;
    }

    bool isEmpty() {
        return start == NULL;
    }

    int size() {
        return sz;
    }

    void display() {
        Node* curr = start;
        while (curr != NULL) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

int main() {
    MyQueue q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.display();

    cout << "Front: " << q.front() << endl;
    q.pop();
    q.display();
    cout << "Size: " << q.size() << endl;

    q.pop();
    q.pop();
    q.pop();
    cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl; 

    return 0;
}
