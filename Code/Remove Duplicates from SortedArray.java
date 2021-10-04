class Solution {
    public int removeDuplicates(int[] nums) {
        int p=0;
        
            for(int j=1;j<nums.length;j++)
            {
                if(nums[j]!=nums[p])
                {   p++;
                    nums[p]=nums[j];
                }
            }
        
        return p+1;
    }
}
