//Used for lossless compression
//Variable Length Coding
//Greedy Idea: Most Frequent character has smallest code
//Condition for Decompression: No code should be prefix of another code


//Optical Merge Pattern
#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int freq;
    char ch;
    Node *left,*right;
    Node(int f,char c,Node *l=NULL ,Node *r=NULL)
    {
        freq=f;
        c=ch;
        left=l;
        right=r;
    }
};

struct compare{
    bool operator()(Node* l,Node* r)
    {
        return l->freq < r->freq;
    }
};

void PrintHCodes(int arr[], int freq[],int n)
{
    priority_queue<Node*,vector<Node*>,compare> h;

    for(int i=0 ; i<n ; i++)
        h.push(new Node(arr[i],freq[i]));

    while(h.size()>1)
    {
        Node* l=h.top(); h.pop();
        Node* r=h.top(); h.pop();
        Node* node=new Node(l->freq+r->freq,'$',l,r);
        h.push(node);
    }

}

void printCodes(Node* root,string str)
{
    if(root->ch!='$')
    {
        cout<<root->ch<<" "<<str<<"\n";
        return;
    }
    printCodes(root->left,str+"0");
    printCodes(root->right,str+"1");
}

int main()
{
    
}