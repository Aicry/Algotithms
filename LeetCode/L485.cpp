#include<iostream>
#include<vector>
using namespace std;
vector<int> nums{1, 1, 0, 1, 0, 0, 1, 1,1,1,0,0,0,0, 1,1};
int findMaxConsecutiveOnes(vector<int>& nums) {
    int n = nums.size();
    int pre, cur;
    int res=0;
    int count=0;
    for (int i = 0; i < n;++i){
        if(nums[i]==1)
            count++;
            else
            {
                res = max(res, count);
                count = 0;
            }
            
    }
     res = max(res, count);
    return res;
    }
int main(){

    cout << findMaxConsecutiveOnes(nums);
    return 0;
}