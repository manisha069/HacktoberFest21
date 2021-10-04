// Array implemented in C++

#include <iostream>
using namespace std;
 
int main()
{
    // Integer array of size 10.
    int arr[10];
    
    // Taking input for array in a loop
    for (int i=0; i<10; i++){
      cin>>arr[i];
    }
    
    //Printing array values
    for (int i=0; i<10; i++){
      cout<<arr[i]<<" ";
    }
  
    return 0;
}
