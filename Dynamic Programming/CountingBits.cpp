#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
 * Given an integer n, return an array ans of length n+1 such that for each i (0<=i<=n), ans[i] is the number of 1's in the binary representation of i
Input: n = 5
Output: [0,1,1,2,1,2]
Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101
 */

vector<int> countBits(int n){
  vector<int> dp(n+1);
  dp[0] = 0;
  for(int i=1;i<=n;i++){
    if(i % 2 == 0)
      dp[i] = dp[i/2]; 
    else
      dp[i] = 1 + dp[i/2];
  }
  return dp;
}

void solve(){
 int n = 5;
 vector<int> ans = countBits(n);
 for(int i=0;i<=n;i++){
   cout << ans[i] << endl;
 }
}

int main(){
  solve();
  return 0;
}
