#include <bits/stdc++.h>

using namespace std;

/*
 * Given an array of coin denominations available,
 * assume you are provided with infinite number of
 * each denominations.
 * Find the minimum number of coins that make up the
 * provided amount.
 *
 * Subproblem defnition: coinChange(coins(i), amount) = minimum number of coins that make up amount from i
 * coinChange(i, amount) = max(1 + coinChange(i+1, amount-coins[i]), coinChange(i+1, 
 * but this subproblem defnition has a problem, it just considers a coin only once.
 * Our problem requires us to consider a coin any number of times, cause we are provided with infinite number of coins.
 */

int coinChange(vector<int>& coins, int amount){
}

void solve(){
  vector<int> coins = {1};
  int amount = 3;
  int ans = coinChange(coins, amount);
  cout << ans << endl;
}

int main(){
  solve();
  return 0;
}
