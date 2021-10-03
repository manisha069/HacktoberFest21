#include<bits/stdc++.h>
using namespace std;

/*Binary Search algorithm searches for an element in a sorted array
by repeatedly dividing the array into two halves.*/


int binarySearch(int arr[], int left, int right, int element)
{
	if(right>=left)
	{
		int mid = left + (right-left)/2; 

		//If element is present at the middle return mid
		if(arr[mid] == element) 						
			return mid;

		//If element is smaller than middle element then search for the element in left subarray
		if(arr[mid] > element)                 				
			return binarySearch(arr,left,mid-1,element);

		//Else search in right subarray
		return binarySearch(arr,mid+1,right,element);

	}
	//If element is not found then return -1
	return -1;
}

int main()
{
	int size;
	cin>>size;
	int arr[size];
	for(int i=0;i<size;i++){
		cin>>a[i];
	}
	int element = 12;

	int result = binarySearch(arr,0,size-1,element);
	if(result==-1)
		cout<<"Element is not present in array"<<endl;
	else
		cout<<"Element is present at index "<<result<<endl;

	return 0;
}
