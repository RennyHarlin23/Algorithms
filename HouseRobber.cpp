#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
 * Given an array representing the amount of money
 * in each house, find the maximum money that can 
 * robbed without robbing adjacent houses.
 *
 * rob(i) = max(rob(i+1), nums[i] + rob(i+2))
 * original problem to solve = rob(0)
 * base case: rob(n) = 0;
 */

int rob(vector<int>& nums){
  int n = nums.size();

  if(n == 1)
    return nums[0];
  
  if(n == 2)
    return max(nums[0], nums[1]);

  vector<int> dp(n);

  dp[n-1] = nums[n-1];
  dp[n-2] = max(nums[n-1], nums[n-2]);

  for(int i=n-3;i>=0;i--){
    dp[i] = max(dp[i+1], nums[i] + dp[i+2]);
  }
  return dp[0];
}

void solve(){
  vector<int> nums = {2, 1, 1,2};
  int ans = rob(nums);
  cout << ans << endl;
}

int main(){
  solve();
  return 0;
}
