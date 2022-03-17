#include<iostream>
 
using namespace std;
 
void FibonacciSearch(int *a, int start, int end, int *fab, int index, int item)
{
	int i, mid;
 
	
	mid = start+fab[index-2];
 
	
	if(item == a[mid])
	{
		cout<<"\n item found at "<<mid<<" index.";
		return;
	}
	
	else if(item == a[start])
	{
		cout<<"\n item found at "<<start<<" index.";
		return;
	}
	
	else if(item == a[end])
	{
		cout<<"\n item found at "<<end<<" index.";
		return;
	}

	else if(mid == start || mid == end)
	{
		cout<<"\nElement not found";
		return;
	}
	
	else if(item > a[mid])
		FibonacciSearch(a, mid, end, fab, index-1, item);
	else
		FibonacciSearch(a, start, mid, fab, index-2, item);
}
 
main()
{
	int f, n, i, biter;
    cout<<"enter the length of array : ";
    cin>>f;
    int fab[f], a[f];
    cout<<"enter the elements : ";
	for(int i=0;i<f;i++){
        cin>>a[i];
    }
    char ch;
 
	fab[0] = 0;
	fab[1] = 1;
	i = 1;
	while(fab[i] < f)
	{
		i++;
		fab[i] = fab[i-1]+fab[i-2];
	}
 
	up:
	cout<<"\nEnter the Element to be searched: ";
	cin>>n;
 

	FibonacciSearch(a, 0, f, fab, i, n);
 
	
	cout<<"\n\n\tDo you want to search more...enter choice(y/n)?";
	cin>>ch;
	if(ch == 'y' || ch == 'Y')
		goto up;
 
	return 0;
}