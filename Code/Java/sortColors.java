//Problem: https://leetcode.com/problems/sort-colors/
//Solution using the 2 pointer approach

class Solution{
  public void sortColors(int[] nums){
        int start = 0
        int end = nums.length-1
        int i = 0;
        while(i >= start && i <= end){
            if(nums[i] == 0){
                nums[i] = nums[start];
                nums[start] = 0;
                start++;
            }
          
            if(nums[i] == 2){
                nums[i] = nums[end];
                nums[end] = 2;
                end--;
                i--;
            }   
          
            i++;
        }
    }
}
