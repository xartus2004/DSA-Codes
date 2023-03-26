#include <iostream>
using namespace std;

//CONTENTS
//1.Print 1 to n using recursion
//2. Print 1 to n using recursion
//3.factorial
//Tail Recursion
//4.fibonacci Series
//Base Cases
//5.Natural Number Sum using Recursion




//1.Print 1 to n using recursion


// void rev(int a)
// {
//     if(a==0)
//         return;
//     cout<<a<<" ";
//         rev(a-1);
// }
// int main()
// {
//     int n;
//     cout<<"Enter a number: ";
//     cin>>n;
//     rev(n);
// }

//2. Print 1 to n using recursion


// void rev(int a)
// {
//     if (a<1)
//         return;
//     rev(a-1);
//     cout<<a<<" ";
// }
// int main()
// {
//     int n;
//     cout<<"Enter a number: ";
//     cin>>n;
//     rev(n);
// }

//Tail Recursion- A recursion where the parent call has nothing to do after the child call is finished

//3.factorial

// int fac(int a)
// {
//     if(a<1) return 1;
//     return a*fac(a-1);
// }
// int main()
// {
//     int n;
//     cout<<"enter a number: ";
//     cin>>n;
//     cout<<"the factorial is: "<<fac(n);
// }

//4.fibonacci Series

// int fib(int n)
// {
//     if (n <= 1)
//         return n;
//     return fib(n - 1) + fib(n - 2);
// }
 
// int main()
// {
//     int n,i;
//     cout<<"enter the number of times you want to print fibo series: ";
//     cin>>n;
//     for (i=0;i<=n;i++)
//     {
//         cout<<fib(i)<<" ";
//     }
//     return 0;
// }

/*BASE CASES -Base case is something which halts your recursion to go deeper.
If you don't have a valid base case then your recursion may results in infinite loop.

e.g. the termination condition of loop in the program of factorial when recursive call reaches to 0 or a lesser number so that the program doesn't halts.
*/

//5.Natural Number Sum using Recursion

// int natu(int n)
// {
//     if (n==0) return 0; 
//     return n+natu(n-1);
// }
// int main()
// {
//     int a;
//     cout<<"enter the number of natural numbers: ";
//     cin>>a;
//     cout<<"the sum is: "<<natu(a);
// }

//6. Palindrome
// int main()
// {
//     string x=NULL,y=NULL;
//     cout<<"enter a string or not : ";
//     cin>>x;
//     int len=sizeof(x)/sizeof(x[0]);

//     for(int i=len-1 ; i>=0 ; i--)
//     {
//         y=y+x[i];   
//     }
//     cout<<y;
//     if (x==y) 
//         cout<<"Its a palindrome";
//     else 
//         cout<<"Its not a palindrome";
// }
