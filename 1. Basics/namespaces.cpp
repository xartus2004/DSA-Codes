//NAMESPACE


//Namespace-a declarative region that provides a scope to the identifiers (the names of types, functions, variables, etc) inside it

//**Namespace is used in cpp because same name can't be given to multiple variables in same scope.**

#include <iostream>
using namespace std;  //**This is not a good practice as it can create conflicts**
using std::cout;      //**This is a good practice
using std::cin;
using std::endl;
//Defining a namespace
namespace n1
{
    int tv=100;
    string kv="Best";
}

namespace n2
{
    int tv=200;
    string kv="Worst";
}
int main()
{
    cout<<n1::tv<<"\n"<<n2::kv;
}



