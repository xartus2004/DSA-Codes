#include <iostream>
#include <stack>
using namespace std;
//ritu raj 2022057 IMG
int main()
{
    int n;
    cout << "enter the size of the array " << endl;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cout << "enter the " << (i + 1) << "th element of the array:";
        cin >> arr[i];
    }
    stack<int> myst;
    stack<int> myst2;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            myst.push(arr[i]);
        }
        if (arr[i] == -1)
        {
            if (!myst.empty())
            {
                myst.pop();
                if (myst.size() == 0)
                {
                    cout << "noe the stack is empty" << endl;
                }
            }
            else
            {
                cout << "empty stack" << endl;
            }
        }
        else if (arr[i] == -2)
        {

            if (!myst.empty())
            {
                myst.top()++;
            }
            else
            {
                cout << "empty stack" << endl;
            }
        }
        else if (arr[i] == -3)
        {

            if (myst.size() >= 2)
            {
                int c = myst.top();
                myst.pop();
                c = c + myst.top();
                myst.pop();
                myst.push(c);
            }
            else
            {
                cout << "the -3 operation can not be done here " << endl;
            }
        }
    }
    while (!myst.empty())
    {
        cout << myst.top() << endl;
        myst.pop();
    }

    return 0;
}
// Question - you are given an array do this for each index of loop 

// 1 if elemnt is positive push it on stack 

// 2. If element is -1 pop the top 

// 3.if element is -2 increment the top element by one

// 4. If element is -3 pop the top 2 elements and push their sum