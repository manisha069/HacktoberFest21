#include<iostream>
using namespace std;
int main()
{
int A[100],K=0,UB;
cout<<"Enter the Array size less than 100:";
cin>>UB; /* To enter the size of Array */
cout<<"Enter the elements in array: \n";
for(K=0;K<UB;K++)
{
cin>>A[K];
  /* Entering elments of 1-D Array*/
}
cout<<"The Traverse of array is:\n";
for(K=0;K<UB;K++)
{
cout<<A[K];
  /*Traversing the Array*/
}
return 0;
}
