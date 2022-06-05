/*
����һ���Ǹ��������� nums�������λ������ĵ�һ��λ�á�
�����е�ÿ��Ԫ�ش������ڸ�λ�ÿ�����Ծ����󳤶ȡ�
���Ŀ����ʹ�����ٵ���Ծ����������������һ��λ�á�
���������ǿ��Ե�����������һ��λ�á�

���� 1
����:
5
2 3 1 1 4
���:
2
����:
��С��Ծ������2�����±�Ϊ0�����±�Ϊ1��λ�ã���1����Ȼ����3��������������һ��λ�á�

���� 2
����:
5
2 3 0 1 4
���:
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