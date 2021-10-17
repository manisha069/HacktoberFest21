#include <bits/stdc++.h>
using namespace std;

//Time Complexity O(n)
//Space Complexity O(1)
int trappingWater(int arr[], int n){
    int left = 0; 
    int right = n-1;
    int res = 0;
    int maxleft = 0, maxright = 0;
    while(left <= right)
    {
        if(arr[left] <= arr[right])
        {
            if(arr[left] >= maxleft) 
                maxleft = arr[left];
            else 
                res += maxleft-arr[left];
            
            left++;
        }
        else
        {
            if(arr[right] >= maxright) 
                maxright = arr[right];
            else
                res += maxright-arr[right];
            
            right--;
        }
    }
    return res;
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    int result=trappingWater(a,n);
    cout<<result<<endl;
}
