#include <iostream>
using namespace std;
template <typename tem>     //'class' keyword can be used in place of 'typename'
tem MyMax(tem x ,tem y)
{
    return (x>y)?x:y;
}
int main()
{
    //write once use for any datatype
    //like macros processed by compiler but better than macros as type checking is performed
    //Two types:
    //  1.Function Templates    :   sort,linear search,binary search
    //  Class Template  :   stacks,queue,deque
    //the main concept behind STL
    cout<<MyMax<int>(3,7)<<endl;        //while using the same datatype mentioning datatype is not necessary
    cout<<MyMax<char>('c','g')<<endl;
    cout<<MyMax<char>('c',90);
    return 0;
}
