class Solution {
    public int removeDuplicates(int[] nums) {
       int len=nums.length;
        int i=0;
        int j=1;
     while(j<len){
         
         if(nums[j]!=nums[i]){
             nums[++i]=nums[j];
         }
         j++;
         
     }
        
        int count=++i;
        for(i=count;i<len;i++){
            nums[i]='_';
        }
        
        return count;
        
    }
}
