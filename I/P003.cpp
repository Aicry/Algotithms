#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[100], w[100];
bool choice[100][100];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= w[i]; j--)
        {
            if (dp[j] <= dp[j - w[i]] + w[i])
            {
                choice[i][j] = true;
                dp[j] = dp[j - w[i]] + w[i];
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <=m; j++)
        {
            cout << choice[i][j] << ends;
        }
        cout << endl;
    }
    cout << endl;
    vector<vector<int>> res;
    for (int i = n; i > 0; i--)
    {
        vector<int> arr;
        int v = m, index = i;
        while (index>=0&&v > 0)
        {
            if (choice[index][v] == true)
            {
                arr.push_back(w[index]);
                v -= w[index];
                if(v==0)
                    {
                        res.push_back(arr);
                        arr.clear();
                    }
            }
            index--;

        }

    }
    for(auto a:res){
        for(auto b:a){
            cout << b << ends;
        }
        cout << endl;
    }
}