#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
 * Given 2 strings formulate an algorithm to find the
 * length of the longest common subsequence
 * 
 * lcs(i,j) = {
 *  if(text1[i] == text2[j]) then return 1 + lcs(i+1, j+1)
 *  else return max( lcs(i+1, j) , lcs(i, j+1))
 * }
 * original problem: lcs(0, 0)
 * base case: when n1 or n2 goes to the actual length of the text 
 */

string text1 = "abcde", text2 = "ace";
int n1 = text1.size();
int n2 = text2.size();
vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));

int LCS(string& text1, int n1, string& text2, int n2){
  if(dp[n1][n2] != -1)
    return dp[n1][n2];

  if(n1 == text1.size() or n2 == text2.size())
    return 0;

  if(text1[n1] == text2[n2]){
    dp[n1][n2] = 1 + LCS(text1, n1+1, text2, n2+1);
    return dp[n1][n2];
  }

  dp[n1][n2] = max(LCS(text1, n1+1, text2, n2), LCS(text1, n1, text2, n2+1));
  return dp[n1][n2];
}

int iterativeLCS(string& text1, int n1, string& text2, int n2){
  dp[text1.size()][text2.size()] = 0;
  
  for(int i=n1-1;i>=0;i--){
    for(int j=n2-1;j>=0;j--){
      if(text1[i] == text2[j])
        dp[i][j] = 1 + dp[i+1][j+1];
      else
        dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
    }
  }
  return dp[0][0];
}

void solve(){
  int len = LCS(text1, 0, text2, 0);
  int len1 = iterativeLCS(text1, 0, text2, 0);
  cout << len << endl;
  cout << len1 << endl;
}

int main(){
  solve();
  return 0;
}
