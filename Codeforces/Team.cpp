#include <bits/stdc++.h>

using namespace std;

int solve(){
  int n, count = 0, a, b, c;
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> a >> b >> c;
    if(a+b+c >= 2)
      count++;
  }
  return count;
}

int main(){
  int ans = solve();
  cout << ans;
  return 0;
}
