#include <iostream>
//Additional Library for Vectors
#include <vector>
using namespace std;
int main()
{
    //1.Declaration
    //  vector <datatype> vector-name;
    //  vector <datatype> vector-name(size);
    // vector <int> v;

    //2.Size
    // cout<<  v.size();

    //3.Resize
    //  v.resize(newsize);
    // v.resize(8);

    //4.Capacity
    // v.capacity();
        //  capacity  >= size
    //capacity increases in the powers of 2 (1,2,4,8,16,32,64,...)
    //**NOTE**-This will happen only when we increase the size of our array one by one 
    //If we do v.resize(10) it is not necessary that its capacity will be 16. IT IS COMPILER DEPENDENT
    //e.g. if we add 5 elements to a vector its size will become 5 but its capacity will be 8
    
    //Capacity doesn't reduces even after reducing the size


    //5.Add Elements

    //  v.push_back(element);
    // v.push_back(8);     //push element at the end

    //v.insert(position,element)
        //position is relative to position of first element 
        // To insert element in between a vector
    // v.insert(v.begin()+2 , 5);
    //Before:   2|3|4
    //After :   2|3|5|4

    //6.Deletion
    // v.pop_back();    //Deletes last element
    //v.erase(position)
        //relative to start/end position of vector
    // v.erase(v.end()-2);
    //Before :   2|3|5|4
    //After  :   2|3|4 

    

    return 0;
}