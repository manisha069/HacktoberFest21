class Solution(object):
    def nextPermutation(self, nums):
        right = len(nums)-1
        while nums[right] <= nums[right-1] and right-1 >=0:
            right -= 1
        if right == 0:
            return self.reverse(nums,0,len(nums)-1)
        pivot = right-1
        successor = 0
        for i in range(len(nums)-1,pivot,-1):
            if nums[i] > nums[pivot]:
                successor = i
                break
        nums[pivot],nums[successor] = nums[successor],nums[pivot]  
        self.reverse(nums,pivot+1,len(nums)-1)
        
    def reverse(self,nums,l,r):
        while l < r:
            nums[l],nums[r] = nums[r],nums[l]
            l += 1
            r -= 1
