#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

double dp[105][105];
double build(int water, int row)
{
    memset(d, 0, sizeof(d));
    dp[0][0] = water;
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            if (dp[i][j] > 1)
            {
                double left = (dp[i][j] - 1) / 2;
                dp[i + 1][j] += left;
                dp[i + 1][j + 1] += left;
            }
        }
        
    }
   
}
