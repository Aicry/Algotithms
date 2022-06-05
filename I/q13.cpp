#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> hights;
void fun(float l, float h, float water)
{
    while ((h - l) > 0.01)
    {

        float mid = (h + l) / 2;
        int n = hights.size();
        float tempWater = 0;
        for (int i = 0; i < n; i++)
        {
            if (mid >= hights[i])
                tempWater += (mid - (float)hights[i] / 3);
            else
            {
                float r2 = (float)(hights[i] - mid) / (float)hights[i];
                tempWater += mid-(mid * (1 + r2 * r2 + r2)) / 3;
            }
        }
        if (tempWater > water)
            h = mid;
        else
            l = mid;
    }
    cout << h  << endl;
}
int main()
{
    int M, N;
    cin >> M >> N;
    int k = N * M;
    int high = 0;
    while (k--)
    {
        int h;
        cin >> h;
        high = max(high, h);
        hights.push_back(h);
    }
    int q;
    cin >> q;
    while (q--)
    {
        float water;
        cin >> water;
        float low = water / (M * N);
        fun(low, low+high, water);
    }
}

