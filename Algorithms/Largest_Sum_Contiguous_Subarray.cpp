//This is the Kadane's algorithm approach in order to find the largest sum contiguous array 

#include<iostream>
#include<climits>
using namespace std;
 

//maxSubArray function 
int maxSubArraySum(int a[], int size)
{
    int max_so_far = INT_MIN, max_ending_here = 0;
 
    for (int i = 0; i < size; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
 
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}


//main function 
int main()
{
    int a[] = {0, -21, 22, -1, 9, -1, 5, -10};
    int n = sizeof(a)/sizeof(a[0]);
    int max_sum = maxSubArraySum(a, n);
    cout << "Maximum contiguous sum in the array is : " << max_sum;
    return 0;
}
