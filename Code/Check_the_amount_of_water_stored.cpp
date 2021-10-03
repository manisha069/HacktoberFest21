#include<vector>
#include<iostream>
using namespace std;

int main(){

    vector<int> arr{0,1,0,2,1,0,1,3,2,1,2,1};
    int n = arr.size();

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
    cout<< res;

    return 0;
}
