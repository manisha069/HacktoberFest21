class Solution {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        int n = arr1.length;
        int m = arr2.length;
        int[] hashArr = new int[1001];
        for(int i=0; i<n;i++){
            hashArr[arr1[i]]++;
        }
        int[] ans = new int[n];
        int idx=0;
        for(int i=0; i<m; i++){
            while(hashArr[arr2[i]]--!=0){
                ans[idx] = arr2[i];
                idx++;
            }
            hashArr[arr2[i]]=0;
        }
        
        for(int i=0; i<1001;i++){
            
            while(hashArr[i]--!=0){
                ans[idx] = i;
                idx++;
            }                
        }
        
        return ans;
        
        
    }
}
