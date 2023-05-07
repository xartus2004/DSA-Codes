#include <iostream>
#include <queue>
using namespace std;


//Binary Tree Implementation


/*
This is implemented similar to Linked List and its nodes have key left and right where key is its data and left and right are pointers to left and right nodes of the tree
*/

struct Node
{
    int key;
    Node *left;
    Node *right;
    Node(int x)
    {
        key=x;
        left=right=NULL;
    } 
};

//Traversal
/*
1.Inorder       :left root right
2.Preorder      :root left right
3.Postorder     :left right root
*/

void inorder(Node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);
    }
}
//auxiliary space   : h+1  O(h) where h is height of binary tree
//teme complexity   : O(n)

void preorder(Node *root)
{
    if(root!=NULL)
    {
        cout<<root->key<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
//auxiliary space   : h+1  O(h) where h is height of binary tree
//teme complexity   : O(n)

void postorder(Node *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->key<<" ";
    }
}
//auxiliary space   : h+1  O(h) where h is height of binary tree
//teme complexity   : O(n)

//Height of binary tree

int height(Node* root)
{
    if(root==NULL)
        return 0;
    else
        return max(height(root->left),height(root->right))+1;
}

//auxiliary space   : h+1  O(h) where h is height of binary tree
//teme complexity   : O(n)

//Print Nodes at K distance

void PrintKDist(Node *root,int k)
{
    if(root==NULL)
        return;
    if(k==0)
        cout<<root->key<<" ";
    else
    {
        PrintKDist(root->left,k-1);
        PrintKDist(root->right,k-1);
    }

}

//auxiliary space   : h+1  O(h) where h is height of binary tree
//teme complexity   : O(n)

//Level order search(Breadth first search BFS)

void PrintLevel(Node *root,int k)
{
    if(root==NULL)
        return;
    queue <Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node *curr=q.front();
        q.pop();
        cout<<curr->key;
        if(curr->left!=NULL)
            q.push(curr->left);
        if(curr->right!=NULL)
            q.push(curr->right);
    }

}

//Time Complexity:  O(n)

//Auxiliary Space:  O(n)
/*
For more detailed analysis
for a tree like:                            1
                                            |
                                            v
                                            2
                                            |
                                            v
                                            3
                            Auxiliary Space will be theta(1)
But for a Prefect tree the number of nodes on the last level will be (n+1)/2 hence Auxiliary Space be theta(n) in worst case.    
*/

/*
A tree in which each node has an equal number of child nodes is called a "perfect tree". In a perfect tree, all leaf nodes are at the same level and the number of total nodes is equal to 2^(height+1)-1, where height is the number of levels in the tree.
*/

//If we would use height of a tree and run a loop to print nodes at each level the time complexity will become O(n + n*h) i.e. O(n*h)


//Level Order traversal line by line

void PrintLevelLine(Node *root,int k)
{
    if(root==NULL)
        return;
    queue <Node*> q;
    q.push(root);
    q.push(NULL);
    while(q.size()>1)
    {
        Node *curr=q.front();
        q.pop();
        if(curr==NULL)
        {
            cout<<"\n";
            q.push(NULL);
            continue;
        }
        cout<<curr->key;
        if(curr->left!=NULL)
            q.push(curr->left);
        if(curr->right!=NULL)
            q.push(curr->right);
    }

}

//Time Complexity:  O(n)

//Auxiliary Space:  O(n)


void PrintLevelLine2(Node *root)
{
    if(root==NULL)
        return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        int count=q.size();

        for(int i=0 ; i<count ; i++)
        {
            Node*curr=q.front();
            q.pop();
            cout<<curr->key<<" ";
            if(curr->left!=NULL)
                q.push(curr->left);
            if(curr->right!=NULL)
                q.push(curr->right);
        }
        cout<<"\n";
    }
}

//Size of Binary tree

int getSize(Node* root)
{
    if(root==NULL)
        return 0;
    else
        return getSize(root->left)+getSize(root->right)+1;
}

//Time Complexity:  O(n)

//Auxiliary Space:  O(h)


//Maximum in Binary Tree

int getMax(Node* root)
{
    if(root==NULL)
        return INT32_MIN;
    else
        return max(root->key , max( getMax(root->left) , getMax(root->right) ));
}

//Printing left view of the Binary tree
int maxLevel=0;
void PrintLeft(Node *root,int level)
{
    if(root==NULL)
        return;
    if(maxLevel<level)
    {
        cout<<(root->key);
        maxLevel=level;
    }
    PrintLeft(root->left,level+1);
    PrintLeft(root->right,level+1);
}


//Iterative solution

void PrintLeft2(Node *root)
{
    if(root==NULL)
        return;
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty())
    {
        int count=q.size();
        for(int i=0 ; i<count ; i++)
        {
            Node *curr=q.front();
            q.pop();
            if(i==0)
                cout<<(curr->key)<<" ";
            if(curr->left!=NULL)
                q.push(curr->left);
            if(curr->right!=NULL)
                q.push(curr->right);
        }
    }
}

//Children Sum Property
//any node is sum of its children nodes

//Consider all possible cases at each stage

bool ChildSum(Node *root)
{
    if(root==NULL)
        return true;
    if(root->left==NULL && root->right==NULL)
        return true;
    int sum=0;
    if(root->left!=NULL)
        return sum+=(root->left->key);
    if(root->right!=NULL)
        return sum+=(root->right->key);

    return (root->key==sum && ChildSum(root->left) && ChildSum(root->right));
}

//Balaced Binary Tree
/*
In a Balanced Binary Tree for every node, the difference between heights of left subtree and right subtree should not be more than one.
*/

