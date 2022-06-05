/*
给你一个非负整数数组 nums，你最初位于数组的第一个位置。
数组中的每个元素代表你在该位置可以跳跃的最大长度。
你的目标是使用最少的跳跃次数到达数组的最后一个位置。
假设你总是可以到达数组的最后一个位置。

样例 1
输入:
5
2 3 1 1 4
输出:
2
解释:
最小跳跃次数是2。从下标为0跳到下标为1的位置，跳1步，然后跳3步到达数组的最后一个位置。

样例 2
输入:
5
2 3 0 1 4
输出:
2


*/
#include <iostream>
#include <vector>
using namespace std;
int findmax(vector<int> nums)
{
    int n = nums.size();
    int maxPos = nums[0];
    int steps = 0;
    for (int i = 1; i < n; ++i)
    {
        int temp = maxPos;
        for (int j = i; j <= maxPos; j++)
        {

            if (nums[j] + j > temp)
            {
                temp = nums[j] + j;
            }
            if(temp>n){
                steps++;               
                return steps;
            }
        }
        if (temp>maxPos)
        {
            steps++;
            maxPos = temp;
        }
    }
    return steps;
}
int main()
{
    vector<int> nums = {2, 2, 1,5, 1, 4};
    cout << findmax(nums);
}