#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> merge(vector<int>& a, vector<int>& b){
  vector<int> c;
  int m = a.size();
  int n = b.size();
  int aCount = 0;
  int bCount = 0;

  while(aCount < m && bCount < n){
    if(a[aCount] >= b[bCount]){
      c.push_back(a[aCount]);
      aCount++;
    }
    else{
      c.push_back(b[bCount]);
      bCount++;
    }
  }
  
  while(aCount < m){
    c.push_back(a[aCount]);
    aCount++;
  }

  while(bCount < n){
    c.push_back(b[bCount]);
    bCount++;
  }
   
  return c;
}

vector<int> mergesort(vector<int>& nums, int front, int end){
  if(front == end)
    return vector<int>{nums[front]};

  int mid = (front+end)/2;

  vector<int> l = mergesort(nums, front, mid);
  vector<int> r = mergesort(nums, mid+1, end);

  vector<int> sol = merge(l, r);
  return sol;
}

int findKthLargest1(vector<int>& nums, int k){
  vector<int> c = mergesort(nums, 0, nums.size()-1);
  return c[k-1];
}

void solve(){
  vector<int> nums = {3,2,3,1,2,4,5,5,6};
  int k = 4;
  int ans = findKthLargest1(nums, k);
  cout << ans << endl;
}

int main(){
  solve();
  return 0;
}
