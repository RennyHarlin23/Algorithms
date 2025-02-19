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
vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};

int mps(vector<vector<int>> grid, int row, int column){
  if(row == grid.size() - 1 and column == grid[0].size() - 1)
    return grid[row][column];

  if(row == grid.size() - 1)
    return grid[row][column] + mps(grid, row, column+1);

  if(column == grid[0].size() - 1)
    return grid[row][column] + mps(grid, row+1, column);

  return grid[row][column] + min(mps(grid, row+1, column), mps(grid, row, column+1));
}

int minimumPathSum(vector<vector<int>> &grid){
  int ans = mps(grid, 0, 0);
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
