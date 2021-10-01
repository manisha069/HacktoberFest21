class Solution:
    def buildArray(self, nums: List[int]) -> List[int]:
        ans=[]
        for i in range(len(nums)):
            temp=nums[i]
            ans.append(nums[temp])
        return ans
