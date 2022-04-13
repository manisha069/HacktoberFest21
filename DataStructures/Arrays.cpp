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
 
    //Insertion of element
    int k, j, n=10;
    cout<<"Enter the position where you want to insert the element:\n";
    cin>>k;
    cout<<"Enter the element you want to insert:\n";
    cin>>item;
    for(j=n;j>=k;j--)
    {
        arr[j+1]=arr[j];
    }
    arr[k]=item;
    n=n+1;
    cout<<"The new array after the insertion of element is:";
    for(i=1;i<=n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
