#include <iostream>
using namespace std;
// int main()
// {
//     //Process of input and output
//     //  Input device---->Buffer---->Process---->Buffer---->Output Device
    
//     //STREAM
//     //stream is an abstraction of a construct that allows you to send or receive an unknown number of bytes
//     //e.g. istream,ostream
//     //cin   :   object of istream     cout  :   object of ostream

// }

//IO Manipulation
int main()
{
    //BOOLEAN VALUE

    bool a=true;
    cout<<a<<"\n";              //1
    cout<<std::boolalpha;
    cout<<a<<"\n";              //true
    cout<<std::noboolalpha;
    cout<<a; 
    int x; 
    cin>>x;                  //1

    //INTEGER VALUES

    int a=26,b=20;
    cout<<a<<" "<<b<<"\n";      //26 20
    cout<<std::hex;
    cout<<a<<" "<<b<<"\n";      //1a 14
    cout<<std::oct;
    cout<<a<<" "<<b<<"\n";      //32 24
    cout<<std::dec;
    cout<<a<<" "<<b<<"\n";      //26 20
    return 0;

    //
}