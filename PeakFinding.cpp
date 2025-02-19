#include <iostream>
#include <vector>
using namespace std;

int helper(vector<int> &nums, int start, int end){
  if(start == end)
    return start;

  if(start == 0)
    if(nums[start] > nums[start+1])
      return start;

  if(end == nums.size() - 1)
    if(nums[end] > nums[end-1])
      return end;

  int mid = (start + end) / 2;
  if(nums[mid-1] < nums[mid] && nums[mid+1] < nums[mid])
    return mid;
  
  if(nums[mid-1] > nums[mid] && nums[mid+1] < nums[mid])
    return helper(nums, start, mid);

  if(nums[mid-1] < nums[mid] && nums[mid+1] > nums[mid])
    return helper(nums, mid, end);
  
  else
    return helper(nums, start, mid);
}

int findPeakElement(vector<int> &nums){
  int idx = helper(nums, 0, nums.size() - 1);
  return idx;
}

void solve(){
  vector<int> nums = {1,2,1,2,1};
  int ans = findPeakElement(nums);
  cout << ans << '\n';
}

int main(){
  solve();
  return 0;
}



