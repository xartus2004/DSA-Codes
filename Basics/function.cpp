//CONTENTS
/*
1.Function Declaration and Definition
2.Default Arguments
3.Inline Function
*/




#include <iostream>
using namespace std;

//If we want to define a variable after the main() function we have to first declare it before main()

// int getmax (int x, int y):      //Declaration of function
// int main()
// {
//     int a=10, b = 20;
//     cout << getmax(a, b);
//     return 0;
// }
// int getmax (int x, int y)       //Definition of function
// {
//     if(x>y)
//       return x;
//     else
//       return y;
// }

//Default Arguments


// When a particular argument is not provided it uses the default argument
//**NOTE** Always assigned from right to left
// void printDetails(int id,string name="NA",string address="NA")
// {
//     cout<<id<<"\n"<<name<<"\n"<<address<<"\n";
// }
// int main()
// {
//     printDetails(101,"Sandeep","noida");
//     cout<<"\n";
//     printDetails(201,"Sriram");
//     cout<<"\n";
//     return 0;
// }


//Inline Funtion
//This prevents the creation of function call stack by replacing the function call with the code in the function itself
//Its helpful for small functions


//MACROS
//      #define <Name of macro> <code>;


//Inline vs Macros
//Inline is better than macros
/*
1. There is no type checking in macros
2. Macros blindly put the values resulting into wrong output
*/
// #define add(x,y) x+y
//  int main()
//     cout << 4 * add(10, 20);    //4*10+20  But we wanted 120((10+20)*4)
//     return 0;

/*
INLINE FUNCTION
1. Inline is just a suggestion to the compiler.
2. Modern compilers may make a function inline even
   if we do not use inline.
3. Using inline too much may increase the binary file size.
4. When we define a method inside a class, it is automatically
   treated as inline suggestion to the compiler.

*/

//FUNCTION OVERLOADING
//Same name of funtions but different implementations depending upon the arguments passed
// void print(int a)
// {
//     cout<<a<<"\n";
// }
// void print(string s)
// {
//     cout<<s<<"\n";
// }
// void print(char c)
// {
//     cout<<c<<"\n";
// }
// int main()
// {
//     print(5);
//     print('a');
//     print("paranjay");
//     return 0;
// }

//This kind of case will call an error in which the compiler can't decide a single funtion of the same name for a particular datatype
// void print(int a)
// {
//     cout<<a<<endl;
// }
// void print()
// {

// }
// int main()
// {
//     print();
//     return 0;
// }

