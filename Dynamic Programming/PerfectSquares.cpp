#include <bits/stdc++.h>

using namespace std;

/*
 * Given an integer n, return the least number of perfect
 * square integers that sum up to n
 * Subproblem defnition: ns(n) = least number of perfect square numbers that add up to n
 * Relate: ns(n) = min(numSquares(n-squares less than or equal to n) for all such squares)
 * Base case: ns(0) = 0
 */

int numSquares(int n){
  vector<int> dp(n+1);
  dp[0] = 0;
  dp[1] = 1;
  for(int i = 1; i <= n; i++){
    int temp = 9999;
    int j = 0;
    while(j*j <= i){
      temp = min(temp, dp[i-j*j]);
      j++;
    }
    dp[i] = 1 + temp;
  }  
  return dp[n];
}

void solve(){
 int n = 12;
 int ans = numSquares(n);
 cout << ans << endl;
}

int main(){
  solve();
  return 0;
}
