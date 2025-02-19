#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
 * Buying
 * Day 1 => you cannot sell, you can only buy
 * Day 2 => you can buy or not buy
 *
 * Selling
 * Day 1 => Not sell
 * Day 2 => can sell
 *
 * Subproblem defnition with it's relation:
 * max_profit(i) = max{ max { price(j) - price(i) for all 1 < j <= n }, max_profit(i+1)}
 * base case: n == 1 return 0
 */

int helper(vector<int>& prices, int n){
  vector<int> dp(n, -1);
  dp[n-1] = 0;
  
  for(int i=n-2;i>=0;i--){
    int temp = 0;
    for(int j=i;j<n;j++){
      temp = max(temp, prices[j] - prices[i]);
    }
    dp[i] = max(temp, dp[i+1]);
  }
  return dp[0];
}

int maxProfit(vector<int>& prices){
  return helper(prices, prices.size());
}

void solve(){
  vector<int> prices = {7,1,5,3,6,4};
  int ans = maxProfit(prices);
  cout << ans << endl;
}

int main(){
  solve();
  return 0;
}
