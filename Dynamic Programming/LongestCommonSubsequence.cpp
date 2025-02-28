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

string text1 = "abcde"; 
string text2 = "ace";
int n1 = text1.size();
int n2 = text2.size();
vector<vector<int>> dp(n1, vector<int>(n2, -1));

int LCS(string text1, int i, string text2, int j){
  if(dp[i][j] != -1)
    return dp[i][j];

  if(i == text1.size() || j == text2.size())
    return 0;

  if(text1[i] == text2[j]){
    return dp[i][j] = 1 + LCS(text1, i+1, text2, j+1);
  }

  return dp[i][j] = max(LCS(text1, i+1, text2, j), LCS(text1, i, text2, j+1));
}

void solve(){
  int len = LCS(text1, 0, text2, 0);
  cout << len << endl;
}

int main(){
  solve();
  return 0;
}
