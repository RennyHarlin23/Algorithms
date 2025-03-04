'''
You have n dice, and each dice has k faces numbered from 1 to k.

Given three integers n, k, and target, return the number of possible ways (out of the kn total ways) to roll the dice,
so the sum of the face-up numbers equals target. Since the answer may be too large, return it modulo 109 + 7.

Subproblem defnition: fun(i, target) = number of ways to get to the target after using i dice
Relate: fun(i, j) = fun(i-1, j - f) for f = 1 to k
Original problem: fun(n, target)
Base case: if i == 0 return 0 or if target == 0 return 1
Topological order: for i = 0 to n and for j = 0 to target
'''

def numRollsToTarget(n, k, target):
    x = 10**9 + 7
    dp = [[0] * (target + 1) for _ in range(n+1)]

    dp[0][0] = 1 # No die rolls should be left and target sum should also be 0

    for i in range(1, n + 1):
        for j in range(1, target+1):
            temp = 0
            for f in range(1, k+1):
                if(j - f >= 0):
                    temp += dp[i-1][j-f]

            dp[i][j] = temp

    return dp[n][target] % x

n = 30
k = 30
target = 500
a = numRollsToTarget(n, k, target)
print(a)
