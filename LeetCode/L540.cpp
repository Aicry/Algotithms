 
#include<iostream>
#include<vector>
using namespace std;
 int main(){
     vector<int> nums{0, 0, 1, 1, 2, 2, 3, 4, 4};
      int lo = 0;
        int hi = nums.size() - 1;
        int mid;
        while (lo < hi) {
          mid=(hi-lo)/2+lo;
          if(mid%2==1)mid--;
          if(nums[mid]==nums[mid+1])lo=mid+2;
          else hi=mid;
        }
        return nums[lo];
 }