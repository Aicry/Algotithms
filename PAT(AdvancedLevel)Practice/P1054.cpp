#include <iostream>
#include <map>
using namespace std;
map<long, int> image;
//map<int, int>::iterator it;

int main()
{
    int m, n, max = 0;
    long t, res;
    cin >> m >> n;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> t;
            if (++image[t] > max)
                max = image[t], res = t;
        }
    }
    cout << res;
}