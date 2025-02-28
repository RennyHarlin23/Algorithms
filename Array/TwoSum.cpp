#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
   The problem we are trying to solve is two sum.
   Given an array of n elements and a sum.
   We want to find whether two elements exist in the array that add up
   to that sum.
 */

vector<int> twoSum(vector<int> &nums, int target){
  vector<int> idx;
  unordered_map<int, int> umap;

  for(int i=0;i<nums.size();++i){
   umap[nums[i]] = i;
  }

  for(int i=0;i<nums.size();++i){
    if(umap.count(target-nums[i])== 0)
      continue;
    else if(i != umap[target-nums[i]]){
      idx.push_back(i);
      idx.push_back(umap[target-nums[i]]);
      break;
    }
  }
  return idx;
}

void solve(){
  vector<int> nums= {3,3};
  int target = 6;
  vector<int> idx = twoSum(nums, target);
  for(auto item:idx){
    cout << item << endl;
  }
}

int main(){
  solve();
  return 0;
}
