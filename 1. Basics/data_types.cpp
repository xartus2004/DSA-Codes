#include <iostream>
using namespace std;

//Data Types
/*Primitive Data Types:
    Integer Types:
        short,int,long,long long,unsigned short,unsigned int,unsigned long,unsigned long long
    Character Types:
        char,unsigned char,wchar.t,char8.t,char16.t,char32.t
    Floating Type:
        float,double,long double
    Others:
        bool,void
Non-Primitive Types
    Arrays,pointers,User Defined(class and struct),string,vectors

*/


// Global Variables

// int x;      //Global Variable
// int main()
// {
//     int y;      //Local Variable
//     cout<<x<<endl;  //for global variable it takes value 0  ->    x=0
//     cout<<y<<endl;  //for local variable it takes garbage value ->  x=undefined value  **garbage value in most compilers*
//     return 0;
// }

//defining a global variable after using it

// extern int x;
// int main()
// {
//     cout<<x;
//     return 0;
// }

//scope of variables

// int x=10;
// int main()
// {
//     int x=20;
//     {
//         int x=30;    //in a particular scope the local variable is given higher precedence
//         cout<<x<<endl;      //30
//         cout<<::x<<endl;    //10    this is SCOPE RESOLUTION OPERATOR
//     }
// }

//only one variable with the same name can be defined in a particular scope
/*
  ->  functions,loops and conditional statements create a new scope
  ->  we can create a new scope by using curly brackets
*/

//Static Variables
/*
->  static local variables are created once and stay for lifetime of a program
->  static data members of a class are shared by all objects
->  static methods of a class can access only static data
->  staic global variables have internal linkage
*/


//const keyword


// int main()
// {
//     const int x=10;
//     x=x+1;          //  compiler error
//     return 0;
// }

//auto keyword

// int main()
// {
//     auto i=2.34;        //This automatically sets the datatype according to input(double in this case)
//     return 0;
// }


//  Literals

// int main()
// {   
//     cout << "Prefixes in Integer Literals\n" ; 
// 	{
//     	int a = 20 ;  //Decimal
//     	int b = 0x1A; //Hexadecimal
//     	int c = 016;  //Octal
//     	int d = 0b11; //Binary
//     	cout << a << "\n"
//     	     << b << "\n"
//     	     << c << "\n"
//     	     << d << "\n";
// 	}
// 	cout << "Suffixes in Integer Literals\n";
// 	{
// 	    int a = 124;
// 	    unsigned b = 124u;
// 	    long int c = 124L;
// 	    long long int d = 124LL;
// 	    cout << a << "\n"
// 	         << b << "\n"
// 	         << c << "\n"
// 	         << d << "\n";
// 	}
// 	cout << "Floating Point Literals\n";
// 	{
// 	    float  a = 10.5f;
// 	    double b = 10.515;
// 	    float  c = 2.1e15f;
// 	    double d = 200.1e-60;
// 	    double f = 0x1A.1p2;
// 	    cout << a << "\n"
//     	     << b << "\n"
//     	     << c << "\n"
//     	     << d << "\n"
//     	     << f << "\n"; 
// 	}
// 	cout << "Character and String Literals\n";
// 	{
// 	    char c = 'g';
// 	    const char *s1 = "gfg";
// 	    string s2 = "courses";
// 	    cout << c  << "\n"
// 	         << s1 << "\n"
// 	         << s2 << "\n";
// 	}
// 	return 0;
// }
void dataTypes(int a, float b, double c, long long l, string d)
{
    cout<<b/c<<" ";
    cout<<b/a<<" ";
    int fin=c/a;
    cout<<fin<<" ";
    l=(int)fin+(int)c;
    cout<<(int)l<<endl;
    cout<<d<<" "<<d[3];
}

int main()
{
    dataTypes(5,6.2,8.54,5.36,"paranjay");
    return 0;
}
