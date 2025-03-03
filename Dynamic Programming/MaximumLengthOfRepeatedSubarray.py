'''
Given two integer arrays nums1 and nums2, 
return the maximum length of a subarray that appears in both arrays.

Subproblem defnition: mls(i, j) = the maximum length of the common subarray A[:i] and B[:j]
Relate: mls(i, j) = if A[i] == B[j] then 1 + mls(i-1, j-1) 
                    else max(mls(i, j-1), mls(i-1, j))
Base case: i = 0 or j = 0
Topological order: for i = 0 to m and for j = 0 to n
Original problem: mls(m, n)
'''

def findLength(nums1, nums2):
    m, n = len(nums1), len(nums2)
    dp = [[0] * (n+1) for _ in range(m+1)]

    for i in range(1, m+1):
        for j in range(1, n+1):
            if(nums1[i-1] == nums2[j-1]):
                dp[i][j] = 1 + dp[i-1][j-1]
            else:
                dp[i][j] = max(dp[i][j-1], dp[i-1][j])

    return dp[m][n]

nums1 = [1,2,3,2,1] 
nums2 = [3,2,1,4,7]

a = findLength(nums1, nums2)
print(a)

