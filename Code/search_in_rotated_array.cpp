//  Leetcode question link - https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

// Problem statement - Given the array nums after the rotation and an integer target, 
// return true if target is in nums, or false if it is not in nums.

#include <bits/stdc++.h>
using namespace std;

bool search(vector<int> &nums, int target)
{
    int start = 0;
    int end = nums.size() - 1;
    int mid;
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (nums[mid] == target)
        {
            return true;
        }
        if (nums[start] == nums[mid])
        {
            start++;
            continue;
        }
        if (nums[end] == nums[mid])
        {
            end--;
            continue;
        }

        if (nums[start] < nums[mid]) //left array is sorted
        {
            if (nums[start] <= target && target < nums[mid])
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        else if (nums[mid] < nums[end]) //right array is sorted
        {
            if (nums[end] >= target && target > nums[mid])
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
    }
    return false;
}

int main()
{
    int n, tar;
    cin >> n >> tar;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    cout << search(v, tar) << endl;
    return 0;
}