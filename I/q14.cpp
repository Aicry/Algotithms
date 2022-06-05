#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> t(n);
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        t[i] = temp;
    }
    sort(t.begin(), t.end());
    int fast = t[0];
    int sum = 0;
    for (int i = 1; i < n ; i++)
    {
        sum += t[i] + fast;
    }
    sum -= fast;
    cout << sum;
}