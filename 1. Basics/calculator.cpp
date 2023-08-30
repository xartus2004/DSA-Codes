#include <iostream>
using namespace std;
int main()
{
    int m,n1,n2;
    cout<<"Enter first number: ";
    cin>>n1;
    cout<<"Enter second number: ";
    cin>>n2;
    cout<<"For Addition Press 1 \nFor subtraction Press 2 \nFor Multiplication Press 3 \nFor Division Press 4 \n";
    cin>>m;
    if (m==1)
        cout<<"The Addition of "<<n1<<" and "<<n2<< " is "<<n1+n2;
    else if (m==2)
        cout<<"The subtraction of "<<n1<<" and "<<n2<< " is "<<n1-n2;
    else if (m==3)
        cout<<"The Multiplication of "<<n1<<" and "<<n2<< " is "<<n1*n2;
    else if (m==4)
        cout<<"The Division of "<<n1<<" and "<<n2<< " is "<<n1/n2;
    return 0;
}