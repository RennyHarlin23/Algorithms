#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
 * mps(i,j) = minimum-path-sum from (i,j) cell to the (m-1,n-1) cell
 * mps(0,0)
 * I can only move either right or down at one instant
 * Base case: if(i == m-1 and j == n-1) return grid[i][j]
 * mps(i,j) = grid[i][j] + min{mps(i+1,j), mps(i,j+1)
 */
vector<vector<int>> grid = {{1,2,3},{4,5,6}};

int mps(vector<vector<int>> grid, int row, int column){
  if(row == grid.size() - 1 and column == grid[0].size() - 1)
    return grid[row][column];

  if(row == grid.size() - 1)
    return grid[row][column] + mps(grid, row, column+1);

  if(column == grid[0].size() - 1)
    return grid[row][column] + mps(grid, row+1, column);

  return grid[row][column] + min(mps(grid, row+1, column), mps(grid, row, column+1));
}
/*
 * Given a grid find the mps of moving the top right to the bottom left
 * subproblem: mps(i,j) = min cost of reaching i,j
 * relate: mps(i,j) = cost of grid[i][j] + min(grid[i-1][j], grid[i][j-1]) 
 * different ways of reaching i, j => can be reached from the left and from the top
 */
int mps_iterative(vector<vector<int>> grid, int row, int column){
  int m = grid.size();
  int n = grid[0].size();
  vector<vector<int>> dp(m, vector<int>(n));
  dp[0][0] = grid[0][0];

  for(int i = 1; i < m; i++){
    dp[i][0] = grid[i][0] + dp[i-1][0];
  }

  for(int j = 1; j < n; j++){
    dp[0][j] = grid[0][j] + dp[0][j-1];
  }

  for(int i = 1; i < m; i++){
    for(int j = 1; j < n; j++){
        dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
    }
  }
  return dp[m-1][n-1];
}

int minimumPathSum(vector<vector<int>> &grid){
  int ans = mps_iterative(grid, 0, 0);
  return ans;
}

void solve(){
  int ans = minimumPathSum(grid);
  cout << ans << endl;
}

int main(){
  solve();
  return 0;
}
