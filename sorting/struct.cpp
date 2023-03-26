#include <iostream>

//Syntax
//struct structure_tag
struct person
{
    int age;
    int height;
    int weight;
    //  int age,height,weight;

    //these age.height,weight are called data members

    //Structure memebers can't be initialized in C
    //But in Cpp they can be initialized so in case if we don't assign a value to a data member it will take default value

};  //remember this semicolon

//using typedef
typedef struct Point
{
    int x;
    int y;
}P;


int main()
{
    struct person p1={19,156,63};
    struct person p2;
    p2.age=21;
    p2.height=167;
    p2.weight=71;

    //struct keyword is not neccessary in cpp while creating 

    P p={1,2};

    //designated initialisation

    person p3={.height=154,.weight=82,.age=30};

    //Array of Structures

    person arr[10];
    arr[0].age=32;
    arr[0].height=159;
    arr[0].weight=76;

    //Structure Pointer

    person p4={24,155,57};
    person *ptr=&p4;
    cout<<ptr->age<<endl;
    ptr->height=157;
    cout<<ptr->height<<endl;

}