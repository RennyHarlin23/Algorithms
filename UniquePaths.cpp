#include <bits/stdc++.h>

using namespace std;

/*
 * Given a m x n grid, the robot is initially located
 * at the top-left corner (0,0). The robot has to go to
 * the bottom-right corner. The robot can only move either 
 * right or down at one instant.
 * Subproblem defnition: f(i, j) = no. of unique paths that exist form (i,j) to (m,n)
 * Original problem = f(0,0)
 * Relate: f(i, j) = 
 * 1. f(i+1, j) + f(i, j+1) + 2
 * 2. if i == m-1, then f(i, j+1) + 1 
 * 3. if j == n-1, then (i+1, j) + 1
 * Base Case: if(i == m-1 and j == n-1), then return 0;
 * Topological Order:
 * for i=m-2 to 0
 *  for j=n-2 to 0
 */

int uniquePaths(int m, int n){
  vector<vector<int>> dp(m, vector<int>(n));
  dp[m-1][n-1] = 1;

  for(int i=m-2;i>=0;i--){
    dp[i][n-1] = dp[i+1][n-1];
  }

  for(int j=n-2;j>=0;j--){
    dp[m-1][j] = dp[m-1][j+1];
  }

  for(int i=m-2;i>=0;i--){
    for(int j=n-2;j>=0;j--){
      dp[i][j] = dp[i+1][j] + dp[i][j+1];
    }
  }
  
  return dp[0][0];
}

void solve(){
  int m, n;
  cin >> m;
  cin >> n;
  int ans = uniquePaths(m, n);
  cout << ans << endl;
}

int main(){
  solve();
  return 0;
}
