'''
Given the number of stairs n
Each time you can either take
1 or 2 steps.
find the total number of ways to
reach the top.


Subproblem defnition: CS(i) = the total number of ways I can reach the ith step
Relate: CS(i) = CS(i-1) + CS(i-2)
Base case: i == 1 return 1
Topological order: for i = 1 to n
Original problem: CS(n)
'''

def climbStairs(n):
    dp = [0] * (n+1)
    dp[1] = 1
    dp[0] = 1
    for i in range(2,n+1):
        dp[i] = dp[i-1] + dp[i-2]
    return dp[n]

a = climbStairs(3)
print(a)
