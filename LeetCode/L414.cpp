#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
//20ms
int thirdMax(vector<int>& nums) {
    int n = nums.size();
  
    sort(nums.rbegin(),nums.rend());
     int max = nums[0];
     int count = 1;
     for (int i = 0; i < n-1;++i){
         if(nums[i]!=nums[i+1])
             count++;
             if(count==3)
                 break;
     }
   if(count<3)
       return max;

         int k = 2;
     for (int i = 1; i < n;++i){
             if(nums[i]<max){
                 max = nums[i];
                 k--;
             }
             if(!k)
                 break;
         }
         return max;


    }


//8ms
/* int thirdMax(vector<int>& nums) {
        int n = nums.size();
        long max_first = LONG_MIN;
        for(int num:nums) {
            if(num > max_first) max_first = num;
        }
        if(n < 3) return max_first;

        long max_second = LONG_MIN, max_third = LONG_MIN;
        for(long num:nums) {
            if(num != max_first) {
                if(num > max_second) max_second = num;
            }
        }
        if(max_second == LONG_MIN) return max_first;

        for(long num:nums) {
            if(num != max_first && num != max_second) {
                if(num > max_third) max_third = num;
            }
        }
        if(max_third == LONG_MIN) return max_first;
        return max_third;
    }*/
int main(){
    vector<int> nums{1, 2, 2,3};
    cout<<thirdMax(nums);
    
}