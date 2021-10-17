/*
write a programe to sort an array using quicksort and partition mathod in c++
*/

#include<bits/stdc++.h>
using namespace std;
//partition method
int partition(int arr[], int l, int h){
        int pivot=arr[l];
        int i=l;// l means low
        int j=h;//h means high
        int temp1;
        while(i<j){
            while(arr[i]<=pivot &&i<h)  // If current element is smaller than or equal to pivot and i less then high
            i++;
            while(arr[j]>pivot && j>l)  // If current element is greater than to pivot and j greater then low
            j--;
            if(i<j)
            {
                //swap arr[i] and arr[j]
            temp1 = arr[i]; 
            arr[i] = arr[j]; 
            arr[j] =temp1;}
        }
        // swap arr[i] and arr[j]
        int temp2 = arr[j]; 
        arr[j] = arr[l]; 
        arr[l] = temp2;

        return j;
    }
   void quicksort(int arr[],int l,int h)
    {
    if(l<h) {
        int povit=partition(arr, l, h);//initialize pivot element which returns partition function
        quicksort(arr,l,povit-1);
        quicksort(arr, povit+1, h);
    }
    }
int main() 
  { 
    int n;
    cout<<"enter the size of the array : ";
    cin>>n;
    int arr[n];
    cout<<"enter array element : ";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
        quicksort(arr, 0, 5);
        cout<<"array after quick sort : ";
        for(int j = 0; j <n; j++) {
            cout<<(arr[j])<<" ";
        }
        
    return 0;
}
