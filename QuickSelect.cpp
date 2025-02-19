#include <iostream>
#include <vector>
#include <string>
using namespace std;

void swap(vector<int>& nums, int a, int b){
  int temp = nums[a];
  nums[a] = nums[b];
  nums[b] = temp;
}

int partition(vector<int>& a, int front, int end){
  if(front == end)
    return front;
  int pivot = a[end];
  if(a[front] > pivot){
    swap(a, front, end-1);
    swap(a, end-1, end);
    return partition(a, front, end-1); 
  }
  return partition(a, front+1, end) + 1;
}

int quickSelect(vector<int>& a, int front, int end, int k){
  if(front == end)
    return a[front];
  int p_idx = partition(a, front, end);
  if(p_idx == k)
    return a[k];
  if(k > p_idx)
    return quickSelect(a, p_idx+1, end, k);
  else
    return quickSelect(a, front, p_idx-1, k);
}

void solve(){
  vector<int> a = {3,2,3,1,2,4,5,5,6};
  int k = 4;
  int ans = quickSelect(a, 0, a.size() - 1, k-1);
  cout << ans << endl;
}

int main(){
  solve();
  return 0;
}
