#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <stack>
#include <queue>
#include <list>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
public:
    

    int findMinDifference(vector<string> timePoints)
    {
        int min1 = 100000;
        int temp = 0;
        vector<int> mins;
        for (auto t : timePoints)
        {
            int hour = 0;
            int min = 0;
            hour = (t[0] - '0') * 10 + (t[1] - '0');
            min = (t[3] - '0') * 10 + (t[4] - '0');
            mins.push_back(hour * 60 + min);
        }

        sort(mins.begin(), mins.end());

        for (int i = 0; i < mins.size() - 2; i++)
        {
            temp = mins[i + 1] - mins[i];
            min1 = min(temp, min1);
        }
        int min2 = mins[0] + 24 * 60 - mins[mins.size() - 1];
        return min1 > min2 ? min2 : min1;
    }
};