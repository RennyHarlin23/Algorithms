'''
Given an integer array nums, return the length of the longest strictly increasing subsequence.

Subproblem defnition: LIS(i) = length of my longest strictly increasing subsequence in nums[:i]
Original problem: LIS(n)
Relate: LIS(i) = max( LIS(index of the element which is strictly lesser than nums[i]) + 1, LIS(i-1))
Base case: i == 0 return 0
'''
def lengthOfLIS(nums):
    pass

nums = [10,9,2,5,3,7,101,18]
ans = lengthOfLIS(nums)
print(ans)
