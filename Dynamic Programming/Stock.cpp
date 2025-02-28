#include <bits/stdc++.h>

using namespace std;

/*
 * Given array containing the prices of stocks.
 * Choose an optimal day to buy and another optimal day in 
 * the future to sell the stock. Return the maximum profit being
 * made.
 * Subproblem defnition: profit(i) = max profit made by buying a stock on ith day
 * Relate = profit(i) = max of profits made by selling from i to n 
 */

int maxProfit(vector<int>& prices){
  int n = prices.size();
  int CP = prices[0]; // cp should be minimized and sp should be maximized
  int mp = 0;
  for(int i = 1; i < n; i++){
    CP = min(CP, prices[i]);
    mp = max(mp, prices[i] - CP);
  }
  return mp;
}

void solve(){
  vector<int> prices = {7,6,4,3,1};
  int ans = maxProfit(prices);
  cout << ans << endl;
}

int main(){
  solve();
  return 0;
}
